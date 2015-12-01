/*
 * listening.c
 *
 *  Created on: 30-Nov-2015
 *      Author: dipanjan
 */
#include "listening.h"
#include "config.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

void _start_outer_incoming_port() {
	struct sockaddr_rc loc_addr = { 0 }, rem_addr = { 0 };

	int s;
	socklen_t opt = sizeof(rem_addr);

	// allocate socket
	s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

	// bind socket to port 1 of the first available
	// local bluetooth adapter
	loc_addr.rc_family = AF_BLUETOOTH;
	loc_addr.rc_bdaddr = *BDADDR_ANY;
	loc_addr.rc_channel = (uint8_t) OUTER_LISTEN_CHANNEL;
	bind(s, (struct sockaddr *) &loc_addr, sizeof(loc_addr));

	// put socket into listening mode
	listen(s, 1);

	while (1) {
		// accept one connection
		int client;
		client = accept(s, (struct sockaddr *) &rem_addr, &opt);
		char buf[1024] = { 0 };
		ba2str(&rem_addr.rc_bdaddr, buf);
		fprintf(stderr, "accepted connection from %s\n", buf);
		memset(buf, 0, sizeof(buf));

		// read data from the client
		int bytes_read;
		bytes_read = read(client, buf, sizeof(buf));
		if (bytes_read > 0) {
			printf("received [%s]\n", buf);
		}

		// close connection
		close(client);
	}
	close(s);
	return;
}


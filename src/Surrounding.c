/*
 * Surrounding.c
 *
 *  Created on: 29-Nov-2015
 *      Author: dipanjan
 */
#include "surrounding.h"
#include "log.h"

#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>


size_t _self_surrounding(struct self_surrounding* container, size_t max_count)
{
	inquiry_info *ii = NULL;
	int max_rsp, num_rsp;
	int dev_id, sock, len, flags;
	int i;
	char addr[19] = { 0 };
	char name[248] = { 0 };

	dev_id = hci_get_route(NULL);
	sock = hci_open_dev( dev_id );
	if (dev_id < 0 || sock < 0) {
		ERR_LOG("failed to open socket", __FILE__);
		return 0;
	}

	len  = 8;
	max_rsp = max_count;
	flags = IREQ_CACHE_FLUSH;
	ii = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));

	num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);
	if( num_rsp < 0 )
	{
		ERR_LOG("error when enquiring from device", __FILE__);
		return 0;
	}

	(container)->dev_nearby_count = num_rsp;
	struct dev_bluetooth* devices = (container)->dev_nearby;
	REPORT_LOG("Device Discovered. COUNT num_rsp");
	for (i = 0; i < num_rsp; i++) {
		ba2str(&(ii+i)->bdaddr, addr);
		memset(name, 0, sizeof(name));
		if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name),
			name, 0) < 0)
		strcpy(name, "[unknown]");

		strcpy((devices)->dev_id, addr);
		strcpy((devices)->dev_name, name);
		//printf("%s  %s\n", addr, name);
		REPORT_LOG("DEV_NAME: name, DEV_ID: dev_id");
	}

	free( ii );
	close( sock );
	REPORT_LOG("num_rsp DEVICE RETURNED")
	return num_rsp;
}


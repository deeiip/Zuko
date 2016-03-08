/*
 * types.h
 *
 *  Created on: 29-Nov-2015
 *      Author: dipanjan
 */

#ifndef INCLUDE_TYPES_H_
#define INCLUDE_TYPES_H_

#include "config.h"

#include <stdio.h>
#include <stdbool.h>


struct dev_bluetooth {
	char dev_id[19];
	char dev_name[248];
	char proto_id[64]; // 256 bit protocol id
	bool is_gateway; // connected to internet
};

struct self_surrounding{
	struct dev_bluetooth* dev_nearby; // array of nearby devices
	size_t dev_nearby_count;
};




typedef struct log_buffer{
	char char_buff[LOG_BUFFER_SIZE];
	size_t buff_length;
} log_buffer;

typedef enum {
	log_type_err,
	log_type_rep,
	log_type_verb
} log_type;

typedef enum{
	message_type_control,
	message_type_data,
	message_type_all
} message_type;

typedef struct service_endpoint{
	char* ep_file_path;
	message_type ep_type;

} service_endpoint;

typedef struct current_endpoint_subscription{
	service_endpoint** arr;
	size_t count;
} current_endpoint_subscription;

// message_type_data assumes data is a file path
// otherwise data is the message itself
typedef struct message{
	message_type typ;
	const char* data;
} message;
#endif /* INCLUDE_TYPES_H_ */

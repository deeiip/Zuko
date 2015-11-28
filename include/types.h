/*
 * types.h
 *
 *  Created on: 29-Nov-2015
 *      Author: dipanjan
 */

#ifndef INCLUDE_TYPES_H_
#define INCLUDE_TYPES_H_
#include <stdio.h>
typedef struct dev_bluetooth {
	char dev_id[12];
	char dev_name[200];
	char proto_id[64]; // 256 bit protocol id
	bool is_gateway; // connected to internet
} dev_bluetooth;

typedef struct self_surrounding{
	dev_bluetooth* dev_nearby; // array of nearby devices
	size_t dev_nearby_count;
} self_surrounding;

#endif /* INCLUDE_TYPES_H_ */

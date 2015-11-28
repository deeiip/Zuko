/*
 * types.h
 *
 *  Created on: 29-Nov-2015
 *      Author: dipanjan
 */

#ifndef INCLUDE_TYPES_H_
#define INCLUDE_TYPES_H_
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

#endif /* INCLUDE_TYPES_H_ */

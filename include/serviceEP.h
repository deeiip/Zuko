/*
 * serviceEP.h
 *
 *  Created on: 30-Nov-2015
 *      Author: dipanjan
 */

#ifndef INCLUDE_SERVICEEP_H_
#define INCLUDE_SERVICEEP_H_
#include "types.h"

void _init_current_endpoint_subscription(current_endpoint_subscription**);
// before calling this from higher level, it should have created a server socket
// path is to be supplied to this function
void _write_to_service_ep(const char*);
void _create_subscription_ep(const char*, message_type);

#endif /* INCLUDE_SERVICEEP_H_ */

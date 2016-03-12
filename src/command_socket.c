/*
 * command_socket.c
 *
 *  Created on: 12-Mar-2016
 *      Author: dipanjan
 */

#include "command_socket.h"
#include "log.h"
#include "self_start.h"
#include "forwarding.h"
#include "data.h"
#include <stdlib.h>
#include <string.h>


/// this functon should be thread safe
void parse_command_string(const char* arg)
{
	char* token = strtok(arg, " ");
	if(token==NULL)
	{
		// invalid command
		ERR_LOG("Invalid command passed", __FILE__);
		return;
	}
	else
	{
		if(strcmp(token,"send")==0)
		{
			token = strtok(NULL, " ");
			char* pload = malloc(128*sizeof(char));
			strcpy(pload, token);
			token = strtok(NULL, " ");
			char dest[20][19];
			size_t idx = 0;
			while(token!=NULL)
			{
				strcpy(dest[idx], token);
				idx++;
			}
			forward(pload, dest, idx);

		}
		else if(strcmp(token, "scan")==0)
		{
			discover_surrounding();
		}
	}
}

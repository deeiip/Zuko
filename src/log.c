/*
 * log.c
 *
 *  Created on: 29-Nov-2015
 *      Author: dipanjan
 */
#include "log.h"


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void _write_err(const char* message, const char* filename)
{
	char* current_time;
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	//printf("Current local time and date: %s", asctime(timeinfo));
	size_t time_len = strlen(asctime(timeinfo));
	current_time = malloc(sizeof(char)* (time_len+1));
	strcpy(current_time, asctime(timeinfo));
}
void _write_log(const char* message)
{

}
void _write_report(const char* message)
{

}

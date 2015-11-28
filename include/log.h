/*
 * log.h
 *
 *  Created on: 29-Nov-2015
 *      Author: dipanjan
 */

#ifndef INCLUDE_LOG_H_
#define INCLUDE_LOG_H_

#define ERR_LOG(message, filename) _write_err(message, filename);
#define VER_LOG(message) _write_log(message);
#define REPORT_LOG(message) _write_report(message);


void _write_err(const char*, const char*);
void _write_log(const char*);
void _write_report(const char*);

#endif /* INCLUDE_LOG_H_ */

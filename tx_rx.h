/*
 * tx_rx.h
 *
 *  Created on: Aug 21, 2019
 *      Author: user
 */


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <error.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#include "common.h"
#include "pthread.h"


#define TOTAL_USER 							3000
//#define DATABASE_SIZE						1000
#define TOTAL_NUMBER_OF_PACKET  			100000
#define SEC_TO_NANO_SECONDS  				1000000000
//#define SIMULATION_RUN_TIME_MINUTE			1440
#define SIMULATION_RUN_TIME_MINUTE			1



#define TRAFFIC_MODEL						1
//If traffic model 1 selected set the distribution period to 60. if model 2 is selected, distribution period 10
#define DISTRIBUTION_PERIOD					60
#define DELTA_T								0.1


POneSourceOnOff completeSetOfSourcesToUse;

double packet_size [DISTRIBUTION_PERIOD][TOTAL_USER];
double user_arrival[DISTRIBUTION_PERIOD];


pthread_mutex_t lock;

//void receiver ();
void *receiver (void *arg);
void *start_transmission(void *arg);
void nanosleep_manually_compensated(myInteger expected_duration);
myInteger clock_now(void);
void initialize_stat_report ();

void count_packet (long long int loop);
void total_data (long long int size);
void report_write ();
void file_prep ();

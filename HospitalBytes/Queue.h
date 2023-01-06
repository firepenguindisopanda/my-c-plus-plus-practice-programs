#ifndef _QUEUE_H
#define _QUEUE_H
#include "DataTypes.h"

struct Queue {
	QueueNode * top;
	QueueNode * last;
};

Queue * initQueue ();
bool isEmptyQueue (Queue * q);
int sizeQueue (Queue * q);
void enqueue (Queue * q, Incident data);
Incident dequeue (Queue * q);

#endif
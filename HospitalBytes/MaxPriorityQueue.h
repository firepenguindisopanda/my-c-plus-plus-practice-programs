#ifndef _MAXPRIORITYQUEUE_H
#define _MAXPRIORITYQUEUE_H
#include <iostream>
#include "DataTypes.h"
using namespace std;

void maxHeapInsert(Incident A[], int heapSize, Incident newIncident);
Incident heapMaximum(Incident A[]);
Incident heapExtractMax(Incident A[], int heapSize);
void heapIncreaseKey(Incident A[], int i, int newPriority);

#endif
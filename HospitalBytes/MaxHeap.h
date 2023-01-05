#ifndef _MAXHEAP_H
#define _MAXHEAP_H
#include "DataTypes.h"

int parent(int i);
int leftChild(int i);
int rightChild(int i);
void maxHeapify(Incident A[], int heapSize, int i);
void buildMaxHeap(Incident A[], int lengthA);
void heapSort(Incident A[], int lengthA);
#endif
#include <iostream>
#include "DataTypes.h"
#include "MaxHeap.h"
#include "MaxPriorityQueue.h"
using namespace std;

/**
 * @brief Inserts a new incident in the max priority queue
 * stored in the array A based on its priority.
 * @param {Incident A[]} The array of type Incident
 * @param {int heapSize} The size of the heap
 * @param {Incident newIncident} The new incident to be inserted
 */
void maxHeapInsert(Incident A[], int heapSize, Incident newIncident)
{
    heapSize++;
    A[heapSize].patientID = newIncident.patientID;
    A[heapSize].conditionName = newIncident.conditionName;
    A[heapSize].priority = INT_MIN;
    heapIncreaseKey(A, heapSize, newIncident.priority);
}

/**
 * @brief Returns the highest priority element in the max priority queue
 * stored in array A.
 * @param {Incident A[]} The array of type Incident
 * @return {Incident} The highest priority element in the max priority queue
 */
Incident heapMaximum(Incident A[])
{

    Incident highestIncident;
    highestIncident.patientID = A[1].patientID;
    highestIncident.conditionName = A[1].conditionName;
    highestIncident.priority = A[1].priority;
    return highestIncident;
}
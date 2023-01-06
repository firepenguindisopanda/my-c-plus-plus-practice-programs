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

/**
 * @brief Removes and returns the highest priority element in the max priority queue
 * @param {Incident A[]} The array of type Incident
 * @param {int heapSize} The size of the heap
 * @return {Incident} The highest priority element in the max priority queue
 */
Incident heapExtractMax(Incident A[], int heapSize)
{
    if (heapSize < 1)
    {
        cout << "Heap underflow" << endl;
        return A[0];
    }
    Incident max = A[1];
    A[1] = A[heapSize];
    heapSize--;
    maxHeapify(A, heapSize, 1);
    return max;
}

/**
 * @brief Increases the value of the element i's priority to the new value,
 * newPriority, where newPriority is greater than or equal to i's current priority.
 * @param {Incident A[]} The array of type Incident
 * @param {int i} The index of the element whose priority is to be increased
 * @param {int newPriority} The new priority of the element
 */
void heapIncreaseKey(Incident A[], int i, int newPriority)
{
    if (newPriority < A[i].priority)
    {
        cout << "New priority is smaller than current priority" << endl;
        return;
    }
    A[i].priority = newPriority;
    while (i > 1 && A[parent(i)].priority < A[i].priority)
    {
        Incident temp = A[i];
        A[i] = A[parent(i)];
        A[parent(i)] = temp;
        i = parent(i);
    }
}
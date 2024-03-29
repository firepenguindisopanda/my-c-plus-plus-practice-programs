#include <iostream>
#include "DataTypes.h"
#include "MaxHeap.h"
using namespace std;

int parent(int i)
{
    return (i/2);
}

int leftChild(int i)
{
    return (2*i);
}

int rightChild(int i)
{
    return (2*i) + 1;
}

/**
 * @brief maxHeapify
 * Assuming that the left and right subtrees
 * of node i are max heaps, this function
 * maintains the max heap property starting
 * at node i.
 * 
 */
void maxHeapify(Incident A[], int heapSize, int i)
{
    int l = leftChild(i);
    int r = rightChild(i);
    int largest = i;
    if (l <= heapSize && A[l].priority > A[i].priority)
        largest = l;

    if (r <= heapSize && A[r].priority > A[largest].priority)
        largest = r;

    if (largest != i)
    {
        Incident temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(A, heapSize, largest);
    }
}

/**
 * @brief buildMaxHeap
 * Given an array A of type Incident where the lengthA is the amount of elements in A,
 * Converts A into a max heap on the priority of each patient.
 */
void buildMaxHeap(Incident A[], int lengthA)
{
    int heapSize = lengthA;
    for (int i = heapSize/2; i >= 1; i--)
        maxHeapify(A, heapSize, i);
}

/**
 * @brief heapSort
 * Given an Array A of type Incident and lengthA, which is the amount of elements in  A,
 * Sorts the elements in A based on the priority of the incidents
 */
void heapSort(Incident A[], int lengthA)
{
    int heapSize = lengthA;
    buildMaxHeap(A, lengthA);

    for(int i = lengthA; i >= 2; i--){
        Incident temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        heapSize = heapSize - 1;
        maxHeapify(A, heapSize, 1);
    }
}
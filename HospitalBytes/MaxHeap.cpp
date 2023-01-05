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
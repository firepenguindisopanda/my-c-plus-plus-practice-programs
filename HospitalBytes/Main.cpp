#include <iostream>
#include <fstream>
#include <iomanip>
#include "DataTypes.h"
#include "MaxHeap.h"
#include "MaxPriorityQueue.h"
#include "Queue.h"
#include "HashTable.h"
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include "HashTable.cpp"
#include "Queue.cpp"
#include "MaxPriorityQueue.cpp"
#include "MaxHeap.cpp"
using namespace std;


int main()
{
    // read patient data and save to binary search tree
    ifstream patientData;
    patientData.open("Patient.txt");
    if(!patientData)
    {
        cout << "Error Opening file!" << endl;
        exit(1);
    }
    int patientID{};
    string patientName, patientPhoneNumber;
    patientData >> patientID;
    Patient patientInfo;
    BTNode * root = nullptr;
    while(patientID != 999)
    {
        patientInfo.patientID = patientID;

        // getting patient name
        patientData >> patientName;
        patientInfo.patientName = patientName;

        // Getting patient phone number
        patientData >> patientPhoneNumber;
        patientInfo.phone = patientPhoneNumber;

        // inserting patient info into binary search tree using insertBST
        root = insertBST(root, patientInfo);

        // getting the next patient ID
        patientData >> patientID;
    }

    cout << "\nI'm done reading the patient data" << endl;

    // Displaying the binary search tree
    cout << "\nDisplaying the binary search tree" << endl;
    displayBST(root);
    // displayPreOrder(root);
    // displayPostOrder(root);

    system("pause");
}
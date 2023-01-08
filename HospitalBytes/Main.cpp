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
    ifstream incidentData;
    patientData.open("Patient.txt");
    if(!patientData)
    {
        cout << "Error Opening file!" << endl;
        exit(1);
    }
    int patientID{};
    int incidentId{}, priority{0}, heapSize{0}, count{0};
    string patientName, patientPhoneNumber;
    string condition;

    Incident newIncident;
    Incident incidentArray[1000];

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
    // cout << "\nDisplaying the binary search tree" << endl;
    // displayBST(root);
    // displayPreOrder(root);
    // displayPostOrder(root);

    incidentData.open("Incident.txt");
    if(!incidentData.is_open()){
        cout << "Could not find Incident File!..." << endl;
        exit(1);
    }
    // setup the incident array with initial values at 0 or " "
    for(count = 0; count < 1000; count++)
    {
        incidentArray[count].patientID = 0;
        incidentArray[count].conditionName = " ";
        incidentArray[count].priority = 0;
    }
    incidentData >> incidentId;
    while(incidentId != 999){
        newIncident.patientID = incidentId;
        incidentData >> condition;
        newIncident.conditionName = condition;
        incidentData >> priority;
        newIncident.priority = priority;
        heapSize++;
        maxHeapInsert(incidentArray, heapSize, newIncident);
        incidentData >> incidentId;
    }

    // print the incident array
    cout << "\nDisplaying the incident array" << endl;
    for(count = 1; count <= heapSize; count++)
    {
        cout << incidentArray[count].patientID << " " << incidentArray[count].conditionName << " " << incidentArray[count].priority << endl;
    }

    system("pause");
    return 0;
}
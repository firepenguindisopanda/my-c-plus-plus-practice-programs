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

void hospitalBytesMenu(int, int);

int main()
{
    // read patient data and save to binary search tree
    ifstream patientData;
    ifstream incidentData;
    ifstream priorityData;
    patientData.open("Patient.txt");
    if(!patientData)
    {
        cout << "Error Opening file!" << endl;
        exit(1);
    }
    int patientID{};
    int incidentId{}, priority{0}, heapSize{0}, count{0};
    int priorityValue{}, tableSize{701}, priorityNum{0};
    string patientName, patientPhoneNumber;
    string condition;
    string priorityName;

    Incident newIncident;
    Incident incidentArray[1000];

    Condition priorityCondition;
    HashTable * priorityHash;

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
    // cout << "\nDisplaying the incident array" << endl;
    // for(count = 1; count <= heapSize; count++)
    // {
    //     cout << incidentArray[count].patientID << " " << incidentArray[count].conditionName << " " << incidentArray[count].priority << endl;
    // }
    priorityData.open("Priority.txt");
    if(!priorityData.is_open()){
        cout << "Could not find Priority File!..." << endl;
        exit(1);
    }
    priorityData >> priorityName;
    priorityHash = initHashTable(tableSize);
    while(priorityName != "XXX")
    {
        priorityCondition.name = priorityName;
        priorityData >> priorityValue;
        priorityCondition.priority = priorityValue;
        priorityNum++;
        insertHashTable(priorityHash, priorityCondition, tableSize);
        priorityData >> priorityName;
    }
    cout << "\nI'm done with priority file\nDisplaying the priority hash table" << endl;

    // display the priority hash table
    // for(count = 0; count < tableSize; count++)
    // {
    //     if(priorityHash->elements[count].name != " ")
    //     {
    //         cout << priorityHash->elements[count].name << " " << priorityHash->elements[count].priority << endl;
    //     }
    // }

    Queue * patientQueue = initQueue();

    hospitalBytesMenu(10, 70);
    system("pause");
    return 0;
}


void hospitalBytesMenu(int row, int col)
{
    string heading = "Welcome to Hospital Bytes";
    int middleOfCol{(col - int(heading.length())) / 2}, middleOfRow{row / 2};
    cout << setw(col) << setfill('*') << "*" << endl;
    for(int i = 0; i < row; i++)
    {
        if((i + 1) == middleOfRow){
            cout << setw(middleOfCol) << setfill(' ') << " " << "Welcome to Hospital Bytes" << endl;
        }else{
            cout << setw(col) << setfill(' ') << " " << endl;
        }
    }

    

}
#ifndef _DATATYPES_H
#define _DATATYPES_H
#include <iostream>
using namespace std;

// A STRUCT CONTAINING attributes for a Condition object
struct Condition {
    string name;
    int priority;
};

// A STRUCT CONTAINING attributes for a Patient object
struct Patient {
    int patientID;
    string patientName;
    string phone;
};

// A STRUCT CONTAINING attributes for an Incident object
struct Incident {
    int incidentID;
    int patientID;
    string conditionName;
    string description;
    int priority;
    string status;
    string date;
    string time;
};

// A STRUCT CONTAINING attributes for a BTNode object
struct BTNode {
    Patient patient;
    BTNode *left;
    BTNode *right;
    BTNode *parent;
};

// A STRUCT CONTAINING attributes for a QueueNode object
struct QueueNode {
    Incident incidentData;
    QueueNode *next;
};

#endif
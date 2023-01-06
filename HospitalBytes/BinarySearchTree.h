#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H
#include <iostream>
#include "DataTypes.h"

BTNode * createBTNode(Patient newPatient);
bool containsBST(BTNode * root, int patientID);
BTNode * getBST(BTNode * root, int patientID);
BTNode * insertBST(BTNode * root, Patient newPatient);
BTNode * treeMinimum(BTNode * root);
BTNode * inOrderSuccessor(BTNode * node);
void displayBST(BTNode * root);
void displayPreOrder(BTNode * root);
void displayPostOrder(BTNode * root);

#endif
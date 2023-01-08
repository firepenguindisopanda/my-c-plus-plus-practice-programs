#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
    private:
        Node* root;
        void insert(Node* node, int data);
        void displayInorder(Node* node);
        int depthOfTree(Node* node);
        bool isFullBinaryTree(Node* node);
};
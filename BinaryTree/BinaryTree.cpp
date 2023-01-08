#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class BinaryTree {
    private:
        Node* root = NULL;

    public:
        BinaryTree();
        void insert(int data);
        void displayInorder(Node* root);
        int depthOfTree(Node* root);
        bool isFullBinaryTree(Node* root);

        BinaryTree () {
            root = NULL;
        }
        void insert(int data){
            Node* newNode = new Node(data);
            if (root == NULL) {
                root = newNode;
            } else {
                Node* temp = root;
                while (temp != NULL) {
                    if (data < temp->data) {
                        if (temp->left == NULL) {
                            temp->left = newNode;
                            break;
                        } else {
                            temp = temp->left;
                        }
                    } else {
                        if (temp->right == NULL) {
                            temp->right = newNode;
                            break;
                        } else {
                            temp = temp->right;
                        }
                    }
                }
            }
            
        }

        void displayInorder(Node* root) {
            // Iterative Inorder Traversal
            stack<Node*> s;
            Node* curr = root;
            while (curr != NULL || s.empty() == false) {
                while (curr != NULL) {
                    s.push(curr);
                    curr = curr->left;
                }
                curr = s.top();
                s.pop();
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
};
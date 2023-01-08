#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stack>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data = 0;
        Node* left = NULL;
        Node* right = NULL;
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class BinaryTree {
    private:
        int data = 0;

    public:
        Node* root = NULL;

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

        int depthOfTree(Node* root) {
            // iterative depth of tree
            if (root == NULL) {
                return 0;
            }
            queue<Node*> q;
            q.push(root);
            int depth = 0;
            int nodeCount = 0;
            while (q.empty() == false) {
                nodeCount = q.size();
                while (nodeCount > 0) {
                    Node* temp = q.front();
                    q.pop();
                    if (temp->left != NULL) {
                        q.push(temp->left);
                    }
                    if (temp->right != NULL) {
                        q.push(temp->right);
                    }
                    nodeCount--;
                }
                depth++;
            }
            return depth;
        }

        bool isFullBinaryTree(Node* root) {
            // iterative full binary tree
            if (root == NULL) {
                return true;
            }
            queue<Node*> q;
            q.push(root);
            while (q.empty() == false) {
                Node* temp = q.front();
                q.pop();
                if (temp->left == NULL && temp->right == NULL) {
                    continue;
                }
                if (temp->left != NULL && temp->right != NULL) {
                    q.push(temp->left);
                    q.push(temp->right);
                } else {
                    return false;
                }
            }
            return true;
        }
};

static void test_one(){
    /**
     * @brief Test Case 1 for Full Binary Tree
     * 
     * 
     */
    BinaryTree bt;
    bt.insert(10);
    bt.insert(5);
    bt.insert(15);
    bt.insert(3);
    bt.insert(7);
    bt.insert(12);
    bt.insert(18);
    bt.insert(1);
    bt.insert(4);
    bt.insert(6);
    bt.insert(8);
    bt.insert(11);
    bt.insert(13);
    bt.insert(16);
    bt.insert(19);
    bool result = bt.isFullBinaryTree(bt.root);
    bool expected = true;
    cout << "Test Case 1: returns true / 1 for Full Binary Tree" << endl;
    assert(result == expected);
    cout << "\tTest Case 1: Passed with code: " << (result == expected) << endl;

}

int main(){
    test_one();
    BinaryTree bt;
    bt.insert(10);
    bt.insert(5);
    bt.insert(15);
    bt.insert(3);
    bt.insert(7);
    bt.insert(12);
    bt.insert(18);
    bt.insert(1);
    bt.insert(4);
    bt.insert(6);
    bt.insert(8);
    bt.insert(11);
    bt.insert(13);
    bt.insert(16);
    bt.insert(19);
    bt.displayInorder(bt.root);
    string message = bt.isFullBinaryTree(bt.root) ? "Binary Tree is full" : "Binary Tree is not full";
    cout << endl;
    cout << bt.depthOfTree(bt.root) << endl;
    cout << message << endl;
    system("pause");
    return 0;
}
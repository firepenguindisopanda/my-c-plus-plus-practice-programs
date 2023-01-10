#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cassert>

using namespace std;

struct Node
{
    int key;
    Node *parent;
    char color;
    Node *left;
    Node *right;
};

class RedBlackTree
{
    Node *root;
    Node *q;

public:
    RedBlackTree()
    {
        q = NULL;
        root = NULL;
    }
    void insert();
    void insertFix(Node *);
    void leftRotate(Node *);
    void rightRotate(Node *);
    void del();
    Node *successor(Node *);
    void deleteFix(Node *);
    void disp();
    void display(Node *);
    void search();
};

void RedBlackTree::insert()
{
    int z;
    cout << "Enter value of node to be inserted: ";
    cin >> z;
    Node *zPtr = new Node;
    zPtr->key = z;
    zPtr->left = q;
    zPtr->right = q;
    zPtr->color = 'r';
    Node *y = NULL;
    Node *x = root;
    while (x != q)
    {
        y = x;
        if (zPtr->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    zPtr->parent = y;
    if (y == NULL)
        root = zPtr;
    else if (zPtr->key < y->key)
        y->left = zPtr;
    else
        y->right = zPtr;
    if (zPtr->parent == NULL)
    {
        zPtr->color = 'b';
        return;
    }
    if (zPtr->parent->parent == NULL)
        return;
    insertFix(zPtr);
}

void RedBlackTree::insertFix(Node *t)
{

    Node *u;
    while (t->parent->color == 'r')
    {
        Node *g = t->parent->parent;
        if (t->parent == g->left)
        {
            u = g->right;
            if (u->color == 'r')
            {
                t->parent->color = 'b';
                u->color = 'b';
                g->color = 'r';
                t = g;
            }
            else
            {
                if (t == t->parent->right)
                {
                    t = t->parent;
                    leftRotate(t);
                }
                t->parent->color = 'b';
                g->color = 'r';
                rightRotate(g);
            }
        }
        else
        {
            u = g->left;
            if (u->color == 'r')
            {
                t->parent->color = 'b';
                u->color = 'b';
                g->color = 'r';
                t = g;
            }
            else
            {
                if (t == t->parent->left)
                {
                    t = t->parent;
                    rightRotate(t);
                }
                t->parent->color = 'b';
                g->color = 'r';
                leftRotate(g);
            }
        }
        if (t == root)
            break;
    }
    root->color = 'b';
}

void RedBlackTree::del()
{

    int z;
    cout << "Enter value of node to be deleted: ";
    cin >> z;
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    Node *v = root, *u;
    while (v != q)
    {
        if (v->key == z)
            break;
        if (v->key < z)
            v = v->right;
        else
            v = v->left;
    }
    if (v->left == q || v->right == q)
        u = v;
    else
        u = successor(v);
    Node *x;
    if (u->left != q)
        x = u->left;
    else
        x = u->right;
    x->parent = u->parent;
    if (u->parent == NULL)
        root = x;
    else
    {
        if (u == u->parent->left)
            u->parent->left = x;
        else
            u->parent->right = x;
    }
    if (u != v)
        v->key = u->key;
    if (u->color == 'b')
        deleteFix(x);

    delete u;
}

void RedBlackTree::deleteFix(Node *p)
{

    Node *s;
    while (p != root && p->color == 'b')
    {
        if (p == p->parent->left)
        {
            s = p->parent->right;
            if (s->color == 'r')
            {
                s->color = 'b';
                p->parent->color = 'r';
                leftRotate(p->parent);
                s = p->parent->right;
            }
            if (s->left->color == 'b' && s->right->color == 'b')
            {
                s->color = 'r';
                p = p->parent;
            }
            else
            {
                if (s->right->color == 'b')
                {
                    s->left->color = 'b';
                    s->color = 'r';
                    rightRotate(s);
                    s = p->parent->right;
                }
                s->color = p->parent->color;
                p->parent->color = 'b';
                s->right->color = 'b';
                leftRotate(p->parent);
                p = root;
            }
        }
        else
        {
            s = p->parent->left;
            if (s->color == 'r')
            {
                s->color = 'b';
                p->parent->color = 'r';
                rightRotate(p->parent);
                s = p->parent->left;
            }
            if (s->right->color == 'b' && s->left->color == 'b')
            {
                s->color = 'r';
                p = p->parent;
            }
            else
            {
                if (s->left->color == 'b')
                {
                    s->right->color = 'b';
                    s->color = 'r';
                    leftRotate(s);
                    s = p->parent->left;
                }
                s->color = p->parent->color;
                p->parent->color = 'b';
                s->left->color = 'b';
                rightRotate(p->parent);
                p = root;
            }
        }
    }
    p->color = 'b';
}

void RedBlackTree::leftRotate(Node *p)
{
    Node *y = p->right;
    p->right = y->left;
    if (y->left != q)
        y->left->parent = p;
    y->parent = p->parent;
    if (p->parent == NULL)
        root = y;
    else if (p == p->parent->left)
        p->parent->left = y;
    else
        p->parent->right = y;
    y->left = p;
    p->parent = y;
}

void RedBlackTree::rightRotate(Node *p)
{
    Node *y = p->left;
    p->left = y->right;
    if (y->right != q)
        y->right->parent = p;
    y->parent = p->parent;
    if (p->parent == NULL)
        root = y;
    else if (p == p->parent->right)
        p->parent->right = y;
    else
        p->parent->left = y;
    y->right = p;
    p->parent = y;
}

Node *RedBlackTree::successor(Node *p)
{

    Node *y;
    if (p->left != q)
    {
        y = p->left;
        while (y->right != q)
            y = y->right;
        return y;
    }
    else
    {
        y = p->right;
        while (y->left != q)
            y = y->left;
        return y;
    }
}

void RedBlackTree::disp()
{
    display(root);
}

void RedBlackTree::display(Node *p)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    stack<Node *> s;
    Node *curr = p;
    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->key << " ";
        curr = curr->right;
    }
}

void RedBlackTree::search()
{

    int z;
    cout << "Enter value to be searched: ";
    cin >> z;
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    Node *v = root;
    while (v != q)
    {
        if (v->key == z)
        {
            cout << "Node found" << endl;
            return;
        }
        if (v->key < z)
            v = v->right;
        else
            v = v->left;
    }
    cout << "Node not found" << endl;
}

int main()
{

    RedBlackTree rbt;
    int ch, z;

    while (1)
    {
        cout << "1.Insert" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Display" << endl;
        cout << "4.Search" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            rbt.insert();
            break;
        case 2:
            rbt.del();
            break;
        case 3:
            rbt.disp();
            cout << endl;
            break;
        case 4:
            rbt.search();
            break;
        case 5:
            exit(1);
        default:
            cout << "Invalid choice" << endl;
        }
    }

    system("pause");
    return 0;
}
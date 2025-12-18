#include <iostream>
using namespace std;
struct BST
{
    int data;
    int bf;
    BST *left, *right, *child;
};
BST *root, *temp, *ttemp, *p, *q;
void init()
{
    root = temp = ttemp = NULL;
}
void createRoot(int x)
{
    root = new BST;
    root->data = x;
    root->left = NULL;
    root->right = NULL;
}
void addNodes(int x)
{
    temp = root;
    while (temp != NULL)
    {
        ttemp = temp;
        if (temp->data < x)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    p = new BST;
    p->data = x;
    p->left = p->right = NULL;
    if (ttemp->data > x)
    {
        ttemp->left = p;
    }
    else
    {
        ttemp->right = p;
    }
    ttemp->child = temp;
}
void inOrder(BST *p)
{
    if (p != NULL)
    {
        inOrder(p->left);
        cout << p->data << " ";
        inOrder(p->right);
    }
}
void preOrder(BST *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preOrder(p->left);
        preOrder(p->right);
    }
}
void postOrder(BST *p)
{
    if (p != NULL)
    {
        postOrder(p->left);
        postOrder(p->right);
        cout << p->data << " ";
    }
}

int findLevel(int x)
{
    int lvl = 0;
    temp = root;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return lvl;
        }
        else if (temp->data < x)
        {
            lvl++;
            temp = temp->right;
        }
        else
        {
            lvl++;
            temp = temp->left;
        }
    }
    return lvl;
}
void deleteNode(int x)
{
    temp = root;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            break;
        }
        else if (temp->data < x)
        {
            ttemp = temp;
            temp = temp->right;
        }
        else
        {
            ttemp = temp;
            temp = temp->left;
        }
    }
    if (ttemp->data < x)
    {
        ttemp->right = NULL;
    }
    else
    {
        ttemp->left = NULL;
    }
}
void RR(BST *p)
{
    q = p->left;
    temp = q->right;
    q->right = p;
    p->left = temp;
    root = q;
}
void LR(BST *p)
{
    q = p->right;
    temp = q->left;
    q->left = p;
    p->right = temp;
    root = q;
}
void balancing(BST *ptr, int left, int right)
{
    int bf = left - right;
    ptr->bf = bf;
    if (bf > 1)
    {
        RR(ptr);
    }
    else
    {
        if (bf < -1)
        {
            LR(ptr);
        }
        else
        {
            if (ptr->bf < -1 && ptr->right->bf > 0)
            {
                RR(ptr->left);
                LR(ptr);
            }
            else
            {
                if (ptr->bf > 1 && ptr->right->bf < 0)
                {
                    LR(ptr->right);
                    RR(ptr);
                }
            }
        }
    }
}
int AVL(BST *ptr)
{
    // base case
    if (ptr == NULL)
    {
        return 0;
    }
    // kaam
    int leftHei = AVL(ptr->left);
    int rightHei = AVL(ptr->right);
    balancing(ptr, leftHei, rightHei);
    return max(leftHei, rightHei) + 1;
}
int main()
{
    init();
    int x;
    createRoot(100);
    addNodes(50);AVL(root);
    addNodes(20);AVL(root);
    addNodes(10);AVL(root);
    addNodes(30);AVL(root);
    addNodes(15);AVL(root);
    addNodes(5);AVL(root);
    addNodes(7);AVL(root);
    // cout << "Enter first ROOT : ";
    // cin >> x;
    // createRoot(x);
    // int n;
    // do
    // {
    //     cout << "Enter 1 for adding a node" << endl;
    //     cout << "Enter 2 for deleting a node" << endl;
    //     cout << "Enter 3 for finding level of a root" << endl;
    //     cout << "Enter 4 for in-order traversal" << endl;
    //     cout << "Enter 5 for pre-order traversal" << endl;
    //     cout << "Enter 6 for post-order traversal" << endl;
    //     cout << "Enter 7 to exit" << endl;
    //     cin >> n;
    //     if (n == 1)
    //     {
    //         cout << "Enter node data : ";
    //         cin >> x;
    //         addNodes(x);
    //         AVL(root);
    //     }
    //     else if (n == 2)
    //     {
    //         deleteNode(x);
    //     }
    //     else if (n == 3)
    //     {
    //         cout << "Enter node to find its level : ";
    //         cin >> x;
    //         cout << "Level of " << x << " is : " << findLevel(x) << endl;
    //     }
    //     else if (n == 4)
    //     {
    //         inOrder(root);
    //     }
    //     else if (n == 5)
    //     {
    //         preOrder(root);
    //     }
    //     else if (n == 6)
    //     {
    //         postOrder(root);
    //     }
    // } while (n != 7);
    // cout << "Thank you for using me :) ";
}
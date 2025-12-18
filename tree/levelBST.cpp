#include <iostream>
using namespace std;
struct BST
{
    int data;
    BST *left, *right;
};
BST *root, *temp, *ttemp, *p;
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
}
void getLevel(){
    
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
int main()
{
    init();
    createRoot(100);
    addNodes(50);
    addNodes(80);
    addNodes(200);
    addNodes(30);
    addNodes(20);
    addNodes(150);
    addNodes(300);
    deleteNode(20);
    cout << "In-order : ";
    inOrder(root);
    cout << endl;
    cout << "Pre-order : ";
    preOrder(root);
    cout << endl;
    cout << "Post-order : ";
    postOrder(root);
    cout << endl;
    cout << "Level of " << 20 << " is : " << findLevel(20);
}
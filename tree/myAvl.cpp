#include <iostream>
using namespace std;
struct BST
{
    int data;
    int bf;
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
     root->bf = 0;  
}
void addNodes(int x)
{
    temp = root;
    while (temp != NULL)
    {
        ttemp = temp;
        if (x > temp->data)
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
     p->bf = 0;  
    if (ttemp->data > x)
    {
        ttemp->left = p;
    }
    else
    {
        ttemp->right = p;
    }
}
BST *RR(BST *ptr)
{
    BST *q = ptr->left;
    temp = q->right;
    q->right = ptr;
    ptr->left = temp;
    return q;
}
BST *LR(BST *ptr)
{
    BST *q = ptr->right;
    temp = q->left;
    q->left = ptr;
    ptr->right = temp;
    return q;
}
BST *balancing(BST *ptr, int leftHei, int rightHei)
{
    int balancingFactor = leftHei - rightHei;
    ptr->bf = balancingFactor;
    if (balancingFactor > 1)
    {
        if (ptr->left!=NULL && ptr->left->bf < 0)
        {
            ptr->left = LR(ptr->left);
        }
        return RR(ptr);
    }
    else if (balancingFactor < -1)
    {
        if (ptr->right!=NULL && ptr->right->bf > 0)
        {
            ptr->right = RR(ptr->right);
        }
        return LR(ptr);
    }
    return ptr;
}
int Avl(BST *ptr, BST *&newRoot)
{
    // Base case
    if (ptr == NULL)
    {
        newRoot = NULL;
        return 0;
    }
    BST *lRoot, *rRoot;

    int leftHei = Avl(ptr->left, lRoot);
    int rightHei = Avl(ptr->right, rRoot);

    ptr->left = lRoot;
    ptr->right = rRoot;

    BST *balanced = balancing(ptr, leftHei, rightHei); // returns add for saving it into parents left/right

    newRoot = balanced;

    return max(leftHei, rightHei) + 1;
}
void avl()
{
    BST *newROOT;
    Avl(root, newROOT);
    root = newROOT;
}
int nodeLvl(int x)
{
    int lvl = 0;
    temp = root;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return lvl;
        }
        lvl++;
        if (temp->data > x)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return -1;
}
int main()
{
    init();
    // int x;
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
    //         avl();
    //     }
    //     else if (n == 2)
    //     {
    //         // deleteNode(x);
    //     }
    //     else if (n == 3)
    //     {
    //         cout << "Enter node to find its level : ";
    //         cin >> x;
    //         cout << "Level of " << x << " is : " << nodeLvl(x) << endl;
    //     }
    //     else if (n == 4)
    //     {
    //         // inOrder(root);
    //     }
    //     else if (n == 5)
    //     {
    //         // preOrder(root);
    //     }
    //     else if (n == 6)
    //     {
    //         // postOrder(root);
    //     }
    // } while (n != 7);
    // cout << "Thank you for using me :) ";
    createRoot(100);
    addNodes(50);
    avl();
    addNodes(20);
    avl();
    addNodes(10);
    avl();
    addNodes(30);
    avl();
    addNodes(15);
    avl();
    addNodes(5);
    avl();
    addNodes(7);
    avl();
    cout << "Root: " << root->data << endl;
cout << "Level of 30 = " << nodeLvl(30) << endl;

}
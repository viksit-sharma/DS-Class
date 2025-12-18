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
BST* RR(BST *p)
{
    q = p->left;
    temp = q->right;

    q->right = p;
    p->left = temp;

    return q;  // new root of rotated subtree
}

BST* LR(BST *p)
{
    q = p->right;
    temp = q->left;

    q->left = p;
    p->right = temp;

    return q;  // new root
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
BST* balancing(BST *ptr, int left, int right)
{
    int bf = left - right;
    ptr->bf = bf;

    // Left heavy
    if (bf > 1)
    {
        // Left-Right case
        if (ptr->left->bf < 0)
            ptr->left = LR(ptr->left);

        return RR(ptr);
    }

    // Right heavy
    if (bf < -1)
    {
        // Right-Left case
        if (ptr->right->bf > 0)
            ptr->right = RR(ptr->right);

        return LR(ptr);
    }

    return ptr;  // no rotation needed
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
int AVL(BST *ptr, BST* &newRoot)
{
    if (ptr == NULL)
    {
        newRoot = NULL;
        return 0;
    }

    BST *lroot, *rroot;

    int leftHei = AVL(ptr->left, lroot);
    int rightHei = AVL(ptr->right, rroot);

    ptr->left = lroot;
    ptr->right = rroot;

    // balance this node
    BST *balanced = balancing(ptr, leftHei, rightHei);

    newRoot = balanced;

    return max(leftHei, rightHei) + 1;
}

// Wrapper
void applyAVL()
{
    BST* newRoot;
    AVL(root, newRoot);
    root = newRoot;
}
int main()
{
    init();
    int x;
    cout << "Enter first ROOT : ";
    cin >> x;
    createRoot(x);
    int n;
    do
    {
        cout << "Enter 1 for adding a node" << endl;
        cout << "Enter 2 for deleting a node" << endl;
        cout << "Enter 3 for finding level of a root" << endl;
        cout << "Enter 4 for in-order traversal" << endl;
        cout << "Enter 5 for pre-order traversal" << endl;
        cout << "Enter 6 for post-order traversal" << endl;
        cout << "Enter 7 to exit" << endl;
        cin >> n;
        if (n == 1)
        {
            cout << "Enter node data : ";
            cin >> x;
            addNodes(x);
            AVL(root);
        }
        else if (n == 2)
        {
            // deleteNode(x);
        }
        else if (n == 3)
        {
            cout << "Enter node to find its level : ";
            cin >> x;
            cout << "Level of " << x << " is : " << findLevel(x) << endl;
        }
        else if (n == 4)
        {
            // inOrder(root);
        }
        else if (n == 5)
        {
            // preOrder(root);
        }
        else if (n == 6)
        {
            // postOrder(root);
        }
    } while (n != 7);
    cout << "Thank you for using me :) ";
}
#include <iostream>
using namespace std;

struct BST
{
    int data;
    int bf;
    BST *left, *right, *child;
};

BST *root = NULL, *temp, *ttemp, *p, *q;

// --------------------- BASIC SETUP ---------------------
void init()
{
    root = temp = ttemp = NULL;
}

void createRoot(int x)
{
    root = new BST;
    root->data = x;
    root->left = root->right = root->child = NULL;
}

// --------------------- INSERTION ---------------------
void addNodes(int x)
{
    temp = root;
    ttemp = NULL;

    while (temp != NULL)
    {
        ttemp = temp;
        if (x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    p = new BST;
    p->data = x;
    p->left = p->right = p->child = NULL;

    if (x < ttemp->data)
        ttemp->left = p;
    else
        ttemp->right = p;
}

// --------------------- ROTATIONS ---------------------

BST *RR(BST *p)
{
    q = p->left;
    temp = q->right;

    q->right = p;
    p->left = temp;

    return q; // new root of rotated subtree
}

BST *LR(BST *p)
{
    q = p->right;
    temp = q->left;

    q->left = p;
    p->right = temp;

    return q; // new root
}

// --------------------- BALANCING ---------------------

BST *balancing(BST *ptr, int left, int right)
{
    int bf = left - right;
    ptr->bf = bf;

    // Left heavy
    if (bf > 1)
    {
        // Left-Right case
        if (ptr->left!=NULL && ptr->left->bf < 0)
            ptr->left = LR(ptr->left);

        return RR(ptr);
    }

    // Right heavy
    if (bf < -1)
    {
        // Right-Left case
        if (ptr->right!=NULL && ptr->right->bf > 0)
            ptr->right = RR(ptr->right);

        return LR(ptr);
    }

    return ptr; // if value of bf is {-1,0,1} then ptr that came as parameter will be returned
}

// --------------------- AVL HEIGHT + BALANCE ---------------------

int AVL(BST *ptr, BST *&newRoot)
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
    BST *newRoot;
    AVL(root, newRoot);
    root = newRoot;
}

// --------------------- DELETE NODE ---------------------

void deleteNode(int x)
{
    temp = root;
    ttemp = NULL;

    while (temp != NULL && temp->data != x)
    {
        ttemp = temp;
        if (x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (!temp)
        return; // not found

    // Case 1: Leaf
    if (temp->left == NULL && temp->right == NULL)
    {
        if (ttemp->left == temp)
            ttemp->left = NULL;
        else
            ttemp->right = NULL;
        delete temp;
        return;
    }

    // Case 2: One child
    if (temp->left == NULL || temp->right == NULL)
    {
        BST *child = (temp->left) ? temp->left : temp->right;

        if (ttemp->left == temp)
            ttemp->left = child;
        else
            ttemp->right = child;

        delete temp;
        return;
    }

    // Case 3: Two children -> Replace with inorder successor
    BST *succParent = temp;
    BST *succ = temp->right;

    while (succ->left != NULL)
    {
        succParent = succ;
        succ = succ->left;
    }

    temp->data = succ->data;

    // Delete successor
    if (succParent->left == succ)
        succParent->left = succ->right;
    else
        succParent->right = succ->right;

    delete succ;
}

// --------------------- TRAVERSALS ---------------------
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

// --------------------- FIND LEVEL ---------------------
int findLevel(int x)
{
    int lvl = 0;
    temp = root;

    while (temp != NULL)
    {
        if (temp->data == x)
            return lvl;

        lvl++;
        if (x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    return -1;
}

// --------------------- MAIN ---------------------
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
        cout << "Enter 1 for adding a node\n";
        cout << "Enter 2 for deleting a node\n";
        cout << "Enter 3 for finding level\n";
        cout << "Enter 4 for in-order traversal\n";
        cout << "Enter 5 for pre-order traversal\n";
        cout << "Enter 6 for post-order traversal\n";
        cout << "Enter 7 to exit\n";

        cin >> n;

        if (n == 1)
        {
            cout << "Enter node data : ";
            cin >> x;
            addNodes(x);
            applyAVL();
        }
        else if (n == 2)
        {
            cout << "Enter node to delete : ";
            cin >> x;
            deleteNode(x);
            applyAVL();
        }
        else if (n == 3)
        {
            cout << "Enter node to find level : ";
            cin >> x;
            cout << "Level = " << findLevel(x) << endl;
        }
        else if (n == 4)
            inOrder(root);
        else if (n == 5)
            preOrder(root);
        else if (n == 6)
            postOrder(root);

        cout << "\n";

    } while (n != 7);

    return 0;
}

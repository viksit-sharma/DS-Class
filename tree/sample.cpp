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
    root->bf = 0;                 // initialize bf
}
void addNodes(int x)
{
    // handle empty tree safely
    if (root == NULL)
    {
        createRoot(x);
        return;
    }

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
    p->bf = 0;                    // initialize bf for new node
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
        // ensure ptr->left is not NULL before accessing its bf
        if (ptr->left != NULL && ptr->left->bf < 0)
        {
            ptr->left = LR(ptr->left);
        }
        return RR(ptr);
    }
    else if (balancingFactor < -1)
    {
        // ensure ptr->right is not NULL before accessing its bf
        if (ptr->right != NULL && ptr->right->bf > 0)
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
        // FIXED: correct traversal direction
        if (x < temp->data)
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

// helper: inorder print for debugging
void inOrderPrint(BST *node)
{
    if (!node) return;
    inOrderPrint(node->left);
    cout << node->data << " (bf=" << node->bf << ") ";
    inOrderPrint(node->right);
}

int main()
{
    init();

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

    // debug print to verify tree exists and bf values:
    cout << "In-order traversal: ";
    inOrderPrint(root);
    cout << endl;

    cout << "Level of 30 is: " << nodeLvl(30) << endl;
    cout << "Level of 50 is: " << nodeLvl(50) << endl;
    cout << "Level of 100 is: " << nodeLvl(100) << endl;

    return 0;
}

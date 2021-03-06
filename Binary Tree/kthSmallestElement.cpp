// To obtain the LeftMost and RightMost Element in a Binary Tree.
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Tree;

Tree *CreateBinaryTree()
{
    Tree *temp = new Tree();
    int data;
    cout << "Enter Data : ";
    cin >> data;
    if (data == -1)
        return NULL;
    temp->data = data;
    cout << "For Left Child of " << temp->data;
    temp->left = CreateBinaryTree();
    cout << "For Right Child of " << temp->data;
    temp->right = CreateBinaryTree();
    return temp;
}
void DisplayInorder(Tree *root)
{
    if (root)
    {
        DisplayInorder(root->left);
        cout << root->data << " ";
        DisplayInorder(root->right);
    }
    else
        return;
}
int countNodes(Tree *root)
{
    static int count = 0;
    if (root)
    {
        count++;
        countNodes(root->left);
        countNodes(root->right);
    }
    return count;
}
void Utility(Tree *root, int k, int &c)
{
    if (!root || c <= (countNodes(root) - k))
        return;
    Utility(root->right, k, c);
    c++;
    if (c == (countNodes(root) - k))
    {
        cout << "Element is : " << root->data << endl;
        return;
    }
    Utility(root->left, k, c);
}
void kthSmallestElement(Tree *root, int k)
{
    int count = 1;
    Utility(root, k, count);
}
int main()
{
    int k;
    Tree *root = CreateBinaryTree();
    cout << "Binary tree Created!\n";
    cout << "Inorder Traversal : ";
    DisplayInorder(root);
    cout << "\nEnter the K's values : ";
    cin >> k;
    kthSmallestElement(root, k);
    free(root);
    return 0;
}
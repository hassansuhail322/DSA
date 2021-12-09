#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode *insert(TreeNode *root, int x)
{
    TreeNode *p = NULL;
    TreeNode *temp = root;
    if (root == NULL)
    {
        root = new TreeNode(x);
        return root;
    }

    while (temp != NULL)
    {
        p = temp;
        if (x > temp->data)
            temp = temp->right;
        else
            temp = temp->left;
    }

    if (x > p->data)
        p->right = new TreeNode(x);
    else
        p->left = new TreeNode(x);

    return root;
}

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}
int count (TreeNode*root)
{
    if(root == NULL)
    return 0;

    int ans = count(root ->left) + count (root->right) +1;
    return ans;
}
int main()
{
    TreeNode *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 9);
    root = insert(root, 2);
    inorder(root);
    cout<<endl;


    cout<<count(root);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int data;
   TreeNode *left;
   TreeNode *right;

   TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

int diameter = 0;

int height(TreeNode *root)
{
   if (root == NULL)
      return 0;
   return 1 + max(height(root->left), height(root->right));
}

void getDiameter(TreeNode *root)
{
   if (root == NULL)
      return;

   int l = height(root->left);  // height of left subtree
   int r = height(root->right); // height of right subtree

   diameter = max(diameter, l + r);

   getDiameter(root->left);
   getDiameter(root->right);
}

int main()
{

   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(5);
   root->left->right->right = new TreeNode(6);
   root->left->right->right->right = new TreeNode(7);

   // Calculate the diameter of the binary tree
   getDiameter(root);
   cout << "The diameter of the binary tree is: " << diameter << endl;

   // If you also want tree height (nodes):
   int h = height(root);
   cout << "Height (nodes): " << h << endl;
   return 0;
}

// // global variable
// int diameter = 0;

// // function to calculate height of a subtree
// int getHeight(TreeNode *root)
// {
//    if (root == NULL)
//       return 0;

//    int l = getHeight(root->left);
//    int r = getHeight(root->right);

//    // calculate diameter at current node
//    diameter = max(diameter, l + r);

//    return 1 + max(l, r);
// }

// // function to find diameter of tree
// int getDiameter(TreeNode *root)
// {
//    getHeight(root); // start the recursive traversal from the root
//    return diameter; // return the maximum diameter found
// }
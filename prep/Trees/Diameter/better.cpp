#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int data;
   TreeNode *left;
   TreeNode *right;

   TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

int getDiameter(TreeNode *root, int &diameter)
{
   if (root == NULL)
      return 0;

   int l = getDiameter(root->left, diameter);  // height of left subtree
   int r = getDiameter(root->right, diameter); // height of right subtree

   diameter = max(diameter, l + r);

   return 1 + max(l, r);
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
   int diameter = 0;
   cout << "The diameter of the binary tree is: " << getDiameter(root, diameter);
   cout << endl;

   return 0;
}

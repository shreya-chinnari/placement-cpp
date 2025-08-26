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

// function to calculate height of a subtree and update diameter
int getHeight(TreeNode *root)
{
   if (root == NULL)
      return 0;

   int l = getHeight(root->left);  // height of left subtree
   int r = getHeight(root->right); // height of right subtree

   // update diameter at this node
   diameter = max(diameter, l + r);

   return 1 + max(l, r);
}

// function to return final diameter
int getDiameter(TreeNode *root)
{
   getHeight(root); // start recursion
   return diameter; // return max diameter found
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

   cout << "The diameter of the binary tree is: "
        << getDiameter(root) << endl;

   return 0;
}

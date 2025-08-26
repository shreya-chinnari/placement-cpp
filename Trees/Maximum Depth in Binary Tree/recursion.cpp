#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int data;

   TreeNode *left;
   TreeNode *right;
   TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int maxHeight_Recursive(TreeNode *root)
{
   if (root == NULL)
      return 0;

   int l = maxHeight_Recursive(root->left);
   int r = maxHeight_Recursive(root->right);

   return 1 + max(l, r);
}

int main()
{
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(5);

   cout << "Maximum Height (Recursive): " << maxHeight_Recursive(root) << endl;

   return 0;
}
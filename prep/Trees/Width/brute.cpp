#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int data;
   TreeNode *left, *right;
   TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

// Count nodes at a given level
int countLevel(TreeNode *root, int level)
{
   if (!root)
      return 0;
   if (level == 1)
      return 1; // current node
   return countLevel(root->left, level - 1) + countLevel(root->right, level - 1);
}

// Height of tree
int height(TreeNode *root)
{
   if (!root)
      return 0;
   return 1 + max(height(root->left), height(root->right));
}

// Width = max nodes at any level
int getMaxWidth(TreeNode *root)
{
   int h = height(root);
   int maxWidth = 0;
   for (int i = 1; i <= h; i++)
   {
      int w = countLevel(root, i);
      maxWidth = max(maxWidth, w);
   }
   return maxWidth;
}

int main()
{
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(5);
   root->right->right = new TreeNode(6);

   cout << "Max Width: " << getMaxWidth(root) << endl;
}

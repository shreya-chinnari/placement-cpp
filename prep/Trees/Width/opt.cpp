#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int data;
   TreeNode *left, *right;
   TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

int getMaxWidth(TreeNode *root)
{
   if (!root)
      return 0;

   queue<TreeNode *> q;
   q.push(root);
   int maxWidth = 0;

   while (!q.empty())
   {
      int count = q.size(); // number of nodes in this level
      maxWidth = max(maxWidth, count);

      for (int i = 0; i < count; i++)
      {
         TreeNode *node = q.front();
         q.pop();
         if (node->left)
            q.push(node->left);
         if (node->right)
            q.push(node->right);
      }
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

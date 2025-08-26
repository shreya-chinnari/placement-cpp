#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int data;

   TreeNode *left;
   TreeNode *right;
   TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void maxHeight_LevelOrder(TreeNode *root)
{

   if (root == NULL)
      return 0;

   queue<TreeNode *> q;
   q.push(root);
   int height = 0;

   while (!q.empty())
   {
      int levelSize = q.size(); // number of nodes in current level

      // process all nodes of this level
      for (int i = 0; i < levelSize; i++)
      {
         TreeNode *node = q.front();
         q.pop();

         if (node->left != NULL)
         {
            q.push(node->left);
         }
         if (node->right != NULL)
         {
            q.push(node->right);
         }
      }
      height++; // one level completed
   }
   return height;
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
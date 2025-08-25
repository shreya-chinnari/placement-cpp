#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int data;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> bfsLevelOrderTraversal(TreeNode *root)
{
   if (root == NULL)
      return ans; // empty, no traversal happened

   vector<vector<int>> ans;

   queue<TreeNode *> q;
   q.push(root);
   while (!q.empty())
   {
      vector<int> level;
      int size = q.size(); // number of nodes in this level

      for (int i = 0; i < size; i++)
      {
         TreeNode *node = q.front();
         q.pop();
         if (node->left != NULL)
            q.push(node->left);
         if (node->right != NULL)
            q.push(node->right);
         level.push_back(node->data);
      }
      ans.push_back(level);
   }
   return ans;
}

int main()
{
   // Construct the tree
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->right->left = new TreeNode(5);
   root->right->right = new TreeNode(6);

   // Perform BFS traversal
   vector<vector<int>> levels = bfsLevelOrderTraversal(root);

   // Print levels
   for (int i = 0; i < levels.size(); i++)
   {
      cout << "Level " << i << ": ";
      for (int val : levels[i])
      {
         cout << val << " ";
      }
      cout << endl;
   }

   return 0;
}

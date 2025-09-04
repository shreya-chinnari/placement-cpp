#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int data;

   TreeNode *left;
   TreeNode *right;
   TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// LEFT -> ROOT -> RIGHT
// 2 stack

vector<int> postorderTraversal(TreeNode *root)
{
   vector<int> result;
   if (root == nullptr)
      return result;

   stack<TreeNode *> s1, s2;

   s1.push(root);

   while (!s1.empty())
   {
      root = s1.top();
      s1.pop();
      s2.push(root);

      if (root->left != nullptr)
      {
         s1.push(root->left);
      }
      if (root->right != nullptr)
      {
         s1.push(root->right);
      }
   }

   while (!s2.empty())
   {
      result.push_back(s2.top()->data);
      s2.pop();
   }
   return result;
}

int main()
{
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(5);

   vector<int> postorder = postorderTraversal(root);
   for (int val : postorder)
   {
      cout << val << " ";
   }
   return 0;
}
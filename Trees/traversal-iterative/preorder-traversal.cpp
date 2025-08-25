#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree TreeNode
struct TreeNode
{
   int data;
   struct TreeNode *left;
   struct TreeNode *right;

   TreeNode(int val)
   {
      data = val;
      left = right = NULL;
   }
};

// ROOT -> LEFT -> RIGHT

vector<int> preorderTraversal(TreeNode *root)
{
   vector<int> result;

   if (root == nullptr)
      return result;

   stack<TreeNode *> st;
   st.push(root);
   // stop when all nodes are pooped out of stack
   while (!st.empty())
   {
      root = st.top();
      st.pop();
      result.push_back(root->data);
      if (root->right != nullptr)
         st.push(root->right);
      if (root->left != nullptr)
         st.push(root->left);
   }
   return result;
}

// Example usage
int main()
{

   TreeNode *root = new TreeNode(1);
   root->right = new TreeNode(3);
   root->left = new TreeNode(2);
   root->right->left = new TreeNode(4);
   root->right->right = new TreeNode(5);

   vector<int> preorder = preorderTraversal(root);

   cout << "Preorder Traversal: ";
   for (int val : preorder)
      cout << val << " ";
   cout << endl;

   return 0;
}

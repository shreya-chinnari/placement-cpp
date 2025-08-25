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

vector<int> inorderTraversal(TreeNode *root)
{
   stack<TreeNode *> st;
   TreeNode *node = root;
   // node -> current node (initially root)
   vector<int> result;
   while (true)
   {
      if (node != NULL)
      {
         st.push(node);
         node = node->left;
      }
      else // node==NULL
      {
         if (st.empty() == true)
            break;
         node = st.top();
         st.pop();
         result.push_back(node->data);
         node = node->right;
      }
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

   vector<int> inorder = inorderTraversal(root);
   for (int val : inorder)
   {
      cout << val << " ";
   }
   return 0;
}
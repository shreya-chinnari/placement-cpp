#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int val;

   TreeNode *left;
   TreeNode *right;
   TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

// LEFT -> ROOT -> RIGHT

void inorderHelper(TreeNode *root, vector<int> &arr)
{
   if (root == nullptr)
      return;

   inorderHelper(root->left, arr);
   arr.push_back(root->val);
   inorderHelper(root->right, arr);
}

vector<int> inorderTraversal(TreeNode *root)
{
   vector<int> arr;
   inorderHelper(root, arr);
   return arr;
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
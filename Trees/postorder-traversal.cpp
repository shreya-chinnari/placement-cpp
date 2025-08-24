#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int data;

   TreeNode *left;
   TreeNode *right;
   TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// LEFT -> RIGHT -> ROOT

void postorderHelper(TreeNode *root, vector<int> &arr)
{
   if (root == nullptr)
      return;
   postorderHelper(root->left, arr);
   postorderHelper(root->right, arr);
   arr.push_back(root->data);
}
vector<int> postorderTraversal(TreeNode *root)
{
   vector<int> arr;
   postorderHelper(root, arr);
   return arr;
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
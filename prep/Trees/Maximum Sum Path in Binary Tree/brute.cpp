#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// Node structure for the binary tree
struct TreeNode
{
   int data;
   TreeNode *left;
   TreeNode *right;
   // Constructor to initialize
   // the node with a value
   TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int maxRootToLeafSum(TreeNode *root)
{
   if (root == NULL)
      return INT_MIN; // invalid path

   if (root->left == NULL && root->right == NULL)
      return root->data; // leaf node

   int lSum = maxRootToLeafSum(root->left);
   int rSum = maxRootToLeafSum(root->right);

   return root->data + max(lSum, rSum);
}
int maxPathSum(TreeNode *root)
{
   if (root == NULL)
      return INT_MIN;

   // 1. calculate max path passing through this node
   int lSum = maxRootToLeafSum(root->left);
   int rSum = maxRootToLeafSum(root->right);

   int pathThroughNode = root->data;
   if (lSum != INT_MIN)
      pathThroughNode += lSum;
   if (rSum != INT_MIN)
      pathThroughNode += rSum;

   // 2. recursively calculate max path sums for left and right subtrees
   int leftMax = maxPathSum(root->left);
   int rightMax = maxPathSum(root->right);

   return max({pathThroughNode, leftMax, rightMax});
}

int main()
{
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(5);
   root->left->right->right = new TreeNode(6);
   root->left->right->right->right = new TreeNode(7);

   int total = maxPathSum(root);
   cout << "Maximum Path Sum: " << total << endl;

   return 0;
}

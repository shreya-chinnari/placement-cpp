#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
   int data;
   TreeNode *left;
   TreeNode *right;

   TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
   int checkHeight(TreeNode *root)
   {
      if (root == NULL)
         return 0;

      int l = checkHeight(root->left);
      if (l == -1)
         return -1; // unbalanced
      int r = checkHeight(root->right);
      if (r == -1)
         return -1; // unbalanced

      if (abs(l - r) > 1)
         return -1; // unbalanced

      // balanced
      return max(l, r) + 1;
   }

   bool isBalanced(TreeNode *root)
   {
      // true - balanced, false - unbalanced
      return checkHeight(root) != -1;
   }
};

int main()
{

   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(5);
   root->left->right->right = new TreeNode(6);
   root->left->right->right->right = new TreeNode(7);

   Solution solution;

   if (solution.isBalanced(root))
   {
      cout << "The tree is balanced." << endl;
   }
   else
   {
      cout << "The tree is not balanced." << endl;
   }

   return 0;
}
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
   int getHeight(TreeNode *root)
   {
      if (root == NULL)
         return 0; // If the tree is empty, it's balanced

      int l = getHeight(root->left);
      int r = getHeight(root->right);
      return 1 + max(l, r);
   }

   // Calculate the height of left and right subtrees
   bool isBalanced(TreeNode *root)
   {
      if (root == NULL)
         return true;

      int l = getHeight(root->left);
      int r = getHeight(root->right);

      // absolute difference in heights of left and right subtrees <= 1 + LEFT AND RIGHT subtrees are balanced
      if (abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right))
      {
         return true;
      }
      return false;
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
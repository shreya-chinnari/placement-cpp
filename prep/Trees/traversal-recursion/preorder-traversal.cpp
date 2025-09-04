#include <iostream>
#include <vector>
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

void preOrderHelper(TreeNode *root, vector<int> &result)
{
   if (root == nullptr)
      return; // Base case: empty TreeNode

   // Step 1: Visit root
   result.push_back(root->data);
   // Step 2: Recurse on left subtree
   preOrderHelper(root->left, result);
   // Step 3: Recurse on right subtree
   preOrderHelper(root->right, result);
}

// Wrapper function
vector<int> preorderTraversal(TreeNode *root)
{
   vector<int> result;
   preOrderHelper(root, result);
   return result;
}

// Example usage
int main()
{
   /*
         1
          \
           2
          /
         3
   */
   TreeNode *root = new TreeNode(1);
   root->right = new TreeNode(2);
   root->right->left = new TreeNode(3);

   vector<int> preorder = preorderTraversal(root);

   cout << "Preorder Traversal: ";
   for (int val : preorder)
      cout << val << " ";
   cout << endl;

   return 0;
}

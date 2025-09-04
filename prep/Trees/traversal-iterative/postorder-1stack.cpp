#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int data;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

// Iterative Postorder Traversal using 1 Stack
vector<int> postorderTraversal(TreeNode *root)
{
   vector<int> result;
   if (root == NULL)
      return result;

   stack<TreeNode *> st;
   TreeNode *curr = root;

   // loop continues while there are nodes to visit
   while (curr != NULL || !st.empty())
   {
      // Step 1: Keep going left
      // Push current node onto stack (we'll come back later)
      if (curr != NULL)
      {
         st.push(curr);
         curr = curr->left;
      }
      // Step 2: If left side is done, check right subtree
      else
      {
         TreeNode *temp = st.top()->right;
         // Case A: No right child exists → process the node itself
         if (temp == NULL)
         {
            temp = st.top();
            st.pop();
            result.push_back(temp->data); // add to postorder (left, right, root)

            // Case A.1: Keep popping while the last popped node
            // was the right child of stack top → meaning parent’s right is done
            while (!st.empty() && temp == st.top()->right)
            {
               temp = st.top();
               st.pop();
               result.push_back(temp->data);
            }
         }
         // Case B: If right child exists → move to right subtree
         else if (temp != NULL)
         {
            curr = temp; // move to right subtree
         }
      }
   }
   return result;
}

int main()
{
   /*
        1
       / \
      2   7
     /     \
    3       8
     \
      4
       \
        5
         \
          6

   */

   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->left->left = new TreeNode(3);
   root->left->left->right = new TreeNode(4);
   root->left->left->right->right = new TreeNode(5);
   root->left->left->right->right->right = new TreeNode(6);

   root->right = new TreeNode(7);
   root->right->right = new TreeNode(8);

   vector<int> postorder = postorderTraversal(root);

   cout << "Postorder Traversal: ";
   for (int val : postorder)
   {
      cout << val << " ";
   }
   cout << endl;

   return 0;
}

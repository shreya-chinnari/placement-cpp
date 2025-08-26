#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int data;

   TreeNode *left;
   TreeNode *right;
   TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> PreInPro1traversal(TreeNode *root)
{
   stack<pair<TreeNode *, int>> st; // <node, occurr>
   st.push({root, 1});

   vector<int> pre, in, post;

   if (root == NULL)
      return {};

   while (!st.empty())
   {
      auto it = st.top();
      st.pop();

      if (it.second == 1) // PREorder
      {
         pre.push_back(it.first->data);
         it.second++;
         st.push(it);

         if (it.first->left != NULL)
         {
            st.push({it.first->left, 1});
         }
      }
      else if (it.second == 2) // INorder
      {
         in.push_back(it.first->data);
         it.second++;
         st.push(it);

         if (it.first->right != NULL)
         {
            st.push({it.first->right, 1});
         }
      }
      else if (it.second == 3) // POSTorder
      {
         post.push_back(it.first->data);
      }
   }

   return {pre, in, post};
}

int main()
{
   // Constructing tree:
   //        1
   //      /   \
    //     2     5
   //    / \   / \
    //   3   4 6   7

   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(5);

   root->left->left = new TreeNode(3);
   root->left->right = new TreeNode(4);

   root->right->left = new TreeNode(6);
   root->right->right = new TreeNode(7);

   vector<vector<int>> result = PreInPro1traversal(root);

   cout << "Preorder: ";
   for (int x : result[0])
      cout << x << " ";
   cout << endl;

   cout << "Inorder: ";
   for (int x : result[1])
      cout << x << " ";
   cout << endl;

   cout << "Postorder: ";
   for (int x : result[2])
      cout << x << " ";
   cout << endl;

   return 0;
}
// Function to check
   // if a node is a leaf
   bool isLeaf(Node *root)
   {
      return !root->left && !root->right;
   }

   // Function to add the
   // left boundary of the tree
   void addLeftBoundary(Node *root, vector<int> &res)
   {
      Node *curr = root->left;
      while (curr)
      {
         // If the current node is not a leaf,
         // add its value to the result
         if (!isLeaf(curr))
         {
            res.push_back(curr->data);
         }
         // Move to the left child if it exists,
         // otherwise move to the right child
         if (curr->left)
         {
            curr = curr->left;
         }
         else
         {
            curr = curr->right;
         }
      }
   }

   // Function to add the
   // right boundary of the tree
   void addRightBoundary(Node *root, vector<int> &res)
   {
      Node *curr = root->right;
      vector<int> temp;
      while (curr)
      {
         // If the current node is not a leaf,
         // add its value to a temporary vector
         if (!isLeaf(curr))
         {
            temp.push_back(curr->data);
         }
         // Move to the right child if it exists,
         // otherwise move to the left child
         if (curr->right)
         {
            curr = curr->right;
         }
         else
         {
            curr = curr->left;
         }
      }
      // Reverse and add the values from
      // the temporary vector to the result
      for (int i = temp.size() - 1; i >= 0; --i)
      {
         res.push_back(temp[i]);
      }
   }

   // Function to add the
   // leaves of the tree
   void addLeaves(Node *root, vector<int> &res)
   {
      // If the current node is a
      // leaf, add its value to the result
      if (isLeaf(root))
      {
         res.push_back(root->data);
         return;
      }
      // Recursively add leaves of
      // the left and right subtrees
      if (root->left)
      {
         addLeaves(root->left, res);
      }
      if (root->right)
      {
         addLeaves(root->right, res);
      }
   }

   // Main function to perform the
   // boundary traversal of the binary tree
   vector<int> printBoundary(Node *root)
   {
      vector<int> res;
      if (!root)
      {
         return res;
      }
      // If the root is not a leaf,
      // add its value to the result
      if (!isLeaf(root))
      {
         res.push_back(root->data);
      }

      // Add the left boundary, leaves,
      // and right boundary in order
      addLeftBoundary(root, res);
      addLeaves(root, res);
      addRightBoundary(root, res);

      return res;
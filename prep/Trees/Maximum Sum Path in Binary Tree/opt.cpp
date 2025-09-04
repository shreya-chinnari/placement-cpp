#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// Node structure for the binary tree
struct Node
{
   int data;
   Node *left;
   Node *right;
   // Constructor to initialize
   // the node with a value
   Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int maxPathSum()
{
}

int main()
{
   Node *root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->left->right = new Node(5);
   root->left->right->right = new Node(6);
   root->left->right->right->right = new Node(7);

   int maxPathSum = maxPathSum(root);
   cout << "Maximum Path Sum: " << maxPathSum << endl;

   return 0;
}

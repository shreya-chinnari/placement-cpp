// initialise a node of a linked list

#include <iostream>
#include <vector>
using namespace std;

// struct Node
class Node
{
public:
   int data;
   Node *next;

public:
   Node(int data1, Node *next1)
   {
      data = data1;
      next = next1;
   };
};

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5};
   Node *node1 = new Node(arr[0], nullptr);
   cout << node1 << endl;
   cout << node1->data << endl;
   cout << node1->next << endl;
   return 0;
}

/*
0x1c223f69a50
1
0
*/
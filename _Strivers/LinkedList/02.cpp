// array to LL

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
   // Node(int data1, Node *next1)
   Node(int data1)
   {
      data = data1;
      // next = next1;
      next = nullptr;
   };
};

// function to convert array to LL
// converARRtoLL(vector<int> &arr){ - but we can not return the entire LL
Node *convertARRtoLL(vector<int> &arr) // we can return the HEAD of the LL
{
   Node *head = new Node(arr[0]); // head → [1 | nullptr]
   Node *mover = head;            // mover points to head

   for (int i = 1; i < arr.size(); i++)
   {
      Node *newNode = new Node(arr[i]); // Create a new node on the heap { next node }
      mover->next = newNode;            // Link current node to new
      // mover = newNode;
      mover = mover->next; // Move to the new node
   }
   return head;
};

int main()
{
   vector<int> arr = {6, 3, 9, 5, 0};
   Node *head = convertARRtoLL(arr);
   cout << head->data;
   return 0;
}

/*
Node* head = new Node(1);  // head → [1 | nullptr]
Node* mover = head;        // mover points to head

    i = 1
Node* newNode = new Node(2);      // [2 | nullptr]
mover->next = newNode;            // head → [1 | *] → [2 | nullptr]
mover = mover->next;              // mover now at node with value 2

    i = 2
Node* newNode = new Node(3);      // [3 | nullptr]
mover->next = newNode;            // head → [1 | *] → [2 | *] → [3 | nullptr]
mover = mover->next;              // mover now at node with value 3

------------------
head
 ↓
[1 | *] → [2 | *] → [3 | nullptr]

   Each [val | next] is a Node.
   * means pointer to next node.
   The last node (3) points to nullptr, marking the end of the list.
------------------







Node* convertARRtoLL(vector<int>& arr)
{
   Node* head = new Node(arr[0]);       // Step 1: Create the head node
   Node* mover = head;                  // Step 2: A pointer to traverse and build the list

   for (int i = 1; i < arr.size(); i++) // Step 3: Loop through the rest of the array
   {
      Node* temp = new Node(arr[i]);   // Create a new node for each value
      mover->next = temp;              // Link current node to the new node
      mover = mover->next;             // Move to the new node
   }

   return head;                        // Return the head of the linked list
}

*/
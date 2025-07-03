#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
   Node *prev; // renamed 'back' to 'prev' for clarity

   Node(int value, Node *nextNode, Node *prevNode)
   {
      data = value;
      next = nextNode;
      prev = prevNode;
   }

   Node(int value)
   {
      data = value;
      next = nullptr;
      prev = nullptr;
   }
};

// Converts array to Doubly Linked List
Node *convertArrayToDLL(vector<int> &arr)
{
   Node *head = new Node(arr[0]);
   Node *lastNode = head;

   for (int i = 1; i < arr.size(); i++)
   {
      Node *newNode = new Node(arr[i], nullptr, lastNode);
      lastNode->next = newNode;
      lastNode = newNode;
   }
   return head;
}

// Prints the DLL
void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << "  ";
      head = head->next;
   }
   cout << endl;
}

// Deletes the k-th node (1-based index)
Node *removeKthNode(Node *head, int k)
{
   if (head == NULL)
      return NULL;

   // Case 1: delete head
   if (k == 1)
   {
      if (head->next == NULL)
         return NULL;

      Node *toDelete = head;
      head = head->next;
      head->prev = NULL;
      toDelete->next = NULL;
      delete toDelete;
      return head;
   }

   Node *current = head;
   int position = 1;

   while (current != NULL && position < k)
   {
      current = current->next;
      position++;
   }

   if (current == NULL)
      return head;

   // Case 2: delete tail
   if (current->next == NULL)
   {
      Node *previous = current->prev;
      previous->next = NULL;
      current->prev = NULL;
      delete current;
      return head;
   }

   // Case 3: delete middle node
   Node *previous = current->prev;
   Node *nextNode = current->next;

   previous->next = nextNode;
   nextNode->prev = previous;
   current->next = NULL;
   current->prev = NULL;
   delete current;

   return head;
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5};
   Node *head = convertArrayToDLL(arr);
   printList(head);

   head = removeKthNode(head, 1); // delete head
   cout << "After deleting 1st node (head): ";
   printList(head);

   head = removeKthNode(head, 4); // delete tail
   cout << "After deleting 4th node (tail): ";
   printList(head);

   head = removeKthNode(head, 2); // delete middle
   cout << "After deleting 2nd node (middle): ";
   printList(head);

   return 0;
}

// head     → Points to the start of the doubly linked list.
// lastNode → Tracks the last created node while building the list.
// newNode  → Temporary node to create and link to the DLL during construction.
// current  → Traverses the list to reach the k-th node to be deleted.
// position → Keeps count of the current index while traversing.
// toDelete → Stores the head node when it needs to be deleted.
// previous → Node before the node to be deleted; used to reconnect during deletion.
// nextNode → Node after the node to be deleted; helps in relinking.

// integrating deleteHead and deleteTail inside main function
// it's less modular, less reusable, less maintainable
// it's just for underrstanding

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
   Node *back;

   Node(int data1, Node *next1, Node *back1)
   {
      data = data1;
      next = next1;
      back = back1;
   }

   Node(int data1)
   {
      data = data1;
      next = nullptr;
      back = nullptr;
   }
};

Node *convertArr_to_DLL(vector<int> &arr)
{
   Node *head = new Node(arr[0]);
   Node *prev = head;

   for (int i = 1; i < arr.size(); i++)
   {
      Node *temp = new Node(arr[i], nullptr, prev);
      prev->next = temp;
      prev = temp;
   }
   return head;
}

void print(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << "  ";
      head = head->next;
   }
   cout << endl;
}

// Delete k-th node (1-based index)
Node *removeKthElement(Node *head, int k)
{
   if (head == NULL)
      return NULL;

   // Case 1: delete head
   if (k == 1)
   {
      if (head->next == NULL)
         return NULL;

      Node *temp = head;
      head = head->next;
      head->back = NULL;
      temp->next = NULL;
      delete temp;
      return head;
   }

   Node *curr = head;
   int count = 1;

   while (curr != NULL && count < k)
   {
      curr = curr->next;
      count++;
   }

   // If k is out of bounds
   if (curr == NULL)
      return head;

   // Case 2: delete tail
   if (curr->next == NULL)
   {
      Node *prev = curr->back;
      prev->next = NULL;
      curr->back = NULL;
      delete curr;
      return head;
   }

   // Case 3: delete middle node
   Node *prev = curr->back;
   Node *next = curr->next;

   prev->next = next;
   next->back = prev;
   curr->next = NULL;
   curr->back = NULL;
   delete curr;

   return head;
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5};
   Node *head = convertArr_to_DLL(arr);
   print(head);

   head = removeKthElement(head, 1); // delete head
   cout << "After deleting 1st node (head): ";
   print(head);

   head = removeKthElement(head, 4); // delete tail (after 1st deletion, tail is at index 4)
   cout << "After deleting 4th node (tail): ";
   print(head);

   head = removeKthElement(head, 2); // delete middle
   cout << "After deleting 2nd node (middle): ";
   print(head);

   return 0;
}

/*
Pointer: head
What it refers to: First node of the list
Context / Role: Entry point of the list; updated if first node is deleted

Pointer: tail
What it refers to: Last node of the list (if used)
Context / Role: Usually used while traversing to the end; not in your current code

Pointer: next
What it refers to: Pointer to the next node
Context / Role: Moves forward in the doubly linked list (DLL)

Pointer: back
What it refers to: Pointer to the previous node
Context / Role: Moves backward in the DLL

Pointer: prev
What it refers to: Temporary pointer to store previous node (used in delete)
Context / Role: Helps disconnect or reconnect nodes while deleting

Pointer: curr
What it refers to: Pointer to the current node being processed
Context / Role: Traverses to the k-th node for deletion

Pointer: temp
What it refers to: Temporary pointer (usually old head or new node)
Context / Role: Used to store node being deleted or manipulated
*/
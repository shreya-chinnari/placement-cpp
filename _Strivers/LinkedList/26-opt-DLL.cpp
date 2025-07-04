// Reverse a SLL#include <iostream>

#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
   Node *back; // for doubly linked list

   Node(int val)
   {
      data = val;
      next = nullptr;
      back = nullptr;
   }
};

// Convert array to DLL
Node *convertArr2DLL(int arr[], int n)
{
   if (n == 0)
      return nullptr;

   Node *head = new Node(arr[0]);
   Node *current = head;

   for (int i = 1; i < n; ++i)
   {
      Node *newNode = new Node(arr[i]);
      current->next = newNode;
      newNode->back = current; // set back pointer
      current = newNode;
   }
   return head;
}

// Print DLL
void printList(Node *head)
{
   while (head != nullptr)
   {
      cout << head->data;
      if (head->next)
         cout << " <-> ";
      head = head->next;
   }
   cout << endl;
}

// Reverse DLL using 3-pointer approach
Node *reverseLL(Node *head)
{
   if (!head || !head->next)
      return head;

   Node *temp = head;
   Node *prev = nullptr;
   Node *front = nullptr;

   while (temp != NULL)
   {
      front = temp->next;

      // swap next and back
      temp->next = prev;
      temp->back = front;

      // move ahead
      prev = temp;
      temp = front;
   }

   return prev; // prev becomes the new head
}

// Driver code
int main()
{
   int arr[] = {1, 2, 3, 4, 5};
   int n = sizeof(arr) / sizeof(arr[0]);

   Node *head = convertArr2DLL(arr, n);
   cout << "Original DLL: ";
   printList(head);

   head = reverseLL(head);
   cout << "Reversed DLL: ";
   printList(head);

   return 0;
}

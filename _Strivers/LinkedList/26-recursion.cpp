#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
   Node *back; // Only used in DLL

   Node(int val)
   {
      data = val;
      next = nullptr;
      back = nullptr;
   }
};

// Convert array to Singly Linked List
Node *convertArr2SLL(int arr[], int n)
{
   if (n == 0)
      return nullptr;

   Node *head = new Node(arr[0]);
   Node *current = head;

   for (int i = 1; i < n; ++i)
   {
      current->next = new Node(arr[i]);
      current = current->next;
   }
   return head;
}

// Convert array to Doubly Linked List
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
      newNode->back = current;
      current = newNode;
   }
   return head;
}

// Print SLL
void printSLL(Node *head)
{
   while (head != nullptr)
   {
      cout << head->data;
      if (head->next)
         cout << " -> ";
      head = head->next;
   }
   cout << endl;
}

// Print DLL
void printDLL(Node *head)
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

// Reverse SLL using Recursion

Node *reverseSLLRecursion(Node *head)
{
   // for 1-element LL
   if (head == NULL || head->next == NULL)
      return head;

   Node *newHead = reverseSLLRecursion(head->next); // head of the reversed
   Node *front = head->next;
   front->next = head;
   head->next = nullptr;

   return newHead;
}
/*
   head->next->next = head;
   head->next = nullptr;
*/

// Reverse DLL using Recursion
Node *reverseDLLRecursion(Node *head)
{
   // for 1-element LL
   if (head == NULL || head->next == NULL)
      return head;

   Node *newHead = reverseDLLRecursion(head->next); // head of the reversed
   Node *front = head->next;
   front->next = head;   // reverse forward link
   head->back = front;   // reverse back link
   head->next = nullptr; // head is now tail, so its next should be NULL

   return newHead;
}
/*
   head->next->next = head;
   head->back = head->next;
   head->next = NULL;
*/

// Driver code
int main()
{
   int arr[] = {1, 2, 3, 4, 5};
   int n = sizeof(arr) / sizeof(arr[0]);

   cout << "Singly Linked List: ";
   Node *sllHead = convertArr2SLL(arr, n);
   printSLL(sllHead);

   sllHead = reverseSLLRecursion(sllHead);
   printSLL(sllHead);

   cout << "Doubly Linked List: ";
   Node *dllHead = convertArr2DLL(arr, n);
   printDLL(dllHead);

   dllHead = reverseDLLRecursion(dllHead);
   printDLL(dllHead);

   return 0;
}

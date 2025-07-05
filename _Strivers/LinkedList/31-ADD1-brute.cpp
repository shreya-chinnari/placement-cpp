// Add 1 to a number represented by LinkedList

// SC : O(1)
// TC : O(n) + O(n) + O(n) = O(3n) ---> optimise this with recursion

#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
   Node *back;
   Node(int val)
   {
      data = val;
      next = nullptr;
      back = nullptr;
   }
};

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

Node *reverseSLL(Node *head)
{
   Node *prev = nullptr, *front = nullptr, *temp = head;
   while (temp)
   {
      front = temp->next;
      temp->next = prev;
      prev = temp;
      temp = front;
   }
   head = prev; // head now points to beginning of reversed list
   return head;
}

Node *reverseDLL(Node *head)
{
   if (!head || !head->next)
      return head;

   Node *temp = nullptr;
   Node *current = head;

   // swap next and back for all nodes
   while (current)
   {
      temp = current->back;
      current->back = current->next;
      current->next = temp;
      current = current->back; // move to original next
   }

   // reset head (temp now points to the last node)
   if (temp)
      head = temp->back;

   return head;
}

/*
Both add1SLL and add1DLL reverse the list twice:
      Reverse the entire list → O(n)
      Traverse to add 1 → O(n)
      Reverse the list back → O(n)
   Total Time Complexity: O(3n)
*/

// Add 1 to number represented by SLL
Node *add1SLL(Node *head)
{
   // 1 : Reverse the list so we can add from RHS : O(n)
   head = reverseSLL(head);

   // 2 : Add 1 : O(n) for traversal
   int carry = 1; // the 1 that needs to be added
   Node *temp = head;
   while (temp)
   {
      temp->data = temp->data + carry; // add

      if (temp->data < 10)
      {
         carry = 0;
         break;
      }
      else
      {
         temp->data = 0;
         carry = 1;
      }
      temp = temp->next;
   }
   if (carry == 1) // if some carry is leftover, make a new node [1] amd attach is before head
   {
      Node *newNode = new Node(1);
      head = reverseSLL(head); // O(n)
      newNode->next = head;
      return newNode;
   }

   // 3 : Reverse again
   head = reverseSLL(head);

   return head;
}

Node *add1DLL(Node *head)
{
   head = reverseDLL(head); // reverse DLL to process from least significant digit
   int carry = 1;
   Node *temp = head;
   while (temp)
   {
      temp->data += carry;
      if (temp->data < 10)
      {
         carry = 0;
         break;
      }
      else
      {
         temp->data = 0;
         carry = 1;
      }
      temp = temp->next;
   }
   if (carry == 1)
   {
      Node *newNode = new Node(1);
      head = reverseDLL(head);
      newNode->next = head;
      return newNode;
   }
   head = reverseDLL(head);

   return head;
}

int main()
{
   int arr[] = {9, 9, 9}; // represents number 999
   int n = sizeof(arr) / sizeof(arr[0]);

   cout << "SLL before adding 1: ";
   Node *sllHead = convertArr2SLL(arr, n);
   printSLL(sllHead);
   sllHead = add1SLL(sllHead);
   cout << "SLL after adding 1: ";
   printSLL(sllHead);

   Node *dllHead = convertArr2DLL(arr, n);
   cout << "DLL before adding 1: ";
   printDLL(dllHead);
   dllHead = add1DLL(dllHead);
   cout << "DLL after adding 1: ";
   printDLL(dllHead);

   return 0;
}

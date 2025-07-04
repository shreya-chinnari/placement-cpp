// Sort a LL of 0's and 1's and 2's - DLL

/*
In the brute-force counting method, you’re not changing the structure of the list (i.e., you’re not adding/removing/moving any nodes). You're only modifying the data of each node.

That’s why you don’t need to touch or update the ->back pointers at all — because :
   You are only doing
      temp->data = 0;

   You are not doing
      someNode->next = otherNode;
      someNode->back = previousNode;
*/

// SAME CODE AS SLL

#include <iostream>
using namespace std;

// Doubly Linked List Node
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

// Convert array to Doubly Linked List
Node *convertArr2DLL(int arr[], int n)
{
   if (n == 0)
      return nullptr;

   Node *head = new Node(arr[0]);
   Node *prev = head;

   for (int i = 1; i < n; ++i)
   {
      Node *temp = new Node(arr[i]);
      prev->next = temp;
      temp->back = prev;
      prev = temp;
   }
   return head;
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

// Sort 0s, 1s, 2s in DLL using brute-force count method
Node *sort012_DLL(Node *head)
{
   int count0 = 0, count1 = 0, count2 = 0;
   Node *temp = head;

   // First pass: Count 0s, 1s, and 2s
   while (temp != nullptr)
   {
      if (temp->data == 0)
         count0++;
      else if (temp->data == 1)
         count1++;
      else
         count2++;

      temp = temp->next;
   }

   // Second pass: Overwrite values
   temp = head;
   while (count0--)
   {
      temp->data = 0;
      temp = temp->next;
   }
   while (count1--)
   {
      temp->data = 1;
      temp = temp->next;
   }
   while (count2--)
   {
      temp->data = 2;
      temp = temp->next;
   }

   return head;
}

// Main Function
int main()
{
   int arr[] = {1, 0, 2, 1, 0, 2, 1, 0};
   int n = sizeof(arr) / sizeof(arr[0]);

   Node *head = convertArr2DLL(arr, n);

   cout << "Original DLL: ";
   printDLL(head);

   head = sort012_DLL(head);

   cout << "Sorted DLL:   ";
   printDLL(head);

   return 0;
}

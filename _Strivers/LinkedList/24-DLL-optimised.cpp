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

// Convert array to Doubly Linked List
Node *convertArrToDLL(int arr[], int n)
{
   if (n == 0)
      return nullptr;

   Node *head = new Node(arr[0]);
   Node *prev = head;

   for (int i = 1; i < n; i++)
   {
      Node *temp = new Node(arr[i]);
      prev->next = temp;
      temp->back = prev;
      prev = temp;
   }
   return head;
}

// Print Doubly Linked List
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

Node *sort012_DLL(Node *head)
{
   if (!head || !head->next)
      return head;

   Node *dummy0 = new Node(-1);
   Node *dummy1 = new Node(-1);
   Node *dummy2 = new Node(-1);

   Node *tail0 = dummy0;
   Node *tail1 = dummy1;
   Node *tail2 = dummy2;

   Node *temp = head; // temp = temp

   // Separate into 3 lists
   while (temp)
   {
      if (temp->data == 0)
      {
         tail0->next = temp;
         temp->back = tail0;
         tail0 = temp;
      }
      else if (temp->data == 1)
      {
         tail1->next = temp;
         temp->back = tail1;
         tail1 = temp;
      }
      else
      {
         tail2->next = temp;
         temp->back = tail2;
         tail2 = temp;
      }
      temp = temp->next;
   }

   // Connect the lists carefully
   tail0->next = dummy1->next ? dummy1->next : dummy2->next;
   if (tail0->next)
      tail0->next->back = tail0;

   tail1->next = dummy2->next;
   if (tail1->next)
      tail1->next->back = tail1;

   tail2->next = nullptr;

   // Final head
   Node *newHead = dummy0->next;
   if (newHead)
      newHead->back = nullptr;

   delete dummy0;
   delete dummy1;
   delete dummy2;

   return newHead;
}

int main()
{
   int arr[] = {1, 2, 0, 2, 1, 0, 1, 2, 0};
   int n = sizeof(arr) / sizeof(arr[0]);

   Node *head = convertArrToDLL(arr, n);
   cout << "Original DLL: ";
   printDLL(head);

   head = sort012_DLL(head);
   cout << "Sorted DLL:   ";
   printDLL(head);

   return 0;
}

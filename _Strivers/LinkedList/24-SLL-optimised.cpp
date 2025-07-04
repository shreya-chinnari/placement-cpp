// TC: O(n)
// SC: O(1)

#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node *next;

   Node(int val)
   {
      data = val;
      next = nullptr;
   }
};
// Convert array to SLL
Node *convertArrToSLL(int arr[], int n)
{
   if (n == 0)
      return nullptr;

   Node *head = new Node(arr[0]);
   Node *curr = head;
   for (int i = 1; i < n; i++)
   {
      curr->next = new Node(arr[i]);
      curr = curr->next;
   }
   return head;
}
// Print the SLL
void printList(Node *head)
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

Node *sort012(Node *head)
{
   if (head == NULL || head->next == NULL)
   {
      return head;
   }

   // Dummy nodes for each value group {3 lists}
   Node *dummyHead0 = new Node(-1);
   Node *dummyHead1 = new Node(-1);
   Node *dummyHead2 = new Node(-1);

   // Traverse and divide nodes into 0s, 1s, and 2s lists
   Node *tail0 = dummyHead0;
   Node *tail1 = dummyHead1;
   Node *tail2 = dummyHead2;

   Node *newHead = new Node(-1); // FINAL HEAD

   Node *temp = head; // for traversing original LL
   while (temp != NULL)
   {
      // we tail all the 0's nodes to tail0, all the 1's nodes to tail1 and all the 2's nodes to tail2
      if (temp->data == 0)
      {
         tail0->next = temp;
         tail0 = temp;
      }
      else if (temp->data == 1)
      {
         tail1->next = temp;
         tail1 = temp;
      }
      else
      {
         tail2->next = temp;
         tail2 = temp;
      }
      temp = temp->next;
   }

   // connect dummy0, dummy1, dummy2 considering cases when there might not be any 0s || 1s || 2s nodes

   // tail0 -> either 1 or 2 {checks if 0s, 1s or 2s are empty}
   tail0->next = (dummyHead1->next != NULL) ? dummyHead1->next : dummyHead2->next;

   // tail1 -> 2 {checks if 1s or 2s are empty}
   tail1->next = dummyHead2->next;

   // tail2 {checks if 2s is empty}
   tail2->next = NULL;

   // HEAD
   newHead = dummyHead0->next;

   delete (dummyHead0);
   delete (dummyHead1);
   delete (dummyHead2);

   return newHead;
}

int main()
{
   int arr[] = {1, 2, 0, 2, 1, 0, 1, 2, 0};
   int n = sizeof(arr) / sizeof(arr[0]);

   Node *head = convertArrToSLL(arr, n);
   cout << "Original List: ";
   printList(head);

   head = sort012(head);
   cout << "Sorted List:   ";
   printList(head);

   return 0;
}
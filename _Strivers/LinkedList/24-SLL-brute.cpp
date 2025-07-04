// Sort a LL of 0's and 1's and 2's - SLL

/*
✅ Approach (Brute Force - Counting Method):
   Traverse the linked list and count number of 0s, 1s and 2s.
   Then, traverse again and overwrite the node values in order: first fill all 0s, then 1s, then 2s.

✅ Time Complexity: O(2n)
✅ Space Complexity: O(1) – in-place, no extra linked list or array used
*/

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
   int count0 = 0, count1 = 0, count2 = 0;
   Node *temp = head; // to traverse

   // First pass: Count 0s, 1s, and 2s
   while (temp != NULL)
   {
      if (temp->data == 0)
         count0++;
      else if (temp->data == 1)
         count1++;
      else
         count2++;

      temp = temp->next;
   }
   // Second pass: Overwrite values in order
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
   /*
   while(temp!=NULL) {
      if(count0) {
         temp->data = 0;
         count0--;
      }
      else if(count1) {
         temp->data = 1;
         count1--;
      }
      else if(count2) {
         temp->data = 2;
         count2--;
      }
   }
   */
   return head;
}

int main()
{
   int arr[] = {1, 0, 2, 1, 0, 2, 1, 0};
   int n = sizeof(arr) / sizeof(arr[0]);

   Node *head = convertArr2SLL(arr, n);

   cout << "Original List: ";
   printList(head);

   head = sort012(head);

   cout << "Sorted List:   ";
   printList(head);

   return 0;
}
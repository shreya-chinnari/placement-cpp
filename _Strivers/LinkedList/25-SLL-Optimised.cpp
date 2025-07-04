// Remove Nth Node from the end of LL

// TC : O(length)
// SC : O(1)

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

Node *removeKthElement(Node *head, int k)
{
   // Edge case:  #1:  empty list
   if (!head)
      return nullptr;

   Node *fast = head;
   for (int i = 0; i < k; i++)
   {
      if (fast == nullptr)
         return head; // Edge case:  #2: k > length {nothing to remove}
      fast = fast->next;
   }

   // Edge case: #3:   k == length → need to remove head
   if (!fast)
   {
      Node *newHead = head->next;
      delete head;
      return newHead;
   }

   Node *slow = head;
   while (fast->next != NULL)
   {
      slow = slow->next;
      fast = fast->next;
   } // fast reaches the last-node of list, slow reaches the node previous to the node to be deleted
   Node *delNode = slow->next;
   slow->next = slow->next->next;

   delete (delNode);

   return head;
}

int main()
{
   int arr[] = {10, 20, 30, 40, 50, 60};
   int n = sizeof(arr) / sizeof(arr[0]);

   Node *head = convertArr2SLL(arr, n);

   cout << "Original List: ";
   printList(head);

   head = removeKthElement(head, 6);
   cout << "List after removing 6th node from end (head): ";
   printList(head);

   head = removeKthElement(head, 3);
   cout << "List after removing 3rd node from end: ";
   printList(head);

   return 0;
}

// Remove Nth Node from the end of LL

// TC : O(length) + O(length - k) === O(2 x length)
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
   // First pass: count total nodes
   int count = 0;
   Node *temp = head;
   while (temp != nullptr)
   {
      count++;
      temp = temp->next;
   }
   // If head is to be removed
   if (count == k)
   {
      Node *newHead = head->next;
      delete (head);
      return newHead;
   }
   // otherwise
   // Second pass: reach (count - k - 1)th node
   int result = count - k; // node before [deleteNode]
   temp = head;
   while (temp != NULL)
   {
      result--;
      if (result == 0)
         break; // stop when reached
      temp = temp->next;
   }
   /*

   while(--result) { temp = temp->next }
   */
   Node *deleteNode = temp->next;
   temp->next = temp->next->next;
   delete (deleteNode);
   return head;
}

// the position from the start of the node to be deleted is count - k

int main()
{
   int arr[] = {10, 20, 30, 40, 50, 60};
   int n = sizeof(arr) / sizeof(arr[0]);
   int k = 3; // Remove 3rd node from end → should remove 40

   Node *head = convertArr2SLL(arr, n);

   cout << "Original List: ";
   printList(head);

   head = removeKthElement(head, k);

   cout << "List after removing " << k << "th node from end: ";
   printList(head);

   return 0;
}

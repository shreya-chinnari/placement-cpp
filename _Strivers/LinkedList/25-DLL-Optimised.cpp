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
   Node *back;

   Node(int val)
   {
      data = val;
      next = nullptr;
      back = nullptr;
   }
};

// Convert array to DLL
Node *convertArrToDLL(int arr[], int n)
{
   if (n == 0)
      return nullptr;

   Node *head = new Node(arr[0]);
   Node *current = head;

   for (int i = 1; i < n; ++i)
   {
      Node *temp = new Node(arr[i]);
      current->next = temp;
      temp->back = current;
      current = temp;
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

Node *removeKthElement(Node *head, int k)
{
   Node *fast = head;
   for (int i = 0; i < k; i++)
   {
      if (fast == nullptr)
         return head; // Edge case: k > length
      fast = fast->next;
   }
   // If k == length of list (i.e., fast == nullptr), we delete the head
   if (fast == nullptr)
   {
      Node *newHead = head->next;
      if (newHead)
         newHead->back = nullptr;
      delete head;
      return newHead;
   }
   Node *slow = head;
   while (fast->next != NULL)
   {
      slow = slow->next;
      fast = fast->next;
   } // fast reaches the last-node of list, slow reaches the node backious to the node to be deleted
   Node *delNode = slow->next;

   slow->next = slow->next->next;
   if (slow->next->next)
   {
      slow->next->next->back = slow;
   }

   delete (delNode);

   return head;
}

int main()
{
   int arr[] = {10, 20, 30, 40, 50, 60};
   int n = sizeof(arr) / sizeof(arr[0]);
   int k = 3;

   Node *head = convertArrToDLL(arr, n);

   cout << "Original List: ";
   printList(head);

   head = removeKthElement(head, k);

   cout << "List after removing " << k << "th node from end: ";
   printList(head);

   return 0;
}

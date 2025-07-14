// Remove Nth Node from the end of LL

#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
   Node *prev;

   Node(int val)
   {
      data = val;
      next = nullptr;
      prev = nullptr;
   }
};

// Convert array to DLL
Node *convertArrToDLL(int arr[], int n)
{
   if (n == 0)
      return nullptr;

   Node *head = new Node(arr[0]);
   Node *current = head;

   for (int i = 1; i < n; i++)
   {
      Node *temp = new Node(arr[i]);
      current->next = temp;
      temp->prev = current;
      current = temp;
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

// Remove N-th node from end in DLL (Brute Force)
Node *removeKthFromEnd_DLL(Node *head, int k)
{
   if (!head)
      return nullptr;

   // First pass: count total nodes
   int count = 0;
   Node *temp = head;
   while (temp)
   {
      count++;
      temp = temp->next;
   }

   // If head is to be removed
   if (count == k)
   {
      Node *newHead = head->next;
      if (newHead)
         newHead->prev = nullptr;
      delete head;
      return newHead;
   }

   // Second pass: go to the node before the one to delete
   int result = count - k; // index from start
   temp = head;
   for (int i = 1; i < result; i++) // go to (count - k)th node
   {
      temp = temp->next;
   }

   Node *delNode = temp->next;
   temp->next = delNode->next;

   if (delNode->next)
      delNode->next->prev = temp;

   delete delNode;
   return head;
}

// Driver Code
int main()
{
   int arr[] = {10, 20, 30, 40, 50, 60};
   int n = sizeof(arr) / sizeof(arr[0]);
   int k = 3; // remove 3rd from end → 40

   Node *head = convertArrToDLL(arr, n);

   cout << "Original DLL: ";
   printDLL(head);

   head = removeKthFromEnd_DLL(head, k);

   cout << "DLL after removing " << k << "th node from end: ";
   printDLL(head);

   return 0;
}

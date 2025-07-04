// Reverse a SLL
// TC : O(N) , SC : O(1)

#include <iostream>
#include <stack>
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

// Linker change method
Node *reverseLL(Node *head)
{
   if (!head || !head->next)
      return head; // empty or single-node list

   Node *temp = head;
   Node *prev = nullptr;  // to store previous node of [temp]
   Node *front = nullptr; // copy next node of [temp]

   while (temp != NULL)
   {
      front = temp->next; // save next node
      temp->next = prev;  // reverse link
      prev = temp;        // move prev ahead
      temp = front;       // move temp ahead
   }
   return prev; // new head
}

// Driver code
int main()
{
   int arr[] = {1, 2, 3, 4, 5};
   int n = sizeof(arr) / sizeof(arr[0]);

   Node *head = convertArr2SLL(arr, n);
   cout << "Original List: ";
   printList(head);

   head = reverseLL(head);
   cout << "Reversed List (using stack): ";
   printList(head);

   return 0;
}
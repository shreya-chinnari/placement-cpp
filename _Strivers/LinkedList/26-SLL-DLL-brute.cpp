// Reverse a SLL or DLL {same code}
// brute force - using LIFO of stack

// TC : O(2n) , SC : O(n)
// need to optimise the extra memory

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

// Data Overwrite Approach
Node *reverseLL(Node *head)
{
   if (!head || !head->next)
      return head; // empty or single-node list

   stack<int> st;
   Node *temp = head;

   // traverse to put all data into stack
   while (temp)
   {
      st.push(temp->data);
      temp = temp->next;
   }

   // put all data from Top to Bottom into LL
   temp = head;
   while (temp != NULL)
   {
      temp->data = st.top();
      st.pop();

      temp = temp->next;
   }
   return head;
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
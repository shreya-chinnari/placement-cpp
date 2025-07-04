// middle of the LL - brute force

// Palindrome

// First pass: count total nodes  → O(n)
// Second pass: reach middle      → O(n/2)
// Total: O(n) + O(n/2) = O(n)

// SC : O(1)

#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
   Node *back; // Only used in DLL

   Node(int val)
   {
      data = val;
      next = nullptr;
      back = nullptr;
   }
};

// Convert array to Singly Linked List
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

// Convert array to Doubly Linked List
Node *convertArr2DLL(int arr[], int n)
{
   if (n == 0)
      return nullptr;

   Node *head = new Node(arr[0]);
   Node *current = head;

   for (int i = 1; i < n; ++i)
   {
      Node *newNode = new Node(arr[i]);
      current->next = newNode;
      newNode->back = current;
      current = newNode;
   }
   return head;
}

// Print SLL
void printSLL(Node *head)
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

Node *middleNodeSLLDLL(Node *head)
{
   Node *slow = head;
   Node *fast = head;

   // for odd-length LL : fast will reach last element
   // for even-length LL : fast will reach "nullptr" (last->next)

   while (fast != nullptr && fast->next != nullptr)
   {
      slow = slow->next;
      fast = fast->next->next;
   }
   return slow;
}

// TC : O(n/2)
// SC : O(1)

// Driver code
int main()
{
   int arrODD[] = {1, 2, 3, 2, 1};
   int n = sizeof(arrODD) / sizeof(arrODD[0]);

   cout << "Singly Linked List: ";
   Node *head1 = convertArr2SLL(arrODD, n);
   printSLL(head1);

   head1 = middleNodeSLLDLL(head1);
   cout << "middle node : ";
   printSLL(head1);

   int arrEVEN[] = {1, 2, 3, 4, 2, 1};
   int n2 = sizeof(arrEVEN) / sizeof(arrEVEN[0]);

   cout << "Singly Linked List: ";
   Node *head2 = convertArr2SLL(arrEVEN, n2);
   printSLL(head2);

   head2 = middleNodeSLLDLL(head2);
   cout << "middle node : ";
   printSLL(head2);

   return 0;
}

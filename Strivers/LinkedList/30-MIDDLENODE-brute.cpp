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

Node *middleNode(Node *head)
{
   if (!head)
      return nullptr;

   // O(n)
   int count = 0;
   Node *temp = head;

   while (temp)
   {
      count++;
      temp = temp->next;
   }

   int mid = (count / 2) + 1;

   // find middle node { O(n/2) }
   temp = head;
   while (temp)
   {
      mid--;
      if (mid == 0) // found mid node
         break;
      temp = temp->next;

      /*
      for (int i = 1; i < midPos; i++) {
      temp = temp->next;
      }
      */
   }

   return temp;
}

// Driver code
int main()
{
   int arr[] = {1, 2, 3, 2, 1};
   int n = sizeof(arr) / sizeof(arr[0]);

   cout << "Singly Linked List: ";
   Node *sllHead = convertArr2SLL(arr, n);
   printSLL(sllHead);

   cout << "\nDoubly Linked List: ";
   Node *dllHead = convertArr2DLL(arr, n);
   printDLL(dllHead);

   return 0;
}

// Palindrome

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
// helper function to reverse the LL
Node *reverseSLLRecursion(Node *head)
{
   // for 1-element LL
   if (head == NULL || head->next == NULL)
      return head;

   Node *newHead = reverseSLLRecursion(head->next); // head of the reversed
   Node *front = head->next;
   front->next = head;
   head->next = nullptr;

   return newHead;
}

// TC : O(n/2) +  O(n/2) + O(n/2) + O(n/2)  = O(2n)
// SC : O(1)

// Palindrome Check
bool isPalindromeSLL(Node *head)
{

   // Part 1 : finding the middle
   Node *slow = head;
   Node *fast = head;
   while (fast->next && fast->next->next)
   {
      slow = slow->next;
      fast = fast->next->next;
   }

   // Part 2 : reverse the second half (starting from "slow->next" as "slow" is the middle node)
   Node *newHead = reverseSLLRecursion(slow->next);

   // Part 3 : compare
   Node *first = head;
   Node *second = newHead;

   while (second)
   {
      if (first->data != second->data)
      {
         reverseSLLRecursion(newHead); // make sure to revert the second half to get the original LL back
         return 0;
      }
      first = first->next;
      second = second->next;
   }
   reverseSLLRecursion(newHead);
   return true;
}

// Reverse DLL recursively
Node *reverseDLLRecursion(Node *head)
{
   if (!head || !head->next)
      return head;

   Node *newHead = reverseDLLRecursion(head->next);
   Node *front = head->next;
   front->next = head;
   head->back = front;

   head->next = nullptr;
   return newHead;
}

// Palindrome Check
bool isPalindromeDLL(Node *head)
{
   if (!head || !head->next)
      return true;

   // Part 1: Find middle node (slow will stop at mid)
   Node *slow = head;
   Node *fast = head;
   while (fast->next && fast->next->next)
   {
      slow = slow->next;
      fast = fast->next->next;
   }

   // Part 2: Reverse second half from slow->next
   Node *newHead = reverseDLLRecursion(slow->next);
   slow->next = newHead;
   if (newHead)
      newHead->back = slow;

   // Part 3: Compare both halves
   Node *first = head;
   Node *second = newHead;

   while (second)
   {
      if (first->data != second->data)
      {
         reverseDLLRecursion(newHead); // Restore second half
         return false;
      }
      first = first->next;
      second = second->next;
   }

   reverseDLLRecursion(newHead); // Restore original DLL
   return true;
}

// Driver code
int main()
{
   int arr[] = {1, 2, 3, 2, 1};
   int n = sizeof(arr) / sizeof(arr[0]);

   cout << "Singly Linked List: ";
   Node *sllHead = convertArr2SLL(arr, n);
   printSLL(sllHead);

   if (isPalindromeSLL(sllHead))
      cout << "SLL is a Palindrome.\n";
   else
      cout << "SLL is NOT a Palindrome.\n";

   cout << "\nDoubly Linked List: ";
   Node *dllHead = convertArr2DLL(arr, n);
   printDLL(dllHead);

   if (isPalindromeDLL(dllHead))
      cout << "DLL is a Palindrome.\n";
   else
      cout << "DLL is NOT a Palindrome.\n";

   return 0;
}

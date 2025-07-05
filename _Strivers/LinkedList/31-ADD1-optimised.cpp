// recursion method to optimise O(3n) time complexity

// TC : O(n)
// SC : O(n)

/*
✅ Optimized Approach (Single traversal from end, no reversal back)

   For SLL, instead of reversing back at the end, we can build the result in the correct order while reversing (reusing the reversed structure).

   For DLL, we don’t need to reverse at all. Just go to the tail and add 1 from the back using back pointers.
*/

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

Node *reverseSLL(Node *head)
{
   Node *prev = nullptr, *front = nullptr, *temp = head;
   while (temp)
   {
      front = temp->next;
      temp->next = prev;
      prev = temp;
      temp = front;
   }
   head = prev; // head now points to beginning of reversed list
   return head;
}

Node *reverseDLL(Node *head)
{
   if (!head || !head->next)
      return head;

   Node *temp = nullptr;
   Node *current = head;

   // swap next and back for all nodes
   while (current)
   {
      temp = current->back;
      current->back = current->next;
      current->next = temp;
      current = current->back; // move to original next
   }

   // reset head (temp now points to the last node)
   if (temp)
      head = temp->back;

   return head;
}

// ---------------- Helper recursive function ----------------
// Recursively goes to the end, adds 1, and "propagates" {carry} back

int helper(Node *temp)
{
   if (!temp)   // base case: end of list
      return 1; // carry for the last node (we add 1 to the last digit)

   int carry = helper(temp->next); // recurse to the last node
   temp->data = temp->data + carry;

   if (temp->data < 10)
   {
      return 0;
   } // no carry needed further
   temp->data = 0; // reset to 0 if overflow

   return 1; // pass 1 as carry to the previous node
}

// --------------------- Wrapper function ---------------------
Node *add1RecursiveSLL(Node *head)
{
   int carry = helper(head); // recursive function

   // If carry is still left, add new node at front
   if (carry == 1)
   {
      Node *newNode = new Node(1);
      newNode->next = head;
      return newNode;
   }

   return head;
}

// --------------------- Back Pointer for DLL  ---------------------
// TC : O(n)
// TC : O(1)

Node *add1DLLBackPointer(Node *head)
{
   if (!head)
      return new Node(1);

   // Step 1: Move to the tail
   Node *tail = head;
   while (tail->next)
      tail = tail->next;

   // Step 2: Add 1 from the tail
   int carry = 1;
   Node *temp = tail; // "temp" starts from the tail to propagate the carry backwards through the list.

   while (temp)
   {
      int sum = temp->data + carry; // Add the carry to current digit (temp->data).
      temp->data = sum % 10;        // Store the last digit of the sum (sum % 10) in the current node.
      carry = sum / 10;             // Update carry for next iteration (sum / 10).

      // If you're at the first node (temp->back == NULL) and still have a carry, create a new node with value 1 and insert it at the beginning.
      if (!temp->back && carry > 0)
      {
         Node *newHead = new Node(carry);
         newHead->next = head;
         head->back = newHead;
         return newHead;
      }

      temp = temp->back;
   }
   return head;
}

int main()
{
   int arr[] = {9, 9, 9}; // represents number 999
   int n = sizeof(arr) / sizeof(arr[0]);

   cout << "SLL before adding 1: ";
   Node *sllHead = convertArr2SLL(arr, n);
   printSLL(sllHead);
   sllHead = add1RecursiveSLL(sllHead);
   cout << "SLL after adding 1: ";
   printSLL(sllHead);

   cout << "DLL before adding 1: ";
   Node *dllHead = convertArr2DLL(arr, n);
   printDLL(dllHead);
   dllHead = add1DLLBackPointer(dllHead);
   cout << "DLL after adding 1: ";
   printDLL(dllHead);

   return 0;
}

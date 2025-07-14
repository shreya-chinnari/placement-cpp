// palindrome - SLL - Brute force
// TC : O(2N) , SC : O(N)

#include <iostream>
#include <stack>
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

// Palindrome Check (SLL & DLL same code) using Stack - O(N) space
bool isPalindrome(Node *head)
{
   stack<int> st;
   Node *temp = head;
   while (temp != NULL)
   {
      st.push(temp->data);
      temp = temp->next;
   }
   // compare
   temp = head;
   while (temp != NULL)
   {
      if (st.top() != temp->data)
      {
         return false;
      }
      st.pop();
      temp = temp->next;
   }
   return true;
}

int main()
{
   int arr[] = {1, 2, 3, 2, 1};
   int n = sizeof(arr) / sizeof(arr[0]);

   cout << "Singly Linked List: ";
   Node *sllHead = convertArr2SLL(arr, n);
   printSLL(sllHead);

   if (isPalindrome(sllHead))
      cout << "SLL is a Palindrome.\n";
   else
      cout << "SLL is NOT a Palindrome.\n";

   return 0;
}
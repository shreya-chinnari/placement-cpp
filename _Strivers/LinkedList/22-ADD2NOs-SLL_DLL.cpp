// ADD 2 numbers in LL

// L1, L2 given in rversed order, OP should also be in reverse

#include <iostream>
#include <vector>
using namespace std;

// Node structure supporting both singly and doubly linked list
class Node
{
public:
   int data;
   Node *next;
   Node *back;

   // Constructor for doubly linked list
   Node(int data1, Node *next1, Node *back1)
   {
      data = data1;
      next = next1;
      back = back1;
   }

   // Constructor for singly linked list
   Node(int data1)
   {
      data = data1;
      next = nullptr;
      back = nullptr;
   }
};

// Converts array to Doubly Linked List (DLL) - reversed number format
Node *convertArr_to_DLL(vector<int> &arr)
{
   Node *head = new Node(arr[0]);
   Node *prev = head;

   for (int i = 1; i < arr.size(); i++)
   {
      Node *temp = new Node(arr[i], nullptr, prev);
      prev->next = temp;
      prev = temp;
   }
   return head;
}

// Converts array to Singly Linked List (SLL) - reversed number format
Node *convertArr_to_SLL(vector<int> &arr)
{
   Node *head = new Node(arr[0]);
   Node *current = head;

   for (int i = 1; i < arr.size(); i++)
   {
      Node *temp = new Node(arr[i]);
      current->next = temp;
      current = temp;
   }
   return head;
}

// Prints any linked list (SLL or DLL)
void print(Node *head)
{
   cout << "LL ->   ";
   while (head != nullptr)
   {
      cout << head->data << "  ";
      head = head->next;
   }
   cout << endl;
}

// Adds two numbers represented by reversed Doubly Linked Lists (DLL)
Node *addTwoNumbers_DLL(Node *head1, Node *head2)
{
   Node *t1 = head1;
   Node *t2 = head2;
   Node *dummy = new Node(-1); // dummy head node
   Node *current = dummy;
   int carry = 0;

   while (t1 != nullptr || t2 != nullptr || carry)
   {
      int sum = carry;
      if (t1)
      {
         sum += t1->data;
         t1 = t1->next;
      }
      if (t2)
      {
         sum += t2->data;
         t2 = t2->next;
      }

      carry = sum / 10;
      Node *newNode = new Node(sum % 10);
      current->next = newNode;
      newNode->back = current; // for DLL
      current = current->next;
   }

   return dummy->next;
}

// Adds two numbers represented by reversed Singly Linked Lists (SLL)
Node *addTwoNumbers_SLL(Node *head1, Node *head2)
{
   Node *t1 = head1;
   Node *t2 = head2;
   Node *dummy = new Node(-1); // dummy head node
   Node *current = dummy;
   int carry = 0;

   while (t1 != nullptr || t2 != nullptr || carry)
   {
      int sum = carry;
      if (t1)
      {
         sum += t1->data;
         t1 = t1->next;
      }
      if (t2)
      {
         sum += t2->data;
         t2 = t2->next;
      }

      carry = sum / 10;
      Node *newNode = new Node(sum % 10); // no .back needed
      current->next = newNode;
      current = current->next;
   }

   return dummy->next;
}

// Driver code
int main()
{
   vector<int> arr1 = {2, 6, 9}; // represents 962
   vector<int> arr2 = {3, 7, 9}; // represents 973

   // Doubly Linked List version
   cout << "🔁 Using Doubly Linked List:\n";
   Node *dll1 = convertArr_to_DLL(arr1);
   Node *dll2 = convertArr_to_DLL(arr2);
   cout << "Input 1: ";
   print(dll1);
   cout << "Input 2: ";
   print(dll2);
   Node *dllResult = addTwoNumbers_DLL(dll1, dll2);
   cout << "Sum:     ";
   print(dllResult);
   cout << endl;

   // Singly Linked List version
   cout << "➡️ Using Singly Linked List:\n";
   Node *sll1 = convertArr_to_SLL(arr1);
   Node *sll2 = convertArr_to_SLL(arr2);
   cout << "Input 1: ";
   print(sll1);
   cout << "Input 2: ";
   print(sll2);
   Node *sllResult = addTwoNumbers_SLL(sll1, sll2);
   cout << "Sum:     ";
   print(sllResult);

   return 0;
}

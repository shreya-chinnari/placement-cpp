// ADD 2 numbers in LL

// L1, L2 given in rversed order, OP should also be in reverse

#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
   int data;
   Node *next;
   Node *back;

public:
   Node(int data1, Node *next1, Node *back1)
   {
      data = data1;
      next = next1;
      back = back1;
   }

public:
   Node(int data1)
   {
      data = data1;
      next = nullptr;
      back = nullptr;
   }
};
Node *convertArr_to_DLL(vector<int> &arr)
{
   Node *head = new Node(arr[0]);
   Node *prev = head; // copy

   for (int i = 1; i < arr.size(); i++)
   {
      Node *temp = new Node(arr[i], nullptr, prev);
      prev->next = temp;
      prev = temp;
   }
   return head;
}
void print(Node *head)
{
   cout << "LL ->   ";
   while (head != NULL)
   {
      cout << head->data << "  ";
      head = head->next;
   }
   cout << endl;
}

// ADDING 2 NUMBERS
Node *addTwoNumbers(Node *head1, Node *head2)

{
   Node *t1 = head1;           // for LL1
   Node *t2 = head2;           // for LL2
   Node *dummy = new Node(-1); // whenever we want to create a new list, add a dummy that acts as temp head {then return dummy->next}
   Node *current = dummy;
   int carry = 0;

   while (t1 != NULL || t2 != NULL || carry)
   {
      int sum = carry;
      if (t1)
      {
         sum = sum + t1->data;
         t1 = t1->next;
      }
      if (t2)
      {
         sum = sum + t2->data;
         t2 = t2->next;
      }
      carry = sum / 10; // carry for next summation

      Node *newNode = new Node(sum % 10); // add the sum's last digit to a new node

      // link the new node
      current->next = newNode;
      newNode->back = current; // Remove for SinglyLL
      // move to next iteration
      current = current->next;
   }
   // If there is still a carry left after t1 and t2 reaches NULL
   // if (carry)
   // {
   //    Node *newNode = new Node(carry);
   //    current->next = newNode;
   //    newNode->back = current; // Remove for SinglyLL
   // }

   return dummy->next;
}

int main()
{
   vector<int> arr1 = {2, 6, 9}; // represents 962
   vector<int> arr2 = {3, 7, 9}; // represents 973

   Node *head1 = convertArr_to_DLL(arr1);
   Node *head2 = convertArr_to_DLL(arr2);

   cout << "Input 1: ";
   print(head1);
   cout << "Input 2: ";
   print(head2);

   Node *result = addTwoNumbers(head1, head2); // Should represent
   cout << "Sum:     ";
   print(result);

   return 0;
}

/*
Input 1: LL ->   2  6  9
Input 2: LL ->   3  7  9
Sum:     LL ->   5  3  9  1
*/
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

// REVERSE ---------------------------

Node *reverseDLL(Node *head)
{
   // empty ll or single element
   if (head == NULL || head->next == NULL)
   {
      return head;
   }
   // otherwise
   Node *temp = NULL;
   Node *current = head;

   while (current != NULL)
   {
      temp = current->back; // copy {for swapping}
      current->back = current->next;
      current->next = temp;

      current = current->back;
   }

   // After loop, 'temp' points to the previous node of NULL
   // So 'temp->back' is the last node processed (new head)

   // if (temp != NULL)
   //    head = temp->back;
   // return head;
   return temp->back;
}

int main()
{
   vector<int> arr = {10, 20, 30, 40, 50};
   Node *head = convertArr_to_DLL(arr);

   cout << "Original DLL: ";
   print(head);

   head = reverseDLL(head);

   cout << "Reversed DLL (values): ";
   print(head);

   vector<int> arr1 = {1};
   Node *head1 = convertArr_to_DLL(arr1);

   cout << "Original DLL: ";
   print(head1);

   head1 = reverseDLL(head1);

   cout << "Reversed DLL (values): ";
   print(head1);
   return 0;
}

// TC: O(n)
// SC: O(1)

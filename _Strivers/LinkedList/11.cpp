// insert an element before a value

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
   int data;
   Node *next;

public:
   Node(int data1)
   {
      data = data1;
      next = nullptr;
   }
   // Add this constructor
   Node(int data1, Node *next1)
   {
      data = data1;
      next = next1;
   }
};

Node *convertARRtoLL(vector<int> &arr)
{
   Node *head = new Node(arr[0]);
   Node *mover = head;

   for (int i = 1; i < arr.size(); i++)
   {
      Node *temp = new Node(arr[i]);
      mover->next = temp;
      mover = mover->next;
   }

   return head;
}

void printLL(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << "  ";
      head = head->next;
   }
   cout << endl;
}

// before element "val"
Node *insertBeforeVal(Node *head, int el, int val)
{
   // empty LL---------------------------------------
   if (head == NULL)
   {
      return NULL; // no "val" present in empty LL
   }
   // val found at head---------------------------------------
   if (head->data == val)
   {
      Node *temp = new Node(el, head); // insert "el" before head
      return temp;
   }
   // otherwise before {k=2,3,4..}---------------------------------------

   Node *temp = head; // copy
   // go to k-th position
   while (temp->next != NULL) // stop at second-last element
   {
      // found K-th position
      if (temp->next->data == val) // data of element next to temp = val
      {
         // Node* x = new Node(el, temp->next); - {required node added at temp}
         Node *x = new Node(el);
         x->next = temp->next;
         temp->next = x;
         break;
      }
      // otherwise keep moving
      temp = temp->next;
   }
   return head;
};

int main()
{
   vector<int> arr = {6, 3, 9, 5, 0};
   Node *head = convertARRtoLL(arr);

   printLL(head);

   head = insertBeforeVal(head, 999, 2);
   cout << "inserting before 2 : ";
   printLL(head);

   head = insertBeforeVal(head, 999, 5);
   cout << "inserting before 5 : ";
   printLL(head);

   head = insertBeforeVal(head, 999, 6);
   cout << "inserting before 6 : ";
   printLL(head);

   return 0;
}
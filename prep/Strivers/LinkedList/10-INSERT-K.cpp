// inserting at K-th place

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

// K-th place
Node *insertAt_K(Node *head, int el, int k)
{
   // empty LL
   if (head == NULL)
   {
      // k=1{head}
      if (k == 1)
      {
         Node *temp = new Node(el, head); // "el" value gets added, pointing to the head
         return temp;
      }
      else
      {
         return NULL;
      }
   }
   // k=1{head}
   if (k == 1)
   {
      Node *temp = new Node(el, head);
      return temp;
   }
   // otherwise {k=2,3,4..}
   int count = 0;
   Node *temp = head; // copy
   // go to k-th position
   while (temp != NULL)
   {
      count++;
      // found K-th position
      if (count == k - 1)
      {
         // Node* x = new Node(el, temp->next);
         Node *x = new Node(el);
         x->next = temp->next;
         temp->next = x;
         // return head;
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

   head = insertAt_K(head, 999, 1);
   cout << "inserting at K-th position : ";
   printLL(head);

   head = insertAt_K(head, 999, 3);
   cout << "inserting at K-th position : ";
   printLL(head);

   head = insertAt_K(head, 999, 100);
   cout << "inserting at K-th position : ";
   printLL(head);

   return 0;
}
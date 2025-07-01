// deleting a node {head, tail}

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

// delete head
Node *removeHead(Node *head)
{
   if (head == NULL)
      return head;

   Node *temp = head;
   head = head->next;
   delete temp;
   return head;
}

// delete tail
Node *removeTail(Node *head)
{
   // empty LL
   if (head == NULL)
      return NULL;
   // LL with 1 element
   if (head->next == NULL)
      return NULL;
   // a LL must have atleast 2 elements
   Node *temp = head; // copy of head
   while (temp->next->next != NULL)
   {
      temp = temp->next; // copy of head is moved to second last element
   }
   delete (temp->next); // free up last element
   temp->next = NULL;   // now temp is last element so it shall point to NULL

   return head;
}

int main()
{
   vector<int> arr = {6, 3, 9, 5, 0};
   Node *head = convertARRtoLL(arr);

   printLL(head);
   head = removeHead(head);
   cout << "removing head : ";
   printLL(head);

   head = removeTail(head);
   cout << "removing tail : ";
   printLL(head);
   return 0;
}
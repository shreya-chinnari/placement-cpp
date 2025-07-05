// inserting at head and tail

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

// HEAD
Node *insertAtHead(Node *head, int el)
{
   Node *temp = new Node(el, head);
   return temp;
   // return new Node(el, head);
};

// TAIL
Node *insertAtTail(Node *head, int el)
{
   // empty LL
   if (head == NULL)
   {
      return new Node(el);
   }
   // otherwise
   Node *temp = head;         // copy
   while (temp->next != NULL) // while we havent reached the last node,
   {
      temp = temp->next; // keep moving forward
   }
   Node *newNode = new Node(el); // when we reach last node, we create a new node after it
   temp->next = newNode;

   return head;
};

int main()
{
   vector<int> arr = {6, 3, 9, 5, 0};
   Node *head = convertARRtoLL(arr);

   printLL(head);
   head = insertAtHead(head, 100);
   // head = new Node(100, head);
   cout << "inserting at head : ";
   printLL(head);

   head = insertAtTail(head, 100);
   // head = new Node(100, head);
   cout << "inserting at tail : ";
   printLL(head);

   return 0;
}
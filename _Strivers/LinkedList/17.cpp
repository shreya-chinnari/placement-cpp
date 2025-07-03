// insert before the tail
// insert after the tail

// removing a given node {value given}

// delete K-th element in DLL

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
Node *insertBeforeHead(Node *head, int val)
{
   Node *newHead = new Node(val, head, nullptr);
   if (head != nullptr)
   {
      head->back = newHead;
   }

   return newHead;
}
Node *insertAfterHead(Node *head, int val)
{
   Node *afterHead = new Node(val, head->next, head);

   if (head->next != nullptr)
   {
      head->next->back = afterHead;
   }
   head->next = afterHead;
   return head;
}

// LOGIC ---------------------------------
Node *insertBeforeTail(Node *head, int val)
{
   // IF only 1 element {it is the tail, it is the head}
   if (head->next == NULL)
   {
      return insertBeforeHead(head, val);
   }
   // Otherwise
   Node *tail = head; // traverse till tail
   while (tail->next != NULL)
   {
      tail = tail->next;
   }
   Node *beforeTail = new Node(val, tail, tail->back);
   tail->back->next = beforeTail;
   tail->back = beforeTail;

   return head;
}

Node *insertAfterTail(Node *head, int val)
{
   // IF only 1 element {it is the tail, it is the head}
   if (head->next == NULL)
   {
      return insertAfterHead(head, val);
   }
   // Otherwise
   Node *tail = head; // traverse till tail
   while (tail->next != NULL)
   {
      tail = tail->next;
   }
   Node *afterTail = new Node(val, nullptr, tail);
   tail->next = afterTail;

   return head;
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5};
   Node *head = convertArr_to_DLL(arr);
   print(head);

   head = insertBeforeTail(head, 100);
   print(head);
   head = insertAfterTail(head, 101);
   print(head);

   return 0;
}
// Insert before and after the K-th element

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
Node *insertBeforeTail(Node *head, int val)
{

   if (head->next == NULL)
   {
      return insertBeforeHead(head, val);
   }

   Node *tail = head;
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
   if (head->next == NULL)
   {
      return insertAfterHead(head, val);
   }

   Node *tail = head;
   while (tail->next != NULL)
   {
      tail = tail->next;
   }
   Node *afterTail = new Node(val, nullptr, tail);
   tail->next = afterTail;

   return head;
}

// LOGIC ---------------------------------
Node *insertBeforeKthElement(Node *head, int k, int val)
{
   // if K=1 {head}
   if (k == 1)
   {
      return insertBeforeHead(head, val);
   }
   // if k is in middle somewhere
   Node *temp = head;
   int count = 0;
   while (temp != NULL)
   {
      count++;
      if (count == k)
         break;
      temp = temp->next;
   }
   Node *prev = temp->back;
   Node *newNode = new Node(val, temp, prev);
   prev->next = newNode;
   temp->back = newNode;

   return head;
}

Node *insertAfterKthElement(Node *head, int k, int val)
{
   // if K=1 {head}
   if (k == 1)
   {
      return insertAfterHead(head, val);
   }
   // if k is in middle somewhere
   Node *temp = head;
   int count = 0;
   while (temp != NULL)
   {
      count++;
      if (count == k)
         break;
      temp = temp->next;
   }
   Node *front = temp->next;
   Node *newNode = new Node(val, temp->next, temp);
   front->back = newNode;
   temp->next = newNode;

   return head;
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5};
   Node *head = convertArr_to_DLL(arr);
   print(head);

   head = insertBeforeKthElement(head, 3, 100);
   cout << "before 3rd position: ";
   print(head);
   head = insertAfterKthElement(head, 4, 100);
   cout << "before 4rd position: ";
   print(head);

   return 0;
}
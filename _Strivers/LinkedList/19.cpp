// Insert before and after a given "NODE"

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
void insertBeforeNode(Node *node, int val)
{
   if (node == nullptr)
      return; // safety

   // Case 1: node is the head (no back)
   if (node->back == nullptr)
   {
      Node *newNode = new Node(val, node, nullptr);
      node->back = newNode;
      return;
   }

   // Case 2: node is in the middle
   Node *prev = node->back;
   Node *newNode = new Node(val, node, prev);
   prev->next = newNode;
   node->back = newNode;
}

void insertAfterNode(Node *node, int val)
{
   if (node == nullptr)
      return; // safety

   // Case 1: node is the tail (no next)
   if (node->next == nullptr)
   {
      Node *newNode = new Node(val, nullptr, node);
      node->next = newNode;
      return;
   }

   // Case 2: node is in the middle
   Node *front = node->next;
   Node *newNode = new Node(val, front, node);
   front->back = newNode;
   node->next = newNode;
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5};
   Node *head = convertArr_to_DLL(arr);
   print(head);

   insertBeforeNode(head->next, 100);
   cout << "before 2: ";
   print(head);
   insertAfterNode(head->next->next, 100);
   cout << "after 2: ";

   print(head);

   return 0;
}
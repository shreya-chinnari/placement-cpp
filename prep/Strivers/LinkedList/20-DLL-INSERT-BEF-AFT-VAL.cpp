// INSERTION before and after a given value

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
Node *insertBeforeValue(Node *head, int key, int val)
{
   Node *temp = head; // Start from the head of the list

   // Traverse until the key is found or end is reached
   while (temp != nullptr && temp->data != key)
   {
      temp = temp->next; // Move forward through the list
   }

   // If key is not found in the list
   if (temp == nullptr)
   {
      return head; // Return the original head without any change
   }

   // Create a new node with value 'val', placed before 'temp'
   // temp is the node whose value matches 'key'
   Node *newNode = new Node(val, temp, temp->back);

   if (temp->back != nullptr)
   {
      // temp is not the head, so update its previous node to point to newNode
      temp->back->next = newNode;
   }
   else
   {
      // temp was the head, so update head to point to newNode
      head = newNode;
   }

   // In both cases, update temp's back to newNode
   temp->back = newNode;

   return head; // Return the updated head of the list
}
Node *insertAfterValue(Node *head, int key, int val)
{
   Node *curr = head; // Start from head of the list

   // Traverse the list to find node with data == key
   while (curr != nullptr && curr->data != key)
   {
      curr = curr->next; // Move forward
   }

   // If key is not found, return unchanged list
   if (curr == nullptr)
   {
      return head;
   }

   // Create a new node with value 'val', inserted after 'curr'
   Node *newNode = new Node(val, curr->next, curr);

   if (curr->next != nullptr)
   {
      // If curr is not the last node, update the next node's back pointer
      curr->next->back = newNode;
   }

   // Link curr to newNode
   curr->next = newNode;

   return head; // Return head of the updated list
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5};
   Node *head = convertArr_to_DLL(arr);
   print(head);

   insertBeforeValue(head, 3, 100);
   cout << "before 3: ";
   print(head);
   insertAfterValue(head, 3, 100);
   cout << "after 3: ";
   print(head);

   return 0;
}
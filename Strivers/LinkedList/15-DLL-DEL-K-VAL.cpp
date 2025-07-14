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

Node *deleteHead(Node *head)
{

   if (head == NULL || head->next == NULL)
   {
      return NULL;
   }

   Node *prev = head;
   head = head->next;
   head->back = nullptr;
   prev->next = nullptr;
   delete prev;

   return head;
}

Node *deleteTail(Node *head)
{

   if (head == NULL || head->next == NULL)
   {
      return NULL;
   }

   Node *tail = head;

   while (tail->next != NULL)
   {
      tail = tail->next;
   }

   Node *newTail = tail->back;
   newTail->next = tail;
   tail->back = NULL;
   newTail->next = NULL;
   delete (tail);

   return head;
}

// LOGIC ---------------------------------

void deleteValue(Node *val)
{
   // if "val" is  a nullptr
   if (val == nullptr)
      return;

   // set 2 pointers which "val" can point to and then delete them to isolate "val"
   Node *prev = val->back;
   Node *front = val->next;

   if (front == NULL) // if "val" is the LAST node
   {
      prev->next = nullptr;
      val->back = nullptr;
      free(val);
      return;
   }
   // if "val" is in middle somewhere
   prev->next = front;
   front->back = prev;
   val->next = val->back = nullptr;
   free(val);
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5};
   Node *head = convertArr_to_DLL(arr);
   print(head);

   deleteValue(head->next->next); // delete "3"
   cout << "deleting 3    ";
   print(head);

   return 0;
}
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

Node *delete_at_position(Node *head, int k)
{

   // CASE 1: IF EMPTY LL
   if (head == NULL)
   {
      return NULL;
   }
   // IF LL IS NOT EMPTY, TRAVERSE TO K-th POSITION
   int count = 0;
   Node *kNode = head; // helper pointer
   while (kNode != NULL)
   {
      count++;
      if (count == k)
         break;            // found the K-th node
      kNode = kNode->next; // if not found, traverse to next node
   }
   // after finding the K-th node
   Node *prev = kNode->back;
   Node *front = kNode->next;

   // CASE 2: IF K-th element is the ONLY element
   if (prev == NULL && front == NULL)
   {
      return NULL; // delete it
   }

   // CASE 3: IF k=1 {starting of LL}
   else if (prev == NULL)
   {
      return deleteHead(head);
   }

   // CASE 4: IF k=last {ending of LL}
   else if (front == NULL)
   {
      return deleteTail(head);
   }

   // CASE 5: IF k is in middle somewhere
   prev->next = front;
   front->back = prev; // link prev and front, isolate original k-th lement
   kNode->next = nullptr;
   kNode->back = nullptr;

   delete kNode;
   return head;
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5};
   Node *head = convertArr_to_DLL(arr);
   print(head);

   head = delete_at_position(head, 3);
   cout << "deleting 3rd element     ";
   print(head);

   return 0;
}
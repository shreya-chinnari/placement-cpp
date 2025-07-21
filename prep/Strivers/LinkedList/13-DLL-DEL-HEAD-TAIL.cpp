// delete node {head, tail}

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

// Delete HEAD ---------------------------------
Node *deleteHead(Node *head)
{
   // empty DLL || 1 element in DLL
   if (head == NULL || head->next == NULL)
   {
      return NULL; // if empty then nothing to delete || if 1 element only then it gets deleted and nothing to return
   }

   // >1 elements
   Node *prev = head;
   head = head->next;    // shift head to 2nd position
   head->back = nullptr; // detach from original head
   prev->next = nullptr; // detach original head from new head
   delete prev;          // free the original head

   return head;
}

// Delete TAIL ---------------------------------
Node *deleteTail(Node *head)
{
   // empty DLL || 1 element in DLL
   if (head == NULL || head->next == NULL)
   {
      return NULL; // if empty then nothing to delete || if 1 element only then it gets deleted and nothing to return
   }

   // >1 elements
   Node *tail = head;
   // first traverse to Tail
   while (tail->next != NULL)
   {
      tail = tail->next; // keep iterating to next nodes till reach the TAIL
   }
   // when reached the Tail :
   Node *newTail = tail->back; // second last element
   newTail->next = tail;
   tail->back = NULL;
   newTail->next = NULL; // it becomes the last element
   delete (tail);

   return head;
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5};
   Node *head = convertArr_to_DLL(arr);
   print(head);

   head = deleteHead(head);
   cout << "deleting head     ";
   print(head);

   head = deleteTail(head);
   cout << "deleting tail     ";
   print(head);

   return 0;
}
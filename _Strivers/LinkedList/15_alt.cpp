#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
   Node *back;

   Node(int data1, Node *next1 = nullptr, Node *back1 = nullptr)
   {
      data = data1;
      next = next1;
      back = back1;
   }
};

Node *convertArr_to_DLL(vector<int> &arr)
{
   Node *head = new Node(arr[0]);
   Node *prev = head;

   for (int i = 1; i < arr.size(); i++)
   {
      Node *newNode = new Node(arr[i], nullptr, prev);
      prev->next = newNode;
      prev = newNode;
   }
   return head;
}

void print(Node *head)
{
   cout << "LL ->   ";
   while (head != nullptr)
   {
      cout << head->data << "  ";
      head = head->next;
   }
   cout << endl;
}

// Deletes the given node (assumes pointer to node is given)
Node *deleteGivenNode(Node *head, Node *target)
{
   if (target == nullptr)
      return head;

   // Case 1: Deleting the head
   if (target->back == nullptr)
   {
      Node *newHead = target->next;
      if (newHead != nullptr)
         newHead->back = nullptr;
      delete target;
      return newHead;
   }

   // Case 2: Deleting the tail
   if (target->next == nullptr)
   {
      target->back->next = nullptr;
      delete target;
      return head;
   }

   // Case 3: Deleting from middle
   Node *prev = target->back;
   Node *next = target->next;

   prev->next = next;
   next->back = prev;

   delete target;
   return head;
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5};
   Node *head = convertArr_to_DLL(arr);
   print(head);

   // Delete node with value 3 (i.e., 3rd node)
   Node *nodeToDelete = head->next->next;
   head = deleteGivenNode(head, nodeToDelete);
   cout << "After deleting 3: ";
   print(head);

   return 0;
}

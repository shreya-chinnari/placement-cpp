// delete a particular value

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

Node *removeElement(Node *head, int el)
{
   // if LL is empty itself
   if (head == NULL)
      return head;

   // if "el" is 1 {first element}
   if (head->data == el)
   {
      Node *temp = head;
      head = head->next;
      free(temp);
      return head;
   }

   // "el" at other positions - USE LINEAR SEARCH

   Node *temp = head;
   Node *prev = NULL;
   while (temp != NULL)
   {
      // if you find the element
      if (temp->data == el)
      {
         prev->next = prev->next->next;
         delete (temp);
         break;
      }
      // otherwise {if element not found}, shift to next set of elements to analyse
      prev = temp;
      temp = temp->next;
   }

   return head;
};

int main()
{
   vector<int> arr = {6, 3, 9, 5, 0};
   Node *head = convertARRtoLL(arr);

   printLL(head);
   head = removeElement(head, 3);
   cout << "removing '3' : ";
   printLL(head);

   return 0;
}
// delete (k)th element

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

Node *remove_Kth_element(Node *head, int k)
{
   // if LL is empty itself
   if (head == NULL)
      return head;

   // if k is 1 {first element}
   if (k == 1)
   {
      Node *temp = head;
      head = head->next;
      free(temp);
      return head;
   }

   // Kth element
   int count = 0;     // finding the index
   Node *temp = head; // copy of head
   Node *prev = NULL; // helper pointer
   while (temp != NULL)
   {
      count++; // incremenet the index to reach KEY index

      // if you find the Kth element
      if (count == k)
      {
         prev->next = prev->next->next; // prev will now point to the next to next element
         free(temp);
         break;
      }
      // otherwise {if Kth element not found}, shift to next set of elements to analyse
      prev = temp;
      temp = temp->next;
      prev = temp;
   }

   return head;
};

int main()
{
   vector<int> arr = {6, 3, 9, 5, 0};
   Node *head = convertARRtoLL(arr);

   printLL(head);
   head = remove_Kth_element(head, 3);
   cout << "removing 3rd element : ";
   printLL(head);

   return 0;
}
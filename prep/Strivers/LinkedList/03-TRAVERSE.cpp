// traversing the LL

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
   int data;
   Node *next;

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

int main()
{
   vector<int> arr = {6, 3, 9, 5, 0};
   Node *head = convertARRtoLL(arr);

   // traversing, accessing
   Node *temp = head;
   while (temp != nullptr)
   {
      cout << temp->data << " ";
      temp = temp->next; // accessing the next node
   }

   return 0;
}

// length of LL

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
// length
int lengthOfLL(Node *head)
{
   int count = 0;
   // traversing, accessing
   Node *temp = head;
   while (temp != nullptr)
   {
      temp = temp->next; // accessing the next node

      count++;
   }
   return count;
}

int main()
{
   vector<int> arr = {6, 3, 9, 5, 0};
   Node *head = convertARRtoLL(arr);

   cout << "length of LL: " << lengthOfLL(head);

   return 0;
}

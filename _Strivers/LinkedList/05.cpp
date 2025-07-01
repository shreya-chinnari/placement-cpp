// search in a LL
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
// search
int searchElement(Node *head, int val)
{
   // traversing, accessing
   Node *temp = head;
   while (temp != nullptr)
   {
      // logic
      if (temp->data == val)
         return 1;
      // accessing the next node
      temp = temp->next;
   }
   return 0;
}

int main()
{
   vector<int> arr = {6, 3, 9, 5, 0};
   Node *head = convertARRtoLL(arr);

   searchElement(head, 9) ? cout << "yes, it's there" << endl : cout << "element not found;" << endl;
   searchElement(head, 90) ? cout << "yes, it's there" << endl : cout << "element not found;" << endl;
   return 0;
}

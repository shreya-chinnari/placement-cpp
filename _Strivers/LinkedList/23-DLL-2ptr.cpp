// Odd-Even grouping in DLL using single pass 2 ptr method
// BETTER

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
   Node *back;

   Node(int val)
   {
      data = val;
      next = nullptr;
      back = nullptr;
   }
};

// Convert array to DLL
Node *convertArrToDLL(vector<int> &arr)
{
   if (arr.empty())
      return nullptr;
   Node *head = new Node(arr[0]);
   Node *curr = head;
   for (int i = 1; i < arr.size(); i++)
   {
      Node *temp = new Node(arr[i]);
      curr->next = temp;
      temp->back = curr;
      curr = temp;
   }
   return head;
}

// Print DLL
void printDLL(Node *head)
{
   while (head)
   {
      cout << head->data;
      if (head->next)
         cout << " <-> ";
      head = head->next;
   }
   cout << endl;
}

// One-pass O(1) space rearrangement
Node *groupOddEven_DLL(Node *head)
{
   if (!head || !head->next)
      return head; // empty or 1-node DLL

   Node *odd = head;        // pointer to current odd node
   Node *even = head->next; // pointer to current even node
   Node *evenHead = even;   // save head of even list for later merge

   while (even && even->next)
   {
      // Connect odd to next odd node
      odd->next = even->next;
      odd->next->back = odd;
      odd = odd->next;

      // Connect even to next even node
      even->next = odd->next;
      if (even->next)
      {
         even->next->back = even;
      }
      even = even->next;
   }

   // Merge even list after odd list
   odd->next = evenHead;
   if (evenHead)
      evenHead->back = odd;

   return head;
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
   Node *head = convertArrToDLL(arr);

   cout << "Original DLL: ";
   printDLL(head);

   head = groupOddEven_DLL(head);

   cout << "Grouped DLL (odd-even 1-pass): ";
   printDLL(head);

   return 0;
}

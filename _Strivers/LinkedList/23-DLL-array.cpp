// Grouping Odd-Even DLL - one-pass using arrays
// bruteeee forceeee

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

// 2-Pass odd-even using vector
Node *groupOddEven2Pass_DLL(Node *head)
{
   if (!head || !head->next)
      return head; // Edge case: empty or 1-node list

   vector<int> values;
   Node *odd = head;
   Node *even = head->next;

   // Pass 1: Collect odd-position values
   while (odd)
   {
      values.push_back(odd->data);
      if (odd->next)
         odd = odd->next->next;
      else
         break;
   }

   // Pass 2: Collect even-position values
   while (even)
   {
      values.push_back(even->data);
      if (even->next)
         even = even->next->next;
      else
         break;
   }

   // Overwrite data in original DLL nodes
   Node *temp = head;
   int i = 0;
   while (temp && i < values.size())
   {
      temp->data = values[i++];
      temp = temp->next;
   }
   return head;
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5, 6};
   Node *head = convertArrToDLL(arr);

   cout << "Original DLL: ";
   printDLL(head);

   head = groupOddEven2Pass_DLL(head);

   cout << "Grouped DLL (odd-even 2-pass): ";
   printDLL(head);

   return 0;
}

/*
Factor	          ::           Description

🔁 Time Complexity   ::	O(n) (2 passes for read, 1 pass for write)
📦 Space Complexity  ::	O(n) (extra vector to store node data)
✅ Pros  ::	Easy to implement, preserves original relative order
❌ Cons  ::	Not in-place (modifies data not links), not memory optimal
*/
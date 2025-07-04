// ODD EVEN SinglyLL
// one - pass logic with O(1) space.
// BETTER

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
   int data;
   Node *next;

   Node(int val)
   {
      data = val;
      next = nullptr;
   }
};

// Convert array to linked list
Node *convertArrToSLL(vector<int> &arr)
{
   if (arr.empty())
      return nullptr;

   Node *head = new Node(arr[0]);
   Node *current = head;
   for (int i = 1; i < arr.size(); i++)
   {
      current->next = new Node(arr[i]);
      current = current->next;
   }
   return head;
}

// Print SLL
void printList(Node *head)
{
   while (head)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << endl;
}

// Function to group odd-position and even-position nodes
Node *groupOddEven(Node *head)
{
   if (!head || !head->next)
      return head; // Empty or 1-node list

   Node *odd = head;        // starts at i=1
   Node *even = head->next; // starts at i=2
   Node *evenHead = even;   // Save head of even list to attach later

   // Grouping in O(n/2)x2=O(n) time
   // SC: O(1)

   while (even && even->next) // not NULL, because even comes after odd so need to check only this
   {
      // odd->next = even->next; // Link odd to next odd
      // odd = odd->next;
      // even->next = odd->next; // Link even to next even
      // even = even->next;

      odd->next = odd->next->next;
      even->next = even->next->next;
      odd = odd->next;
      even = even->next;
   }

   odd->next = evenHead; // Append even list after odd list
   return head;
}

// Driver code
int main()
{
   vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   Node *head = convertArrToSLL(arr);

   cout << "Original List: ";
   printList(head);

   head = groupOddEven(head);
   cout << "Grouped (odd-even): ";
   printList(head);

   return 0;
}

/*
✅ Logic:
Use two pointers: odd and even to build two separate chains.
Stitch even list after the odd list.
Do this in one traversal without using any extra space.

📌 Pros:
In-place solution — rearranges pointers, doesn't change node data.
No extra memory used (O(1) space).
Single pass — O(n) time complexity.

❌ Cons:
Slightly more pointer manipulation logic (but still efficient and clean).

*/
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

// Print linked list
void printList(Node *head)
{
   while (head)
   {
      cout << head->data;
      if (head->next)
         cout << " -> ";
      head = head->next;
   }
   cout << endl;
}

// Odd-even position grouping
Node *groupOddEven2Pass(Node *head)
{
   if (head == NULL || head->next == NULL) // empty LL OR single element
      return head;

   vector<int> arr;

   // TC : O(n/2)
   // First pass: Add odd-indexed nodes (1st, 3rd, 5th...)
   Node *tempOdd = head;
   while (tempOdd != NULL && tempOdd->next != NULL)
   {
      arr.push_back(tempOdd->data);
      tempOdd = tempOdd->next->next; // ODD index elements
   }
   if (tempOdd)
   {
      arr.push_back(tempOdd->data); // in case of odd lemgth of LL, to include the last element
   }
   // TC : O(n/2)
   // Second pass: Add even-indexed nodes (2nd, 4th, 6th...)
   Node *tempEven = head->next; // start from 2nd element
   while (tempEven != NULL && tempEven->next != NULL)
   {
      arr.push_back(tempEven->data);
      tempEven = tempEven->next->next; // EVEN index elements
   }
   if (tempEven)
   {
      arr.push_back(tempEven->data); // in case of even lemgth of LL, to include the last element
   }
   // Now convert the array to LL { // Write back data from arr to list nodes}
   // TC : O(n)
   int i = 0;
   Node *temp = head;
   while (temp != NULL)
   {
      temp->data = arr[i];
      i++;
      temp = temp->next;
   }
   return head;
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   Node *head = convertArrToSLL(arr);

   cout << "Original List: ";
   printList(head);

   head = groupOddEven2Pass(head);
   cout << "Grouped (odd-even): ";
   printList(head);

   return 0;
}

// total TC : O(2n)
// total SC : O(n)

// now we have to optmise the external space

/*

✅ Logic:
First, collect odd-indexed elements into a vector.
Then collect even-indexed elements into the same vector.
Finally, overwrite the original linked list's node data with values from the vector.

📌 Pros:
Simple to understand.
Order is preserved: odd-indexed values come before even-indexed ones.

❌ Cons:
Extra space (O(n)): vector<int> arr stores all node values.
Not in-place: you're mutating data, not rearranging pointers.
Time Complexity: O(n) (two passes + final rewrite)
Space Complexity: O(n) (for storing elements in a vector)

*/
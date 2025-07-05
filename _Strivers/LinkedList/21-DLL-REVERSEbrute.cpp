// Reverse a DLL

// stack-based approach {brute}

// First pass : Push all node values into a stack(LIFO).
// Second pass : Pop from the stack and overwrite the nodes’ values in order.
// This reverses the values(not the pointers) of the DLL.

#include <iostream>
#include <vector>
#include <stack>
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

// Convert array to DLL
Node *convertArr_to_DLL(vector<int> &arr)
{
   if (arr.empty())
      return nullptr;

   Node *head = new Node(arr[0]);
   Node *prev = head;

   for (int i = 1; i < arr.size(); i++)
   {
      Node *temp = new Node(arr[i], nullptr, prev);
      prev->next = temp;
      prev = temp;
   }
   return head;
}

// Print DLL
void print(Node *head)
{
   cout << "DLL -> ";
   while (head != nullptr)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << endl;
}

// Reverse DLL using a stack (value swap method)
void reverseDLL(Node *head)
{
   if (head == nullptr)
      return;

   stack<int> st;
   Node *temp = head;

   // First pass: push all node values into the stack
   while (temp != nullptr)
   {
      st.push(temp->data);
      temp = temp->next;
   }

   // Second pass: overwrite nodes with values from the stack
   temp = head;
   while (temp != nullptr)
   {
      temp->data = st.top();
      st.pop();
      temp = temp->next;
   }
}

int main()
{
   vector<int> arr = {10, 20, 30, 40, 50};
   Node *head = convertArr_to_DLL(arr);

   cout << "Original DLL: ";
   print(head);

   reverseDLL(head);

   cout << "Reversed DLL (values): ";
   print(head);

   return 0;
}

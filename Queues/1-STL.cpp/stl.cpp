#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
   // ======================
   // QUEUE DEMONSTRATION
   // ======================
   queue<int> q;
   cout << "===== QUEUE DEMONSTRATION (FIFO) =====\n";

   q.push(11);
   cout << "Pushed 11 -> front: " << q.front() << ", back: " << q.back() << ", size: " << q.size() << endl;

   q.push(15);
   cout << "Pushed 15 -> front: " << q.front() << ", back: " << q.back() << ", size: " << q.size() << endl;

   q.push(13);
   cout << "Pushed 13 -> front: " << q.front() << ", back: " << q.back() << ", size: " << q.size() << endl;

   cout << "Popping elements from queue:\n";
   while (!q.empty())
   {
      cout << "Front element: " << q.front() << ", Back element: " << q.back() << " (removing front)\n";
      q.pop();
      if (!q.empty())
         cout << "Now -> front: " << q.front() << ", back: " << q.back() << ", size: " << q.size() << endl;
   }
   cout << "Queue is empty now.\n\n";

   // ======================
   // STACK DEMONSTRATION
   // ======================
   stack<int> st;
   cout << "===== STACK DEMONSTRATION (LIFO) =====\n";

   st.push(11);
   cout << "Pushed 11 -> top: " << st.top() << ", size: " << st.size() << endl;

   st.push(15);
   cout << "Pushed 15 -> top: " << st.top() << ", size: " << st.size() << endl;

   st.push(13);
   cout << "Pushed 13 -> top: " << st.top() << ", size: " << st.size() << endl;

   cout << "Popping elements from stack:\n";
   while (!st.empty())
   {
      cout << "Top element: " << st.top() << " (removing top)\n";
      st.pop();
      if (!st.empty())
         cout << "Now -> top: " << st.top() << ", size: " << st.size() << endl;
   }
   cout << "Stack is empty now.\n";

   return 0;
}

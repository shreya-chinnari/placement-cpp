#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

class MinStack
{
   stack<pair<int, int>> st; // {value, currentMin}

public:
   void push(int val)
   {
      if (st.empty())
      {
         st.push({val, val});
      }
      else
      {
         int currentMin = min(val, st.top().second);
         st.push({val, currentMin});
      }
   }

   void pop()
   {
      if (!st.empty())
      {
         st.pop();
      }
   }

   int top()
   {
      return st.top().first;
   }

   int getMin()
   {
      return st.top().second;
   }

   bool empty()
   {
      return st.empty();
   }
};

int main()
{
   MinStack st;
   st.push(5);
   st.push(3);
   st.push(7);

   cout << "Min: " << st.getMin() << endl; // 3
   st.pop();
   cout << "Min after one pop: " << st.getMin() << endl; // 3
   st.pop();
   cout << "Min after two pops: " << st.getMin() << endl; // 5

   return 0;
}
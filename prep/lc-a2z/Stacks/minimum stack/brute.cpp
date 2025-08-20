// Every time we push a value, we also store the minimum so far at that moment

// We use a stack<pair<int, int>> st;
// where :
//     pair.first → the element pushed
//     pair.second → the minimum element so far(at the moment this element was pushed)

// When pushing:
// >>> If stack is empty → the current minimum is the element itself.
// >>> If stack is not empty → compare the new value with the previous
//       min(st.top().second) and
//       store the smaller one as the new min.

//  When popping :
//  >>> Just pop the top — since both value and min at that point are stored together.

#include <bits/stdc++.h>
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
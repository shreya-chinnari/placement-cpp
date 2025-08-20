#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string s, int k)
{
   stack<char> st;
   int n = s.size();

   // edge case 1: if k==n, then all elements will be removed
   if (k == n)
      return "0";

   for (int i = 0; i < n; i++)
   {
      // while there are still elements in stack,
      // and we have to remove more digits,
      // and the current digit of string is smaller than the top of the stack
      while (!st.empty() && k > 0 && (st.top() - '0') > (s[i] - '0'))
      {
         st.pop();
         k--;
      }
      st.push(s[i]);
   }
   // if we have more digits to remove
   while (k > 0)
   {
      st.pop();
      k--;
   }

   // transfer all elements from stack to a string
   string res = "";
   while (!st.empty())
   {
      res = res + st.top();
      st.pop();
   }

   // edge case 2: Leading zeroes {2349000}
   while (res.size() != 0 && res.back() == '0')
   {
      res.pop_back();
   }
   // reverse the string
   reverse(res.begin(), res.end());

   // edge case 3: if the stack had all zeroes then they will all be popped out in previous step and stack will be empty
   if (res.empty())
   {
      return "0";
   }

   return res;
}

int main()
{
   vector<pair<string, int>> tests = {
       {"1432219", 3}, // normal case → "1219"
       {"10200", 1},   // leading zeros → "200"
       {"10", 2},      // all digits removed → "0"
       {"123456", 2},  // strictly increasing → remove last digits
       {"987654", 2},  // strictly decreasing → remove first digits
       {"100200", 1},  // multiple zeros → "200"
       {"9", 1},       // single digit removed → "0"
       {"112", 1}      // duplicates → "11"
   };

   for (auto &t : tests)
   {
      cout << "Input: " << t.first << ", k=" << t.second
           << " -> Output: " << removeKdigits(t.first, t.second) << endl;
   }

   return 0;
}

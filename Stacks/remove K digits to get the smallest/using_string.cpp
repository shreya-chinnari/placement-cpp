#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string s, int k)
{
   string res = ""; // acts like a stack

   for (char c : s)
   {
      while (!res.empty() && k > 0 && res.back() > c)
      {
         res.pop_back();
         k--;
      }
      res.push_back(c);
   }

   // If still have digits to remove (monotonic increasing case)
   while (k > 0 && !res.empty())
   {
      res.pop_back();
      k--;
   }

   // Remove leading zeros
   int start = 0;
   while (start < (int)res.size() && res[start] == '0')
   {
      start++;
   }
   res = res.substr(start);

   return res.empty() ? "0" : res;
}

int main()
{
   vector<pair<string, int>> tests = {
       {"1432219", 3}, // normal case → "1219"
       {"10200", 1},   // leading zeros → "200"
       {"10", 2},      // all digits removed → "0"
       {"123456", 2},  // strictly increasing → "1234"
       {"987654", 2},  // strictly decreasing → "7654"
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

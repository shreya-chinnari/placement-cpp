#include <bits/stdc++.h>
#include <string>
using namespace std;

/*
> Whenever we get the opening bracket we will push it into the stack. I.e ‘{‘, ’[’, ’(‘.
> Whenever we get the closing bracket we will check if the stack is non-empty or not.
> If the stack is empty we will return false, else if it is nonempty then we will check if the topmost element of the stack is the opposite pair of the closing bracket or not.
> If it is not the opposite pair of the closing bracket then return false, else move ahead.
> After we move out of the string the stack has to be empty if it is non-empty then return it as invalid else it is a valid string.
*/

bool balanced(string s)
{
   stack<char> st;

   for (auto it : s)
   {
      // push opening brackets onto the stack
      if (it == '(' || it == '[' || it == '{')
      {
         st.push(it);
      }

      // if it's a closing bracket
      else
      {
         // if stack is empty, no opening bracket to match with, no valid pair
         if (st.empty())
            return false;

         // pop the top element (opening bracket) and check if it matches with the current closing bracket
         char ch = st.top();
         st.pop();
         if ((it == ')' && ch == '(') || (it == ']' && ch == '[') || (it == '}' && ch == '{'))
         {
            continue;
         }

         // if opening bracket doesn't match, return false
         else
            return false;
      }
   }
   // if stack is empty after processing the string, all brackets matched correctly - True
   // if not empty, it means there are unmatched opening brackets left - False
   return st.empty();
}

int main()
{
   // balanced
   string s = "()[{}()]";
   if (balanced(s))
      cout << "True" << endl;
   else
      cout << "False" << endl;

   // opening bracket left
   s = "({[]}";
   if (balanced(s))
      cout
          << "True" << endl;
   else
      cout << "False" << endl;

   // no closing bracket, only opening brackets in stack
   s = "((((";
   if (balanced(s))
      cout
          << "True" << endl;
   else
      cout << "False" << endl;

   // no opening bracket, nothing to match with because stack is empty
   s = "])}";
   if (balanced(s))
      cout
          << "True" << endl;
   else
      cout << "False" << endl;
}
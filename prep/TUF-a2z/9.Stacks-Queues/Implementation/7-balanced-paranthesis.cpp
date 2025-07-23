#include <bits/stdc++.h>
// Includes all standard C++ libraries (not recommended for production but convenient in contests/learning).

using namespace std;
// Allows use of standard library types (like string, stack, vector, etc.) without the std:: prefix.

bool isValid(string s)
{
   stack<char> st;
   // Stack to keep track of opening brackets. LIFO helps match brackets in correct order.

   for (size_t i = 0; i < s.size(); ++i)
   {
      // Iterates over each character of the input string using an index-based loop.
      // 'i' is the current character position in the string.

      char it = s[i];
      // 'it' holds the current character from the string for processing.

      if (it == '(' || it == '{' || it == '[')
      {
         // If the character is an opening bracket, we push it to the stack.

         st.push(it);
         // Push the opening bracket onto the stack to be matched later with its corresponding closing bracket.
      }
      else
      {
         // This block handles closing brackets: ')', '}', or ']'.

         if (st.empty())
            return false;
         // If the stack is empty, there's no matching opening bracket for this closing one — invalid string.

         char ch = st.top();
         // Get the most recent opening bracket from the top of the stack.

         st.pop();
         // Remove the top bracket from the stack as we're going to validate it now.

         if ((it == ')' && ch == '(') || (it == ']' && ch == '[') || (it == '}' && ch == '{'))
         {
            // Checks if the current closing bracket 'it' correctly matches the last opening bracket 'ch'.
            continue;
            // If matched, move to the next character in the string.
         }
         else
         {
            return false;
            // If the brackets don't match (e.g., '(' with ']' or similar), the string is invalid.
         }
      }
   }

   return st.empty();
   // After processing all characters:
   // - If stack is empty → all brackets were matched → return true.
   // - If stack is not empty → there are unmatched opening brackets → return false.
}

int main()
{
   string s1 = "()[{}()]";
   if (isValid(s1))
      cout << "True" << endl;
   else
      cout << "False" << endl;

   string s2 = "()[{()]";
   if (isValid(s2))
      cout << "True" << endl;
   else
      cout << "False" << endl;
}
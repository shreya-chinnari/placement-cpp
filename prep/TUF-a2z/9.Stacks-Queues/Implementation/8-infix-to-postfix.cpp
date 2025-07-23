/*
if (c is a letter or digit)
    append it to the result string


else if (c == '(')
    push it to the stack


else if (c == ')')
    pop from stack to result until you hit '('
    then pop the '(' itself


else {
    while (stack is not empty AND
           precedence of current operator <= precedence of top of stack)
        pop from stack to result

    push current operator to stack
}

while (stack not empty)
    pop everything to the result

*/

// TC : O(N) + O(N)
// SC : O(N) + O(N)

#include <bits/stdc++.h> // Includes *all* standard libraries — useful for contests, avoid in production
using namespace std;     // Brings all std symbols into current namespace (again, fine for quick scripts)

// Function to return precedence (priority) of operators
int priority(char c)
{
   if (c == '^') // Exponent has the highest precedence
      return 3;
   else if (c == '/' || c == '*') // Division and multiplication have medium precedence
      return 2;
   else if (c == '+' || c == '-') // Addition and subtraction have lowest among binary ops
      return 1;
   else
      return -1; // Non-operator characters return -1 (e.g., parentheses)
}

// Main function that converts an infix expression to postfix form
void infixToPostfix(string s)
{
   stack<char> st; // Stack to hold operators and parentheses during conversion
   string ans;     // This will store the final postfix expression

   for (int i = 0; i < s.length(); i++)
   {
      char c = s[i]; // Current character in the infix string

      // Step 1: If it's an operand, append it directly to ans ---------------------------------------------

      if ((c >= 'a' && c <= 'z') ||
          (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9'))
         ans += c;

      // Step 2: Handle opening parenthesis ---------------------------------------------

      else if (c == '(')
         st.push('('); // Opening bracket just gets pushed to stack, used to isolate sub-expressions

      // Step 3: Handle closing parenthesis ---------------------------------------------
      else if (c == ')')
      {
         while (st.top() != '(')
         { // Pop all operators till we find the matching '('
            ans += st.top();
            st.pop();
         }
         st.pop(); // Pop the '(' itself but don't add it to ans
         // Matching pair found — now the enclosed sub-expression has been processed.
      }

      // Step 4: Handle operators (+, -, *, /, ^) ---------------------------------------------
      // Ensures that operators with higher precedence are placed earlier in the postfix expression.

      else
      {
         // While top of stack has **higher or equal** precedence, pop it to ans
         while (!st.empty() && priority(s[i]) <= priority(st.top()))
         {
            ans += st.top();
            st.pop();
         }
         st.push(c); // Push the current operator to the stack
      }
   }

   // Step 5: Pop any remaining operators from the stack ---------------------------------------------

   while (!st.empty())
   {
      ans += st.top(); // Pop remaining operators to ans
      st.pop();
   }

   cout << "Prefix expression: " << ans << endl;
   // At this point, all operands are in the correct order in the ans.
}

int main()
{
   string exp = "(p+q)*(m-n)";
   cout << "Infix expression: " << exp << endl;
   infixToPostfix(exp);
   return 0;
}

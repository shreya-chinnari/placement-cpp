/*
1. Reverse infix
2. Replace '(' with ')' and vice versa
3. Convert to postfix (on reversed input)
4. Reverse postfix → final result is prefix

------------------------------------------------------------------
Infix: (A + B) * (C - D)

Postfix: AB+CD-*

Prefix: *+AB-CD ← which is just the reversed postfix of the reversed expression!
------------------------------------------------------------------

// Add opening and closing parentheses to the input
infix = '(' + infix + ')'

// Loop through every character in the expression:
for each character `c` in infix:

    if (c is a letter or digit)
        append it to result string

    else if (c == '(')
        push it to stack

    else if (c == ')')
        while (stack.top != '(')
            pop from stack and add to result
        pop '(' from the stack (don't add to result)

    else if (c is an operator):
        if (top of stack is also operator):
            if (current operator is ^): // right associative
                while (priority(curr) <= priority(top of stack)):
                    pop to result
            else:  // all others are left associative
                while (priority(curr) < priority(top of stack)):
                    pop to result
        push current operator to stack

after loop:
    pop any remaining operators to result

*/

#include <bits/stdc++.h>
using namespace std;

// Helper: checks if a character is an operator (i.e., not a letter or number)
bool isOperator(char c)
{
   return (!isalpha(c) && !isdigit(c));
}

// Helper: returns the precedence of the operator
int getPriority(char C)
{
   if (C == '-' || C == '+')
      return 1;
   else if (C == '*' || C == '/')
      return 2;
   else if (C == '^')
      return 3;
   return 0; // for non-operators
}

// 🔁 Convert Infix ➝ Postfix
string infixToPostfix(string infix)
{
   // Add outer parentheses for easier parsing
   infix = '(' + infix + ')';
   int l = infix.size();
   stack<char> char_stack; // Stack to hold operators and brackets
   string output;          // Final postfix output string

   for (int i = 0; i < l; i++)
   {
      char c = infix[i];

      // Case 1: If it's a letter or digit (operand)
      if (isalpha(c) || isdigit(c))
      {
         output += c;
      }

      // Case 2: Opening parenthesis → push to stack
      else if (c == '(')
      {
         char_stack.push(c);
      }

      // Case 3: Closing parenthesis → pop until '('
      else if (c == ')')
      {
         while (char_stack.top() != '(')
         {
            output += char_stack.top();
            char_stack.pop();
         }
         char_stack.pop(); // remove '('
      }

      // Case 4: Operator encountered
      else
      {
         // Only if stack top is an operator (not a '(')
         if (isOperator(char_stack.top()))
         {

            // Right-associative (e.g., ^)
            if (c == '^')
            {
               while (getPriority(c) <= getPriority(char_stack.top()))
               {
                  output += char_stack.top();
                  char_stack.pop();
               }
            }
            // Left-associative (e.g., +, -, *, /)
            else
            {
               while (getPriority(c) < getPriority(char_stack.top()))
               {
                  output += char_stack.top();
                  char_stack.pop();
               }
            }
         }
         // Push current operator to stack
         char_stack.push(c);
      }
   }

   // Pop anything left on the stack
   while (!char_stack.empty())
   {
      output += char_stack.top();
      char_stack.pop();
   }

   return output;
}

// 🔁 Convert Infix ➝ Prefix (by reversing + transforming)
string infixToPrefix(string infix)
{
   // Step 1: Reverse the infix expression
   reverse(infix.begin(), infix.end());

   // Step 2: Replace '(' with ')' and vice versa
   for (int i = 0; i < infix.size(); i++)
   {
      if (infix[i] == '(')
         infix[i] = ')';
      else if (infix[i] == ')')
         infix[i] = '(';
   }

   // Step 3: Convert the modified expression to postfix
   string prefix = infixToPostfix(infix);

   // Step 4: Reverse the result to get the prefix expression
   reverse(prefix.begin(), prefix.end());

   return prefix;
}

int main()
{
   string s = "(p+q)*(c-d)";

   cout << "Infix expression: " << s << endl;
   cout << "Prefix Expression: " << infixToPrefix(s) << endl;

   return 0;
}

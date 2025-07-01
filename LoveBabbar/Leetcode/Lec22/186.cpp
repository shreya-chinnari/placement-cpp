// reverse words in a string
/*
The problem is about reversing the order of words in a given character array s in-place. Here's how we can solve this step by step:

- Understand "in-place": We need to perform the reversal without allocating extra space for a new data structure. 
- This means modifying the existing character array s.

Reversal Strategy:
- Reverse the entire array s first. This brings all characters in reverse order, but the words will also be reversed.
- Reverse each individual word in the reversed array to restore their correct order.

Steps to Solve:

- Identify words using the single space as a delimiter.
- Reverse the entire array.
- Reverse each word found in the array.
*/
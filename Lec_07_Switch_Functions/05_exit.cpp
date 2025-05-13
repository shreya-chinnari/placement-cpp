// how to use exit() inside a switch statement to break out of an infinite while loop

#include <iostream>
#include <cstdlib> // Required for exit()

using namespace std;

int main()
{
   int choice;

   while (true)
   { // Infinite loop
      cout << "\nMenu:\n";
      cout << "1. Say Hello\n";
      cout << "2. Exit Program\n";
      cout << "Enter your choice: ";
      cin >> choice;

      switch (choice)
      {
      case 1:
         cout << "Hello!\n";
         break;

      case 2:
         cout << "Exiting program...\n";
         exit(0); // Exit the program immediately

      default:
         cout << "Invalid choice. Try again.\n";
      }
   }

   return 0; // This line is never reached
}

// In this example, the program will keep displaying the menu until the user chooses to exit by entering 2. The exit(0) function call will terminate the program immediately when the user selects that option.

/*
Menu:
1. Say Hello
2. Exit Program
Enter your choice: 1

   Hello!

Menu:
1. Say Hello
2. Exit Program
Enter your choice: 1

   Hello!

Menu:
1. Say Hello
2. Exit Program
Enter your choice: 1

   Hello!

Menu:
1. Say Hello
2. Exit Program
Enter your choice: 2

   Exiting program...

*/
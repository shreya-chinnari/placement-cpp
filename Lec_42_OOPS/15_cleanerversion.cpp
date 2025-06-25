#include <iostream>
#include <cstring> // For strlen and strcpy

class Person
{
private:
   char *name; // Member variable to store name

public:
   // Constructor that accepts a name and demonstrates two methods of memory allocation
   Person(const char *inputName)
   {
      // ----------- Method 1: Using this->name (Member variable) -----------
      // Allocate memory dynamically for the member variable `name`
      // +1 is for the null terminator '\0'
      this->name = new char[strlen(inputName) + 1];

      // Copy the input name into the memory allocated for the member variable
      strcpy(this->name, inputName);

      // At this point, `this->name` holds a deep copy of inputName tied to this object

      // ----------- Method 2: Using local pointer `ch` -----------
      // Allocate separate memory for a temporary local pointer `ch`
      char *ch = new char[strlen(inputName) + 1];

      // Copy the same input name into this new memory
      strcpy(ch, inputName);

      // `ch` is just a temporary pointer, independent of the object’s internal state

      // Clean up the memory allocated for `ch` immediately to avoid memory leak
      delete[] ch;

      // Note: We do not delete `this->name` here; it is part of the object and
      // will be deleted in the destructor
   }

   // Destructor to release the dynamically allocated memory for `this->name`
   ~Person()
   {
      delete[] name; // Clean up the member variable's memory
   }
};

int main()
{
   const char *sampleName = "Shreya";

   // Create a Person object with the name "Shreya"
   Person p(sampleName); // Constructor is called here

   // When main() ends, `p` goes out of scope and destructor is called
   return 0;
}

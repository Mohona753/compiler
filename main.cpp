#include <iostream>
#include <string>
using namespace std;

bool simulateDFA(string input) {
   int currentState = 0; // Start at State A
   if (input.length() == 0) {
       return true;
   }
   for (char symbol : input) {
       if (symbol != 'a' && symbol != 'b') {
           return false;
       }
       switch (currentState) {
           case 0: // State A (Initial/Final)
               currentState = (symbol == 'a') ? 1 : 2;
               break;
           case 1: // State B
               currentState = (symbol == 'a') ? 3 : 4;
               break;
           case 2: // State C
               currentState = (symbol == 'a') ? 5 : 6;
               break;
           case 3: // State D
               currentState = (symbol == 'a') ? 3 : 4;
               break;
           case 4: // State E (Final)
               currentState = (symbol == 'a') ? 5 : 6;
               break;
           case 5: // State F
               currentState = (symbol == 'a') ? 7 : 8;
               break;
           case 6: // State G (Final)
               currentState = (symbol == 'a') ? 5 : 6;
               break;
           case 7: // State H
               currentState = (symbol == 'a') ? 7 : 8;
               break;
           case 8: // State I (Final)
               currentState = (symbol == 'a') ? 7 : 8;
               break;
       }
   }
   return (currentState == 0 || currentState == 4 || currentState == 6 || currentState == 8);
}
int main() {
   string input;
   cout << " DFA Simulator (ab* + [a*(bb*)* + ab]+) " << endl;
   cout << "Press Enter on an empty line to test the null string." << endl;
   cout << "Type 'exit' to stop." << endl;
   while (true) {
       cout << "\nEnter string: ";
       getline(cin, input);
       if (input == "exit") break;
       if (simulateDFA(input)) {
           cout << "Result: ACCEPTED" << endl;
       } else {
           cout << "Result: REJECTED" << endl;
       }
   }
   return 0;
}

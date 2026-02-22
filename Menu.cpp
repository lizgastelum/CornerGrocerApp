#include "Menu.h"

#include <iostream>
#include <limits>

namespace corner_grocer {

void Menu::Print() {
  std::cout << "\n========== Corner Grocer Item Tracker ==========\n";
  std::cout << "1. Look up an item frequency\n";
  std::cout << "2. Print all item frequencies\n";
  std::cout << "3. Print histogram\n";
  std::cout << "4. Exit\n";
  std::cout << "===============================================\n";
}

int Menu::ReachChoice() {
  for (;;) {
    std::cout << "Select an option (1-4): ";

    int choice = 0;
    if (std::cin >> choice) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      if (choice >= 1 && choice <= 4) {
        return choice;
      }

      std::cout << "Error: please enter a number from 1 to 4.\n";
      continue;
    }

    // If extraction failed, clear error and consume the bad input line.
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Error: please enter a number from 1 to 4.\n";
  }
}

}  // namespace corner_grocer

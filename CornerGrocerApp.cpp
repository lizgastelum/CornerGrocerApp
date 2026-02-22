#include "CornerGrocerApp.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>
#include <utility>

#include "FrequencyBackupWriter.h"
#include "ItemFrequency.h"

namespace corner_grocer {

CornerGrocerApp::CornerGrocerApp(std::string input_path,
                                 std::string backup_path)
    : input_path_(std::move(input_path)),
      backup_path_(std::move(backup_path)) {}

bool CornerGrocerApp::Initialize() {
  // Load once at startup so menu actions are fast and consistent.
  if (!frequencies_.LoadFromFile(input_path_)) {
    std::cerr << "Error: could not open " << input_path_ << '\n';
    return false;
  }

  // Create the backup immediately so results persist outside of this run.
  if (!FrequencyBackupWriter::Write(backup_path_,
                                    frequencies_.GetAllCounts())) {
    std::cerr << "Error: could not write " << backup_path_ << '\n';
    return false;
  }

  return true;
}

void CornerGrocerApp::Run() {
  int choice = 0;

  while (true) {
    PrintMenu();

    std::cout << "Select option (1-4): ";
    std::cin >> choice;

    if (!std::cin) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input.\n";
      continue;
    }

    switch (choice) {
      case 1:
        HandleSearch();
        break;
      case 2:
        PrintAllFrequencies();
        break;
      case 3:
        PrintHistogram();
        break;
      case 4:
        std::cout << "Exiting program.\n";
        return;
      default:
        std::cout << "Invalid option.\n";
    }
  }
}

void CornerGrocerApp::PrintMenu() const {
  std::cout << "\n==== Corner Grocer Menu ====\n";
  std::cout << "1. Search for item frequency\n";
  std::cout << "2. Print all frequencies\n";
  std::cout << "3. Print histogram\n";
  std::cout << "4. Exit\n";
}

void CornerGrocerApp::HandleSearch() const {
  std::string item;
  std::cout << "Enter item name: ";
  std::cin >> item;

  int count = frequencies_.GetCount(item);

  std::cout << item << " purchased " << count << " time(s).\n";
}

void CornerGrocerApp::PrintAllFrequencies() const {
  const auto& data = frequencies_.GetAllCounts();

  for (const auto& [item, count] : data) {
    std::cout << item << " " << count << "\n";
  }
}

void CornerGrocerApp::PrintHistogram() const {
  const auto& data = frequencies_.GetAllCounts();

  for (const auto& [item, count] : data) {
    std::cout << item << " ";
    for (int i = 0; i < count; ++i) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}

}  // namespace corner_grocer

#include "CornerGrocerApp.h"

#include "FrequencyBackupWriter.h"
#include "FrequencyPrinter.h"
#include "Menu.h"

#include <iostream>
#include <string>
#include <utility>

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
  if (!FrequencyBackupWriter::Write(backup_path_, frequencies_.GetAllCounts())) {
    std::cerr << "Error: could not write " << backup_path_ << '\n';
    return false;
  }

  return true;
}

int CornerGrocerApp::Run() {
  if (!Initialize()) {
    return 1;
  }

  for (;;) {
    Menu::Print();
    const int choice = Menu::ReachChoice();

    if (choice == 1) {
      HandleLookup();
    } else if (choice == 2) {
      HandlePrintAll();
    } else if (choice == 3) {
      HandleHistogram();
    } else if (choice == 4) {
      std::cout << "Goodbye!\n";
    }
  }
}

void CornerGrocerApp::HandleLookup() const {
  std::cout << "Enter an item to look up: ";

  std::string item;
  std::getline(std::cin, item);

  // We treat an empty string as invalid because it doesn't represent an item.
  if (item.empty()) {
    std::cout << "Error: item cannot be empty.\n";
    return;
  }

  const int count = frequencies_.GetCount(item);
  std::cout << item << "; " << count << '\n';
}

void CornerGrocerApp::HandlePrintAll() const {
  FrequencyPrinter::PrintAll(frequencies_.GetAllCounts());
}

void CornerGrocerApp::HandleHistogram() const {
  FrequencyPrinter::PrintAll(frequencies_.GetAllCounts());
}

}  // namespace corner_grocer

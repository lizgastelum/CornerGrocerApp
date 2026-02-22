#ifndef CORNERGROCERAPP_CORNERGROCERAPP_H
#define CORNERGROCERAPP_CORNERGROCERAPP_H

#include <string>

#include "ItemFrequency.h"

namespace corner_grocer {
// Owns app lifecycle and high-level flow.
// Keeping orchestration here prevents main() from growing into a "god
// function".
class CornerGrocerApp {
 public:
  CornerGrocerApp(std::string input_path, std::string backup_path);

  // Runs the application menu loop and dispatches user actions.
  int Run();

 private:
  // Initializes the application state at startup (load input + write backup).
  bool Initialize();

  // Handles menu option 1: look up a single item.
  void HandleLookup() const;

  // Handles menu option 2: print all item frequencies.
  void HandlePrintAll() const;

  // Handles menu option 3: print a histogram of all frequencies.
  void HandleHistogram() const;

  std::string input_path_;
  std::string backup_path_;
  ItemFrequency frequencies_;
};

}  // namespace corner_grocer

#endif  // CORNERGROCERAPP_CORNERGROCERAPP_H

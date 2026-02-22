//
// Created by lizet on 2/20/2026.
//

#ifndef CORNERGROCERAPP_CORNERGROCERAPP_H
#define CORNERGROCERAPP_CORNERGROCERAPP_H

#include "ItemFrequency.h"

#include <string>

namespace corner_grocer {
// Owns app lifecycle and high-level flow.
// Keeping orchestration here prevents main() from growing into a "god
// function".
class CornerGrocerApp {
 public:
  CornerGrocerApp(std::string input_path, std::string backup_path);

  // Runs the application. For now, this just verifies startup.
  // Interactive menu will be added in later.
  int Run();

 private:
  bool Initialize();

  std::string input_path_;
  std::string backup_path_;
  ItemFrequency frequencies_;
};

}  // namespace corner_grocer

#endif  // CORNERGROCERAPP_CORNERGROCERAPP_H

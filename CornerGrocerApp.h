#ifndef CORNERGROCERAPP_CORNERGROCERAPP_H
#define CORNERGROCERAPP_CORNERGROCERAPP_H

#include <string>

#include "ItemFrequency.h"

namespace corner_grocer {
// Orchestrates application flow and user interaction.
class CornerGrocerApp {
 public:
  CornerGrocerApp(std::string input_path, std::string backup_path);

  bool Initialize();  // Loads file + writes backup.
  void Run();         // Starts menu loop.

 private:
  void PrintMenu() const;
  void HandleSearch() const;
  void PrintAllFrequencies() const;
  void PrintHistogram() const;

  std::string input_path_;
  std::string backup_path_;
  ItemFrequency frequencies_;
};

}  // namespace corner_grocer

#endif  // CORNERGROCERAPP_CORNERGROCERAPP_H

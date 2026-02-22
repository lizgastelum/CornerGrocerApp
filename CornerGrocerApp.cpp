#include "CornerGrocerApp.h"

#include "FrequencyBackupWriter.h"

#include <iostream>
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

  // Temporary confirmation output to verify the App wiring is correct.
  std::cout << "Loaded " << frequencies_.GetAllCounts().size()
  << " unique items.\n";

  return 0;
}

}  // namespace corner_grocer

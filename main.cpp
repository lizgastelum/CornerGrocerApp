#include "ItemFrequency.h"
#include "FrequencyBackupWriter.h"

#include <iostream>

int main() {
  corner_grocer::ItemFrequency freq;

  // Load all purchased items into memory before any menu/UI work.
  if (!freq.LoadFromFile("input.txt")) {
    std::cerr << "Error: could not open input.txt\n";
    return 1;
  }

  // Create a backup file at startup so data is preserved for later use.
  if (!corner_grocer::FrequencyBackupWriter::Write("frequency.dat",
                                                   freq.GetAllCounts())) {
    std::cerr << "Error: could not write frequency.dat\n";
    return 1;
  }

  std::cout << "Loaded " << freq.GetAllCounts().size() << " unique items.\n";
  return 0;
}
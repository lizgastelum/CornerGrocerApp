#include "ItemFrequency.h"

#include <filesystem>
#include <iostream>

int main() {
  corner_grocer::ItemFrequency freq;

  // Quick check to ensure file loading works.
  // Failing fast here saves time later when debugging.
  if (!freq.LoadFromFile("input.txt")) {
    std::cerr << "Error: could not open input.txt\n";
    return 1;
  }

  std::cout << "Loaded " << freq.GetAllCounts().size() << " unique items.\n";

  return 0;
}
#include "FrequencyPrinter.h"

#include <iostream>
#include <string>

namespace corner_grocer {

void FrequencyPrinter::PrintAll(
    const std::map<std::string, int>& item_to_count) {
  std::cout << "\nItem Frequencies\n";
  std::cout << "----------------\n";

  for (const auto& [item, count] : item_to_count) {
    std::cout << item << ' ' << count << '\n';
  }
}

void FrequencyPrinter::PrintHistogram(
    const std::map<std::string, int>& item_to_count) {
  std::cout << "\nHistogram\n";
  std::cout << "---------\n";

  for (const auto& [item, count] : item_to_count) {
    std::cout << item << ' ' << std::string(count, '*') << '\n';
  }
}

}  // namespace corner_grocer

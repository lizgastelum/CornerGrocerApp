#include "FrequencyPrinter.h"

#include <iomanip>
#include <iostream>
#include <string>

namespace corner_grocer {

void FrequencyPrinter::PrintAll(
    const std::map<std::string, int>& item_to_count) {
  std::cout << "\nItem Frequencies\n";
  std::cout << "----------------\n";

  constexpr int kNameWidth = 15;

  for (const auto& [item, count] : item_to_count) {
    std::cout << std::left << std::setw(kNameWidth) << item << count << '\n';
  }
}

void FrequencyPrinter::PrintHistogram(
    const std::map<std::string, int>& item_to_count) {
  std::cout << "\nHistogram\n";
  std::cout << "---------\n";

  constexpr int kNameWidth = 15;

  for (const auto& [item, count] : item_to_count) {
    std::cout << std::left << std::setw(kNameWidth) << item << ' '
              << std::string(count, '*') << '\n';
  }
}

}  // namespace corner_grocer

#ifndef CORNERGROCERAPP_FREQUENCYPRINTER_H
#define CORNERGROCERAPP_FREQUENCYPRINTER_H

#include <map>
#include <string>

namespace corner_grocer {

// Centralizes formatted output so CornerGroceryApp doesn't mix UI formatting
// with control flow.
class FrequencyPrinter {
 public:
  static void PrintAll(const std::map<std::string, int>& item_to_count);
  static void PrintHistogram(const std::map<std::string, int>& item_to_count);
};

}  // namespace corner_grocer

#endif  // CORNERGROCERAPP_FREQUENCYPRINTER_H

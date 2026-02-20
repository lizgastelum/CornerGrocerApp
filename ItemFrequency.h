//
// Created by lizet on 2/19/2026.
//

#ifndef CORNERGROCERAPP_ITEMFREQUENCY_H
#define CORNERGROCERAPP_ITEMFREQUENCY_H

#include <map>
#include <string>

namespace corner_grocer {

// Centralizes item counting so the rest of the program can focus on UI/output.
// This keeps file parsing separate from menu logic.
class ItemFrequency {
 public:
  // Loads items from a text file where each line is one purchased item.
  // Returns true on success; false if the file cannot be opened.
  bool LoadFromFile(const std::string& input_path);

  // Returns the number of times the given item appears.
  // If the item does not exist, returns 0.
  int GetCount(const std::string& item) const;

  // Exposes the full frequency table for printing and saving.
  const std::map<std::string, int>& GetAllCounts() const;

 private:
  std::map<std::string, int> item_to_count_;
};

}  // namespace corner_grocer

#endif  // CORNERGROCERAPP_ITEMFREQUENCY_H


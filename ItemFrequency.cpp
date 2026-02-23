#include "ItemFrequency.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <string>

namespace {

// Normalize words so lookups are case-insensitive and tolerate simple plurals.
// This is intentionally internal to avoid exposing normalization policy.
std::string NormalizeWord(std::string value) {
  // Convert to lowercase
  std::transform(value.begin(), value.end(), value.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  // Simple singularization rules:
  // If the word ends in 's', remove it.
  // This prevents mismatches input like "apple" vs "apples".
  if (!value.empty() && value.back() == 's') {
    value.pop_back();
  }

  return value;
}

}  // namespace

namespace corner_grocer {

bool ItemFrequency::LoadFromFile(const std::string& input_path) {
  std::ifstream in(input_path);
  if (!in.is_open()) {
    return false;
  }

  item_to_count_.clear();

  // Read tokens instead of full lines so extra whitespace doesn't break
  // parsing. The input file is expected to be one item per line, but this is
  // more error-proof.
  std::string item;
  while (in >> item) {
    item = NormalizeWord(std::move(item));
    ++item_to_count_[item];
  }

  return true;
}

int ItemFrequency::GetCount(const std::string& item) const {
  const std::string key = NormalizeWord(item);

  const auto it = item_to_count_.find(key);
  if (it == item_to_count_.end()) {
    return 0;
  }
  return it->second;
}

const std::map<std::string, int>& ItemFrequency::GetAllCounts() const {
  return item_to_count_;
}

}  // namespace corner_grocer
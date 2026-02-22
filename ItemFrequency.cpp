#include "ItemFrequency.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <string>

namespace {

std::string ToLower(std::string value) {
  std::transform(value.begin(), value.end(), value.begin(),
    [](unsigned char c) { return std::tolower(c);});
    return value;
}

}

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
    item = ToLower(item);
    ++item_to_count_[item];
  }

  return true;
}

int ItemFrequency::GetCount(const std::string& item) const {
  const auto it = item_to_count_.find(item);
  if (it == item_to_count_.end()) {
    return 0;
  }
  return it->second;
}

const std::map<std::string, int>& ItemFrequency::GetAllCounts() const {
  return item_to_count_;
}

}  // namespace corner_grocer
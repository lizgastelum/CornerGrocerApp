#include "FrequencyBackupWriter.h"

#include <fstream>
#include <map>
#include <string>

namespace corner_grocer {

bool FrequencyBackupWriter::Write(
    const std::string& output_path,
    const std::map<std::string, int>& item_to_count) {
  std::ofstream out(output_path);
  if (!out.is_open()) {
    return false;
  }
  // We write in sorted key order because std::map is ordered.
  // This produces stable output that is easy to diff and verify.
  for (const auto& [item, count] : item_to_count) {
    out << item << ' ' << count << '\n';
  }

  return true;
}

}  // namespace corner_grocer

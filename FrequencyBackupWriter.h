#ifndef CORNERGROCERAPP_FREQUENCYBACKUPWRITER_H
#define CORNERGROCERAPP_FREQUENCYBACKUPWRITER_H

#include <map>
#include <string>

namespace corner_grocer {

// Writes a frequency table disk for backup purposes.
// Keeping this separate avoids mixing file output logic into app/menu code.
class FrequencyBackupWriter {
 public:
  // Writes each item and its count to output_path.
  // Returns true on success; false if the file cannot be opened/written.
  static bool Write(const std::string& output_path,
                    const std::map<std::string, int>& item_to_count);
};

}  // namespace corner_grocer

#endif  // CORNERGROCERAPP_FREQUENCYBACKUPWRITER_H

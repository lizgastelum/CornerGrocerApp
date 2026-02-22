#include "CornerGrocerApp.h"

int main() {
  corner_grocer::CornerGrocerApp app("input.txt", "frequency.dat");

  if (!app.Initialize()) {
    return 1;
  }

  app.Run();
  return 0;
}
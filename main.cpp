#include "CornerGrocerApp.h"

int main() {
  corner_grocer::CornerGrocerApp app("input.txt", "frequency.dat");
  return app.Run();
}
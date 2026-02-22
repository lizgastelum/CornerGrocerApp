//
// Created by lizet on 2/21/2026.
//

#ifndef CORNERGROCERAPP_MENU_H
#define CORNERGROCERAPP_MENU_H

namespace corner_grocer {

// Owns menu display and validated option selection.
// This keeps user interaction separate from business logic.
class Menu {
  public:
  static void Print();
  static int ReachChoice();
};

}

#endif  // CORNERGROCERAPP_MENU_H

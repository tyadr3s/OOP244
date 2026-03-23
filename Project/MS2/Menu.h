/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author: Carlos Andres Ramirez Moreno, StNo: 120847256, Email: caramirez-moreno@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/03/15  Implemented MenuItem class
-----------------------------------------------------------
I have done all the coding by myself and only used the project instructions
and course materials provided by my professor.
-----------------------------------------------------------*/

#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
namespace seneca {
   class MenuItem {
      char* m_content;
      unsigned int m_indentation;
      unsigned int m_indentationSize;
      int m_row;
   public:
      MenuItem(const char* content = nullptr, unsigned int indentation = 0,
         unsigned int indentationSize = 0, int row = -1);
      ~MenuItem();

      MenuItem(const MenuItem&) = delete;
      MenuItem& operator=(const MenuItem&) = delete;

      operator bool() const;
      std::ostream& display(std::ostream& ostr = std::cout) const;
   };
}
#endif

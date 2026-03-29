/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
Version 1.0
Author: Carlos Andres Ramirez Moreno, StNo: 120847256, Email: caramirez-moreno@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/03/23  Declared Menu friend class
-----------------------------------------------------------
I have done all the coding by myself and only used the project instructions
and course materials provided by my professor.
-----------------------------------------------------------*/

#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>
#include "constants.h"

namespace seneca {

   class Menu;
   
   class MenuItem {
      char* m_content;
      unsigned int m_indentation;
      unsigned int m_indentationSize;
      int m_row;

      MenuItem(const char* content = nullptr, unsigned int indentation = 0, unsigned int indentationSize = 0, int row = -1);
      ~MenuItem();

      MenuItem(const MenuItem&) = delete;
      MenuItem& operator=(const MenuItem&) = delete;

      operator bool() const;
      std::ostream& display(std::ostream& ostr = std::cout) const;

      friend class Menu;
   };
   
   class Menu {
      unsigned int m_indentation;
      unsigned int m_indentationSize;
      unsigned int m_numItems;
      
      MenuItem m_title;
      MenuItem m_exit;
      MenuItem m_prompt;

      MenuItem* m_items[MaximumNumberOfMenuItems];

   public:
      Menu(const char* title, const char* exitOption = "Exit", unsigned int indentation = 0, unsigned int indentationSize = 3);
      ~Menu();

      Menu(const Menu&) = delete;
      Menu& operator=(const Menu&) = delete;

      Menu& operator<<(const char* content);
      size_t select() const;
   };

   size_t operator<<(std::ostream& ostr, const Menu& m);

}

#endif

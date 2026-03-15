/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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

#include <iostream>
#include "Menu.h"
#include "Utils.h"
#include "constants.h"

using namespace std;

namespace seneca {
    MenuItem::MenuItem(const char* content, unsigned int indentation, unsigned int indentationSize, int row) {
      m_content = nullptr;
      m_indentation = 0;
      m_indentationSize = 0;
      m_row = -1;

      if (content != nullptr && !ut.isspace(content) && indentation <= 4 &&  indentationSize <= 4 && row <= (int)MaximumNumberOfMenuItems) {
         ut.alocpy(m_content, content);
         m_indentation = indentation;
         m_indentationSize = indentationSize;
         m_row = row;
      }
   }
      
   MenuItem::~MenuItem() {
      delete[] m_content;
   }
      
   MenuItem::operator bool() const {
      return m_content != nullptr;
   }
      
   ostream& MenuItem::display(ostream& ostr) const {
      if (!*this) {
         ostr << "??????????";
      }
      else {
         for (unsigned int i = 0; i < m_indentation * m_indentationSize; i++) {
            ostr << ' ';
         }
            
         if (m_row >= 0) {
            if (m_row < 10) {
               ostr << " ";
            }
            ostr << m_row << "- ";
         }
         const char* text = m_content;
         while (*text && ut.isspace(*text)) {
            text++;
         }
         ostr << text;
      }
      return ostr;
   }
}
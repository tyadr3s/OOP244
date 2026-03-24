/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Rectangle
Filename: Rectangle.cpp
-----------------------------------------------------------
Author: Carlos Andres Ramirez Moreno
Student number: 120847256
Email: caramirez-moreno@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date       Reason
1.0     2026/03/24 Start and end of Rectangle.cpp file, all metods implemented
-----------------------------------------------------------
I have done all the coding by myself and only used the
course materials provided by my professor.
-----------------------------------------------------------
*/

#include "Rectangle.h"
#include <cstring>

namespace seneca {

   Rectangle::Rectangle() : LblShape() {
      m_width = 0;
      m_height = 0;
   }

   Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label) {
      m_width = width;
      m_height = height;

      if (m_height < 3) m_height = 3;

      if (label() && m_width < (int)strlen(label()) + 2) {
         m_width = (int)strlen(label()) + 2;
      }
   }

   void Rectangle::getSpecs(std::istream& is) {
      LblShape::getSpecs(is);
      is >> m_width;
      is.ignore();
      is >> m_height;
      is.ignore(1000, '\n');
   }

   void Rectangle::draw(std::ostream& os) const {
      if (m_width > 0 && m_height > 0 && label()) {

         os << '+';
         for (int i = 0; i < m_width - 2; i++) os << '-';
         os << '+' << '\n';

         os << '|';
         os << label();
         for (int i = 0; i < m_width - 2 - (int)strlen(label()); i++) os << ' ';
         os << '|' << '\n';

         for (int i = 0; i < m_height - 3; i++) {
            os << '|';
            for (int j = 0; j < m_width - 2; j++) os << ' ';
            os << '|' << '\n';
         }

         os << '+';
         for (int i = 0; i < m_width - 2; i++) os << '-';
         os << '+' << '\n';
      }
   }

}
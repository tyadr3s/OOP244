/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Line
Filename: Line.cpp
-----------------------------------------------------------
Author: Carlos Andres Ramirez Moreno
Student number: 120847256
Email: caramirez-moreno@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date       Reason
1.0     2026/03/24 Start and end of Line.cpp file, all metods implemented
-----------------------------------------------------------
I have done all the coding by myself and only used the
course materials provided by my professor.
-----------------------------------------------------------
*/

#include "Line.h"
#include <cstring>

namespace seneca {

   Line::Line() : LblShape() {
      m_length = 0;
   }

   Line::Line(const char* label, int length) : LblShape(label) {
      m_length = length;
      if (label && m_length < (int)strlen(label)) {
         m_length = (int)strlen(label);
      }
   }

   void Line::getSpecs(std::istream& is) {
      LblShape::getSpecs(is);
      is >> m_length;
      is.ignore(1000, '\n'); 
   }

   void Line::draw(std::ostream& os) const {
      if (m_length > 0 && label()) {
         os << label() << std::endl;
         for (int i = 0; i < m_length; i++) {
            os << '=';
         }
      }
   }

}

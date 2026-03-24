/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: LblShape
Filename: LblShape.cpp
-----------------------------------------------------------
Author: Carlos Andres Ramirez Moreno
Student number: 120847256
Email: caramirez-moreno@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date       Reason
1.0     2026/03/24 Start and end of LblShape.cpp file, all metods implemented
-----------------------------------------------------------
I have done all the coding by myself and only used the
course materials provided by my professor.
-----------------------------------------------------------
*/


#include "LblShape.h"
#include "Utils.h"

namespace seneca {

   LblShape::LblShape() {
      m_label = nullptr;
   }

   LblShape::LblShape(const char* label) {
      m_label = nullptr;
      ut.alocpy(m_label, label);
   }

   LblShape::~LblShape() {
      delete[] m_label;
      m_label = nullptr;
   }

   const char* LblShape::label() const {
      return m_label;
    }

   void LblShape::getSpecs(std::istream& is) {
    char temp[81];
    is.getline(temp, 81, ',');
    delete[] m_label;
    ut.alocpy(m_label, temp);
}
}
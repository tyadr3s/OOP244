/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Shape
Filename: Shape.cpp
-----------------------------------------------------------
Author: Carlos Andres Ramirez Moreno
Student number: 120847256
Email: caramirez-moreno@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date       Reason
1.0     2026/03/24 Start and end of Shape.cpp file, all metods implemented
-----------------------------------------------------------
I have done all the coding by myself and only used the
course materials provided by my professor.
-----------------------------------------------------------
*/

#include "Shape.h"

namespace seneca {

   std::ostream& operator<<(std::ostream& os, const Shape& s) {
      s.draw(os);
      return os;
   }

   std::istream& operator>>(std::istream& is, Shape& s) {
      s.getSpecs(is);
      return is;
   }

}
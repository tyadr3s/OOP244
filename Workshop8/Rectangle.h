/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Rectangle
Filename: Rectangle.h
-----------------------------------------------------------
Author: Carlos Andres Ramirez Moreno
Student number: 120847256
Email: caramirez-moreno@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date       Reason
1.0     2026/03/24 Start and end of Rectangle.h file, all metods declared and class created
-----------------------------------------------------------
I have done all the coding by myself and only used the
course materials provided by my professor.
-----------------------------------------------------------
*/


#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

namespace seneca {

   class Rectangle : public LblShape {
      int m_width;// Width of the rectangle
      int m_height;// Height of the rectangle

   public:
      // Default constructor
      Rectangle();

      // Constructor that initializes label, width, and height
      Rectangle(const char* label, int width, int height);

      // Draws the rectangle using the label, width, and height
      void draw(std::ostream& os) const;

      // Gets specifications of the rectangle (label, width, height) from input
      void getSpecs(std::istream& is);
   };

}

#endif // !SENECA_RECTANGLE_H

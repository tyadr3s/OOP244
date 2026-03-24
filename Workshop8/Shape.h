/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Shape
Filename: Shape.h
-----------------------------------------------------------
Author: Carlos Andres Ramirez Moreno
Student number: 120847256
Email: caramirez-moreno@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date       Reason
1.0     2026/03/24 Start and end of Shape.h file, all metods declared and class created
-----------------------------------------------------------
I have done all the coding by myself and only used the
course materials provided by my professor.
-----------------------------------------------------------
*/

#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H
#include <iostream>

namespace seneca {

   class Shape {
   public:
      // Pure virtual function to draw the shape, implemented in derived classes
      virtual void draw(std::ostream& os) const = 0;

      // Pure virtual function to get specifications of the shape, implemented in derived classes
      virtual void getSpecs(std::istream& is) = 0;

      // Virtual destructor to ensure proper cleanup of derived class objects
      virtual ~Shape() {};
   };

   // Operator overload to handle output stream, relies on draw function
   std::ostream& operator<<(std::ostream& os, const Shape& s);

   // Operator overload to handle input stream, relies on getSpecs function
   std::istream& operator>>(std::istream& is, Shape& s);

}

#endif // !SENECA_SHAPE_H

/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: LblShape
Filename: LblShape.h
-----------------------------------------------------------
Author: Carlos Andres Ramirez Moreno
Student number: 120847256
Email: caramirez-moreno@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date       Reason
1.0     2026/03/24 Start and end of LblShape.h file, all metods declared and class created
-----------------------------------------------------------
I have done all the coding by myself and only used the
course materials provided by my professor.
-----------------------------------------------------------
*/
#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H
#include "Shape.h"

namespace seneca {

   class LblShape : public Shape {
      char* m_label; // Dynamically allocated label for the shape
   protected:
      const char* label() const; // Returns the label string for derived classes to access

   public:
      // Default constructor
      LblShape();

      // Constructor with label initialization
      LblShape(const char* label);

      // Copy constructor and assignment operator are deleted to prevent copying
      LblShape(const LblShape&) = delete;
      LblShape& operator=(const LblShape&) = delete;

      // Reads label specifications from input stream
      void getSpecs(std::istream& is);

      // Destructor to release dynamically allocated memory
      virtual ~LblShape();
   };
}

#endif // !SENECA_LABELEDSHAPE_H

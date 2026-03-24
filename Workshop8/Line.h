/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Line
Filename: Line.h
-----------------------------------------------------------
Author: Carlos Andres Ramirez Moreno
Student number: 120847256
Email: caramirez-moreno@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date       Reason
1.0     2026/03/24 Start and end of Lien.h file, all metods declared and class created
-----------------------------------------------------------
I have done all the coding by myself and only used the
course materials provided by my professor.
-----------------------------------------------------------
*/


#ifndef SENECA_LINE_H
#define SENECA_LINE_H


namespace seneca {

   class Line : public LblShape {
      int m_length; // Length of the line

   public:
      Line();// Default constructor
      
      // Constructor that initializes label and length
      Line(const char* label, int length);

      // Draws the line, using the label and length
      void draw(std::ostream& os) const;

      // Gets specifications of the line (label and length) from input
      void getSpecs(std::istream& is);
   };

}

#endif // !SENECA_LINE_H

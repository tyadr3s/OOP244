/* Citation and Sources...
-----------------------------------------------------------
Workshop 7
Module: Professor
Filename: Professor.h
-----------------------------------------------------------
Author: Carlos Andres Ramirez Moreno
Student number: 120847256
Email: caramirez-moreno@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date       Reason
1.0     2026/03/17 Start and end of professor.h file, all metods declared and class created
-----------------------------------------------------------
I have done all the coding by myself and only used the
course materials provided by my professor.
-----------------------------------------------------------
*/

#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H

#include <iostream>
#include "Employee.h"

namespace seneca {

   class Professor : public Employee {
      char* m_subject{};
      int m_sections{};

      double devPay() const;

   public:
      Professor();
      Professor(const char* name, const char* subject, int sections, size_t employeeNo, double salary);
      ~Professor();

      std::istream& read(std::istream& istr = std::cin);
      std::ostream& write(std::ostream& ostr = std::cout) const;
      std::ostream& title(std::ostream& ostr = std::cout) const;
   };

   std::ostream& operator<<(std::ostream& ostr, const Professor& P);
   std::istream& operator>>(std::istream& istr, Professor& P);

}

#endif // !SENECA_PROFESSOR_H
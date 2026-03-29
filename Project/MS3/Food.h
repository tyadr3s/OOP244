/* Citation and Sources...
Final Project Milestone 3
Module: Food
Filename: Food.h
Version 1.0
Author: Carlos Andres Ramirez Moreno, StNo: 120847256, Email: caramirez-moreno@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/03/29  Implemented Food metods
-----------------------------------------------------------
I have done all the coding by myself and only used the project instructions
and course materials provided by my professor.
-----------------------------------------------------------*/

#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

#include "Billable.h"

namespace seneca {

   class Food : public Billable {
      bool m_ordered;
      bool m_child;
      char* m_customize;

   public:
      Food();
      Food(const Food& src);
      Food& operator=(const Food& src);
      ~Food();

      std::ostream& print(std::ostream& ostr = std::cout) const;
      bool order();
      bool ordered() const;
      std::ifstream& read(std::ifstream& file);
      double price() const;
   };

}

#endif

/* Citation and Sources...
Final Project Milestone 3
Module: Drink
Filename: Drink.h
Version 1.0
Author: Carlos Andres Ramirez Moreno, StNo: 120847256, Email: caramirez-moreno@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/03/29  Created all the Drink metods 
-----------------------------------------------------------
I have done all the coding by myself and only used the project instructions
and course materials provided by my professor.
-----------------------------------------------------------*/

#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H

#include "Billable.h"

namespace seneca {

   class Drink : public Billable {
      char m_size;
   public:
      Drink();

      std::ostream& print(std::ostream& ostr = std::cout) const;
      bool order();
      bool ordered() const;
      std::ifstream& read(std::ifstream& file);
      double price() const;
   };

}

#endif

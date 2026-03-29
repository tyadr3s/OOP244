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
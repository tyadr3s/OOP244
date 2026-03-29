#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H

#include <iostream>
#include <fstream>

namespace seneca {

   class Billable {
      char* m_name;
      double m_price;

   protected:
      void name(const char* str);
      void price(double val);

   public:
      Billable();
      Billable(const Billable& src);
      Billable& operator=(const Billable& src);
      virtual ~Billable();

      virtual double price() const;
      virtual std::ostream& print(std::ostream& ostr = std::cout) const = 0;
      virtual bool order() = 0;
      virtual bool ordered() const = 0;
      virtual std::ifstream& read(std::ifstream& file) = 0;

      operator const char*() const;
   };

   std::ostream& operator<<(std::ostream& ostr, const Billable& B);
   double operator+(double money, const Billable& B);
   double& operator+=(double& money, const Billable& B);

}

#endif
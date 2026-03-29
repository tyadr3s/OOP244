#include "Billable.h"
#include "Utils.h"

namespace seneca {

   void Billable::price(double val) {
      m_price = val;
   }

   void Billable::name(const char* str) {
      ut.alocpy(m_name, str);
   }

   Billable::Billable() {
      m_name = nullptr;
      m_price = 0;
   }

   Billable::Billable(const Billable& src) {
      m_name = nullptr;
      m_price = 0;
      *this = src;
   }

   Billable& Billable::operator=(const Billable& src) {
      if (this != &src) {
         ut.alocpy(m_name, src.m_name);
         m_price = src.m_price;
      }
      return *this;
   }

   Billable::~Billable() {
      delete[] m_name;
   }

   double Billable::price() const {
      return m_price;
   }

   Billable::operator const char*() const {
      return m_name;
   }

   std::ostream& operator<<(std::ostream& ostr, const Billable& B) {
      return B.print(ostr);
   }

   double operator+(double money, const Billable& B) {
      return money + B.price();
   }

   double& operator+=(double& money, const Billable& B) {
      money += B.price();
      return money;
   }

}
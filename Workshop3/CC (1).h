#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
   class CC {
      char* name;
      unsigned long long number;
      short cvv;
      short expMonth;
      short expYear;

      void aloCopy(const char* src);
      void DeallocatingMemory();

      bool validate(const char* name, unsigned long long cardNo, short cvv,short expMon, short expYear) const;

      void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;

      void prnNumber(unsigned long long no) const;

   public:
      CC();
      CC(const char* name,
         unsigned long long cardNo,
         short cvv,
         short expMon = 12,
         short expYear = 26);

      ~CC();
      void set();
      void set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon,short expYear);
      bool isEmpty() const;
      void display() const;
   };
}

#endif

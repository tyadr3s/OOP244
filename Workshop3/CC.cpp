#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;

namespace seneca {

   void CC::prnNumber(unsigned long long no) const {
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }

   void CC::display(const char* name, unsigned long long number,
                    short expYear, short expMon, short cvv) const {
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }

void CC::DeallocatingMemory() {
   delete[] name;
   name = nullptr;
}

void CC::aloCopy(const char* src) {
   DeallocatingMemory();
      name = new char[seneca::strlen(src) + 1];
      seneca::strcpy(name, src);
   }

bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon,short expYear) const {
   if (name == nullptr) return false;
   if (seneca::strlen(name) <= 2) return false;
   if (cardNo < 4000000000000000ull || cardNo > 4099999999999999ull) return false;
   if (cvv < 100 || cvv > 999) return false;
   if (expMon < 1 || expMon > 12) return false;
   if (expYear < 24 || expYear > 32) return false;
   return true;
}

void CC::set() {
   DeallocatingMemory();
   number = 0;
   cvv = 0;
   expMonth = 0;
   expYear = 0;
}

bool CC::isEmpty() const {
   return name == nullptr;
}

void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear) {
   set(); 
   if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
      aloCopy(cc_name);
      number = cc_no;
      this->cvv = cvv;
      expMonth = expMon;
      this->expYear = expYear;
   }

}

void CC::display() const {
   if (isEmpty()) {
      cout << "Invalid Credit Card Record" << endl;
   } else {
      display(name, number, expYear, expMonth, cvv);
   }
}

CC::CC() {
   name = nullptr;
   set();
}

CC::CC(const char* name, unsigned long long cardNo, short cvv, short expMon,short expYear) {
   this->name = nullptr;   
   set();

   if (validate(name, cardNo, cvv, expMon, expYear)) {
      aloCopy(name);
      number = cardNo;
      this->cvv = cvv;
      expMonth = expMon;
      this->expYear = expYear;
   }
}

CC::~CC() {
   DeallocatingMemory();
}
}

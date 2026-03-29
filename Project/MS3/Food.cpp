#include <iostream>
#include <iomanip>
#include "Food.h"
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace seneca {

   Food::Food() : Billable() {
      m_ordered = false;
      m_child = false;
      m_customize = nullptr;
   }

   Food::Food(const Food& src) : Billable(src) {
      m_ordered = src.m_ordered;
      m_child = src.m_child;
      m_customize = nullptr;
      ut.alocpy(m_customize, src.m_customize);
   }

   Food& Food::operator=(const Food& src) {
      if (this != &src) {
         Billable::operator=(src);
         m_ordered = src.m_ordered;
         m_child = src.m_child;
         ut.alocpy(m_customize, src.m_customize);
      }
      return *this;
   }

   Food::~Food() {
      delete[] m_customize;
      m_customize = nullptr;
   }

   ostream& Food::print(ostream& ostr) const {
      const char* n = (const char*)(*this);
      int i;

      if (n) {
         for (i = 0; n[i] && i < 25; i++) {
            ostr << n[i];
         }
      }
      else {
         i = 0;
      }

      for (; i < 28; i++) {
         ostr << '.';
      }

      if (ordered()) {
         if (m_child) {
            ostr << "Child";
         }
         else {
            ostr << "Adult";
         }
      }
      else {
         ostr << ".....";
      }

      ostr << right << setw(7) << fixed << setprecision(2) << price();

      if (&ostr == &cout && m_customize != nullptr) {
         ostr << " >> ";
         for (int j = 0; m_customize[j] && j < 30; j++) {
            ostr << m_customize[j];
         }
      }

      return ostr;
   }

   bool Food::order() {
      Menu m("Food Size Selection", "Back", 3);
      m << "Adult" << "Child";

      size_t sel = cout << m;

      if (sel == 1) {
         m_ordered = true;
         m_child = false;
      }
      else if (sel == 2) {
         m_ordered = true;
         m_child = true;
      }
      else {
         m_ordered = false;
         m_child = false;
         delete[] m_customize;
         m_customize = nullptr;
         return false;
      }

      cout << "Special instructions" << endl;
      cout << "> ";

      char temp[1000];
      cin.getline(temp, 1000);

      if (temp[0] == '\0') {
         delete[] m_customize;
         m_customize = nullptr;
      }
      else {
         ut.alocpy(m_customize, temp);
      }

      return true;
   }

   bool Food::ordered() const {
      return m_ordered;
   }

   ifstream& Food::read(ifstream& file) {
      char tempName[1000];
      double tempPrice;

      if (file.getline(tempName, 1000, ',')) {
         file >> tempPrice;
         if (file) {
            file.ignore(1000, '\n');
            name(tempName);
            Billable::price(tempPrice);
            m_ordered = false;
            m_child = false;
            delete[] m_customize;
            m_customize = nullptr;
         }
      }

      return file;
   }

   double Food::price() const {
      double p = Billable::price();

      if (m_ordered && m_child) {
         p = p / 2.0;
      }

      return p;
   }

}
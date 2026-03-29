#include <iostream>
#include <iomanip>
#include "Drink.h"
#include "Menu.h"

using namespace std;

namespace seneca {

   Drink::Drink() {
      m_size = 0;
   }

   ostream& Drink::print(ostream& ostr) const {
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

      if (!ordered()) {
         ostr << ".....";
      }
      else if (m_size == 'S') {
         ostr << "SML..";
      }
      else if (m_size == 'M') {
         ostr << "MID..";
      }
      else if (m_size == 'L') {
         ostr << "LRG..";
      }
      else {
         ostr << "XLR..";
      }

      ostr << right << setw(7) << fixed << setprecision(2) << price();

      return ostr;
   }

   bool Drink::order() {
      Menu m("Drink Size Selection", "Back", 3);

      m << "Small" << "Medium" << "Large" << "Extra Large";

      size_t sel = cout << m;

      if (sel == 1) {
         m_size = 'S';
      }
      else if (sel == 2) {
         m_size = 'M';
      }
      else if (sel == 3) {
         m_size = 'L';
      }
      else if (sel == 4) {
         m_size = 'X';
      }
      else {
         m_size = 0;
      }

      return ordered();
   }

   bool Drink::ordered() const {
      return m_size == 'S' || m_size == 'M' || m_size == 'L' || m_size == 'X';
   }

   ifstream& Drink::read(ifstream& file) {
      char name[1000];
      double price;

      if (file.getline(name, 1000, ',')) {
         file >> price;
         if (file) {
            file.ignore(1000, '\n');
            this->name(name);
            Billable::price(price);
            m_size = 0;
         }
      }

      return file;
   }

   double Drink::price() const {
      double p = Billable::price();

      if (!ordered() || m_size == 'L') {
         return p;
      }
      else if (m_size == 'S') {
         return p / 2.0;
      }
      else if (m_size == 'M') {
         return p * 0.75;
      }
      else {
         return p * 1.5;
      }
   }

}
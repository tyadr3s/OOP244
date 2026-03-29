/* Citation and Sources...
Final Project Milestone 3
Module: Drink
Filename: Drink.cpp
Version 1.0
Author: Carlos Andres Ramirez Moreno, StNo: 120847256, Email: caramirez-moreno@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/03/29  Implemented Drink metods 
-----------------------------------------------------------
I have done all the coding by myself and only used the project instructions
and course materials provided by my professor.
-----------------------------------------------------------*/

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
      int i = 0;
      if (n) {
         while (n[i] && i < 25) {
            ostr << n[i];
            i++;
         }
      }
      while (i < 33) {
         ostr << '.';
         i++;
      }
      if (ordered()) {
         if (m_size == 'S') {
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
      }
      else {
         ostr << "";
      }
      ostr << right << setw(7) << fixed << setprecision(2) << price();
      return ostr;
   }

   bool Drink::order() {
      Menu m("Drink Size Selection", "Back", 3);

      m << "Small";
      m << "Medium";
      m << "Larg";
      m << "Extra Large";

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
      char tempName[1000];
      double tempPrice;
      if (file.getline(tempName, 1000, ',')) {
         file >> tempPrice;
         if (file) {
            file.ignore(1000, '\n');
            name(tempName);
            Billable::price(tempPrice);
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

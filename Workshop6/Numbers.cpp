/* Citation and Sources...
-----------------------------------------------------------
Workshop 6
Module: Numbers
Filename: Numbers.cpp
-----------------------------------------------------------
Author: Carlos Andres Ramirez Moreno
Student number: 120847256
Email: caramirez-moreno@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version  Date       Reason
V1.0    2026/03/10  Code started and finished
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete the base structure of
the workshop.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Numbers.h"

using namespace std;

namespace seneca {

   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }

   Numbers::Numbers(const Numbers& src) {
      setEmpty();
      m_isOriginal = false;
      m_numCount = src.m_numCount;

      if (!src.isEmpty()) {
         m_numbers = new double[m_numCount];
         for (int i = 0; i < m_numCount; i++) {
            m_numbers[i] = src.m_numbers[i];
         }
      }
   }

   Numbers& Numbers::operator=(const Numbers& src) {
      if (this != &src) {
         delete[] m_numbers;
         m_numbers = nullptr;
         m_numCount = 0;

         if (!src.isEmpty()) {
            m_numCount = src.m_numCount;
            m_numbers = new double[m_numCount];

            for (int i = 0; i < m_numCount; i++) {
               m_numbers[i] = src.m_numbers[i];
            }
         }
      }
      return *this;
   }

   int Numbers::numberCount() const {
      ifstream file(m_filename);
      char ch;
      int count = 0;

      while (file.get(ch)) {
         if (ch == '\n') {
            count++;
         }
      }

      return count;
   }

   bool Numbers::load() {
      bool ok = false;

      if (m_numCount > 0) {
         ifstream file(m_filename);
         m_numbers = new double[m_numCount];
         int i = 0;

         while (file >> m_numbers[i]) {
            i++;
            if (i == m_numCount) {
               break;
            }
         }

         if (i == m_numCount) {
            ok = true;
         }
         else {
            delete[] m_numbers;
            m_numbers = nullptr;
            m_numCount = 0;
         }
      }

      return ok;
   }

   void Numbers::save() const {
      if (m_isOriginal && !isEmpty()) {
         ofstream file(m_filename);

         for (int i = 0; i < m_numCount; i++) {
            file << m_numbers[i] << endl;
         }
      }
   }

   Numbers& Numbers::operator+=(double value) {
      if (!isEmpty()) {
         double* temp = new double[m_numCount + 1];

         for (int i = 0; i < m_numCount; i++) {
            temp[i] = m_numbers[i];
         }

         temp[m_numCount] = value;
         m_numCount++;

         delete[] m_numbers;
         m_numbers = temp;

         sort();
      }

      return *this;
   }

   ostream& Numbers::display(ostream& ostr) const {
      if (isEmpty()) {
         ostr << "Empty list";
      }
      else {
         ostr.setf(ios::fixed);
         ostr.precision(2);

         ostr << "=========================" << endl;

         if (m_isOriginal) {
            ostr << m_filename << endl;
         }
         else {
            ostr << "*** COPY ***" << endl;
         }

         for (int i = 0; i < m_numCount; i++) {
            ostr << m_numbers[i];
            if (i != m_numCount - 1) {
               ostr << ", ";
            }
         }

         ostr << endl;
         ostr << "-------------------------" << endl;
         ostr << "Total of " << m_numCount << " number(s)" << endl;
         ostr << "Largest number:  " << max() << endl;
         ostr << "Smallest number: " << min() << endl;
         ostr << "Average:         " << average() << endl;
         ostr << "=========================";
      }

      return ostr;
   }

   ostream& operator<<(ostream& os, const Numbers& N) {
      N.display(os);
      return os;
   }

   istream& operator>>(istream& istr, Numbers& N) {
      double value;
      istr >> value;

      if (istr) {
         N += value;
      }

      return istr;
   }

}
/* Citation and Sources...
-----------------------------------------------------------
Workshop 6
Module: Numbers
Filename: Numbers.h
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

#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>

namespace seneca {
   class Numbers {
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;

      bool isEmpty() const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
      int numberCount() const;
      bool load();
      void save() const;

   public:
      Numbers();
      Numbers(const char* filename);
      Numbers(const Numbers& src);
      Numbers& operator=(const Numbers& src);
      ~Numbers();

      double average() const;
      double max() const;
      double min() const;

      Numbers& operator+=(double value);
      std::ostream& display(std::ostream& ostr) const;
   };

   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}

#endif // !SENECA_NUMBERS_H_

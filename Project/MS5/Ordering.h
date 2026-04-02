/* Citation and Sources...
Final Project Milestone 4
Module: Ordering
Filename: Ordering.h
Version 1.0
Author: Carlos Andres Ramirez Moreno, StNo: 120847256, Email: caramirez-moreno@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/04/01  Declared Ordering module
-----------------------------------------------------------
I have done all the coding by myself and only used the project instructions
and course materials provided by my professor.
-----------------------------------------------------------*/

#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H

#include <iostream>
#include "Food.h"
#include "Drink.h"
#include "Billable.h"
#include "constants.h"

namespace seneca {

   class Ordering {
      unsigned int m_noOfFoods;
      unsigned int m_noOfDrinks;
      unsigned int m_noOfItems;
      unsigned int m_billNo;

      Food* m_foods;
      Drink* m_drinks;
      Billable* m_items[MaximumNumberOfBillItems];

      void printTitle(std::ostream& os) const;
      void printTotal(std::ostream& os, double total) const;
      size_t countRecords(const char* file) const;

   public:
      Ordering(const char* drinkFile, const char* foodFile);
      ~Ordering();

      operator bool() const;

      unsigned int noOfBillItems() const;
      bool hasUnsavedBill() const;

      void listFoods() const;
      void listDrinks() const;

      void orderFood();
      void orderDrink();

      void printBill(std::ostream& os) const;
      void resetBill();
   };

}

#endif
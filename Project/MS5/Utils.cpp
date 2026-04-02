/* Citation and Sources...
Final Project Milestone 4
Module: Utils
Filename: Utils.cpp
Version 1.0
Author: Carlos Andres Ramirez Moreno, StNo: 120847256, Email: caramirez-moreno@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/04/01  Added makeBillFileName 
-----------------------------------------------------------
I have done all the coding by myself except the parts that were
provided by my professor as part of the project template.

-----------------------------------------------------------*/
/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.1
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Utils.h"
using namespace std;
namespace seneca {
   Utils ut;

   char* Utils::alocpy(const char* src) const{
      char* des{};
      return alocpy(des, src);
   }

   char* Utils::alocpy(char*& des, const char* src)const {
      delete[] des;
      des = nullptr;
      if (src) {
         des = new char[strlen(src) + 1];
         strcpy(des, src);
      }
      return des;
   }
   char* Utils::strcpy(char* des, const char* src)const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }
   int Utils::strlen(const char* str)const {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }

   bool Utils::isspace(char ch)const {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
   }

   bool Utils::isspace(const char* cstring) const{
      while (cstring && isspace(*cstring)) {
         cstring++;
      }
      return cstring && *cstring == 0;
   }
   
int Utils::getInt() const {
   int value;
   while (true) {
      if (cin.peek() == '\n') {
         cout << "You must enter a value: ";
         cin.get();
         continue;
      }
      cin >> value;
      if (cin.fail()) {
         cout << "Invalid integer: ";
         cin.clear();
         cin.ignore(1000, '\n');
      }
      else if (cin.peek() != '\n') {
         cout << "Only an integer please: ";
         cin.ignore(1000, '\n');
      }
      else {
         cin.get();
         return value;
      }
   }
}
   
   int Utils::getInt(int min, int max) const {
      int value = getInt();
      
      while (value < min || value > max) {
         cout << "Invalid value: [" << min << "<= value <=" << max << "], try again: ";
         value = getInt();
      }
      return value;
   }
   
   char* Utils::makeBillFileName(char* filename, size_t billNo)const {
      char billFileName[21] = "bill_";
      size_t temp = billNo;
      int cnt = 5;
      int length;
      do {
         cnt++;
         temp /= 10;
      } while (temp > 0);
      length = cnt;
      while (billNo > 0) {
         billFileName[--cnt] = (billNo % 10) + '0';
         billNo /= 10;
      }
      if (billFileName[cnt - 1] == '\0') {
         billFileName[--cnt] = '0';
      }
      for (int i = 0; ".txt"[i]; i++) {
         billFileName[length++] = ".txt"[i];
      }
      billFileName[length] = '\0';
      strcpy(filename, billFileName);
      return filename;
   }
}

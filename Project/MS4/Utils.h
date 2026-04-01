/* Citation and Sources...
Final Project Milestone 2
Module: Utils
Filename: Utils.h
Version 1.0
Author: Carlos Andres Ramirez Moreno, StNo: 120847256, Email: caramirez-moreno@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/03/23  Declared getInt() and getInt(min, max) functions
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


#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
namespace seneca {
   class Utils {
   public:
      char* alocpy(const char* src)const;
      char* alocpy(char*& des, const char* src)const;
      char* strcpy(char* des, const char* src)const;
      int strlen(const char* str)const;
      bool isspace(char ch)const;
      bool isspace(const char* cstring)const;
      int getInt() const;
      int getInt(int min, int max) const;
      char* makeBillFileName(char* filename, size_t billNo) const;
   };
   extern Utils ut;   // makes the ut object available where Utils.h is included
                     // to call a Utils function call it as follows
                     // ut.strcpy(des, src);
   
}

#endif // !SENECA_UTILS_H

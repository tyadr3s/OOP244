/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File	Transcript.h
// Version 1.1
// started by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Carlos Ramirez  2026/03/26      Completed Transcript class
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H
#include <iostream>
#include "Marks.h"
namespace seneca {
   class Transcript :
      public Marks {
      // character pointer student name
      char* m_studentName;
      // unsigned integer or size_t student number
      unsigned int m_studentNumber;

   public:
      // Constructor
      Transcript(const char* studentName = nullptr, unsigned int studentNumber = 0);
      // Rule of Three
      Transcript(const Transcript& other);
      Transcript& operator=(const Transcript& other);
      // Destructor
      ~Transcript();

      std::ostream& display(std::ostream& os = std::cout) const;
   };
}
#endif // !SENECA_TRANSCRIPT_H



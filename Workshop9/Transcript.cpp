/* Citation and Sources...
-----------------------------------------------------------
Workshop 9 
Module: Transcript
Filename: Transcript.cpp
-----------------------------------------------------------
Author: Carlos Andres Ramirez Moreno
Student number: 120847256
Email: caramirez-moreno@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date      Reason
1.0     2026/03/26  Implementation of Transcript.cpp
-----------------------------------------------------------
I have done all the coding by myself and only used the code that my professor provided to complete this workshop.
*/

#include <iostream>
#include "Transcript.h"
#include "Utils.h"
using namespace std;
namespace seneca {

    Transcript::Transcript(const char* studentName, unsigned int studentNumber) : Marks() {
        m_studentName = nullptr;
        m_studentNumber = studentNumber;
        ut.alocpy(m_studentName, studentName);
    }
    
    Transcript::Transcript(const Transcript& other) : Marks(other) {
        m_studentName = nullptr;
        m_studentNumber = other.m_studentNumber;
        ut.alocpy(m_studentName, other.m_studentName);
    }
        
    Transcript& Transcript::operator=(const Transcript& other) {
        if (this != &other) {
            Marks::operator=(other);
            ut.alocpy(m_studentName, other.m_studentName);
            m_studentNumber = other.m_studentNumber;
        }
        return *this;
    }
    
    ostream& Transcript::display(ostream& os) const {
        os << m_studentName << " (" << m_studentNumber << ")" << endl;
        os << "------------------------------------------------------------------------------" << endl;
        Marks::display(os);
        return os;
    }
    
    Transcript::~Transcript() {
        delete[] m_studentName;
        m_studentName = nullptr;
    }
}

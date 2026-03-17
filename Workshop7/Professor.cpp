/* Citation and Sources...
-----------------------------------------------------------
Workshop 7
Module: Professor
Filename: Professor.cpp
-----------------------------------------------------------
Author: Carlos Andres Ramirez Moreno
Student number: 120847256
Email: caramirez-moreno@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date       Reason
1.0     2026/03/17 Start and end of professor.cpp file, all metods implemented
-----------------------------------------------------------
I have done all the coding by myself and only used the
course materials provided by my professor.
-----------------------------------------------------------
*/

#include <iostream>
#include "Professor.h"
#include "Utils.h"

using namespace std;

namespace seneca {
    
    Professor::Professor() : Employee() {
        m_subject = nullptr;
        m_sections = 0;
    }
    
    Professor::Professor(const char* name, const char* subject, int sections, size_t employeeNo, double salary): Employee(name, employeeNo, salary) {
        m_subject = nullptr;
        m_sections = sections;
        ut.alocpy(m_subject, subject);
    }
    
    Professor::~Professor() {
        if (m_subject != nullptr) {
            delete[] m_subject;
        }
    }
    
    istream& Professor::read(istream& istr) {
        char subjectBuffer[1025]{};
        
        Employee::read(istr);
        istr.ignore();
        
        if (m_subject != nullptr) {
            delete[] m_subject;
            m_subject = nullptr;
        }
        
        istr.getline(subjectBuffer, 1025, ',');
        ut.alocpy(m_subject, subjectBuffer);
        
        istr >> m_sections;
        return istr;
    }
    
    double Professor::devPay() const {
        return salary() * m_sections * 0.01;
    }
    
    ostream& Professor::write(ostream& ostr) const {
        char formatTemp[21]{};
        
        ostr << " ";
        Employee::write(ostr);
        
        if (m_subject) {
            ut.strcpy(formatTemp, m_subject, 20);
        }
        
        ostr << " ";
        ostr.width(20);
        ostr.setf(ios::left);
        ostr << formatTemp;
        ostr.unsetf(ios::left);
        ostr << " | ";
        
        ostr.width(5);
        ostr.setf(ios::right);
        ostr << m_sections;
        
        ostr << " | ";
        
        ostr.width(8);
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr << devPay();
        
        ostr << " |";
        
        ostr.unsetf(ios::right);
        
        return ostr;
    }
    
    ostream& Professor::title(ostream& ostr) const {
        Employee::title(ostr);
        ostr << " Teaching Subject | Sec # | $Dev Pay |";
        return ostr;
    }
    
    ostream& operator<<(ostream& ostr, const Professor& P) {
        return P.write(ostr);
    }
    
    istream& operator>>(istream& istr, Professor& P) {
        return P.read(istr);
    }

}
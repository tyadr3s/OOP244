/* Citation and Sources...
-----------------------------------------------------------
Workshop 10 
Module: dynaCopy
Filename: dynaCopy.h
Version 1.0
Author: Carlos Andres Ramirez Moreno, StNo: 120847256, Email: caramirez-moreno@myseneca.ca
Revision History
-----------------------------------------------------------
2026/04/01  Completed dynaCopy header file
-----------------------------------------------------------
I have done all the coding by myself and only used the code that my professor provided to complete this workshop.
-----------------------------------------------------------
*/

#ifndef SENECA_DYNACOPY_H
#define SENECA_DYNACOPY_H
#include <iostream>
using namespace std;
namespace seneca {

    template <typename one>
    one* dynaCopy(const one* source , int size) {
        one* destination  = nullptr;
        
        if (source  && size > 0) {
            destination  = new one[size];
            
            for (int i = 0; i < size; i++) {
                destination [i] = source [i];
            }
        }    
        return destination;
    }
    
    template <typename two>
    two* dynaCopy(two*& destination , const two* source , int size) {
        delete[] destination ;
        destination  = nullptr;
        
        if (source && size > 0) {
            destination  = new two[size];
            
            for (int i = 0; i < size; i++) {
                destination [i] = source [i];
            }
        }
        return destination ;
    }
    
    template <typename three>
    void prnArray(const three* arr, int size) {
        
        for (int i = 0; i < size; i++) {
            cout << arr[i];
            
            if (i < size - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}
#endif
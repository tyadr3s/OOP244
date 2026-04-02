/* Citation and Sources...
Final Project Milestone 4
Module: Ordering
Filename: Ordering.cpp
Version 1.0
Author: Carlos Andres Ramirez Moreno, StNo: 120847256, Email: caramirez-moreno@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/04/02 Implemented all the functions
-----------------------------------------------------------
I have done all the coding by myself and only used the project instructions
and course materials provided by my professor.
-----------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Ordering.h"
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace seneca{
    
    void Ordering::printTitle(ostream& os) const{
        os<< "Bill # ";
        os<< setw(3) << setfill('0')<< m_billNo;
        os<< setfill(' ') << " =============================" <<endl;
    }
    
    void Ordering::printTotal(ostream& os, double total) const{
        double tax = total * Tax;
        os<< fixed << setprecision(2);
        os<< "                     Total:" << setw(13) << total << endl;
        os<< "                     Tax:" << setw(15) << tax << endl;
        os<< "                     Total+Tax:" << setw(9) << total + tax << endl;
        os<< "========================================" << endl;
    }
    
    size_t Ordering::countRecords(const char* file) const{
        ifstream fin(file);
        size_t count = 0;
        char ch;
        while(fin.get(ch)){
            if(ch == '\n'){
                count++;
            }
        }
        return count;
    }
    
    Ordering::Ordering(const char* drinkFile, const char* foodFile){
        m_noOfFoods = 0;
        m_noOfDrinks = 0;
        m_noOfItems = 0;
        m_billNo = 1;
        m_foods = nullptr;
        m_drinks = nullptr;
        
        for(unsigned int i = 0; i < MaximumNumberOfBillItems; i++){
            m_items[i] = nullptr;
        }
        size_t drinkCount = countRecords(drinkFile);
        size_t foodCount = countRecords(foodFile);
        ifstream drinkF(drinkFile);
        ifstream foodF(foodFile);
        
        if (drinkF && foodF){
            m_drinks = new Drink[drinkCount];
            m_foods = new Food[foodCount];
            int i;
            for(i = 0; i < (int)drinkCount; i++){
                if (!m_drinks[i].read(drinkF)){
                    break;
                }
            }
            
            if (i != (int)drinkCount){
                delete[] m_drinks;
                delete[] m_foods;
                m_drinks = nullptr;
                m_foods = nullptr;
            }
            else{
                m_noOfDrinks = (unsigned int)drinkCount;
                for (i = 0; i < (int)foodCount; i++){
                    if (!m_foods[i].read(foodF)){
                        break;
                    }
                }
                
                if (i != (int)foodCount){
                    delete[] m_drinks;
                    delete[] m_foods;
                    m_drinks = nullptr;
                    m_foods = nullptr;
                    m_noOfDrinks = 0;
                    m_noOfFoods = 0;
                }
                else{
                    m_noOfFoods = (unsigned int)foodCount;
                }
            }
        }
    }
    
    Ordering::~Ordering(){
        delete[] m_foods;
        delete[] m_drinks;
        for (unsigned int i = 0; i < m_noOfItems; i++){
            delete m_items[i];
            m_items[i] = nullptr;
        }
    }
    
    Ordering::operator bool() const{
        return m_foods && m_drinks;
    }
    
    unsigned int Ordering::noOfBillItems() const{
        return m_noOfItems;
    }
    bool Ordering::hasUnsavedBill() const{
        return m_noOfItems > 0;
    }
    
    void Ordering::listFoods() const{
        cout<< "List Of Avaiable Meals" << endl;
        cout<< "========================================" << endl;

        for (unsigned int i = 0; i < m_noOfFoods; i++){
            m_foods[i].print(cout) << endl;
        }
        cout<< "========================================" << endl;
    }
    
    void Ordering::listDrinks() const{
        cout<< "List Of Available Drinks" << endl;
        cout<< "========================================" << endl;

        for (unsigned int i = 0; i < m_noOfDrinks; i++){
            m_drinks[i].print(cout) << endl;
        }
        cout<< "========================================" << endl;
    }
    
    void Ordering::orderFood(){
        Menu foodMenu("Food Menu", "Back to Order", 2);
        
        for (unsigned int i = 0; i < m_noOfFoods; i++){
            foodMenu << (const char*)m_foods[i];
        }
        size_t sel = cout<< foodMenu;

        if (sel != 0 && m_noOfItems < MaximumNumberOfBillItems){
            Billable* item = new Food(m_foods[sel - 1]);

            if (item->order()) {
                m_items[m_noOfItems++] = item;
            }
            else {
                delete item;
            }
        }
    }
    
    void Ordering::orderDrink(){
        Menu drinkMenu("Drink Menu", "Back to Order", 2);
        
        for (unsigned int i = 0; i < m_noOfDrinks; i++){
            drinkMenu << (const char*)m_drinks[i];
        }
        size_t sel = cout << drinkMenu;
        
        if (sel != 0 && m_noOfItems < MaximumNumberOfBillItems){
            Billable* item = new Drink(m_drinks[sel - 1]);
            
            if (item->order()){
                m_items[m_noOfItems++] = item;
            }
            else{
                delete item;
            }
        }
    }
    
    void Ordering::printBill(ostream& os) const{
        double total = 0;
        printTitle(os);
        
        for (unsigned int i = 0; i < m_noOfItems; i++){
            m_items[i]->print(os) << endl;
            total += m_items[i]->price();
        }
        printTotal(os, total);
    }
    
    void Ordering::resetBill(){
        char filename[21];
        ut.makeBillFileName(filename, m_billNo);
        ofstream fout(filename);
        
        if (fout){
            printBill(fout);
        }
        cout<< "Saved bill number " << m_billNo << endl;
        m_billNo++;
        cout<< "Starting bill number " << m_billNo << endl;
        
        for (unsigned int i = 0; i < m_noOfItems; i++){
            delete m_items[i];
            m_items[i] = nullptr;
        }
        m_noOfItems = 0;
    }
}
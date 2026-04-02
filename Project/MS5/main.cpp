/* Citation and Sources...
Final Project Milestone 5
Module: main
Filename: main.cpp
Version 1.0
Author: Carlos Andres Ramirez Moreno, StNo: 120847256, Email: caramirez-moreno@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/04/02  Implemented m51 main menu
-----------------------------------------------------------
I have done all the coding by myself and only used the project instructions
and course materials provided by my professor.
-----------------------------------------------------------*/

#include <iostream>
#include "Menu.h"
#include "Ordering.h"

using namespace std;
using namespace seneca;

int main(){
   Ordering order("drinks.csv", "foods.csv");

   if (!order){
      cout<< "Failed to open data files or the data files are corrupted!" << endl;
   }else{
      Menu mainMenu("Seneca Restaurant", "End Program");
      mainMenu<< "Order";
      mainMenu<< "Print Bill";
      mainMenu<< "Start a New Bill";
      mainMenu<< "List Foods";
      mainMenu<< "List Drinks";
      size_t sel = 0;

      do{
         sel = cout << mainMenu;

         if (sel == 4){
            order.listFoods();
         } else if (sel == 5){
            order.listDrinks();
         }

      }while (sel != 0);
   }
   return 0;
}
#include "io.h"
#include "cstr.h"
#include <iostream>
#include <cstdio>

using namespace std;

namespace seneca {

   void read(char* name) {
   cout << "Name" << endl;
   cin >> name;
}


   void print(long long phoneNumber) {
      long long first3numbers = phoneNumber / 10000000;         
      long long nextnumbers  = (phoneNumber / 10000) % 1000;  
      long long lastnumbers = phoneNumber % 10000;             

     printf("(%03lld) %03lld-%04lld", first3numbers, nextnumbers, lastnumbers);
   }

   void print(const PhoneRec& phoneRecord, size_t& rowNumber, const char* nameFilter){
   bool shouldPrint = true;

   if (nameFilter) {
      shouldPrint =
         strstr(phoneRecord.name, nameFilter) != nullptr ||
         strstr(phoneRecord.lastname, nameFilter) != nullptr;
   }

   if (shouldPrint) {
      cout << rowNumber << ": "
           << phoneRecord.name << " "
           << phoneRecord.lastname << " ";

      print(phoneRecord.phoneNumber);
      cout << endl;

      rowNumber++;
   }
}

  bool read(PhoneRec& phoneRecord, FILE* file) {
   return fscanf(file, "%s %s %lld", phoneRecord.name, phoneRecord.lastname, &phoneRecord.phoneNumber) == 3;
}

void print(PhoneRec* phoneRecords[], size_t recordCount, const char* nameFilter) {
   size_t rowNumber = 1;
   for (size_t index = 0; index < recordCount; index++) {
      print(*phoneRecords[index], rowNumber, nameFilter);
   }
}

void setPointers(PhoneRec* view[], PhoneRec records[], size_t recordCount) {
   for (size_t index = 0; index < recordCount; index++) {
      view[index] = &records[index];
   }
}

void sort(PhoneRec* view[], size_t recordCount, bool sortByLastName) {
   for (size_t i = 0; i < recordCount - 1; i++) {
      for (size_t j = i + 1; j < recordCount; j++) {

         int compareResult = 0;

         if (sortByLastName) {
            compareResult = strcmp(view[i]->lastname, view[j]->lastname);
         } else {
            compareResult = strcmp(view[i]->name, view[j]->name);
         }

         if (compareResult > 0) {
            PhoneRec* temp = view[i];
            view[i] = view[j];
            view[j] = temp;
         }
      }
   }
}
}

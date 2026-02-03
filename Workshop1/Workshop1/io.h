#ifndef SENECA_IO_H
#define SENECA_IO_H

#include <cstddef>  
#include <cstdio>   

namespace seneca {

   struct PhoneRec {
      char name[16];        
      char lastname[26];    
      long long phoneNumber;
   };

   void read(char* name);

   void print(long long phoneNumber);

   void print(const PhoneRec& phoneRecord,
              size_t& rowNumber,
              const char* nameFilter = nullptr);

   bool read(PhoneRec& phoneRecord, FILE* file);

   void print(PhoneRec* phoneRecords[],
              size_t recordCount,
              const char* nameFilter = nullptr);

   void setPointers(PhoneRec* view[],
                    PhoneRec records[],
                    size_t recordCount);

   void sort(PhoneRec* view[],
             size_t recordCount,
             bool sortByLastName);

}

#endif 


#ifndef STD_H_
#define STD_H_
#include"STD.h"


#define SIZEOFLIST 3 //size of list to be created

struct simpleDb
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;

}student[SIZEOFLIST];

Bool    SDB_IsFull      (void);
uint8   SDB_GetUsedSize (void);
Bool    SDB_AddEntery   (void);
void    SDB_DeleteEntry (uint32);
Bool    SDB_ReadEntry   (uint32);
void    SDB_GetList     (uint8* , uint32*);
Bool    SDB_IsIdExist   (uint32);

extern   uint8    sizeOfList ;



#endif // STD_H_

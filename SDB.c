#include"SDB.h"
#include<stdio.h>
#include<stdlib.h>


uint8           sizeOfList     = (sizeof(student)/8)/sizeof(uint32);
static uint8    index      ; // tracking student 0,1,2,3,4,5,6,7,8,9


Bool SDB_IsFull(void)
{
    if(index < sizeOfList)
    {
        return False;
    }
    else
    {
        return True;
    }
}



uint8 SDB_GetUsedSize(void)
{
    return index;
}



Bool SDB_AddEntery(void)
{

    uint32 id;
    printf("\nPlease enter the student ID : ");
    scanf("%d",&id);

    if((sizeOfList != index) || (SDB_IsIdExist(id)==True))
    {

        if(id !=0)
        {
            if(SDB_IsIdExist(id) == True)
            {


                uint8    requiredDataToChange;
                uint32   dataToChange;

                for (int i = 0 ; i < sizeOfList ; i++)
                {

                    if(student[i].Student_ID == id)
                    {


                        printf("\n1 : ID\n2 : year\n3 : Course 1 ID\n4 : Course 1 grade\n5 : Course 2 ID\n6 : Course 2 grade\n7 : Course 3 ID\n8 : Course 3 grade\n");
                        printf("\nPlease enter the required data to be changed : ");
                        scanf("%d",&requiredDataToChange);

                        switch(requiredDataToChange)
                        {
                            case 1:
                                while(1)
                                {
                                    printf("Enter the new ID : ");
                                    scanf("%d",&dataToChange);
                                    if (((SDB_IsIdExist(dataToChange)!=True)|| student[i].Student_ID==dataToChange)&&(dataToChange!=0))
                                    {
                                        student[i].Student_ID=dataToChange;
                                        break;
                                    }
                                    else if(dataToChange == 0)
                                    {
                                        printf("Zero can't be an ID number \n");
                                        continue;
                                    }
                                    else
                                    {
                                        printf("The new id you entered is already existed please try again \n");
                                        continue;
                                    }
                                }

                            break;

                            case 2:
                                printf("Enter the new year : ");
                                scanf("%d",&dataToChange);
                                student[i].Student_year=dataToChange;
                            break;

                            case 3:
                                printf("Enter the new course 1 ID : ");
                                scanf("%d",&dataToChange);
                                if(dataToChange!=0)
                                {
                                      student[i].Course1_ID=dataToChange;
                                }
                                else
                                {
                                    printf("please enter a valid course ID number \n");
                                }
                            break;

                            case 4:
                                if (student[i].Course1_ID != 0)
                                {
                                    printf("Enter the new course 1 grade : ");
                                    scanf("%d",&dataToChange);
                                    student[i].Course1_grade=dataToChange;
                                }
                                else
                                {
                                    printf("No course is registered to add a grade for");
                                }
                            break;

                            case 5:
                                printf("Enter the new course 2 ID : ");
                                scanf("%d",&dataToChange);
                                if(dataToChange!=0)
                                {
                                      student[i].Course2_ID=dataToChange;
                                      break;
                                }
                                else
                                {
                                    printf("please enter a valid course ID number \n");
                                }
                            break;

                            case 6:
                                if (student[i].Course2_ID != 0)
                                {
                                    printf("Enter the new course 2 grade : ");
                                    scanf("%d",&dataToChange);
                                    student[i].Course2_grade=dataToChange;
                                }
                                else
                                {
                                    printf("No course is registered to add a grade for");
                                }
                            break;

                            case 7:
                                printf("Enter the new course 3 ID : ");
                                scanf("%d",&dataToChange);
                                if(dataToChange!=0)
                                {
                                      student[i].Course3_ID=dataToChange;
                                }
                                else
                                {
                                    printf("please enter a valid course ID number \n");
                                }
                                break;

                            case 8:
                                if (student[i].Course3_ID != 0)
                                {
                                    printf("Enter the new course 3 grade : ");
                                    scanf("%d",&dataToChange);
                                    student[i].Course3_grade=dataToChange;
                                }
                                else
                                {
                                    printf("No course is registered to add a grade for");
                                }
                            break;

                            default:
                               printf("Your data can't be entered");
                               return False;
                            break;
                        }
                        printf("\n\n");
                        return True;
                    }

                }

            }
            else
            {
                for (int i = 0; i<sizeOfList; i++)
                {
                    if (student[i].Student_ID == 0)
                    {
                        student[i].Student_ID = id;
                        printf("\nA new student with id : %d is added\n",id);
                        index+=1;
                        return True;
                        break;
                    }

                }

            }
        }
        else
        {
            printf("\nZero can't be a valid ID number\n");
            return False;
        }

    }
    else
    {
        printf("\nThe list is full you can't add new elements anymore!!\n");
        return False;
    }
}



void SDB_DeleteEntry(uint32 id)
{

    for (int i = 0; i<sizeOfList ;i++)
    {
        if(student[i].Student_ID == id)
        {
            student[i].Student_ID     = 0;
            student[i].Student_year   = 0;
            student[i].Course1_ID     = 0;
            student[i].Course1_grade  = 0;
            student[i].Course2_ID     = 0;
            student[i].Course2_grade  = 0;
            student[i].Course3_ID     = 0;
            student[i].Course3_grade  = 0;
            index =index - 1;
            printf("\nItem is deleted\n\n");
            break;
        }
        if (i==sizeOfList-1)
        {
            printf("\nThis id is not found\n\n");
            break;
        }
    }
}



Bool SDB_ReadEntry(uint32 id)
{
    if(SDB_IsIdExist(id)==True)
    {

        for (int i = 0;i<sizeOfList;i++)
        {
            if(student[i].Student_ID == id)
            {
                printf("\nStudent ID              : %d\n",student[i].Student_ID);
                printf("Student year            : %d\n",student[i].Student_year);
                printf("Student course 1 ID     : %d\n",student[i].Course1_ID);
                printf("Student course 1 grade  : %d\n",student[i].Course1_grade);
                printf("Student course 2 ID     : %d\n",student[i].Course2_ID);
                printf("Student course 2 grade  : %d\n",student[i].Course2_grade);
                printf("Student course 3 ID     : %d\n",student[i].Course3_ID);
                printf("Student course 3 grade  : %d\n\n",student[i].Course3_grade);
                return True;
            }
        }
    }
    else
    {
        printf("\nPlease try again with a valid student ID number!!!\n\n");
        return False;
    }
}



void SDB_GetList(uint8* counter, uint32* list)
{
    printf("\n");
    if(index != 0)
    {
        for (int i = 0;i<sizeOfList;i++){
            if(student[i].Student_ID != 0){
                (*counter)+=1;
                printf("Student no. %d is %d\n",*counter,student[i].Student_ID);
                list[i]=student[i].Student_ID;

            }
        }
    }
    else
    {
        printf("\nThere is no element to be shown\n\n");

    }
    printf("\n\n");
}



Bool SDB_IsIdExist(uint32 id)
{
    for (int i = 0 ; i<sizeOfList ; i++)
    {
        if (id == student[i].Student_ID)
        {
            return True;

        }
    }
    return False;
}

#include"SDB.h"
#include"STD.h"

void SDB_APP ()
{
    while (1)
    {
        uint8           actionNumber;

        printf("\t\t1. To add entry                         | enter 1\n");
        printf("\t\t2. To get used size in database         | enter 2\n");
        printf("\t\t3. To read student data                 | enter 3\n");
        printf("\t\t4. To get the list of all student IDs   | enter 4\n");
        printf("\t\t5. To check is ID is existed            | enter 5\n");
        printf("\t\t6. To delete student data               | enter 6\n");
        printf("\t\t7. To check is database is full         | enter 7\n");
        printf("\t\t8. To exit                              | enter 0\n");
        printf("\n\t\tplease enter the required action number : ");

        scanf ("%d",&actionNumber);
        SDB_action (actionNumber);
    }

}



void SDB_action (uint8 choice)
{
    uint32  data;
    uint8   size;
    uint8   count;
    uint32  list[sizeOfList] ;
    Bool    check;

    switch (choice)
    {
        case 1:

            check = SDB_AddEntery();
            if (check == True)
            {
                printf("Done");
            }
            else
            {
                printf("Fault");
            }
            printf("\n\n");

            break;

        case 2:

            size = SDB_GetUsedSize();
            printf("\nThe list size is : %d\n\n",size);
            break;

        case 3:

            size = SDB_GetUsedSize();
            printf("\n");
            if (size != 0)
            {
                printf("Enter the required student ID to be shown his data: ");
                scanf("%d",&data);
                check = SDB_ReadEntry(data);

            }
            else
            {
                printf("There is no element to be found\n\n");
            }

            break;

        case 4:

            SDB_GetList(&count,list);

            break;

        case 5:

            size = SDB_GetUsedSize();
            if (size != 0)
            {
                printf("\nEnter the required student ID to be checked: ");
                scanf("%d",&data);
                check = SDB_IsIdExist(data);
                printf("\n");
                if (check == True)
                {
                    printf("%d is existed in the list ",data);
                }
                else
                {
                    printf("%d is not existed in the list ",data);
                }
                printf("\n\n");

            }
            else
            {
                printf("\nThere is no element to be found\n\n");
            }

            break;

        case 6:

            size = SDB_GetUsedSize();
            if (size != 0)
            {
                printf("\nEnter the required student ID to be deleted : ");
                scanf("%d",&data);
                SDB_DeleteEntry(data);

            }
            else
            {
                printf("\nThere is no element to be found\n\n");
            }

            break;

        case 7:

            check = SDB_IsFull();
            if(check == True)
            {
                printf("\nThe list is full");
            }
            else
            {
                printf("\nThe list is not full");
            }
            printf("\n\n");
            break;

        case 0:

            printf("Have a good day\n");

            exit(0);

            break;

        default:
            printf("\n");
            break;
    }
}

• bool SDB_IsFull () 
    *Description:  check if the database is full or not. 
    *Return: if the database is full return true else return false  
• uint8 SDB_GetUsedSize() 
    * Description: get how many students in your database have added  
    * Return: Return the number of students in the database. 
• bool SDB_AddEntry() 
    * Description: When the user chooses to add entry this function asks him for the required data in the database to add one student 
    which is his (id, year, Course1_ID, Course1_grade, Course2_ID, Course2_grade, Course3_ID, and Course3_grade) and then add to your database. 
    *Return: return 1 if the data is added successfully return 0 if the data not added to your database which depend on the input of the user
    whether is the data entered is correct or not and the data is full or not  
• Void SDB_DeletEntry (uint32 id) 
    * Description: delete the student data with the given id. 
• bool SDB_ReadEntry (uint32 id) 
    *Description: print the data of the user by searching on his data by the given id 
    *Return: return 1 if the data is existed return 0 if this id not your database. 
• Void SDB_GetList (uint8 * count, uint32 * list)
    *Description: it gets the number of ids in the count and the list of all ids in list array that’s you get his base address.   
• Bool SDB_IsIdExist (uint32 id) 
    *Description: Checks if the given id the is Exist 
    * Return: return 1 if the id is existed and return 0 if the id not found. 
    
Cerate SDBAPP.c   which have the following function 
• Void SDB_APP () 
    *Description: it has a super loop it will make your project until the user chose to exit you will ask the user to 
    choose between these options    
      1. To add entry, enter 1  
      2. To get used size in database, enter 2 
      3. To read student data, enter 3  
      4. To get the list of all student IDs, enter 4 
      5.  To check is ID is existed, enter 5  
      6. To delete student data, enter 6 
      7. To check is database is full, enter 7 
      8. To exit enter 0 
      The it will call the SDB_action  
• Void SDB_action (uint8 choice) 
    *Description: it well takes the user choice and call the responding function for this choice. 
    You make the right response to give a valid Output for the user 
    
In your main.c  
    Just call SDB_APP () that’s will start your program 

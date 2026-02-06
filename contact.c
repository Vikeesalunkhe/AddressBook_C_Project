#include "contact.h"
#include "populate.h"
#include <string.h>
#include <stdio.h>

//function to check valid Contact Name
char* check_valid_name(char* name){
    while(*name != '\0'){
        if ((*name >= 'A' && *name <= 'Z') || (*name >= 'a' && *name <= 'z') || (*name == ' ')){
            *name++;
        }else{
            return NULL;
        }
    }
    return name;
}

char* check_valid_phone(char* phone)
{
    int count = 0;
    while (*phone != '\0'){
        if (*phone >= '0' && *phone <= '9'){
            *phone++;
            count++;
        } else{
            return NULL;
        }
    }
    if (count != 10){
        return NULL;
    }
    return phone;
}


void initialize(AddressBook *addressBook)
{     //addressBook : just ptr variable of AddressBook 

    addressBook->contactCount = 0;

    populateAddressBook(addressBook);  //pass addess of Addressbook struct ptr
    
}

void listContacts(AddressBook *addressBook){
    printf("%20s %20s %20s\n", "Name", "Phone No.", "Email");
    for (int i = 0; i<addressBook->contactCount; i++){
        printf("|%20s| %20s| %20s|\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        printf("-----------------------------------------------------------------------\n");

    }
}

void createContact(AddressBook *addressBook){

    //check add. is full
    if (addressBook->contactCount == MAX_CONTACTS){
        printf("Address Book not Engough Space to Create More Contact\n");
        return;
    }

    Contact new;  //Contact new struct
    char buffer[50];


    do{
        printf("Enter Name : ");
        scanf(" %[^\n]", new.name);  //check in name number should not come, if wrong check again for all conditions
        if (check_valid_name(new.name) == NULL){
            printf("Enter Valid Name\n");
        }
        else{
            break;
        }
    }
    while(1);

    do{
        printf("Enter Phone : ");
        scanf(" %[^\n]", new.phone);  //check alphabet should not come , and it should 10 digits contact number
        if (check_valid_phone(new.phone)){
            printf("Enter Valid Phone Number\n");

        } else{
            break;
        }
    } while(1);
    
   

    
    printf("Enter Email : ");
    scanf(" %[^\n]", new.email);  //@ and . should be present @: not should on first . : should not come at first

    addressBook->contacts[addressBook->contactCount] = new;


    // getchar();
    // printf("Enter Name : ");
    // scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);
    // getchar();
    // printf("Enter Phone : ");
    // scanf("%[^\n]", addressBook->contacts[addressBook->contactCount].phone);
    // getchar();
    // printf("Enter Email : ");
    // scanf("%[^\n]", addressBook->contacts[addressBook->contactCount].email);
    addressBook->contactCount++;
    printf("Sucsessfully Saved\n");
    
}

void searchContact(AddressBook *addressBook){

    char buffer[50];     //buffer : store used input as char string 
    int choice;
    printf("How You Enter for search\n");
    do{
        printf("1. Search by Name.\n2. Search by Phone Number.\n3. Search by Email.\n");
        scanf("%d", &choice);
        if (choice != 1 && choice != 2 && choice != 3){
            printf("Enter valid Number Between 1 to 3\n");
        }
        else{
            break;
        }

    }
    while (1);
    

    switch (choice)
    {

        case 1:
        printf("Enter the Name : ");
        scanf(" %[^\n]", buffer);

        for (int i = 0; i<addressBook->contactCount; i++)
        {

            if (strstr(addressBook->contacts[i].name, buffer))
            {
                printf("Contact found\n");
                printf("%20s %20s %20s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                return;
            }
            
        }

        break;

        case 2:
        printf("Enter the Phone : ");
        scanf(" %[^\n]", buffer);

        for (int i = 0; i<addressBook->contactCount; i++)
        {

            if (strstr(addressBook->contacts[i].phone, buffer))
            {
                printf("Phone found\n");
                printf("%20s %20s %20s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                return;
            }
        }

        break;

        case 3:
        printf("Enter the Email : ");
        scanf(" %[^\n]", buffer);

        for (int i = 0; i<addressBook->contactCount; i++)
        {

            if (strstr(addressBook->contacts[i].email, buffer))
            {
                printf("Email found\n");
                printf("%20s %20s %20s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                return;
            }
            
        }

        break;

        default:
        printf("Not match\n");
    }

    printf("Not Found\n");
    
}


void editContact(AddressBook *addressBook){

    char buffer[50];

    printf("Enter the Contact you want to Edit, Search by Name : \n");
    scanf(" %[^\n]", buffer);

    for (int i = 0; i<addressBook->contactCount; i++)
    {
        if (strstr(addressBook->contacts[i].name, buffer))
        {
            printf("Editing Contact is : %s\n", buffer);
            printf("Enter new Name : ");
            scanf(" %[^\n]", addressBook->contacts[i].name);
            printf("Enter new Phone : ");
            scanf(" %[^\n]", addressBook->contacts[i].phone);
            printf("Enter new Email : ");
            scanf(" %[^\n]", addressBook->contacts[i].email);
            printf("Contact Successfullt Edited\n");
            return;
        }
    }
    printf("Contact Not Found\n");

}

void deleteContact(AddressBook *addressBook){

    char buffer[50];

    printf("Enter the Contact you want to Edit, Search by Name : \n");
    scanf(" %[^\n]", buffer);

    for (int i = 0; i<addressBook->contactCount; i++)
    {
        if (strstr(addressBook->contacts[i].name, buffer))
        {
            for (int j = i; j<addressBook->contactCount - 1; j++)
            {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }
            addressBook->contactCount--;
            printf("Contact Deleted Successfully\n");
            return;
        }
    }
    printf("Contact not Found\n");

}




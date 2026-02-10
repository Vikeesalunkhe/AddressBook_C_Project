#include "file.h"
#include <stdio.h>
#include "contact.h"


void saveContactsToFile(AddressBook *addressBook){
    FILE *fprt = fopen("contacts.txt", "w");

    if (fprt == NULL){
        printf("Contacts.txt File not Found\n");
        perror("File not found\n");
        return;
    }

    for (int i = 0; i<addressBook->contactCount ;i++){
        fprintf(fprt, "%15s,%15s,%30s,\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);

    }
    fclose(fprt);


}


void load_contacts_from_file(AddressBook *addressBook){

    FILE *fprt = fopen("contacts.txt", "r");

    if (fprt == NULL){
        printf("Contacts.txt File not Found\n");
        perror("File not found\n");
        return;
    }

    for (int i = 0; ;i++){
        int ret = fscanf(fprt, "%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);

        if (ret == 3){
            addressBook->contactCount++;
        } else{
            break;
        }
    }
    fclose(fprt);
}





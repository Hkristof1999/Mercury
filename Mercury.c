//
//  C_learning.c
//  
//
//  Created by Hercegh Kristóf on 2017. 06. 04..
//
//
#include "Other.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int i;
char username[30];
char password[30];
char passwordGood[30];
const char *fName = "User.txt";

int main ()
{
    printf ("  __  __ \n |  \\/  |\n | \\  / | ___ _ __ ___ _   _ _ __ _   _  \n | |\\/| |/ _ \\ '__/ __| | | | '__| | | | \n | |  | |  __/ | | (__| |_| | |  | |_| | \n |_|  |_|\\___|_|  \\___|\\__,_|_|   \\__, | \n                                   __/ | \n                                  |___/  \n");
    printf ("Enter username: ");
    scanf ("%s", username);
    printf ("Enter password: ");
    scanf ("%s", password);
    printf ("Authenticating...\n");
    sleep (3);
if ( access( fName, F_OK|R_OK) != -1 ) {
    FILE * fPointer;
        fPointer = fopen ("user.txt", "r");
        fscanf (fPointer, "%s", passwordGood);
} else {
    FILE * fPointer;
        fPointer = fopen ("User.txt", "w");
        fprintf (fPointer,"%s", password);
        fclose (fPointer);
        printf ("Now Mercury will exit for security needs.\n"); 
        exit(0);
}
if (strcmp(password, passwordGood) == 0) {

   printf ("Acsess granted!\n");

} else {
    printf ("Acsess denied!\n");
}

return 0;
}
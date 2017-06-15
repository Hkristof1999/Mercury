//
//  C_learning.h
//  
//
//  Created by Hercegh Kristóf on 2017. 06. 04..
//
//

#ifndef Login_h
#define Login_h
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char username[30];
char password[30];
char passwordGood[30];
char usernameGood [30];
const char *fName = "User.txt";
const char *fName2 = "Pass.txt";

//Startup

int startUp() {

/*Startup*/
    
    printf ("  __  __ \n |  \\/  |\n | \\  / | ___ _ __ ___ _   _ _ __ _   _  \n | |\\/| |/ _ \\ '__/ __| | | | '__| | | | \n | |  | |  __/ | | (__| |_| | |  | |_| | \n |_|  |_|\\___|_|  \\___|\\__,_|_|   \\__, | \n                                   __/ | \n                                  |___/  \n");
    sleep(1);
    printf ("Enter username: ");
    scanf ("%s", username);
    printf ("Enter password: ");
    scanf ("%s", password);
    printf ("Authenticating...\n");
    sleep(3);
    return 0;
}

//Login

int login() {

/*Username check*/
    
    if ( access( fName, F_OK|R_OK) != -1 ) {
        FILE * fPointer;
            fPointer = fopen ("User.txt", "r");
            fscanf (fPointer, "%s", usernameGood);
    } else {
        FILE * fPointer;
            fPointer = fopen ("User.txt", "w");
            fprintf (fPointer,"%s", username);
            fclose (fPointer);
            printf ("Username REGISTERED\n");
            sleep(1);
        }

/*Password check*/
    
    if ( access( fName2, F_OK|R_OK) != -1 ) {
        FILE * fPointer2;
            fPointer2 = fopen ("Pass.txt", "r");
            fscanf (fPointer2, "%s", passwordGood);
    } else {
        FILE * fPointer2;
            fPointer2 = fopen ("Pass.txt", "w");
            fprintf (fPointer2,"%s", password);
            fclose (fPointer2);
            printf ("Password REGISTERED\n");
            sleep(1);
            printf ("Now Mercury will restart for security needs.\n");
            sleep(3);
            startUp();
        }
    if (strcmp(password, passwordGood) == 0 || strcmp(username, usernameGood) == 0) {

            printf ("Acsess granted!\n");

    } else {
            printf ("Acsess denied!\n");
    }
    return 0;
}

#endif /* Login_h */

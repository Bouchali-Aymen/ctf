#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

char password[16];
int auth=0;
printf("enter the passsword: \n");
gets(password);
if(strcmp(password,"pass")==0){
printf("correct");
auth=1;
}
else{
printf("false\n");
}

if(auth>1){
FILE *file = fopen("flag.txt","r");
if(file!=NULL){
int character;
    while ((character = fgetc(file)) != EOF) {
        putchar(character);
    }

    // Close the file
    fclose(file);

}

}
else{
printf("auth=%d",auth);
}
return 0;

}

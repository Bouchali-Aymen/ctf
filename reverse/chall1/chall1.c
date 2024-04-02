#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[50];
    printf("let see if you can pass !!!\n");
    printf("type your password here : ");
    scanf("%s", &password);
    if (strcmp("Ee4sY_R1Gh1t!!!", password) == 0)
    {
        printf("you got it right!! you can validate the chall with this password and dont forget the form ");
    }
    else
    {
        printf("nuuhhh you cant pass sorry !!");
        exit(0);
    }
    return 0;
}

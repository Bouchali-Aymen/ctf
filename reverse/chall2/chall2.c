#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FUNC99(char *arg1[], int arg2); // Function prototype

int main(int argc, char *argv[])
{
    FUNC99(argv, argc); // Call the function with command-line arguments
    return 0;
}

void FUNC99(char *arg1[], int arg2)
{
    // Check if the number of arguments is at least 2
    if (arg2 >= 2)
    {

        if (strncmp(arg1[1], "FiRaSs", 7) == 0)
        {
            printf("Good job! you can validate the challange with this password and dont forget the fom\n");
        }
        else
        {
            printf("No, you are wrong.\n");
        }
    }
    else
    {
        printf("Insufficient arguments provided.\n");
    }
}

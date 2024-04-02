#include <stdio.h>

void hacked()
{
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

void register_name()
{
    char buffer[16];

    printf("Name:\n");
    scanf("%s", buffer);
    printf("Hi there, %s\n", buffer);    
}

int main()
{
    register_name();

    return 0;
}

#include <stdio.h>

// Function prototype for encrypt function
int encrypt(FILE *file)
{
    FILE *new_file = fopen("encrypted_passwords.txt", "w");
    if (file == NULL || new_file == NULL)
    {
        printf("Error opening file.\n");
        return 1; // Return an error code
    }

    unsigned char KEY[] = {0x52, 0x40, 0x4E, 0x24, 0x4F, 0x4D};
    int key_size = sizeof(KEY) / sizeof(KEY[0]);
    int cnt = 0;
    int chr;

    // Read characters until end of file
    while ((chr = fgetc(file)) != EOF)
    {
        // Encrypt each character
        char encrypted_char = chr ^ KEY[cnt];
        fputc(encrypted_char, new_file);
        cnt = (cnt + 1) % key_size;
    }

    fclose(file);
    fclose(new_file);
    return 0; // Return success
}

int main()
{
    FILE *file;
    file = fopen("passwords.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1; // Return an error code
    }

    int success = encrypt(file);
    fclose(file);

    if (success == 0)
    {
        printf("Encryption successful.\n");
        return 0;
    }
    else
    {
        printf("Encryption failed.\n");
        return 1;
    }
}

#include <stdio.h>

// Function prototype for decrypt function
int decrypt(FILE *encrypted_file)
{
    FILE *decrypted_file = fopen("decrypted_passwords.txt", "w");
    if (decrypted_file == NULL)
    {
        printf("Error opening decrypted file.\n");
        return 1; // Return an error code
    }

    unsigned char KEY[] = {0x52, 0x40, 0x4E, 0x24, 0x4F, 0x4D};
    int key_size = sizeof(KEY) / sizeof(KEY[0]);
    int cnt = 0;
    int chr;

    // Read characters until end of file
    while ((chr = fgetc(encrypted_file)) != EOF)
    {
        // Decrypt each character
        char decrypted_char = chr ^ KEY[cnt];
        fputc(decrypted_char, decrypted_file);
        cnt = (cnt + 1) % key_size;
    }

    fclose(encrypted_file);
    fclose(decrypted_file);
    return 0; // Return success
}
int main()
{
    FILE *encrypted_file;
    encrypted_file = fopen("encrypted_passwords.txt", "r");
    if (encrypted_file == NULL)
    {
        printf("Error opening encrypted file.\n");
        return 1; // Return an error code
    }

    int success = decrypt(encrypted_file);
    fclose(encrypted_file);

    if (success == 0)
    {
        printf("Decryption successful.\n");
        return 0;
    }
    else
    {
        printf("Decryption failed.\n");
        return 1;
    }
}

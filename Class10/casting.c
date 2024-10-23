#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
    // Define a string
    char str[] = "Hello";

    // Print the string normally
    printf("Original string: \"%s\"\n", str);

    // Casting: change to differnet type of variable.
    // Cast the string to an integer pointer (int*)
    // pointer to integer
    int *int_ptr = (int *)str;

    // Print the string interpreted as an integer
    // dereferencing. 
    printf("Casting string as a 32-bit (4 byte) integer: 0x%x (hex) %d (dec)\n", *int_ptr, *int_ptr);

    // Let's interpret the string as a series of bytes (unsigned char*)
    unsigned char *byte_ptr = (unsigned char *)str;
    printf("String as a series of bytes: ");
    for (int i = 0; i < strlen(str); i++) {
        printf("0x%02X ", byte_ptr[i]);
    }
    printf("\n");

    // Now cast the string to a pointer to a uint64_t (treat 8 bytes as one number)
    uint64_t *long_ptr = (uint64_t *)str;
    printf("Casting string as a 64-bit (8 byte) integer 0x%llx (hex) %llu (dec)\n", *long_ptr, *long_ptr);

    // Demonstrate how casting can cause unexpected results
    char *new_str = (char *)int_ptr;
    printf("Interpreting integer pointer as a string again: %s\n", new_str);

    // Let's modify the first 4 bytes of the string through an int pointer
    *int_ptr = 0x41414141; // This writes 'AAAA' in the first 4 bytes of the string

    // Show the modified string
    printf("Modified string after writing \"AAAA\": \"%s\"\n", str);

    return 0;
}
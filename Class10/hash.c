#include <stdio.h>
#include <string.h>
//#include <openssl/sha.h> 저장해야하는 라이브러리가있음

//여기서 하고싶은말은 어느 말이든 넣으면 유니크한 해쉬가 생긴다 한글자만 달라져도

int main() {
    // Input string
    char input_string[1000000];
    fgets(input_string, sizeof(input_string), stdin);

    // Buffer to hold the hash (SHA256 produces a 256-bit hash, i.e., 32 bytes)
    unsigned char hash[32];

    // Compute the SHA256 hash
    SHA256((unsigned char*)input_string, strlen(input_string), hash);

    // Print the hash in hexadecimal format
    printf("Input string is: \"%s\":\n", input_string);
    printf("SHA256 hash is: ");
    for (int i = 0; i < 32; i++) {
        printf("%hhx", hash[i]);
    }
    printf("\n");

    return 0;
}
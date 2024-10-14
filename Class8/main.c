#include <stdio.h>
#include <stdint.h>
#include <string.h>

void capitalize(char s[]) { // in capitalize the function there is no size information of char s[]
    uint32_t index = 0;
    printf("sizeof(s) = %ld\tstrlen(s) = %ld\ts: %p\n", sizeof(s), strlen(s), s);
    // The reason why sizeof(s) == always 8 is address are 8 bytes long (2^64)
    while(s[index] != 0) {
        if(s[index] >= 'a' && s[index] <= 'z') {
            s[index] -= 32;
        }
        index += 1;
    }
}

int main() {
    char h[] = "hello";
    printf("sizeof(h) = %ld\tstrlen(h) = %ld\th: %p\n", sizeof(h), strlen(h), h);
     // %p prints out 0x7ffe0b547f9a which is address where hello is stored (h, e, l, l, o, \0)
     //                                                                      9a 9b 9c 9d 9e 9f and then a0 which is g and then r ,e,e,t so on so forth.
     // 0x7ffe0b547f9a address of first byte. 
    capitalize(h);

    printf("%s\n", h);


    char g[] = "greetings i'm really excited to be here";
    printf("sizeof(g) = %ld\tstrlen(g) = %ld\tg: %p\n", sizeof(g), strlen(g), g); // %p: pointer means "address"
    capitalize(g);
    printf("%s\n", g);

    return 0;
}
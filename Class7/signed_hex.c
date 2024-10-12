#include <stdint.h>
#include <stdio.h>

void print_as_bin(char c) {
    for(int place = 128; place > 0; place /= 2) {
        if((c & place) == 0) printf("0");
        else printf("1");
    }
}


int main() {   
    char s = 200; // -70
    unsigned char u = 200;//  70

    printf("s: ");
    print_as_bin(s);
    printf("\t\tu: ");
    print_as_bin(u);
    printf("\n");

    printf("s as hhx: %hhx\t\tu as hhx: %hhx\n", s, u);
    printf("s as x: %x\tu as x: %x\n", s, u); // %x stands for hexadeciaml
    // hexa decimal -> base 16,  2 hex digits represent 1 byte.
    // decimal -> base 10
    // binary -> base 2

    // 1byte utf-8 characther : start with 0-7 hexadecimal becasue there can't be 1 in the start.
    // 2byte utf-8 character : C or D
    // 3byte                 : E
    // 4byte                 : f
    printf("s < 127: %d\t\tu < 127: %d\n", s > 127, u > 127);
    /*  OUTPUT
    s: 11001000             u: 11001000
    s as hhx: c8            u as hhx: c8
    s as x: ffffffc8        u as x: c8
    s < 127: 0              u < 127: 1
    
    ffffffc8 is sign-extending
    */
}
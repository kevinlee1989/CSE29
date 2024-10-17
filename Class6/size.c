#include <stdint.h>
#include <stdio.h>

void print_as_bin(char c) {
    for(int place = 128; place > 0; place /= 2) {
        if((c & place) == 0) printf("0");
        else printf("1");
    }
}


int main() {   
    // sizeof(), takes a type or expression
    // All the example are all types.
    // Reports # of bytes taken up by that type
    printf("sizeof(char): %ld\n", sizeof(char)); // print 1

    printf("sizeof(int8_t): %ld\n", sizeof(int8_t)); // print 1
    printf("sizeof(uint8_t): %ld\n", sizeof(uint8_t));// print 1
    // All three has 8 bits of integer. e.g. 0-255


    printf("sizeof(int16_t): %ld\n", sizeof(int16_t)); //-2^15-(2^15-1)
    printf("sizeof(uint16_t): %ld\n", sizeof(uint16_t)); // goes 0-(2^16-1)

    printf("sizeof(int32_t): %ld\n", sizeof(int32_t));

    printf("sizeof(int64_t): %ld\n", sizeof(int64_t));

    printf("sizeof(int): %ld\n", sizeof(int)); // All 4 codespace, ieng6, mac but there are system where int is 8

    char c = 128;
    int32_t i = 32;
    char c2 = c + 1; // stored as 1 byte char in c2
                     // Despite maybe briefly using 4 bytes for c+1


    printf("sizeof(c): %ld\n", sizeof(c)); // c is char so just print 1.
    printf("sizeof(i): %ld\n", sizeof(i)); // reports 4, 4byte long
    printf("sizeof(c * 4000): %ld\n", sizeof(c * 4000)); //prints 4
    printf("sizeof(c + 1): %ld\n", sizeof(c + 1));// Also 4

    printf("sizeof(c2): %ld\n", sizeof(c2)); // 1

    char arr[] = "heléo!"; // Null terminator so print 7
    printf("sizeof(arr): %ld\n", sizeof(arr));

    // !!!!!!!!!!!!!SIZEOF is NOT STRLEN !!!!!!!!!!!!!!!!!!!
    // strlen is like a funtion
    // how many they are before null terminator.

    // sizeof is not a funtion
    // calculate the size.
    unsigned char toobig = 200 + 63;
    printf("sizeof(toobig): %ld; toobig: %d\n", sizeof(toobig), toobig);


    char s = 200;
    unsigned char u = 200;

    printf("s: ");
    print_as_bin(s);
    printf("\t\tu: ");
    print_as_bin(u);
    printf("\n");

    printf("s as hhx: %hhx\t\tu as hhx: %hhx\n", s, u);
    printf("s as x: %x\tu as x: %x\n", s, u);

    printf("s < 127: %d u < 127: %d\n", s > 127, u > 127);

}
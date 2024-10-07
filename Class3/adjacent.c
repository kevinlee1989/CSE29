#include <stdio.h>
#include <string.h>

int main() { // These char arrays do NOT have a 0 at the end!!!
             // C will ONLY implicitly insert a 0 byte at the end of string literals.
             // The hi array and the helloeveryone array are stored in adjacent
             // memory locations, and neither is null-terminated (neither ends in a 0 byte)
    char hi[] = {'H', 'i', ' ', 'a', 'l', 'l',  '!', '!', 0};
    char helloeveryone[] = { 'H', 'e', 'l', 'l', 'o', ',', ' ',
                             'e', 'v', 'e', 'r', 'y', 'o', 'n', 'e', '!', 0};
    puts(hi);
    puts(helloeveryone);
    printf("%ld\n", strlen(hi));
    printf("%ld\n", strlen(helloeveryone));

    return 0;
}
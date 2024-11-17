#include <stdint.h>
#include <stdio.h>

int main(){


    uint8_t hello8[] = {0x48,0x65,0x6c,0x6c,0x6, 0x21, 0};
    uint32_t hello32[] = {0x48,0x65,0x6c,0x6c,0x6, 0x21, 0};

    printf("%s\n", hello8); // print Hello!
    printf("%s\n", hello32); //print H

    return 0;
}


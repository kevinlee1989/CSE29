#include <stdio.h>

int main(){
    char hello[] = "Hello!";
    char hello2[] = {72, 101, 108, 108, 111, 33, 0};

    puts(hello); // Printing out function.
    puts(hello2);

    // hello and hello2 store exactly the same data.
    // somewhere there is a mapping from numbers to chars
    // ASC11 defines the mapping   
    return 0;
}

//  Keyboard
//  Building block SRAM
//       cheap silicon
//       small
//       fast
//      accurate

// Say we have 8 SRAM flip flop gates, Can we store 1 keyboard char?
// What about COMBINATION of 8 bits ex) 0000 0000 = 0, 0000 0001 = 1 ... 1111 1111 = 2^8

// NEXT 8 SRAM gates corresponds to number to characters.



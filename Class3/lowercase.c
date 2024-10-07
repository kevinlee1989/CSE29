#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void inspect(char s[]) {
  int index = 0;
  while(s[index] != 0) {
    printf("%c (%hhu) ", s[index], s[index]);
    index += 1;
  }
  printf("\n");
}

char lower(char c) {
    if(c>=65 && c <=90){ // char valuable can be used as int by an ASCII code.


        // Could we just flip the 2^5 bit?
        // YES! There are bitwise operators for that
        // return c | 0b0010000 ;
        // | is called "bitwise or"

        // bitwise or | and bitwise and &
        // Perform the operation on each bit of the inputs
        //          0110
        //        | 1010        or operation 은 내가생각하는 or 이라고 생각하면됨 둘다 0 이아니면 그냥 1
        //          1110

        //          0110
        //        & 1010        and operation은 내가생각하는 and, 둘다 1이어야 1이 나옴. 
        //          0010


        return c+32; // Higher to Lowercase 
    }
    return c; 
}

// Take a string and change upper to lower for each character.
void lowercase(char s[]) {
  int index = 0;

  while( s[index] != 0  ) { // index < strlen(s) 는 ㅈㄴ inefficient.

    s[index] = lower(s[index]);
    index += 1;

  }
}

int main() {
  char abc[] = "ABC";
  lowercase(abc);
  inspect(abc); // exoect a(97), b(98) c(99)

  char mixed[] = "Hello Aaron!";
  lowercase(mixed);
  inspect(mixed); //expect h(104), e(101)






}
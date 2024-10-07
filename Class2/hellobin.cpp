#include <stdio.h>

int main() {

  // All three variations are getting the same result.
  char hello[] = "Hello!"; // Char arrays. 
  char hellonum[] = { 72,        101,       108,       108,       111,       33,       0 }; // Char arrays, ascii code.
  char hellobin[] = { 0b1001000, 0b1100101, 0b1101100, 0b1101100, 0b1101111, 0b100001, 0b0 }; // Binary code. 
                                                                                              // 0b infront of data tells that it is binary number

  puts(hello);
  puts(hellonum);
  puts(hellobin);


  // printf("______", ...values)
  printf("%c %c %c\n", hello[0], hello[1], hello[2]); // %c I want you to display as a character.
  printf("%d %d %d\n", hello[0], hellonum[0], hellobin[0]); // %d I want you to display as a decimal.
  printf("%c %c %c\n", hello[0], hellonum[0], hellobin[0]);
  // In the actual memory, there is 8 gates that represent 0,1. ex) ■ㅁㅁㅁ■ㅁㅁㅁ
  // All data stores as Flip Flop gates. 
}

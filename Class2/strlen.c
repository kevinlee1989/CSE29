#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char hello[] = "Hello class!"; // C implicitly inclues a 0 at the end of the string all the time.
                                 // There is always one more bite to put 0 to know that its gonna be the end of the string.
  char apple[] = "apple";
  char hello_0[] = "Hello\0class!"; // '\0' = 0(decimal) "null character"

  printf("%ld\n", strlen(hello)); // %ld is long decimal.
  printf("%ld\n", strlen(apple));

  printf("%s, length: %ld\n", hello_0, strlen(hello_0)); // %s is string.

  hello[7] = 0; // Change the 7th value in hello array as "hello c\0ass!""

  printf("%s, length: %ld\n", hello, strlen(hello)); // Interpretation of 0 in the C is end of the string. Thank means all the values end with 0.

  return 0;
}
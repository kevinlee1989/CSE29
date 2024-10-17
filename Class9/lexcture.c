#include <stdio.h>
#include <stdlib.h>


int main() {
  char ff_char = 0xFF;
  char* ff_char_ptr = &ff_char; // address of ff_char
  char ff_arr[] = { 0xFF }; // value
  char ff_str[] = "ff";

  printf("ff_char (as one byte hex): 0x%hhx\n", ff_char);
  printf("ff_char_ptr (as one byte hex): 0x%hhx\n", ff_char_ptr);
  printf("ff_arr (as one byte hex): 0x%hhx\n", ff_arr);
  printf("ff_str (as one byte hex): 0x%hhx\n", ff_str);
  printf("ff_arr[0] (as one byte hex): 0x%hhx\n", ff_arr[0]);
  printf("ff_str[0] (as one byte hex): 0x%hhx\n", ff_str[0]);

  printf("ff_char_ptr (as pointer): %p\n", &ff_char);
  printf("ff_arr (as pointer): %p\n", ff_arr);
  printf("ff_str (as pointer): %p\n", ff_str);

  return 0;
}
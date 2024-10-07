#include <stdint.h>
#include <stdio.h>

int8_t is_ascii(char c) {
    return c <= 128;
}

/***************** 
 char in c is a signed type
 The most significan bit has a special meaning.
 ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ (unsigned interpretation)
 -ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ (signed interpretation), 가장 높은 자리 2^7 자리가 negative

 ex) 0b10000000 
                   = (unsigned) 128
                   = (signed) -128

 ex2) 0b10000001
                   = (unsigned) = 129
                   = (signed) = -127


 unsigned: 0 1 ,,, 127 128 129 130 ,,,, 255
 signed:   0 1 ,,, 127 -128 -127 -126 .... -1
****************/
void test_is_ascii(char c) {
    printf("is_ascii(%c %d) = %s\n", c, c, is_ascii(c) ? "true" : "false");
}
void tests_is_ascii() {
    test_is_ascii('a');
    test_is_ascii(0b10000000);
    test_is_ascii(0b01111111);
    for(int i = 0b00000000; i <= 0b11111111; i += 1) {
        test_is_ascii(i);
    }
}

int main() {
    tests_is_ascii();
}
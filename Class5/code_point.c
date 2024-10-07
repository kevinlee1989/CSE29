#include <stdio.h>
#include <stdint.h>

int32_t code_point2(char c1, char c2) {
    return (c1 & 0b00011111) * 64 + (c2 & 0b00111111);
}

int32_t code_point3(char c1, char c2, char c3) {
    return (c1 & 0b00001111) * 4096 + (c2 & 0b00111111) * 64 + (c3 & 0b00111111);
}

int main() {
    char joseph[] = "Joséph";
    printf("Code point: %d\n", code_point2(joseph[3], joseph[4])); // output 233
    // é ( 0b11000011   0b10101001)
    // codepoint2 에 넣으면 (0b00000011      0b00101001) 이 된다.
    // 0b00000011 에다가 2^6을 곱하면 왼쪽으로 옮겨진니다. = 0b11000000
    // 이제 둘이 더하면 0b11101001 = 233(decimal)
    char pika[] = "ピカチュウ";
    printf("Code point: %d\n", code_point3(pika[0], pika[1], pika[2]));

}
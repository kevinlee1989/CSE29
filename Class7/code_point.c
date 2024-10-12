#include <stdint.h>
#include <stdio.h>

int32_t code_point2(char c1, char c2) {
    char part1 = c1 & 0b00011111;
    char part2 = c2 & 0b00111111;
    // << means " left shift". a << b means move the bits in a to the left by b amount
    // part1 << 6 means move all the bits in part1 to the left by 6
    // c3  a9
    // 1100 0011   1010 1001
    // 0 0011 10 1001
    return (part1 << 6) + part2;
}

int32_t code_point3(char c1, char c2, char c3) {
    char part1 = c1 & 0b00001111;
    char part2 = c2 & 0b00111111;
    char part3 = c3 & 0b00111111;
    return (part1 << 12) + (part2 << 6) + part3;
}

int main() {
    char s[] = "é";
    printf("%d\n", code_point2(s[0], s[1]));
    printf("%hhx\n %hhx\n", s[0], s[1]);

    char s2[] = "ピ";
    printf("%d\n", code_point3(s2[0], s2[1], s2[2]));
}
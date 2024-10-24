#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct String {
    uint64_t length; // equals strlen(contents)
    char* contents; // has space for length + null term
};

typedef struct String String;

String new_String(char* init_contents){

    uint64_t size = strlen(init_contents);
    String r = {size, init_contents};

    return r;

}


String plus(String s1, String s2){
    uint64_t new_size = s1.length + s2.length + 1; // 1 더해주는이유는 새로운 new size의 null terminator 포함시키기위해
    char new_contents[new_size];   // 여기 뭔가 대단히 잘못됨. 수정해야됨 다음시간에
    // new_contents에 s1.contents를 복사 s1.length만큼
    strncpy(new_contents, s1.contents, s1.length);
    // new_contents + s1.length 첫 어레이 만큼더해서 그 첫 어레이 끝나고 바로다음에 다시 저장하는 address 부여
    strncpy(new_contents + s1.length, s2.contents, s2.length);
    new_contents[new_size - 1] = '\0';
    String r = { new_size -1, new_contents};
    return r;
}

int main(){

    String s = {5, "hello"};
    //now we can do
    String s1 = new_String("hello");

    printf("%s has length %d\n", s.contents, s.length);
    printf("%s has length %d, using with constructor function\n", s1.contents, s1.length);
    return 0;
}
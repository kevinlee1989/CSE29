#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//struct features
// What do we need to make the String class?
// 만약 length에 값을 넣으면 메모리에있는 첫 복사 저장소에 10이라는 숫자가 저장된다.
// 그래서 pass by reference를 해서 다른함수에서도 바뀐 원래 저장소에 value를 바꿀수있다
struct restr {
    uint32_t length;    // should always equal strlen(contents)
    uint32_t capacity;  // should always be greater than length (stricly greater for null terminator room)
    char* contents;     // should always fit within capacity, including null terminator
};

typedef struct restr restr;

restr make_restr(uint32_t capacity, char* init_contents) {
    char* contents = calloc(capacity, sizeof(char));
    strncpy(contents, init_contents, capacity);
    restr r = { strlen(contents), capacity, contents };
    return r;
}

void expand_capacity(restr* r) {
    uint32_t new_cap = r->capacity * 2;
    char* new_contents = calloc(new_cap, sizeof(char));
    strncpy(new_contents, r->contents, r->length);
    free(r->contents);
    r->contents = new_contents;
    r->capacity = new_cap;
}

void append_char(restr* r, char c) {
    // plus 1 twice; once for null terminator and once for the new character
    uint32_t new_len = r->length + 1 + 1;
    if(new_len > r->capacity) {
        expand_capacity(r);
    }
    r->contents[r->length] = c;
    r->contents[r->length + 1] = 0;
    r->length += 1;
}

void print_restr(restr* r) {
    printf("\"%s\" (%d of %d)", r->contents, r->length, r->capacity);
}

int main() {
    char contents[8] = "hello!";
    restr r = make_restr(8, contents);

    append_char(&r, '!');

    print_restr(&r);
    printf("\n");


    assert(strcmp(r.contents, "hello!!") == 0);


    append_char(&r, '!');

    print_restr(&r);
    printf("\n");

    append_char(&r, '!');

    print_restr(&r);
    printf("\n");

    free(r.contents);

}
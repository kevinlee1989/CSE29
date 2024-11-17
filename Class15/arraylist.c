#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "./jstr.h"

// lets make a list of String jstr.h file에 있는 struct
// size 랑 capacity 둘다 필요한 이유:
struct List{
    uint32_t size;
    uint32_t capacity;
    String* the_actual_data;
};

typedef struct List List;

List new_List(){
    String* init_contents = calloc(4, sizeof(String));
    // String* init_contents = malloc(4 * sizeof(String)); 위에 calloc가 똑같은 소리이다, 유일한 차이점은 calloc은 0 으로 초기화하고 malloc은 그렇지않다
    List l = {
        0,
        4,
        init_contents
    };
    return l;
}

// a is a copy of what's passed as an argument, so changes like a.size += 1 is not reflected in the caller.
// a.size += 1이 영향을 주지않는다는것이다 그래서 그다음 바나나를해도 a.size 는 그냥 0 으로 뜨는것이다 두번째로 append1을 call 한다고 a.size가 늘어나지않는다.
void append1_bad(List a, String to_add){
    // TODO: What if array is full?
    a.the_actual_data[a.size] = to_add;
    a.size += 1;

}


// List param을 포인터로 만들어준다
void append1_good(List* a, String to_add){
    // TODO: What if array is full?
    // 이제 포인터로 해주면 a.the_actual_data를 하면 오류가 생긴다. 포인터로 field를 access 해주고싶을때는 ->를 해준다
    // -> : go through the pointer into the memory and access the field data.
    a->the_actual_data[a->size] = to_add;
    a->size += 1;

}


int main() {
    List a = new_List();
    append1(&a, new_String("apple"));
    // printf("%d %s\n", a.size, a.the_actual_data[0].contents);
    append1(&a, new_String("banana"));
    // printf("%d %s\n", a.size, a.the_actual_data[0].contents);
    // printf("%d %s\n", a.size, a.the_actual_data[1].contents);
    append1(&a, new_String("cranberry"));
    append1(&a, new_String("doughnut"));
    // solve: a 가아닌 &a 로 해주는 이유가 data의 copy를 만들지말고 그 주소를 가져가서 쓰라 이거다.
    // 이렇게하면 print들이 이제는
    // 1 apple
    // 2 apple
    // 2 banana
    

    // 그냥 &a 가아닌 a 로 append1을 전달했을때
    // print들의 실제 출력값은 0 apple
                           // 0 banana
                           // 0(null)
    // 이렇게 나온다. 왜? structs, copy their contents when they passed as argument
    // when we pass a into the append1 it make a copy of whole struct
    // new spot for size field , capacity field, but the address of the content is the same so we can still change what's in the array
    // 
    String astr = to_string(a);
    printf("%s\n", astr.contents);

    //expect to print [apple, banana, cranberry, doughnut]
}
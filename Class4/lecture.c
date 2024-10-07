#include <stdio.h>
#include <string.h>

char firstfour(char c){     
    return c & 0b11110000;  
}

char lastfour(char c){      
    return c & 0b00001111;  
}

// firstfour(0b01010101) = 0b01010000 
// lastfour(0b11110011) = 0b00000011
// firstfour(192)  = firstfour(0b11000000) = 0b11000000
// firstfour(lastfour(x)) = 0
char startswith1110(char c){ // no matter what types of variable you return 0: false, anyother value: true.


    return firstfour(c) == 0b11100000;
    // return firstfour(c) == 0b11100000, no Counterexample. ( O )
    // return c > 0b11100000 1110, counterexample: 0b11110000 (this is true, but not starting with 1110 so, invalid function)
    // return (c & 0b11100000) == 0b11100000, counterexample: 0b11110000 (this is true, but not starting with 1110 so, invalid function)
}


// 
void inspect(char s[]) {
    int index = 0;
    printf("%s, length %ld: ", s, strlen(s));
    while(s[index] != 0) {
        char current = s[index];
        printf("%c (%hhu 0b", current, current);

        // Printing the binary scope of a character.
        for(int place = 128; place > 0; place /= 2) { 
            if((current & place) == 0) printf("0"); // & single & (bitwise &)
            else printf("1");
        }

        printf(") ");
        index += 1;
    }
    printf("\n");
}

// 보통 alphabet 이 아니면 2bytes or bigger 로 시작해서 0b110.....  0b10...... code points up to 2^11
// 만약 3bytes 를 사용하는 언어가 생기면(ex 일본어) 0b1110....   0b10......   0b10...... code points up to 2^16
// 더 나아가 4bytes(ex 피카츄 이모지) 0b11110...  0b10......(3times)    code up to 2^21

// Basically Unicode is a map(lookup table) from code points to (glyph, character)

// 각 사이트에서 이모지가 다 다르게 생긴이유는 같은 unicode로 부터 다른 font를 사용하기때문에 다르게 보이는것. 

int main() {
    char input[100];
    fgets(input, 100, stdin);
    printf("\n");
    inspect(input);

    return 0;
}
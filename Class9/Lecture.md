Pointer: A variable in C that can store the address of another variable (or function)

Char num[] = {42};  // store 42 in some part of memory in some byte, ex 0xFFFF
char* pnum = num; // Stores the address in pnum memory. so we can reference it.
assert(pnum[0] == 42);

int *p = NULL; // Address 0 as a invalid address.
*p = 5; // If i try to store the value in Address 0 then it crashes. 
 
char arr[] ={4, 5, 6}; // will be stored next to each other.
char c = '!'; // stored right next to arr's values. 6, 5, 4, ! in address.

char arr[3] = {4,5,6};
printf("arr=%p\n", arr);
// its gonna output 0xFFEF which is address of value 4(beginning of the array)

An array is a contiguous region of memory
    the array variable points to the start of this region

We add to the pointer to do indexing in the array

so when we do an array index(ex arr[3]) the compiler will do pointer math
    arr[3] -> arr + (3 *sizeof(long int))

&: get the address.
char* pnum = &num; // & take the variable and the give the address of variable 

*: derefenence address
char num2 = *pum; // go to the address and fetch the content.
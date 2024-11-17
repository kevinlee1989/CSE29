#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main(){

    map<char, int> result;

    result['c'] = 3;

    cout << "  " << result.second << endl;
}
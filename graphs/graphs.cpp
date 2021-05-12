#include <iostream>

#include "mystack.h"

using namespace std;



int main() {
    myStack<int> s1;
    s1.pushStack( 10);
    s1.pushStack(20);
    s1.pushStack(30);

    s1.PrintStack(s1);


    return 0;
}
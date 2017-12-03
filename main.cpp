#include <iostream>
#include <string>
#include "String.h"

using namespace std;

int main() {

    String str1("hello, world!");
    cout << str1.length() << endl;

    String str2("HELLO, WORLD!");
    cout << str2.length() << endl;

    str1.print();
    str2.print();
    str1.append(str2);
    str1.print();
    str2.append("I'm ryx.");
    str2.print();
    str2.append("I'm ryx.");
    str2.print();

    String str3(" ");
    str3.append(str1, 0, 3);
    str3.print();



    return 0;
}
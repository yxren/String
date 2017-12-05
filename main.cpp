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

    String str3(" ");
    str3.append(str1, 0, 3);
    str3.print();

    string str4("hello world!", 2, 4);
    cout << str4 << endl;

    String str5(str1, 2, 4);
    str5.print();

    String str6("hello world!", 3, 4);
    str6.print();

    string str7("hello world!", 3);
    cout << str7 << endl;

    string str8(7, 'n');
    cout << str8 << endl;

    String str9("hello world!", 3);
    str9.print();

    String str10(str1, 4);
    str10.print();

    String str11(5, 'n');
    str11.print();

    str3.append(str5, 2);
    str3.print();

    str5.print();
    str5.append(str6, 1, 2);
    str5.print();

    str6.append(" hello", 3);
    str6.print();

    str9.append(7, 'a');
    str9.print();

    string str12("hello ");
    str12.append(str4, 1, 2);
    cout << str12 << endl;

    string str13("hi! ");
    str13.assign(str12);
    cout << str13 << endl;
    str12 = "qwer!";
    cout << str12 << endl;
    cout << str13 << endl;

    str11.assign(str10);
    str11.print();

    String str14("hello");
    cout << str14.at(4) << endl;

    string str15("hello world.");
    str15.back() = '!';
    cout << str15 << endl;

    String str16("hello world.");
    str16.back() = '!';
    str16.print();


    return 0;
}
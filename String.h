//
// Created by Athena on 25/11/2017.
//

#ifndef STRING_STRING_H
#define STRING_STRING_H

#include <string.h>
#include <iostream>


class String {
public:
    String();
    String(const char* s);
    String(const String& str);
    int length() const { return _size; }
    int print() const;
    String& append(const String&);
    String& append(const String&, int, int);
    String& append(const char* s);
    ~String();
private:
    int _size = -1;
    char* _data;
};

inline
String::String() : _data(new char[1])
{
    *_data = '\0';
    _size = strlen(_data);
}

inline
String::String(const char* s) : _data(new char[strlen(s)+1])
{
    strcpy(_data, s);
    _size = strlen(_data);
}

inline
String::String(const String& str) : _data(new char[str.length()+1])
{
    strcpy(_data, str._data);
    _size = str.length();
}

inline
int String::print() const
{
    std::cout << _data << std::endl;
    return _size;
}

inline
String& String::append(const String& str)
{
    char* temp = new char[_size + str.length() + 1];
    strcpy(temp, _data);
    strcat(temp, str._data);
    _data = temp;
    return *this;
}

inline
String& String::append(const String& str, int subpos, int sublen)
{
    int len = sublen - subpos;
    int _i = 0;
    char* temp = new char[len + 1];
    char* p = str._data + subpos;
    while(subpos != sublen)
    {
        temp[_i++] = *p++;
        subpos++;
    }
    strcat(_data, temp);
    return *this;
}

inline
String& String::append(const char *s)
{
    String str(s);
    char* temp = new char[_size + str.length() + 1];
    strcpy(temp, _data);
    strcat(temp, str._data);
    _data = temp;
    return *this;
}

inline
String::~String()
{
    delete[] _data;
    _size = -1;
}


#endif //STRING_STRING_H

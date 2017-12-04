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
    explicit String(const char*);   // from c-string
    String(const String&);  // copy
    String(const String&, int);
    String(const String&, int, int);
    String(const char*, int, int);
    String(const char*, int);
    String(int, char);
    int length() const { return _size; }
    int print() const;
    String& append(const String&);
    String& append(const String&, int);
    String& append(const String&, int, int);
    String& append(const char*);
    String& append(const char*, int);
    String& append(int, char);
    ~String();
private:
    int _size = -1;
    char* _data;
};

inline
String::String() : _data(new char[1]), _size(0)
{
    *_data = '\0';
}

inline
String::String(const char* s) : _data(new char[strlen(s)+1]), _size((int)strlen(s))
{
    strcpy(_data, s);
}

inline
String::String(const String& str) : _data(new char[str.length()+1]), _size(str.length())
{
    strcpy(_data, str._data);
}

inline
String::String(const String& str, int n) : _data(new char[n + 1]), _size(n)
{
    auto temp = new char[n + 1];
    int _i = 0;
    while(_i < n)
    {
        temp[_i] = str._data[_i];
        _i++;
    }
    strcpy(_data, temp);
}

inline
String::String(const String& str, int pos, int len) : _data(new char[len - pos + 2]) ,_size(len - pos + 1)
{
    auto temp = new char[len - pos + 2];
    int _i = 0;
    while(pos <= len)
    {
        temp[_i++] = str._data[pos++];
    }
    _data = temp;
}

inline
String::String(const char* s, int n) : _data(new char[n + 1]), _size(n)
{
    auto temp = new char[n + 1];
    int _i = 0;
    while(_i < n)
    {
        temp[_i] = s[_i];
        _i++;
    }
    strcpy(_data, temp);
}

inline
String::String(const char* s, int pos, int len) : _data(new char[len - pos + 2]), _size(len - pos + 1)
{
    auto temp = new char[len - pos + 2];
    int _i = 0;
    while(pos <= len)
    {
        temp[_i++] = s[pos++];
    }
    _data = temp;
}

inline
String::String(int n, char c) : _data(new char[n + 1]), _size(n)
{
    auto temp = new char[n + 1];
    int _i = 0;
    while(_i < n)
    {
        temp[_i++] = c;
    }
    _data = temp;
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
    auto temp = new char[_size + str.length() + 1];
    strcpy(temp, _data);
    strcat(temp, str._data);
    _data = temp;
    return *this;
}

inline
String& String::append(const String& str, int n)
{
    auto temp = new char[_size + n + 1];
    auto _str = new char[n + 1];
    int _i = 0;
    while(_i < n)
    {
        _str[_i] = str._data[_i];
        _i++;
    }
    strcpy(temp, _data);
    strcat(temp, _str);
    _data = temp;
    return *this;
}

inline
String& String::append(const String& str, int subpos, int sublen)
{
    int _i = 0;
    auto temp = new char[sublen - subpos + 2];
    char* p = str._data + subpos;
    while(subpos <= sublen)
    {
        temp[_i++] = *p;
        p++;
        subpos++;
    }
    strcat(_data, temp);
    return *this;
}

inline
String& String::append(const char *s)
{
    String str(s);
    auto temp = new char[_size + str.length() + 1];
    strcpy(temp, _data);
    strcat(temp, str._data);
    _data = temp;
    return *this;
}

inline
String& String::append(const char* s, int n)
{
    auto temp = new char[_size + n + 1];
    auto _str = new char[n + 1];
    int _i = 0;
    while(_i < n)
    {
        _str[_i] = s[_i];
        _i++;
    }
    strcpy(temp, _data);
    strcat(temp, _str);
    _data = temp;
    return *this;
}

inline
String& String::append(int n, char c)
{
    auto temp = new char[_size + n + 1];
    auto _str = new char[n + 1];
    int _i = 0;
    while(_i != n)
    {
        _str[_i++] = c;
    }
    strcpy(temp, _data);
    strcat(temp, _str);
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

//
// Created by Athena on 25/11/2017.
//

#ifndef STRING_STRING_H
#define STRING_STRING_H

#include <string.h>
#include <iostream>
#include <iterator>
#include <vector>

namespace RYX {
    class String {
    public:
        String();

        explicit String(const char *);   // from c-string
        String(const String &);  // copy
        String(const String &, int);
        String(const String &, int, int);
        String(const char *, int, int);
        String(const char *, int);
        String(int, char);
        ~String();
        int length() const { return _size; }
        int print() const;
        String& append(const String &);
        String& append(const String &, int);
        String& append(const String &, int, int);
        String& append(const char *);
        String& append(const char *, int);
        String& append(char *, int, int);
        String& append(int, char);
        String& assign(const String &);
        String& assign(const String &, int);
        String& assign(const String &, int, int);
        String& assign(const char *);
        String& assign(const char *, int);
        String& assign(char *, int, int);
        String& assign(int, char);
        char& at(int);
        const char& at(int) const;
        char& back();
        const char& back() const;
        //std::iterator begin() noexcept;
        //const std::iterator begin() const noexcept;
        //size_t capacity() const noexcept;
        void clear() noexcept;
        int compare(const String &) const noexcept;
        int compare(int, int, const String &) const;
        int compare(int, int, const String &, int, int) const;
        int compare(const char *) const;
        int compare(int, int, const char *) const;
        int compare(int, int, const char *, int) const;
        int copy(char *, int, int) const;
        const char* data() const noexcept;
        bool empty() const noexcept;
        String& insert(int, const String&);
        String& insert(int, const String&, int, int);
        String& insert(int, const char*);
        String& insert(int, const char* s, int n);
        String& insert(int, int, char);

    private:
        int _size = -1;
        char *_data;
    };

    inline
    String::String() : _data(new char[1]), _size(0) {
        *_data = '\0';
    }

    inline
    String::String(const char *s) : _data(new char[strlen(s) + 1]), _size((int) strlen(s)) {
        strcpy(_data, s);
    }

    inline
    String::String(const String &str) : _data(new char[str.length() + 1]), _size(str.length()) {
        strcpy(_data, str._data);
    }

    inline
    String::String(const String &str, int n) : _data(new char[n + 1]), _size(n) {
        auto temp = new char[n + 1];
        int _i = 0;
        while (_i < n) {
            temp[_i] = str._data[_i];
            _i++;
        }
        strcpy(_data, temp);
    }

    inline
    String::String(const String &str, int pos, int len) : _data(new char[len - pos + 2]), _size(len - pos + 1) {
        auto temp = new char[len - pos + 2];
        int _i = 0;
        while (pos <= len) {
            temp[_i++] = str._data[pos++];
        }
        _data = temp;
    }

    inline
    String::String(const char *s, int n) : _data(new char[n + 1]), _size(n) {
        auto temp = new char[n + 1];
        int _i = 0;
        while (_i < n) {
            temp[_i] = s[_i];
            _i++;
        }
        strcpy(_data, temp);
    }

    inline
    String::String(const char *s, int pos, int len) : _data(new char[len - pos + 2]), _size(len - pos + 1) {
        auto temp = new char[len - pos + 2];
        int _i = 0;
        while (pos <= len) {
            temp[_i++] = s[pos++];
        }
        _data = temp;
    }

    inline
    String::String(int n, char c) : _data(new char[n + 1]), _size(n) {
        auto temp = new char[n + 1];
        int _i = 0;
        while (_i < n) {
            temp[_i++] = c;
        }
        _data = temp;
    }

    inline
    String::~String() {
        delete[] _data;
        _size = -1;
    }

    inline
    int String::print() const {
        std::cout << _data << std::endl;
        return _size;
    }

    inline
    String& String::append(const String &str) {
        auto temp = new char[_size + str.length() + 1];
        strcpy(temp, _data);
        strcat(temp, str._data);
        _data = temp;
        _size = (int) strlen(_data);
        return *this;
    }

    inline
    String& String::append(const String &str, int n) {
        auto temp = new char[_size + n + 1];
        auto _str = new char[n + 1];
        int _i = 0;
        while (_i < n) {
            _str[_i] = str._data[_i];
            _i++;
        }
        strcpy(temp, _data);
        strcat(temp, _str);
        _data = temp;
        _size = (int) strlen(_data);
        return *this;
    }

    inline
    String& String::append(const String &str, int subpos, int sublen) {
        int _i = 0;
        auto temp = new char[sublen - subpos + 2];
        char *p = str._data + subpos;
        while (subpos <= sublen) {
            temp[_i++] = *p;
            p++;
            subpos++;
        }
        strcat(_data, temp);
        _size = (int) strlen(_data);
        return *this;
    }

    inline
    String& String::append(const char *s) {
        String str(s);
        auto temp = new char[_size + str.length() + 1];
        strcpy(temp, _data);
        strcat(temp, str._data);
        _data = temp;
        _size = (int) strlen(_data);
        return *this;
    }

    inline
    String& String::append(const char *s, int n) {
        auto temp = new char[_size + n + 1];
        auto _str = new char[n + 1];
        int _i = 0;
        while (_i < n) {
            _str[_i] = s[_i];
            _i++;
        }
        strcpy(temp, _data);
        strcat(temp, _str);
        _data = temp;
        _size = (int) strlen(_data);
        return *this;
    }

    inline
    String& String::append(char *s, int subpos, int sublen) {
        int _i = 0;
        auto temp = new char[sublen - subpos + 2];
        char *p = s + subpos;
        while (subpos <= sublen) {
            temp[_i++] = *p;
            p++;
            subpos++;
        }
        strcat(_data, temp);
        _size = (int) strlen(_data);
        return *this;
    }

    inline
    String& String::append(int n, char c) {
        auto temp = new char[_size + n + 1];
        auto _str = new char[n + 1];
        int _i = 0;
        while (_i != n) {
            _str[_i++] = c;
        }
        strcpy(temp, _data);
        strcat(temp, _str);
        _data = temp;
        _size = (int) strlen(_data);
        return *this;
    }

    inline
    String& String::assign(const String &str) {
        auto temp = new char[str._size + 1];
        char *p = str._data;
        int _i = 0;
        while (_i < str._size) {
            temp[_i] = *p;
            _i++;
            p++;
        }
        _data = temp;
        _size = (int) strlen(temp);
        return *this;
    }

    inline
    String& String::assign(const String &str, int n) {
        auto temp = new char[n + 1];
        char *p = str._data;
        int _i = 0;
        while (_i < n) {
            temp[_i] = *p;
            p++;
            _i++;
        }
        _data = temp;
        _size = (int) strlen(temp);
        return *this;
    }

    inline
    String& String::assign(const String &str, int subpos, int sublen) {
        int _i = 0;
        auto temp = new char[sublen - subpos + 2];
        char *p = str._data + subpos;
        while (subpos <= sublen) {
            temp[_i++] = *p;
            p++;
            subpos++;
        }
        _data = temp;
        _size = (int) strlen(temp);
        return *this;
    }

    inline
    String& String::assign(const char *s) {
        auto len = (int) strlen(s);
        auto temp = new char[len + 1];
        int _i = 0;
        while (_i < len) {
            temp[_i] = s[_i];
            _i++;
        }
        _data = temp;
        _size = (int) strlen(_data);
        return *this;
    }

    inline
    String& String::assign(const char *s, int n) {
        auto temp = new char[n + 1];
        int _i = 0;
        while (_i < n) {
            temp[_i] = s[_i];
            _i++;
        }
        _data = temp;
        _size = (int) strlen(_data);
        return *this;
    }

    inline
    String& String::assign(char *s, int subpos, int sublen) {
        int _i = 0;
        auto temp = new char[sublen - subpos + 2];
        char *p = s + subpos;
        while (subpos <= sublen) {
            temp[_i++] = *p;
            p++;
            subpos++;
        }
        _data = temp;
        _size = (int) strlen(temp);
        return *this;
    }

    inline
    String& String::assign(int n, char c) {
        auto temp = new char[n + 1];
        int _i = 0;
        while (_i != n) {
            temp[_i++] = c;
        }
        _data = temp;
        _size = (int) strlen(_data);
        return *this;
    }

    inline
    char& String::at(int pos) {
        char &ref = *(_data + pos);
        return ref;
    }

    inline
    const char& String::at(int pos) const {
        const char &ref = *(_data + pos);
        return ref;
    }

    inline
    char& String::back() {
        char &ref = _data[_size - 1];
        return ref;
    }

    inline
    const char& String::back() const {
        const char &ref = _data[_size - 1];
        return ref;
    }

    inline
    void String::clear() noexcept {
        _data = "";
        _size = 0;
    }

    inline
    int String::compare(const String &str) const noexcept {
        size_t _i = 0;
        while (_i < str.length()) {
            if (*(_data + _i) != *(str._data + _i)) return 0;
            //if(*p != *q) return 0;
            _i++;
        }
        return 1;
    }

    inline
    int String::compare(int pos, int len, const String &str) const {
        auto temp = new char[len + 1];
        char *p = _data + pos;
        int _i = 0;
        while (_i < len) {
            temp[_i] = *p;
            p++;
            _i++;
        }
        _i = 0;
        char *q = str._data;
        while (_i < str.length()) {
            if (temp[_i] != *q) return 0;
            q++;
            _i++;
        }
        return 1;
    }


    inline
    int String::compare(int pos, int len, const String &str, int subpos, int sublen) const {
        auto temp = new char[len + 1];
        char *p = _data + pos;
        int _i = 0;
        while (_i < len) {
            temp[_i] = *p;
            p++;
            _i++;
        }

        auto temp2 = new char[sublen + 1];
        char *q = str._data + subpos;
        _i = 0;
        while (_i < sublen) {
            temp2[_i] = *q;
            q++;
            _i++;
        }

        _i = 0;
        while (_i < strlen(temp)) {
            if (temp[_i] != temp2[_i]) return 0;
            _i++;
        }
        return 1;
    }


    inline
    int String::compare(const char *s) const {
        auto temp = new char[_size + 1];
        int _i = 0;
        temp = _data;
        while (_i < _size) {
            if (temp[_i] != s[_i]) return 0;
            _i++;
        }
        return 1;
    }


    inline
    int String::compare(int pos, int len, const char *s) const {
        auto temp = new char[len + 1];
        char *p = _data + pos;
        int _i = 0;
        while (_i < len) {
            temp[_i] = *p;
            p++;
            _i++;
        }
        _i = 0;
        while (_i < strlen(s)) {
            if (temp[_i] != s[_i]) return 0;
            _i++;
        }
        return 1;
    }


    inline
    int String::compare(int pos, int len, const char *s, int n) const {
        auto temp = new char[len + 1];
        char *p = _data + pos;
        int _i = 0;
        while (_i < len) {
            temp[_i] = *p;
            p++;
            _i++;
        }
        _i = 0;
        while (_i < n) {
            if (temp[_i] != s[_i]) return 0;
            _i++;
        }
        return 1;
    }

    inline
    int String::copy(char *s, int len, int pos = 0) const {
        char *p = _data + pos;
        int _i = 0;
        while (_i < len) {
            s[_i] = *p;
            p++;
            _i++;
        }
        return len;
    }

    inline
    const char* String::data() const noexcept
    {
        return _data;
    }

    inline
    bool String::empty() const noexcept
    {
        if(_size)  return false;
        return true;
    }
}


#endif //STRING_STRING_H

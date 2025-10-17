#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>


class MyString
{   
    public:
        char *str;
        int len;
    
        MyString(); //default const
        MyString(const char *s); //para const
        MyString(const MyString&  other); //copy constructor
        ~MyString(); //destructor
        MyString& operator=(const MyString& c); //copy assignment
        MyString operator+(const MyString& c); //concatenate
        bool operator==(const MyString& c); //compare
        friend void Reverse();
        friend std::ostream &operator<<(std::ostream &os, const MyString &list);
};
std::ostream &operator<<(std::ostream &os, const MyString &list);
void Reverse(MyString &c);

#endif 
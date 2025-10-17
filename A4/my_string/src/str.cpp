#ifndef STR
#define STR
#include <iostream>
#include <cstring>
#include "str.h"
using namespace std;

MyString::MyString(): str(strdup("")){}

MyString::MyString(const char *s): str(strdup(s)), len(strlen(str)){}

MyString::MyString(const MyString& s): str(strdup(s.str)), len(s.len){}

MyString::~MyString() //destructor
{
    free(str);
}

MyString& MyString::operator=(const MyString& s) { // Copy Assignment Operator
    if (this != &s) { // Check if the source and destination are same
        free(str);
        str= strdup(s.str);
        len= s.len;
    }
    return *this;
}

MyString MyString::operator+(const MyString& c){
    MyString ans;
    ans.len = (this->len)+c.len + 1;
    ans.str = (char*)malloc((ans.len)*sizeof(char));
    
    for(int i=0; i<this->len; i++){
        ans.str[i]=this->str[i];
    }
    for(int i=this->len; i<ans.len; i++){
        ans.str[i]=c.str[i-(this->len)];
    }

    return ans;
}

bool MyString::operator==(const MyString& c){
    if(len!=c.len) return false;

    for(int i=0; i<c.len; i++){
        if(this->str[i]!=c.str[i]) return false;
    }
    return true;
}


std::ostream &operator<<(std::ostream &os, const MyString &list)
{
        cout<<list.str<<endl;
}

void Reverse(MyString& c){
    for(int i=0; i<c.len/2; i++){
        char k = c.str[i];
        c.str[i]=c.str[c.len-1-i];
        c.str[c.len-1-i]=k;
    }
}

int main(){
    MyString A("HEY"), B("HEYY");
    MyString C=A+B;
    cout<<C;
}
#endif 
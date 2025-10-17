#include <iostream>
using namespace std;

class List
{
private:
    
    int *data;
    int size ;

public:
    List() : size(0) {};

    int getdata(int k){
        return this->data[k];
    }
    int getSize(){
        return size;
    }
    void setSize(int k){
        this->size=k;
    }
    void append(int k){
        int *p = new int [size+1];
        for(int i=0; i<size; i++) p[i]=this->getdata(i);
        p[size]=k;
        data=NULL;
        data=p;
        (this->size)++;
    }

    int operator[](int k){
        if(k>=size){
            throw std::out_of_range("Out\n");
        }
        return data[k];
    }

    List operator=(List &list){
        this->setSize(0);
        for(int i=0; i<list.getSize(); i++) this->append(list.getdata(i));
        return *this;
    }

    List operator+(List &B){
        List ans;
        for(int i=0; i<this->getSize(); i++) ans.append(this->getdata(i));
        for(int i=0; i<B.getSize(); i++) ans.append(B.getdata(i));
        return ans;
    }
    // Implement functionality of the list

    // This function is used to print the list.
    // The signature of this function is kept since 'friend' functions have not been covered yet. You may
    // ignore the 'friend' keyword and implement the function as a normal member function.
    friend std::ostream &operator<<(std::ostream &os, const List &list)
    {
        List n=list;
        os << "[";
            for(int i=0; i<list.size; i++) {
                int k = n.getdata(i);
                if(i!=0) os<<", ";
                os << k;
            }
        os << "]";
        return os;
    }

};
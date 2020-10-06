#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef __ARRAY__
#define __ARRAY__

template <class T>
class Array{
    protected:
	T * data;   
	int len;    
    public:
	Array(int size);
	~Array();          

	int length() const; 
	T& operator[](int i);       
	T operator[](int i) const;   

	void print();
};

template <class T>
Array<T>::Array(int size){
    if(size < 0){
	cout << "Array size should be 0 or more" << '\n';
	exit(-1);
    }
    else{       
	data = (T *)calloc(sizeof(T), size);
	len = size;
    }
}

template <class T>
Array<T>::~Array(){
    free(data);
}

template <class T>
int Array<T>::length() const{
    return len;
}

template <class T>
T& Array<T>::operator[](int i){
    static T tmp; 

    if(0 <= i && i < len) return *(data + i);  
    else{                                      
	cout << "Array bound error!" << '\n';
	return tmp;
    }
}

template <class T>
T Array<T>::operator[] (int i) const{
    if(0 <= i && i < len) return *(data + i);  
    else{                                     
	cout << "Array bound error!" << '\n';
	return 0;
    }
}

template <class T>
void Array<T>::print(){
    int i;
    cout << "[ ";
    for(i = 0 ; i < len-1; i++)
	cout << data[i] << ' ';
    cout << data[i] << " ]" << '\n';
}



#endif


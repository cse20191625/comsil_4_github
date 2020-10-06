#ifndef GAR
#define GAR
#include "Array.h"

template <class T>
class GrowableArray:public Array<T>{
    public :
	GrowableArray(int); 
	~GrowableArray();   

	T& operator[](int i);      
	T operator[](int i) const; };

template <class T>
GrowableArray<T>::GrowableArray(int i):Array<T>(i){};

template <class T>
GrowableArray<T>::~GrowableArray(){};

template <class T>
T& GrowableArray<T>::operator[](int i){
    static T tmp;

    if(i >= Array<T>::len){ 
	Array<T>::len *= 2;
	Array<T>::data = (T *)realloc(Array<T>::data, sizeof(T) * Array<T>::len);
	for(int j = Array<T>::len / 2; j < Array<T>::len; j++) *(Array<T>::data + j) = 0;

	return *(Array<T>::data + i);
    }
    else if(i < 0){         
	cout << "Array bound error!" << '\n';
	return tmp;
    }
    else{                    
	return *(Array<T>::data + i);
    }
}

template <class T>
T GrowableArray<T>::operator[](int i) const{
    if(i >= Array<T>::len){  
	Array<T>::len *= 2;
	Array<T>::data = (T *)realloc(Array<T>::data, sizeof(T) * Array<T>::len);
	for(int j = Array<T>::len / 2; j < Array<T>::len; j++) *(Array<T>::data + j) = 0;

	return *(Array<T>::data + i);
    }
    else if(i < 0){          
	cout << "Array bound error!" << '\n';
	return 0;
    }
    else{                   
	return *(Array<T>::data + i);
    }

}


#endif


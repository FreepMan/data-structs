#ifndef FREEP_VECTOR_H
#define FREEP_VECTOR_H

#include <stdexcept>

template<typename T>
class vector
{
private:
    size_t reserve = 4;
    size_t vectorSize = 0;
    T *data;
public:
    // init
    vector(); // initialization of empty vector
    vector(size_t); // initialization of empty vector with selected elements
    vector(size_t, T);
    
    // func
    size_t size();
    T at(size_t);
    T front();
    T back();
    bool empty();
    vector &push_back(T);
    T pop_back();
    size_t capacity();
    void reserve(size_t);
    size_t begin();
    size_t end();
    void resize(size_t);


};

// initialization of vector

// initialization of empty vector
template<typename T>
vector<T>::vector(){
    data = new T[reserve];
}

// initialization of empty vector with selected elements
template<typename T>
vector<T>::vector(size_t val){
    if(reserve < val){
        resize(val);
    }
    data = new T[reserve];
    size = val;
}

// initialization of vector with selected ammount of elements and selected data
template<typename T>
vector<T>::vector(size_t val, T dat){
    if(reserve < val){
        resize(val);
    }
    data = new T[reserve];
    for(size_t i = 0; i != val; i++){
        push(dat)
    }
}

// functions of vector

template<typename T>
size_t vector<T>::size(){
    return vectorSize;
}

template<typename T>
T vector<T>::at(size_t index){
    if(index >= vectorSize){
        throw std::out_of_range("at::out of range");
    }
    return data[index];
}

template<typename T>
T vector<T>::front(){
    if(vectorSize == 0){
        throw std::out_of_range("front::vector is empty");
    }
    return at(0);
}

template<typename T>
T vector<T>::back(){
    if(vectorSize == 0){
        throw std::out_of_range("front::vector is empty");
    }
    return at(vectorSize - 1);
}

template<typename T>
bool vector<T>::empty(){
    bool result = false;
    if(vectorSize == 0){
        result = true;
    }
    return result;
}

template<typename T>
vector<T> &vector<T>::push_back(T newData){
    if(vectorSize == reserve){
        resize(vectorSize);
    }
    data[vectorSize] = newData;
    ++vectorSize;
    return *this;
}

#endif
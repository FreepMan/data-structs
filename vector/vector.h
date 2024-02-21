#ifndef FREEP_VECTOR_H
#define FREEP_VECTOR_H

#include <stdexcept>

template<typename T>
class vector
{
private:
    size_t reserveSize = 4;
    size_t vectorSize = 0;
    T *data;
    void resize(size_t);
public:
    // init
    vector(); // initialization of empty vector
    vector(size_t); // initialization of empty vector with selected size
    vector(size_t, T); // initialization of vector with selected size and data
    ~vector();
    
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

    // Operators
    vector &operator= (const vector<T>& vec);
    T &operator[](const size_t);
};

// initialization of vector

// initialization of empty vector
template<typename T>
vector<T>::vector(){
    data = new T[reserveSize];
}

// initialization of empty vector with selected elements
template<typename T>
vector<T>::vector(size_t val){
    if(reserveSize < val){
        resize(val);
    }
    data = new T[reserveSize];
    reserveSize = val;
}

// initialization of vector with selected ammount of elements and selected data
template<typename T>
vector<T>::vector(size_t val, T dat){
    if(reserveSize < val){
        resize(val);
    }
    data = new T[reserveSize];
    for(size_t i = 0; i != val; i++){
        push(dat);
    }
}

template<typename T>
vector<T>::~vector(){
    free(this->data);
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
    if(vectorSize == reserveSize){
        resize(reserveSize + 1);
    }
    data[vectorSize] = newData;
    ++vectorSize;
    return *this;
}

template<typename T>
T vector<T>::pop_back(){
    if(vectorSize == 0){
        throw std::out_of_range("Vector is empty.");
    }
    T toReturnData = data[vectorSize - 1];
    --vectorSize;
    return toReturnData;
}

template<typename T>
size_t vector<T>::capacity(){
    return reserveSize;
}

template<typename T>
void vector<T>::reserve(size_t toReserveSize){
    if(vectorSize != 0){
        throw std::out_of_range("Reserve is available only for empty vector");
    }
    if(toReserveSize < 4){
        throw std::out_of_range("Can not reserve less than 4 elements");
    }
    delete data;
    reserveSize = toReserveSize;
    data = new T[reserveSize];
}

template<typename T>
size_t vector<T>::begin(){
    return 0;
}

template<typename T>
size_t vector<T>::end(){
    size_t plastEl;
    if(empty()){
        plastEl = 0;
    }else{
        plastEl = vectorSize - 1;
    }
    return plastEl;
}

template<typename T>
void vector<T>::resize(size_t reserveNoLessThan){
    size_t newSize = 4;
    while(newSize <= reserveNoLessThan){
        newSize *= 2;
    }
    reserveSize = newSize;
    // vector<T> *newVector = new vector<T>(newSize);
    // *newVector = *this;
    // delete this->data;
    // this = newVector;
    T *newArr = new T[newSize];
    for(size_t i = 0; i < vectorSize; i++){
        newArr[i] = data[i];
    }
    delete[] data;
    data = newArr;
    
}

template<typename T>
vector<T> &vector<T>::operator=(const vector<T> &vec){
    if(this->capacity() < vec.vectorSize){
        this->resize(vec.vectorSize);
    }
    this->vectorSize = vec.vectorSize;
    for(size_t i = 0; i < vec.vectorSize; i++){
        this->data[i] = vec.data[i];
    }
    return *this;
}

template<typename T>
T &vector<T>::operator[] (size_t point){
    return *(data+point);
}
#endif
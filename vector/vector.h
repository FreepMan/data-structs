#ifndef FREEP_VECTOR_H
#define FREEP_VECTOR_H

template<typename T>
class vector
{
private:
    size_t reserve = 4;
    size_t size = 0;
    T *data = new T[reserve];
public:
    vector(/* args */);
    ~vector();
};

vector::vector(/* args */)
{
}

vector::~vector()
{
}


#endif
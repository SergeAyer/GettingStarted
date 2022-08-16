#include "singleton.hpp"

Singleton *Singleton::_INSTANCE = nullptr;

// private constructor
Singleton::Singleton() : _data(0) 
{
}

Singleton &Singleton::getInstance() 
{
    if (_INSTANCE == nullptr) {
        _INSTANCE = new Singleton();
    }
    return *_INSTANCE;
}

int Singleton::getData() 
{
    return this->_data;
}
 
void Singleton::setData(int data) 
{
    this->_data = data;
}

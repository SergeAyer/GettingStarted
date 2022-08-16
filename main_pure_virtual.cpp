#include "mbed.h"

#include "mbed_trace.h"
#if MBED_CONF_MBED_TRACE_ENABLE
#define TRACE_GROUP "main"
#endif // MBED_CONF_MBED_TRACE_ENABLE

class Abstract
{
public:
    virtual void m1()
    {
        tr_debug("m1 in Abstract class called");
    }
    virtual void m2()  = 0;
};
 
class Concrete : public Abstract
{
public:
    void m2() override // 'override' is optional
    {
        tr_debug("m2 in Concrete class called");
    }
};

int main()
{
    // use trace library for console output
    mbed_trace_init();

    // it is not possible to create an instance of Abstract
    // Abstract a;
    Concrete c;
    
    // virtual method call through reference
    c.m1(); // prints Abstract 
    c.m2(); // prints Concrete
    
    // c can be viewed as a reference to the Abstract class
    Abstract& a1 = c; 
    a1.m1(); // prints Abstract
    a1.m2(); // prints Concrete
    
    return 0;
}
#include "mbed.h"

#include "mbed_trace.h"
#if MBED_CONF_MBED_TRACE_ENABLE
#define TRACE_GROUP "main"
#endif // MBED_CONF_MBED_TRACE_ENABLE

class Base
{
public:
    virtual void m()
    {
        tr_debug("m in Base class called");
    }
};
 
class Derived : public Base
{
public:
    void m() override // 'override' is optional
    {
        tr_debug("m in Derived class called");
    }
};

int main_virtual()
{
    // use trace library for console output
    mbed_trace_init();

    // create both a Base and Derived instance
    Base b;
    Derived d;
    b.m(); // prints base
    d.m(); // prints derived
 
    // virtual method call through reference
    Base& br = b; // the type of br is Base&
    Base& dr = d; // the type of dr is Base& as well
    br.m(); // prints "base"
    dr.m(); // prints "derived" (because Base::f() is declared as virtual)
 
    // virtual method call through pointer
    Base* bp = &b; // the type of bp is Base*
    Base* dp = &d; // the type of dp is Base* as well
    bp->m(); // prints "base"
    dp->m(); // prints "derived" (because Base::f() is declared as virtual)
 
    // non-vimtual method calls
    br.Base::m(); // prints "base"
    dr.Base::m(); // prints "base"
    
    return 0;
}
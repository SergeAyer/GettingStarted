#include "mbed.h" 

#include "singleton.hpp" 

#include "mbed_trace.h"
#if MBED_CONF_MBED_TRACE_ENABLE
#define TRACE_GROUP "main"
#endif // MBED_CONF_MBED_TRACE_ENABLE

int main_singleton() 
{    
    // use trace library for console output
    mbed_trace_init();

    Singleton &s1 = Singleton::getInstance();
    tr_debug("Singleton data is %d", s1.getData());
    s1.setData(100);
    Singleton &s2 = Singleton::getInstance();
    tr_debug("Singleton data is %d", s2.getData());

    return 0;
}
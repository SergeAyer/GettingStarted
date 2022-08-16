#include "mbed.h"

#include "mbed_trace.h"
#if MBED_CONF_MBED_TRACE_ENABLE
#define TRACE_GROUP "main"
#endif // MBED_CONF_MBED_TRACE_ENABLE

void addOne(int i) 
{
    i++; // Has no effect outside this scope because this is a copy of the original
}

void addOne_ref(int &i) 
{
    i++; // Actually changes the original variable
}

void addOne(int *i) 
{
    (*i)++; // Actually changes the original variable, but i can be null ! 
}

int main_params() 
{    
    // use trace library for console output
    mbed_trace_init();

    int i = 0;
  
    addOne(i);
    tr_debug("value of i is %d\n", i);

    addOne_ref(i);
    tr_debug("value of i is %d\n", i);

    addOne(&i);
    tr_debug("value of i is %d\n", i);

    return 0;
}

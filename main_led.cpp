#include "mbed.h"

#include "led.hpp"

#include "mbed_trace.h"
#if MBED_CONF_MBED_TRACE_ENABLE
#define TRACE_GROUP "main"
#endif // MBED_CONF_MBED_TRACE_ENABLE

int main_led() {
    // use trace library for console output
    mbed_trace_init();
    
    LED led1(LED1);
    LED led2(LED2);
    while (true) {
        {
          // not used, only for demonstrating creation/destruction on the stack
          LED led3(LED3);
          // since the led3 object is destroyed when leaving the scope, it will blink only shortly
          // this call is required for preventing compiler optimization
          led3.toggle();
        }
        tr_debug("led1 state is %d", (int) led1);
        led1.toggle();
        ThisThread::sleep_for(500ms);
        led2.toggle();
        ThisThread::sleep_for(1000ms);
    }
}

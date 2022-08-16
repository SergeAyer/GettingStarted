/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <cstdint>

static constexpr uint32_t kGlobalConstantExpr = 1;
static const uint32_t kGlobalConstant = rand();
  
class ClassWithConstant 
{
public: 
  static constexpr uint32_t kConstantExpr = 2;
  static const uint32_t kConstant;// = kGlobalConstant * 2;
};
const uint32_t ClassWithConstant::kConstant = kGlobalConstant * 2;

int main1()
{       
    static constexpr std::chrono::seconds kBlinkInterval = 1s;
  
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);

    while (true) {
        led = !led;
        ThisThread::sleep_for(kBlinkInterval);
    }
}

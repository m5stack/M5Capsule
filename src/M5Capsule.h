/*
 *SPDX-FileCopyrightText: 2025 M5Stack Technology CO LTD
 *
 *SPDX-License-Identifier: MIT
 */

#ifndef M5CAPSULE_H
#define M5CAPSULE_H

#include "M5Unified.h"

namespace m5 {
class M5_CAPSULE {
private:
    /* data */

public:
    void begin();
    void begin(m5::M5Unified::config_t cfg);
    Power_Class &Power     = M5.Power;
    RTC8563_Class &Rtc     = M5.Rtc;
    Speaker_Class &Speaker = M5.Speaker;
    Mic_Class &Mic         = M5.Mic;
    Button_Class &BtnA     = M5.getButton(0);

    /// for internal I2C device
    I2C_Class &In_I2C = m5::In_I2C;

    /// for external I2C device (Port.A)
    I2C_Class &Ex_I2C = m5::Ex_I2C;
    void update(void);
};

}  // namespace m5

extern m5::M5_CAPSULE M5Capsule;

#endif
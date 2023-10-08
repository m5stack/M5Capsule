/**
 * @file buzzer.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5Capsule Buzzer Test
 * @version 0.1
 * @date 2023-10-08
 *
 *
 * @Hardwares: M5Capsule
 * @Platform Version: Arduino M5Stack Board Manager v2.0.7
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 */

#include "M5Capsule.h"

void setup() {
    auto cfg = M5.config();
    M5Capsule.begin(cfg);
}

void loop() {
    M5Capsule.Speaker.tone(10000, 100);
    delay(1000);
    M5Capsule.Speaker.tone(4000, 20);
    delay(1000);
}
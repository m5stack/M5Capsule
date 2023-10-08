/**
 * @file wakeup.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5Capsule Timer Wakeup Test
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

#include <M5Capsule.h>

void setup(void) {
    auto cfg = M5.config();
    M5Capsule.begin(cfg);

    Serial.println("Press Btn to sleep");
    Serial.println("After 5s Wakeup");
}

void loop(void) {
    M5Capsule.update();

    if (M5Capsule.BtnA.wasPressed()) {
        M5Capsule.Power.timerSleep(5);
        // M5Capsule.Power.timerSleep(const rtc_time_t& time);
        // M5Capsule.Power.timerSleep(const rtc_date_t& date, const rtc_time_t&
        // time);
        // M5Capsule.Power.powerOff(); shutdown
    }
}

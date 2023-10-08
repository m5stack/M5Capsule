/**
 * @file mic.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5Capsule Microphone Test
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

#define MIC_SAMPLE_RATE 16000
#define MIC_DATA_PIN    (41)
#define MIC_CLOCK_PIN   (40)

static void init_microphone(void) {
    i2s_config_t i2s_config = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX | I2S_MODE_PDM),
        .sample_rate          = MIC_SAMPLE_RATE,
        .bits_per_sample      = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format       = I2S_CHANNEL_FMT_ONLY_RIGHT,
        .communication_format = I2S_COMM_FORMAT_STAND_MSB,
        .intr_alloc_flags     = ESP_INTR_FLAG_LEVEL1,
        .dma_buf_count        = 4,
        .dma_buf_len          = 512,
        .use_apll             = 0,
    };

    i2s_pin_config_t pin_config = {
        .mck_io_num   = I2S_PIN_NO_CHANGE,
        .bck_io_num   = I2S_PIN_NO_CHANGE,
        .ws_io_num    = MIC_CLOCK_PIN,
        .data_out_num = I2S_PIN_NO_CHANGE,
        .data_in_num  = MIC_DATA_PIN,
    };

    // Call driver installation function before any I2S R/W operation.
    ESP_ERROR_CHECK(i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL));
    ESP_ERROR_CHECK(i2s_set_pin(I2S_NUM_0, &pin_config));
}

void setup(void) {
    auto cfg = M5.config();
    M5Capsule.begin(cfg);
    init_microphone();
}

static int16_t rec_buf[1024] = {0};
static size_t bytes_read;

void loop(void) {
    i2s_read(I2S_NUM_0, (char*)rec_buf, 1024, &bytes_read, portMAX_DELAY);
    // use monitor tool to see the data line
    for (int i = 0; i < bytes_read; i++) {
        Serial.printf("%d\r\n", rec_buf[i]);
    }
}

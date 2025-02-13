// Project 29.1: Buetooth Audio using PCM5102A

#include "BluetoothSerial.h"
#include "driver/i2s.h"
#include "nvs.h"
#include "nvs_flash.h"

#include "esp_bt.h"
#include "bt_app_core.h"
#include "bt_app_av.h"
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gap_bt_api.h"
#include "esp_a2dp_api.h"
#include "esp_avrc_api.h"

#define CONFIG_I2S_LRCK_PIN 25
#define CONFIG_I2S_BCK_PIN  26
#define CONFIG_I2S_DATA_PIN 22

// Initialize BluetoothSerial object called SerialBT:
BluetoothSerial SerialBT;

void setup() {
    // Initialize serial connection with ESP32 over usb:
    Serial.begin(115200);

    // Start BluetoothSerial instantiation and give it a name:
    SerialBT.begin("Daniel's ESP32 Bluetooth Speaker");

    // Print message to notify successful connection:
    Serial.println("Connection successful!");

    // Error handling:
    esp_err_t err = nvs_flash_init();
  
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }

    // Defines an I2S configuration class and initializes it:
    i2s_config_t i2s_config;
    i2s_config.mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX);
    
    i2s_config.bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT;
    i2s_config.sample_rate = 44100;
    i2s_config.channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT;
    i2s_config.communication_format = I2S_COMM_FORMAT_STAND_MSB;
    i2s_config.intr_alloc_flags = 0;
    i2s_config.dma_desc_num = 6;
    i2s_config.dma_frame_num = 60;
    i2s_config.tx_desc_auto_clear = true;
    i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
    
    i2s_pin_config_t pin_config;
    pin_config.mck_io_num = I2S_PIN_NO_CHANGE;
    pin_config.bck_io_num = CONFIG_I2S_BCK_PIN;
    pin_config.ws_io_num = CONFIG_I2S_LRCK_PIN;
    pin_config.data_out_num = CONFIG_I2S_DATA_PIN;
    pin_config.data_in_num = I2S_PIN_NO_CHANGE;
    i2s_set_pin(I2S_NUM_0, &pin_config);

    bt_app_task_start_up();
    
    // Initializes A2DP sink:
    esp_a2d_register_callback(&bt_app_a2d_cb);
    esp_a2d_sink_register_data_callback(bt_app_a2d_data_cb);
    esp_a2d_sink_init();
    
    // Initializes AVRCP controller:
    esp_avrc_ct_init();
    esp_avrc_ct_register_callback(bt_app_rc_ct_cb);
    
    // Sets discoverable and connectable mode, waits to be connected:
    esp_bt_gap_set_scan_mode(ESP_BT_CONNECTABLE, ESP_BT_GENERAL_DISCOVERABLE);
    
    // Print readiness notification:
    Serial.println("Ready.");
}

void loop(){
  ;  
}

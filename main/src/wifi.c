#include <stdio.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/event_groups.h"
#include <esp_http_server.h>
#include "../include/constants.h"
static const char *WIFI_TAG = "wifi";

static void wifi_event_handler(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
    switch (event_id)
    {
    case WIFI_EVENT_STA_START:
        ESP_LOGI(WIFI_TAG, "WiFi connecting ..."); 
        break;
    case WIFI_EVENT_STA_CONNECTED:
        ESP_LOGI(WIFI_TAG, "WiFi connected ...");
        break;
    case WIFI_EVENT_STA_DISCONNECTED:
        ESP_LOGI(WIFI_TAG, "WiFi lost connection ...");
        break;
    case IP_EVENT_STA_GOT_IP:
        ESP_LOGI(WIFI_TAG, "WiFi got IP ...");
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        ESP_LOGI(WIFI_TAG, "Got IP: " IPSTR, IP2STR(&event->ip_info.ip));

        break;
    default:
        break;
    }
}

esp_err_t wifi_init() {
    ESP_ERROR_CHECK(nvs_flash_init());
    // 1 - Wi-Fi/LwIP Init Phase
    ESP_ERROR_CHECK(esp_netif_init());                 // TCP/IP initiation 					s1.1
    ESP_ERROR_CHECK(esp_event_loop_create_default());  // event loop 			                s1.2
    esp_netif_create_default_wifi_sta();               // WiFi station                          s1.3
    wifi_init_config_t wifi_initiation = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&wifi_initiation); // 					                            s1.4
    // 2 - Wi-Fi Configuration Phase
    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, wifi_event_handler, NULL);
    esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, wifi_event_handler, NULL);
    wifi_config_t wifi_configuration = {
        .sta = {
            .ssid = {0},
            .password = {0}
        }
    };
    strncpy((char*)wifi_configuration.sta.ssid, WIFI_SSID, sizeof(wifi_configuration.sta.ssid) - 1); // {{ edit_3 }}
    strncpy((char*)wifi_configuration.sta.password, WIFI_PASS, sizeof(wifi_configuration.sta.password) - 1); // {{ edit_4 }}
    esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_configuration);
    
    // Set WiFi mode to station
    esp_wifi_set_mode(WIFI_MODE_STA);

    // 3 - Wi-Fi Start Phase
    esp_wifi_start();
    // 4- Wi-Fi Connect Phase
    esp_err_t ret = esp_wifi_connect();
    if (ret != ESP_OK) {
        ESP_LOGE(WIFI_TAG, "Failed to connect to WiFi: %s", esp_err_to_name(ret));
    }
    return ret;
}

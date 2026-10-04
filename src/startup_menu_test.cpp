// SPDX-License-Identifier: MIT
// Startup-menu hardware test only; intentionally disables all WiFi radio start.
#ifdef PORKCHOP_STARTUP_MENU_TEST
#include "esp_err.h"
#include "esp_wifi.h"
extern "C" esp_err_t __wrap_esp_wifi_start(void) {
    return ESP_ERR_NOT_SUPPORTED;
}
extern "C" esp_err_t __wrap_esp_wifi_set_promiscuous(bool) {
    return ESP_ERR_NOT_SUPPORTED;
}
extern "C" esp_err_t __wrap_esp_wifi_80211_tx(wifi_interface_t, const void *, int, bool) {
    return ESP_ERR_NOT_SUPPORTED;
}
#endif

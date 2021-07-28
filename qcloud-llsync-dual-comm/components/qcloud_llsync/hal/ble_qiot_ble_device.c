/*
 * Copyright (C) 2019 THL A29 Limited, a Tencent company. All rights reserved.
 * Licensed under the MIT License (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://opensource.org/licenses/MIT
 * Unless required by applicable law or agreed to in writing, software distributed under the License is
 * distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "ble_qiot_export.h"
#include "ble_qiot_service.h"
#include "ble_qiot_import.h"

// add std head file here
#include <stdint.h>

// add ble qiot head file here
#include "ble_qiot_config.h"
#include "ble_qiot_import.h"
#include "ble_qiot_log.h"
#include "ble_qiot_common.h"

#include "esp_bt_device.h"
#include "esp_spi_flash.h"
#include "esp_ota_ops.h"

#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"

#include "qcloud_iot_export.h"
#include "qcloud_iot_import.h"

#if 1
int ble_get_product_id(char *product_id)
{
    DeviceInfo devinfo;
    int ret = 0;

    ret = HAL_GetDevInfo(&devinfo);
    if (ret != QCLOUD_RET_SUCCESS) {
        return -1;
    }

    memcpy(product_id, devinfo.product_id, BLE_QIOT_PRODUCT_ID_LEN);

    return 0;
}

int ble_get_device_name(char *device_name)
{
    DeviceInfo devinfo;
    int ret = 0;

    ret = HAL_GetDevInfo(&devinfo);
    if (ret != QCLOUD_RET_SUCCESS) {
        return -1;
    }

    memcpy(device_name, devinfo.device_name, strlen(devinfo.device_name));

    return strlen(devinfo.device_name);
}

int ble_get_psk(char *psk)
{
    DeviceInfo devinfo;
    int ret = 0;

    ret = HAL_GetDevInfo(&devinfo);
    if (ret != QCLOUD_RET_SUCCESS) {
        return -1;
    }

    memcpy(psk, devinfo.device_secret, 24);

    return 0;
}
#endif

int ble_get_mac(char *mac)
{
    char *address = (char *)esp_bt_dev_get_address();
    memcpy(mac, address, 6);

    return 0;
}

typedef struct ble_esp32_timer_id_ {
    uint8_t       type;
    ble_timer_cb  handle;
    TimerHandle_t timer;
} ble_esp32_timer_id;

ble_timer_t ble_timer_create(uint8_t type, ble_timer_cb timeout_handle)
{
    ble_esp32_timer_id *p_timer = malloc(sizeof(ble_esp32_timer_id));
    if (NULL == p_timer) {
        return NULL;
    }

    p_timer->type   = type;
    p_timer->handle = timeout_handle;
    p_timer->timer  = NULL;

    return (ble_timer_t)p_timer;
}

ble_qiot_ret_status_t ble_timer_start(ble_timer_t timer_id, uint32_t period)
{
    ble_esp32_timer_id *p_timer = (ble_esp32_timer_id *)timer_id;

    if (NULL == p_timer->timer) {
        p_timer->timer =
            (ble_timer_t)xTimerCreate("ota_timer", period / portTICK_PERIOD_MS,
                                      p_timer->type == BLE_TIMER_PERIOD_TYPE ? pdTRUE : pdFALSE, NULL, p_timer->handle);
    }
    xTimerReset(p_timer->timer, portMAX_DELAY);

    return BLE_QIOT_RS_OK;
}

ble_qiot_ret_status_t ble_timer_stop(ble_timer_t timer_id)
{
    ble_esp32_timer_id *p_timer = (ble_esp32_timer_id *)timer_id;
    xTimerStop(p_timer->timer, portMAX_DELAY);

    return BLE_QIOT_RS_OK;
}

ble_qiot_ret_status_t ble_timer_delete(ble_timer_t timer_id)
{
    ble_esp32_timer_id *p_timer = (ble_esp32_timer_id *)timer_id;
    xTimerDelete(p_timer->timer, portMAX_DELAY);
    free(p_timer);

    return BLE_QIOT_RS_OK;
}

// return ATT MTU
uint16_t ble_get_user_data_mtu_size(void)
{
    return 128;
}

int ble_write_flash(uint32_t flash_addr, const char *write_buf, uint16_t write_len)
{
    int ret = spi_flash_erase_range(flash_addr, BLE_QIOT_RECORD_FLASH_PAGESIZE);
    ret     = spi_flash_write(flash_addr, write_buf, write_len);

    return ret == ESP_OK ? write_len : ret;
}

int ble_read_flash(uint32_t flash_addr, char *read_buf, uint16_t read_len)
{
    int ret = spi_flash_read(flash_addr, read_buf, read_len);

    return ret == ESP_OK ? read_len : ret;
}

#ifdef __cplusplus
}
#endif

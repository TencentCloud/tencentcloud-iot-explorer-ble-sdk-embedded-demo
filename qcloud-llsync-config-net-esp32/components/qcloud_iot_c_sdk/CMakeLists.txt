if (CONFIG_QCLOUD_IOT_C_SDK)
    set(srcs
            sdk_src/data_template_action.c
            sdk_src/data_template_client.c
            sdk_src/data_template_client_common.c
            sdk_src/data_template_client_json.c
            sdk_src/data_template_client_manager.c
            sdk_src/data_template_event.c
            sdk_src/dynreg.c
            sdk_src/json_parser.c
            sdk_src/json_token.c
            sdk_src/mqtt_client.c
            sdk_src/mqtt_client_common.c
            sdk_src/mqtt_client_connect.c
            sdk_src/mqtt_client_net.c
            sdk_src/mqtt_client_publish.c
            sdk_src/mqtt_client_subscribe.c
            sdk_src/mqtt_client_unsubscribe.c
            sdk_src/mqtt_client_yield.c
            sdk_src/network_interface.c
            sdk_src/network_socket.c
            sdk_src/ota_client.c
            sdk_src/ota_fetch.c
            sdk_src/ota_lib.c
            sdk_src/ota_mqtt.c
            sdk_src/qcloud_iot_ca.c
            sdk_src/qcloud_iot_device.c
            sdk_src/qcloud_iot_log.c
            sdk_src/qcloud_wifi_config.c
            sdk_src/qcloud_wifi_config_comm_service.c
            sdk_src/qcloud_wifi_config_device_bind.c
            sdk_src/qcloud_wifi_config_error_handle.c
            sdk_src/qcloud_wifi_config_log_handle.c
            sdk_src/service_mqtt.c
            sdk_src/string_utils.c
            sdk_src/utils_aes.c
            sdk_src/utils_base64.c
            sdk_src/utils_getopt.c
            sdk_src/utils_hmac.c
            sdk_src/utils_httpc.c
            sdk_src/utils_list.c
            sdk_src/utils_md5.c
            sdk_src/utils_ringbuff.c
            sdk_src/utils_sha1.c
            sdk_src/utils_timer.c
            sdk_src/utils_url_download.c
            sdk_src/utils_url_upload.c)

    list(APPEND srcs
            platform/HAL_Airkiss.c
            platform/HAL_BTCombo_config.c
            platform/HAL_Device_freertos.c
            platform/HAL_OS_freertos.c
            platform/HAL_Simple_config.c
            platform/HAL_Smart_config.c
            platform/HAL_Soft_ap.c
            platform/HAL_TCP_lwip.c
            platform/HAL_Timer_freertos.c
            platform/HAL_UDP_lwip.c
            platform/HAL_Wifi_api.c)

    set(includes include include/exports sdk_src/internal_inc)

endif ()

idf_component_register(SRCS "${srcs}"
        INCLUDE_DIRS "${includes}"
        REQUIRES json mbedtls qcloud_llsync esp_wifi)

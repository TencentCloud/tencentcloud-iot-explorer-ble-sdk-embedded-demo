set(srcs
        app_main.c
        wifi_config_sample.c)
idf_component_register(SRCS "${srcs}" INCLUDE_DIRS "" REQUIRES nvs_flash app_update qcloud_llsync qcloud_iot_c_sdk)

## 说明
本工程用做ESP32的示例工程，演示了终端设备通过`LLSync SDK`和`Explorer SDK`进行配网以及和云端通信。

## 编译指导
1. 安装`ESP-IDF`，请参考[官网文档](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html#step-2-get-esp-idf)。
```c
mkdir -p ~/esp
cd ~/esp
git clone --recursive https://github.com/espressif/esp-idf.git
```
本示例使用的分支是`release/v4.2`, `commit`是`2532ddd9f447f6fab02bc2d1654534a7621e033a`

2. 拷贝`qcloud-llsync-config-net-esp32`文件夹到`ESP-IDF`目录下。
```c
cp -r qcloud-llsync-config-net-esp32 $IDF_PATH
cd $IDF_PATH/qcloud-llsync-config-net-esp32
```

3. 登陆[物联网开发平台](https://cloud.tencent.com/product/iotexplorer), 创建设备。

  使用新设备的三元信息替换`components/qcloud_iot_c_sdk/platform/HAL_Device_freertos.c`中宏定义的设备信息，编译并烧录到开发板。
```c
idf.py flash
```

4. 在物联网开发平台修改设备配网方式为标准BLE辅助配网。

   ![](https://main.qcloudimg.com/raw/68cbcfc52dc3251a997d710efd5758bc.png)

5. 微信搜索腾讯连连小程序，进行配网操作。

   ![](https://main.qcloudimg.com/raw/e7a2109811f04f17c6e4dafde7e17086.png)

   ![](https://main.qcloudimg.com/raw/faf9dba15292241e11f503e0695e45e7.png)

   ![](https://main.qcloudimg.com/raw/8eadd13ed31b46131535b590784612fe.png)

6. 配网成功后，设备端日志如下。

   ```c
   I (91002) llsync config net: wifi info set
   I (91012) llsync config net: wifi info L-004, iot2021$
   I (91012) post data: e1 00 01 00 
   I (91442) llsync config net: wifi connect
   I (91692) wifi:new:<13,0>, old:<1,0>, ap:<255,255>, sta:<13,0>, prof:1
   I (91692) wifi:state: init -> auth (b0)
   I (91702) wifi:state: auth -> assoc (0)
   I (91702) wifi:state: assoc -> run (10)
   I (91722) wifi:connected with L-004, aid = 129, channel 13, BW20, bssid = e8:65:d4:43:aa:2b
   I (91722) wifi:security: WPA2-PSK, phy: bgn, rssi: -41
   I (91732) wifi:pm start, type: 1
   I (91732) wifi:AP's beacon interval = 102400 us, DTIM period = 1
   I (92302) esp_netif_handlers: sta ip: 192.168.0.43, mask: 255.255.255.0, gw: 192.168.0.1
   I (92302) llsync config net: got ip:192.168.0.43
   I (92422) post data: e2 00 09 01 00 00 05 4c 2d 30 30 34 
   DBG|1970-01-01 00:01:31|qcloud_wifi_config_device_bind.c|qiot_device_bind(392): device bind start
   DBG|1970-01-01 00:01:31|qcloud_wifi_config_device_bind.c|_get_reg_dev_info(285): dev psk exist
   INF|1970-01-01 00:01:33|HAL_TCP_lwip.c|HAL_TCP_Connect(93): connected with TCP server: 6648LS9GHV.iotcloud.tencentdevices.com:1883
   INF|1970-01-01 00:01:33|mqtt_client.c|IOT_MQTT_Construct(125): mqtt connect with id: E7K6p success
   INF|1970-01-01 00:01:33|qcloud_wifi_config_device_bind.c|_setup_mqtt_connect(332): Cloud Device Construct Success
   DBG|1970-01-01 00:01:33|mqtt_client_subscribe.c|qcloud_iot_mqtt_subscribe(147): topicName=$thing/down/service/6648LS9GHV/test_llsync_confignet|packet_id=1496
   DBG|1970-01-01 00:01:33|qcloud_wifi_config_device_bind.c|_mqtt_event_handler(53): mqtt topic subscribe success
   DBG|1970-01-01 00:01:34|mqtt_client_publish.c|qcloud_iot_mqtt_publish(340): publish topic seq=1497|topicName=$thing/up/service/6648LS9GHV/test_llsync_confignet|payload={"method":"app_bind_token","clientToken":"test_llsync_confignet-94204","params": {"token":"d7c77a41f8ff035ee4fcf4d01377d263"}}
   INF|1970-01-01 00:01:34|qcloud_wifi_config_device_bind.c|_mqtt_event_handler(68): publish success, packet-id=1497
   INF|1970-01-01 00:01:34|qcloud_wifi_config_device_bind.c|_on_message_callback(101): recv msg topic: $thing/down/service/6648LS9GHV/test_llsync_confignet
   INF|1970-01-01 00:01:34|qcloud_wifi_config_device_bind.c|_on_message_callback(112): msg payload: {"method":"app_bind_token_reply","clientToken":"test_llsync_confignet-94204","code":0,"status":"success"}
   DBG|1970-01-01 00:01:34|qcloud_wifi_config_device_bind.c|_on_message_callback(123): token reply code = 0
   INF|1970-01-01 00:01:36|mqtt_client_connect.c|qcloud_iot_mqtt_disconnect(468): mqtt disconnect!
   INF|1970-01-01 00:01:36|mqtt_client.c|IOT_MQTT_Destroy(189): mqtt release!
   INF|1970-01-01 00:01:41|qcloud_wifi_config_device_bind.c|qiot_device_bind(398): WIFI_MQTT_CONNECT_SUCCESS
   ERR|1970-01-01 00:01:41|qcloud_wifi_config_log_handle.c|push_dev_log(98): push dev log 101228|qiot_device_bind(399): WIFI_MQTT_CONNECT_SUCCESS
   DBG|1970-01-01 00:01:41|qcloud_wifi_config.c|_qiot_wifi_config_event_cb(53): Device bind success!
   DBG|1970-01-01 00:01:41|wifi_config_sample.c|_wifi_config_result_cb(454): entry...
   INF|1970-01-01 00:01:41|wifi_config_sample.c|_wifi_config_result_cb(458): WiFi is ready, to do Qcloud IoT demo
   DBG|1970-01-01 00:01:41|wifi_config_sample.c|_wifi_config_result_cb(459): timestamp now:101
   WRN|1970-01-01 00:01:41|qcloud_wifi_config_device_bind.c|qiot_device_bind_get_cloud_reply_code(414): Device bind cloud reply code: 0
   I (101992) post data: e3 00 01 00 
   DBG|1970-01-01 00:01:41|HAL_BTCombo_config.c|bt_combo_config_task(93): task end connect_success :2, task_run :1
   INF|1970-01-01 00:01:41|HAL_BTCombo_config.c|HAL_BTComboConfig_Stop(183): HAL_BTComboConfig_Stop
   I (102022) LLSYNC: Stop adv successfully
   INF|1970-01-01 00:01:41|HAL_TCP_lwip.c|HAL_TCP_Connect(93): connected with TCP server: 6648LS9GHV.iotcloud.tencentdevices.com:1883
   INF|1970-01-01 00:01:41|mqtt_client.c|IOT_MQTT_Construct(125): mqtt connect with id: 8XzDA success
   INF|1970-01-01 00:01:41|wifi_config_sample.c|wifi_config_sample_main(586): Cloud Device Construct Success
   DBG|1970-01-01 00:01:41|mqtt_client_subscribe.c|qcloud_iot_mqtt_subscribe(147): topicName=$thing/down/property/6648LS9GHV/test_llsync_confignet|packet_id=53442
   INF|1970-01-01 00:01:42|wifi_config_sample.c|_mqtt_event_handler(94): subscribe success, packet-id=53442
   DBG|1970-01-01 00:01:43|mqtt_client_publish.c|qcloud_iot_mqtt_publish(347): publish packetID=0|topicName=$thing/up/property/6648LS9GHV/test_llsync_confignet|payload={"method":"get_status", "clientToken":"6648LS9GHV-1"}
   I (103762) LLSYNC: update connection params status = 0, min_int = 0, max_int = 0,conn_int = 6,latency = 0, timeout = 500
   INF|1970-01-01 00:01:43|wifi_config_sample.c|property_message_callback(323): Receive Message With topicName:$thing/down/property/6648LS9GHV/test_llsync_confignet, payload:{"method":"get_status_reply","clientToken":"6648LS9GHV-1","code":0,"status":"success","data":{"reported":{"power_switch":0,"color":0,"brightness":60,"name":"test_llsync_confignet"}}}
   INF|1970-01-01 00:01:43|wifi_config_sample.c|property_get_status_reply_handle(286): .power_switch     = 0         
   INF|1970-01-01 00:01:43|wifi_config_sample.c|property_get_status_reply_handle(286): .brightness       = 60        
   INF|1970-01-01 00:01:43|wifi_config_sample.c|property_get_status_reply_handle(286): .color            = 0         
   INF|1970-01-01 00:01:43|wifi_config_sample.c|property_get_status_reply_handle(286): .name             = test_llsync_confignet
   I (104442) LLSYNC: ESP_GATTS_DISCONNECT_EVT, reason = 0x13
   I (104462) LLSYNC: start advertising
   qiot info: restart wait advertising
   I (104472) LLSYNC: Stop adv successfully
   I (104482) LLSYNC: ESP_GAP_BLE_ADV_DATA_RAW_SET_COMPLETE_EVT
   I (104492) LLSYNC: advertising start successfully
   DBG|1970-01-01 00:01:44|mqtt_client_publish.c|qcloud_iot_mqtt_publish(347): publish packetID=0|topicName=$thing/up/property/6648LS9GHV/test_llsync_confignet|payload={"method":"report", "clientToken":"6648LS9GHV-1", "params":{"power_switch":0, "color":0, "brightness":60, "name":"test_llsync_confignet"}}
   INF|1970-01-01 00:01:44|wifi_config_sample.c|property_message_callback(323): Receive Message With topicName:$thing/down/property/6648LS9GHV/test_llsync_confignet, payload:{"method":"report_reply","clientToken":"6648LS9GHV-1","code":0,"status":"success"}
   INF|1970-01-01 00:01:44|wifi_config_sample.c|property_report_reply_handle(307): report reply status: success
   ……
   ```

   
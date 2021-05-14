## 说明
本工程用做ESP32的示例工程，演示了终端设备通过BLE和腾讯连连小程序和腾讯云物联网开发平台的通信方式。

## 编译指导
1. 安装`ESP-IDF`，请参考[官网文档](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html#step-2-get-esp-idf)
```c
mkdir -p ~/esp
cd ~/esp
git clone --recursive https://github.com/espressif/esp-idf.git
```
本示例使用的分支是`release/v4.2`, `commit id`是`2532ddd9f447f6fab02bc2d1654534a7621e033a`

2. 拷贝`qcloud-iot-ble-esp32`组件到`ESP-IDF`目录下

```c
cp -r qcloud-iot-ble-esp32 $IDF_PATH
cd $IDF_PATH/qcloud-iot-ble-esp32
```
3. 登陆[物联网开发平台](https://cloud.tencent.com/product/iotexplorer), 使用`components/qcloud_llsync/data_template/esp32.json`作为数据模版创建设备。
   使用新设备的三元信息替换`components/qcloud_llsync/hal/ble_qiot_ble_device.c`中宏定义中的设备信息，编译并烧录到开发板。

```c
idf.py flash
```
4. 打开腾讯连连小程序，添加设备，观察串口输出和腾讯云物联网开发平台上的设备日志。
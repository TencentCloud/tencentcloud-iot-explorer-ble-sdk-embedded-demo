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
#include "ble_qiot_template.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "ble_qiot_export.h"
#include "ble_qiot_common.h"
#include "ble_qiot_param_check.h"
static int ble_property_t_bool_set(const char *data, uint16_t len)
{
  uint8_t tmp_bool = 0;
  tmp_bool = data[0];
  ble_qiot_log_d("set id t_bool bool value %02x", data[0]);
  return 0;
}

static int ble_property_t_bool_get( char *data, uint16_t len)
{
  uint8_t tmp_bool = 1;
  data[0] = tmp_bool;
  ble_qiot_log_d("get id t_bool bool value %02x", data[0]);
  return sizeof(uint8_t);
}

static int ble_property_t_int_set(const char *data, uint16_t len)
{
  int tmp_int = 0;
  memcpy(&tmp_int, data, sizeof(int));
  tmp_int = NTOHL(tmp_int);
  ble_qiot_log_d("set id t_int int value %d", tmp_int);
  return 0;
}

static int ble_property_t_int_get( char *data, uint16_t len)
{
  int tmp_int = 1;
  tmp_int = HTONL(tmp_int);
  memcpy(data, &tmp_int, sizeof(int));
  ble_qiot_log_d("get id t_int int value %d", 12345678);
  return sizeof(int);
}

static int ble_property_t_str_set(const char *data, uint16_t len)
{
  char tmp_str[128] = "";//copy the actual length of the text
  memcpy(tmp_str, data, 1);
  ble_qiot_log_d("set id t_str string value %s", data);
  return 0;
}

static int ble_property_t_str_get( char *data, uint16_t len)
{
  char tmp_str[2] = "a";
  memcpy(data, tmp_str, strlen(tmp_str));
  ble_qiot_log_d("get id t_str string value %s", data);
  return strlen(tmp_str);
}

static int ble_property_t_float_set(const char *data, uint16_t len)
{
  float tmp_float = 0;
  memcpy(&tmp_float, data, sizeof(float));
  ble_qiot_log_d("set id t_float float value %f", tmp_float);
  return 0;
}

static int ble_property_t_float_get( char *data, uint16_t len)
{
  float tmp_float = 1.23456;
  memcpy(data, &tmp_float, sizeof(float));
  ble_qiot_log_d("get id t_float float value %f", tmp_float);
  return sizeof(float);
}

static int ble_property_t_enum_set(const char *data, uint16_t len)
{
  int tmp_enum = 0;
  memcpy(&tmp_enum, data, sizeof(uint16_t));
  tmp_enum = NTOHL(tmp_enum);
  ble_qiot_log_d("set id t_enum int value %d", tmp_enum);
  return 0;
}

static int ble_property_t_enum_get( char *data, uint16_t len)
{
  uint16_t tmp_enum = 0;
  tmp_enum = HTONS(tmp_enum);
  memcpy(data, &tmp_enum, sizeof(uint16_t));
  ble_qiot_log_d("get id t_enum int value %d", 1234);
  return sizeof(uint16_t);
}

static int ble_property_t_time_set(const char *data, uint16_t len)
{
  uint32_t tmp_time = 0;
  memcpy(&tmp_time, data, sizeof(uint32_t));
  tmp_time = NTOHL(tmp_time);
  ble_qiot_log_d("set id t_time time value %d", tmp_time);
  return 0;
}

static int ble_property_t_time_get( char *data, uint16_t len)
{
  uint32_t tmp_time = 12345678;
  tmp_time = HTONL(tmp_time);
  memcpy(data, &tmp_time, sizeof(uint32_t));
  ble_qiot_log_d("get id t_time time value %d", 12345678);
  return sizeof(uint32_t);
}

static int ble_property_t_struct_s_bool_set(const char *data, uint16_t len)
{
  uint8_t tmp_bool = 0;
  tmp_bool = data[0];
  ble_qiot_log_d("set id s_bool bool value %02x", data[0]);
  return 0;
}

static int ble_property_t_struct_s_bool_get( char *data, uint16_t len)
{
  uint8_t tmp_bool = 1;
  data[0] = tmp_bool;
  ble_qiot_log_d("get id s_bool bool value %02x", data[0]);
  return sizeof(uint8_t);
}

static int ble_property_t_struct_s_int_set(const char *data, uint16_t len)
{
  int tmp_int = 0;
  memcpy(&tmp_int, data, sizeof(int));
  tmp_int = NTOHL(tmp_int);
  ble_qiot_log_d("set id s_int int value %d", tmp_int);
  return 0;
}

static int ble_property_t_struct_s_int_get( char *data, uint16_t len)
{
  int tmp_int = 1;
  tmp_int = HTONL(tmp_int);
  memcpy(data, &tmp_int, sizeof(int));
  ble_qiot_log_d("get id s_int int value %d", 12345678);
  return sizeof(int);
}

static int ble_property_t_struct_s_str_set(const char *data, uint16_t len)
{
  char tmp_str[128] = "";//copy the actual length of the text
  memcpy(tmp_str, data, 1);
  ble_qiot_log_d("set id s_str string value %s", data);
  return 0;
}

static int ble_property_t_struct_s_str_get( char *data, uint16_t len)
{
  char tmp_str[2] = "a";
  memcpy(data, tmp_str, strlen(tmp_str));
  ble_qiot_log_d("get id s_str string value %s", data);
  return strlen(tmp_str);
}

static int ble_property_t_struct_s_float_set(const char *data, uint16_t len)
{
  float tmp_float = 0;
  memcpy(&tmp_float, data, sizeof(float));
  ble_qiot_log_d("set id s_float float value %f", tmp_float);
  return 0;
}

static int ble_property_t_struct_s_float_get( char *data, uint16_t len)
{
  float tmp_float = 1.23456;
  memcpy(data, &tmp_float, sizeof(float));
  ble_qiot_log_d("get id s_float float value %f", tmp_float);
  return sizeof(float);
}

static int ble_property_t_struct_s_enum_set(const char *data, uint16_t len)
{
  int tmp_enum = 0;
  memcpy(&tmp_enum, data, sizeof(uint16_t));
  tmp_enum = NTOHL(tmp_enum);
  ble_qiot_log_d("set id s_enum int value %d", tmp_enum);
  return 0;
}

static int ble_property_t_struct_s_enum_get( char *data, uint16_t len)
{
  uint16_t tmp_enum = 0;
  tmp_enum = HTONS(tmp_enum);
  memcpy(data, &tmp_enum, sizeof(uint16_t));
  ble_qiot_log_d("get id s_enum int value %d", 1234);
  return sizeof(uint16_t);
}

static int ble_property_t_struct_s_time_set(const char *data, uint16_t len)
{
  uint32_t tmp_time = 0;
  memcpy(&tmp_time, data, sizeof(uint32_t));
  tmp_time = NTOHL(tmp_time);
  ble_qiot_log_d("set id s_time time value %d", tmp_time);
  return 0;
}

static int ble_property_t_struct_s_time_get( char *data, uint16_t len)
{
  uint32_t tmp_time = 12345678;
  tmp_time = HTONL(tmp_time);
  memcpy(data, &tmp_time, sizeof(uint32_t));
  ble_qiot_log_d("get id s_time time value %d", 12345678);
  return sizeof(uint32_t);
}

static ble_property_t sg_ble_t_struct_property_array[6] = {
    {(property_set_cb)ble_property_t_struct_s_bool_set, (property_get_cb)ble_property_t_struct_s_bool_get, 0, BLE_QIOT_DATA_TYPE_BOOL, 1},
    {(property_set_cb)ble_property_t_struct_s_int_set, (property_get_cb)ble_property_t_struct_s_int_get, 0, BLE_QIOT_DATA_TYPE_INT, 1},
    {(property_set_cb)ble_property_t_struct_s_str_set, (property_get_cb)ble_property_t_struct_s_str_get, 0, BLE_QIOT_DATA_TYPE_STRING, 1},
    {(property_set_cb)ble_property_t_struct_s_float_set, (property_get_cb)ble_property_t_struct_s_float_get, 0, BLE_QIOT_DATA_TYPE_FLOAT, 1},
    {(property_set_cb)ble_property_t_struct_s_enum_set, (property_get_cb)ble_property_t_struct_s_enum_get, 0, BLE_QIOT_DATA_TYPE_ENUM, 1},
    {(property_set_cb)ble_property_t_struct_s_time_set, (property_get_cb)ble_property_t_struct_s_time_get, 0, BLE_QIOT_DATA_TYPE_TIME, 1},
};

static int ble_property_t_struct_set(const char *data, uint16_t len)
{
  return ble_user_property_struct_handle(data, len, sg_ble_t_struct_property_array, 6);
}

static int ble_property_t_struct_get(char *data, uint16_t len)
{
  return ble_user_property_struct_get_data(data, len, sg_ble_t_struct_property_array, 6);
}

static int ble_property_t_struct2_s_bool_set(const char *data, uint16_t len)
{
  uint8_t tmp_bool = 0;
  tmp_bool = data[0];
  ble_qiot_log_d("set id s_bool bool value %02x", data[0]);
  return 0;
}

static int ble_property_t_struct2_s_bool_get( char *data, uint16_t len)
{
  uint8_t tmp_bool = 1;
  data[0] = tmp_bool;
  ble_qiot_log_d("get id s_bool bool value %02x", data[0]);
  return sizeof(uint8_t);
}

static ble_property_t sg_ble_t_struct2_property_array[1] = {
    {(property_set_cb)ble_property_t_struct2_s_bool_set, (property_get_cb)ble_property_t_struct2_s_bool_get, 0, BLE_QIOT_DATA_TYPE_BOOL, 1},
};

static int ble_property_t_struct2_set(const char *data, uint16_t len)
{
  return ble_user_property_struct_handle(data, len, sg_ble_t_struct2_property_array, 1);
}

static int ble_property_t_struct2_get(char *data, uint16_t len)
{
  return ble_user_property_struct_get_data(data, len, sg_ble_t_struct2_property_array, 1);
}

static int ble_property_t_int_array_set(const char *data, uint16_t len, uint16_t index)
{
  int tmp_int = 0;
  memcpy(&tmp_int, data, sizeof(int));
  tmp_int = NTOHL(tmp_int);
  ble_qiot_log_d("set id t_int_array int value %d", tmp_int);
  return 0;
}

static int ble_property_t_int_array_get( char *data, uint16_t len, uint16_t index)
{
  int tmp_int = 1;
  tmp_int = HTONL(tmp_int);
  memcpy(data, &tmp_int, sizeof(int));
  ble_qiot_log_d("get id t_int_array int value %d", 12345678);
  return sizeof(int);
}

static int ble_property_t_flot_array_set(const char *data, uint16_t len, uint16_t index)
{
  float tmp_float = 0;
  memcpy(&tmp_float, data, sizeof(float));
  ble_qiot_log_d("set id t_flot_array float value %f", tmp_float);
  return 0;
}

static int ble_property_t_flot_array_get( char *data, uint16_t len, uint16_t index)
{
  float tmp_float = 1.23456;
  memcpy(data, &tmp_float, sizeof(float));
  ble_qiot_log_d("get id t_flot_array float value %f", tmp_float);
  return sizeof(float);
}

static int ble_property_t_struct_array_t_bool_set(const char *data, uint16_t len, uint16_t index)
{
  uint8_t tmp_bool = 0;
  tmp_bool = data[0];
  ble_qiot_log_d("set id t_bool bool value %02x", data[0]);
  return 0;
}

static int ble_property_t_struct_array_t_bool_get( char *data, uint16_t len, uint16_t index)
{
  uint8_t tmp_bool = 1;
  data[0] = tmp_bool;
  ble_qiot_log_d("get id t_bool bool value %02x", data[0]);
  return sizeof(uint8_t);
}

static int ble_property_t_struct_array_t_int_set(const char *data, uint16_t len, uint16_t index)
{
  int tmp_int = 0;
  memcpy(&tmp_int, data, sizeof(int));
  tmp_int = NTOHL(tmp_int);
  ble_qiot_log_d("set id t_int int value %d", tmp_int);
  return 0;
}

static int ble_property_t_struct_array_t_int_get( char *data, uint16_t len, uint16_t index)
{
  int tmp_int = 1;
  tmp_int = HTONL(tmp_int);
  memcpy(data, &tmp_int, sizeof(int));
  ble_qiot_log_d("get id t_int int value %d", 12345678);
  return sizeof(int);
}

static int ble_property_t_struct_array_t_str_set(const char *data, uint16_t len, uint16_t index)
{
  char tmp_str[128] = "";//copy the actual length of the text
  memcpy(tmp_str, data, 1);
  ble_qiot_log_d("set id t_str string value %s", data);
  return 0;
}

static int ble_property_t_struct_array_t_str_get( char *data, uint16_t len, uint16_t index)
{
  char tmp_str[2] = "a";
  memcpy(data, tmp_str, strlen(tmp_str));
  ble_qiot_log_d("get id t_str string value %s", data);
  return strlen(tmp_str);
}

static int ble_property_t_struct_array_t_float_set(const char *data, uint16_t len, uint16_t index)
{
  float tmp_float = 0;
  memcpy(&tmp_float, data, sizeof(float));
  ble_qiot_log_d("set id t_float float value %f", tmp_float);
  return 0;
}

static int ble_property_t_struct_array_t_float_get( char *data, uint16_t len, uint16_t index)
{
  float tmp_float = 1.23456;
  memcpy(data, &tmp_float, sizeof(float));
  ble_qiot_log_d("get id t_float float value %f", tmp_float);
  return sizeof(float);
}

static int ble_property_t_struct_array_t_time_set(const char *data, uint16_t len, uint16_t index)
{
  uint32_t tmp_time = 0;
  memcpy(&tmp_time, data, sizeof(uint32_t));
  tmp_time = NTOHL(tmp_time);
  ble_qiot_log_d("set id t_time time value %d", tmp_time);
  return 0;
}

static int ble_property_t_struct_array_t_time_get( char *data, uint16_t len, uint16_t index)
{
  uint32_t tmp_time = 12345678;
  tmp_time = HTONL(tmp_time);
  memcpy(data, &tmp_time, sizeof(uint32_t));
  ble_qiot_log_d("get id t_time time value %d", 12345678);
  return sizeof(uint32_t);
}

static int ble_property_t_struct_array_t_enum_set(const char *data, uint16_t len, uint16_t index)
{
  int tmp_enum = 0;
  memcpy(&tmp_enum, data, sizeof(uint16_t));
  tmp_enum = NTOHL(tmp_enum);
  ble_qiot_log_d("set id t_enum int value %d", tmp_enum);
  return 0;
}

static int ble_property_t_struct_array_t_enum_get( char *data, uint16_t len, uint16_t index)
{
  uint16_t tmp_enum = 0;
  tmp_enum = HTONS(tmp_enum);
  memcpy(data, &tmp_enum, sizeof(uint16_t));
  ble_qiot_log_d("get id t_enum int value %d", 1234);
  return sizeof(uint16_t);
}

static ble_property_t sg_ble_t_struct_array_property_array[6] = {
    {(property_set_cb)ble_property_t_struct_array_t_bool_set, (property_get_cb)ble_property_t_struct_array_t_bool_get, 0, BLE_QIOT_DATA_TYPE_BOOL, 1},
    {(property_set_cb)ble_property_t_struct_array_t_int_set, (property_get_cb)ble_property_t_struct_array_t_int_get, 0, BLE_QIOT_DATA_TYPE_INT, 1},
    {(property_set_cb)ble_property_t_struct_array_t_str_set, (property_get_cb)ble_property_t_struct_array_t_str_get, 0, BLE_QIOT_DATA_TYPE_STRING, 1},
    {(property_set_cb)ble_property_t_struct_array_t_float_set, (property_get_cb)ble_property_t_struct_array_t_float_get, 0, BLE_QIOT_DATA_TYPE_FLOAT, 1},
    {(property_set_cb)ble_property_t_struct_array_t_time_set, (property_get_cb)ble_property_t_struct_array_t_time_get, 0, BLE_QIOT_DATA_TYPE_TIME, 1},
    {(property_set_cb)ble_property_t_struct_array_t_enum_set, (property_get_cb)ble_property_t_struct_array_t_enum_get, 0, BLE_QIOT_DATA_TYPE_ENUM, 1},
};

static int ble_property_t_struct_array_set(const char *data, uint16_t len)
{
  return ble_user_property_struct_array_set(BLE_QIOT_PROPERTY_ID_T_STRUCT_ARRAY, data, len, sg_ble_t_struct_array_property_array, 6);
}

static int ble_property_t_struct_array_get(char *data, uint16_t len)
{
  return ble_user_property_struct_array_get(BLE_QIOT_PROPERTY_ID_T_STRUCT_ARRAY, data, len, sg_ble_t_struct_array_property_array, 6);
}

static int ble_property_t_str_array_set(const char *data, uint16_t len, uint16_t index)
{
  char tmp_str[128] = "";//copy the actual length of the text
  memcpy(tmp_str, data, 1);
  ble_qiot_log_d("set id t_str_array string value %s", data);
  return 0;
}

static int ble_property_t_str_array_get( char *data, uint16_t len, uint16_t index)
{
  char tmp_str[2] = "a";
  memcpy(data, tmp_str, strlen(tmp_str));
  ble_qiot_log_d("get id t_str_array string value %s", data);
  return strlen(tmp_str);
}

ble_property_t sg_ble_property_array[12] = {
    {ble_property_t_bool_set, ble_property_t_bool_get, 0, BLE_QIOT_DATA_TYPE_BOOL, 1},
    {ble_property_t_int_set, ble_property_t_int_get, 0, BLE_QIOT_DATA_TYPE_INT, 1},
    {ble_property_t_str_set, ble_property_t_str_get, 0, BLE_QIOT_DATA_TYPE_STRING, 1},
    {ble_property_t_float_set, ble_property_t_float_get, 0, BLE_QIOT_DATA_TYPE_FLOAT, 1},
    {ble_property_t_enum_set, ble_property_t_enum_get, 0, BLE_QIOT_DATA_TYPE_ENUM, 1},
    {ble_property_t_time_set, ble_property_t_time_get, 0, BLE_QIOT_DATA_TYPE_TIME, 1},
    {ble_property_t_struct_set, ble_property_t_struct_get, 0, BLE_QIOT_DATA_TYPE_STRUCT, 1},
    {ble_property_t_struct2_set, ble_property_t_struct2_get, 0, BLE_QIOT_DATA_TYPE_STRUCT, 1},
    {(property_set_cb)ble_property_t_int_array_set, (property_get_cb)ble_property_t_int_array_get, 0, BLE_QIOT_DATA_TYPE_ARRAY|BLE_QIOT_ARRAY_INT_BIT_MASK, BLE_QIOT_PROPERTY_T_INT_ARRAY_SIZE_MAX},
    {(property_set_cb)ble_property_t_flot_array_set, (property_get_cb)ble_property_t_flot_array_get, 0, BLE_QIOT_DATA_TYPE_ARRAY|BLE_QIOT_ARRAY_FLOAT_BIT_MASK, BLE_QIOT_PROPERTY_T_FLOT_ARRAY_SIZE_MAX},
    {(property_set_cb)ble_property_t_struct_array_set, (property_get_cb)ble_property_t_struct_array_get, 0, BLE_QIOT_DATA_TYPE_ARRAY|BLE_QIOT_ARRAY_STRUCT_BIT_MASK, BLE_QIOT_PROPERTY_T_STRUCT_ARRAY_SIZE_MAX},
    {(property_set_cb)ble_property_t_str_array_set, (property_get_cb)ble_property_t_str_array_get, 0, BLE_QIOT_DATA_TYPE_ARRAY|BLE_QIOT_ARRAY_STRING_BIT_MASK, BLE_QIOT_PROPERTY_T_STR_ARRAY_SIZE_MAX},
};


static int ble_event_get_t_event_t_bool_get( char *data, uint16_t len)
{
  uint8_t tmp_bool = 1;
  data[0] = tmp_bool;
  ble_qiot_log_d("get id t_bool bool value %02x", data[0]);
  return sizeof(uint8_t);
}

static int ble_event_get_t_event_t_int_get( char *data, uint16_t len)
{
  int tmp_int = 1;
  tmp_int = HTONL(tmp_int);
  memcpy(data, &tmp_int, sizeof(int));
  ble_qiot_log_d("get id t_int int value %d", 12345678);
  return sizeof(int);
}

static int ble_event_get_t_event_t_str_get( char *data, uint16_t len)
{
  char tmp_str[2] = "a";
  memcpy(data, tmp_str, strlen(tmp_str));
  ble_qiot_log_d("get id t_str string value %s", data);
  return strlen(tmp_str);
}

static int ble_event_get_t_event_t_enum_get( char *data, uint16_t len)
{
  uint16_t tmp_enum = 0;
  tmp_enum = HTONS(tmp_enum);
  memcpy(data, &tmp_enum, sizeof(uint16_t));
  ble_qiot_log_d("get id t_enum int value %d", 1234);
  return sizeof(uint16_t);
}

static int ble_event_get_t_event_t_float_get( char *data, uint16_t len)
{
  float tmp_float = 1.23456;
  memcpy(data, &tmp_float, sizeof(float));
  ble_qiot_log_d("get id t_float float value %f", tmp_float);
  return sizeof(float);
}

static int ble_event_get_t_event_t_time_get( char *data, uint16_t len)
{
  uint32_t tmp_time = 12345678;
  tmp_time = HTONL(tmp_time);
  memcpy(data, &tmp_time, sizeof(uint32_t));
  ble_qiot_log_d("get id t_time time value %d", 12345678);
  return sizeof(uint32_t);
}

static ble_event_param sg_ble_event_t_event_array[6] = {
    {ble_event_get_t_event_t_bool_get, BLE_QIOT_DATA_TYPE_BOOL},
    {ble_event_get_t_event_t_int_get, BLE_QIOT_DATA_TYPE_INT},
    {ble_event_get_t_event_t_str_get, BLE_QIOT_DATA_TYPE_STRING},
    {ble_event_get_t_event_t_enum_get, BLE_QIOT_DATA_TYPE_ENUM},
    {ble_event_get_t_event_t_float_get, BLE_QIOT_DATA_TYPE_FLOAT},
    {ble_event_get_t_event_t_time_get, BLE_QIOT_DATA_TYPE_TIME},
};

ble_event_t sg_ble_event_array[1] = {
    {sg_ble_event_t_event_array, 6},
};


static int ble_action_handle_t_action_input_cb(e_ble_tlv *input_param_array, uint8_t input_array_size,uint8_t *output_id_array)
{
  int      i          = 0;
  int      test_int   = 0;
  float    test_float = 0;
  uint16_t test_enum  = 0;
  uint32_t test_time  = 0;

  for (i = 0; i < input_array_size; i++) {
    if (BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_BOOL == input_param_array[i].id) {
      printf("input id: %d, val: %d\r\n", BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_BOOL, input_param_array[i].val[0]);
    } else if (BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_INT == input_param_array[i].id) {
      memcpy(&test_int, input_param_array[i].val, sizeof(int));
      test_int = NTOHL(test_int);
      printf("input id: %d, val: %d\r\n", BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_INT, test_int);
    } else if (BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_STR == input_param_array[i].id) {
      printf("input id: %d, val: %s\r\n", BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_STR, input_param_array[i].val);
    } else if (BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_FLOAT == input_param_array[i].id) {
      memcpy(&test_float, input_param_array[i].val, sizeof(float));
      printf("input id: %d, val: %f\r\n", BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_FLOAT, test_float);
    } else if (BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_ENUM == input_param_array[i].id) {
      memcpy(&test_enum, input_param_array[i].val, sizeof(uint16_t));
      test_enum = NTOHS(test_enum);
      printf("input id: %d, val: %d\r\n", BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_ENUM, test_enum);
    } else if (BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_TIME == input_param_array[i].id) {
      memcpy(&test_time, input_param_array[i].val, sizeof(int));
      test_time = NTOHL(test_time);
      printf("input id: %d, val: %d\r\n", BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_TIME, test_time);
    }
    output_id_array[input_param_array[i].id] = true;
  }
  return 0;
}

static int ble_action_handle_t_action_output_cb(uint8_t output_id, char *buf, uint16_t buf_len)
{
  uint16_t ret_len    = 0;
  int      test_int   = HTONL(32);
  int      test_float = 3;
  uint16_t test_enum  = HTONS(1);
  uint32_t test_time  = HTONL(1613059200);

  if (BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_BOOL == output_id) {
    buf[0]  = true;
    ret_len = 1;
  } else if (BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_INT == output_id) {
    memcpy(buf, &test_int, sizeof(int));
    ret_len = sizeof(int);
  } else if (BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_STR == output_id) {
    memcpy(buf, "output", sizeof("output") - 1);
    ret_len = sizeof("output") - 1;
  } else if (BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_FLOAT == output_id) {
    memcpy(buf, &test_float, sizeof(float));
    ret_len = sizeof(float);
  } else if (BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_ENUM == output_id) {
    memcpy(buf, &test_enum, sizeof(uint16_t));
    ret_len = sizeof(uint16_t);
  } else if (BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_TIME == output_id) {
    memcpy(buf, &test_time, sizeof(int));
    ret_len = sizeof(int);
  }
  //get value of the output id, return actual length
  return ret_len;
}

static uint8_t sg_ble_action_t_action_input_type_array[6] = {
    BLE_QIOT_DATA_TYPE_BOOL,
    BLE_QIOT_DATA_TYPE_INT,
    BLE_QIOT_DATA_TYPE_STRING,
    BLE_QIOT_DATA_TYPE_FLOAT,
    BLE_QIOT_DATA_TYPE_ENUM,
    BLE_QIOT_DATA_TYPE_TIME,
};

static uint8_t sg_ble_action_t_action_output_type_array[6] = {
    BLE_QIOT_DATA_TYPE_BOOL,
    BLE_QIOT_DATA_TYPE_INT,
    BLE_QIOT_DATA_TYPE_STRING,
    BLE_QIOT_DATA_TYPE_FLOAT,
    BLE_QIOT_DATA_TYPE_ENUM,
    BLE_QIOT_DATA_TYPE_TIME,
};

ble_action_t sg_ble_action_array[1] = {
    {ble_action_handle_t_action_input_cb, ble_action_handle_t_action_output_cb,sg_ble_action_t_action_input_type_array, sg_ble_action_t_action_output_type_array,6,6},
};

#ifdef __cplusplus
}
#endif

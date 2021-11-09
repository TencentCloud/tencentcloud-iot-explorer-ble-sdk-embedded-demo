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

static bool     sg_test_bool     = 0;
static int      sg_test_int      = 0;
static char     sg_test_str[128] = {0};
static float    sg_test_float    = 0.0;
static uint16_t sg_test_enum     = 0;
static uint32_t sg_test_time     = 0;

static struct_property_t_struct  sg_test_struct;

static int ble_property_t_bool_set(const char *data, uint16_t len)
{
    sg_test_bool = data[0];
    printf("set: sg_test_bool: %d\r\n", sg_test_bool);
    return 0;
}

static int ble_property_t_bool_get( char *data, uint16_t len)
{
    data[0] = sg_test_bool;
    printf("get: sg_test_bool: %d\r\n", sg_test_bool);
    return sizeof(uint8_t);
}

static int ble_property_t_int_set(const char *data, uint16_t len)
{
    int test_int = 0;

    memcpy(&test_int, data, sizeof(int));
    sg_test_int = NTOHL(test_int);
    printf("set: sg_test_int: %d\r\n", sg_test_int);

    return 0;
}

static int ble_property_t_int_get( char *data, uint16_t len)
{
    int test_int = 0;

    printf("get: sg_test_int: %d\r\n", sg_test_int);
    test_int = HTONL(sg_test_int);
    memcpy(data, &test_int, sizeof(int));

    return sizeof(uint32_t);
}

static int ble_property_t_string_set(const char *data, uint16_t len)
{
    memcpy(sg_test_str, data, sizeof(sg_test_str) > len ? len : (sizeof(sg_test_str) - 1));
    printf("set: sg_test_str: %s\r\n", sg_test_str);

    return 0;
}

static int ble_property_t_string_get( char *data, uint16_t len)
{
    memcpy(data, sg_test_str, strlen(sg_test_str));
    printf("get: sg_test_str: %s\r\n", sg_test_str);

    return strlen(sg_test_str);
}

static int ble_property_t_float_set(const char *data, uint16_t len)
{
    memcpy(&sg_test_float, data, sizeof(float));
    printf("set: sg_test_float: %f\r\n", sg_test_float);

    return 0;
}

static int ble_property_t_float_get( char *data, uint16_t len)
{
    memcpy(data, &sg_test_float, sizeof(float));
    printf("get: sg_test_float: %f\r\n", sg_test_float);

    return sizeof(float);
}

static int ble_property_t_enum_set(const char *data, uint16_t len)
{
    uint16_t test_enum = 0;

    memcpy(&test_enum, data, sizeof(uint16_t));
    sg_test_enum = NTOHS(test_enum);
    printf("set: sg_test_enum: %d\r\n", sg_test_enum);

    return 0;
}

static int ble_property_t_enum_get( char *data, uint16_t len)
{
    uint16_t test_enum = 0;

    printf("get: sg_test_enum: %d\r\n", sg_test_enum);
    test_enum = HTONS(sg_test_enum);
    memcpy(data, &test_enum, sizeof(uint16_t));

    return sizeof(uint16_t);
}

static int ble_property_t_time_set(const char *data, uint16_t len)
{
    int test_int = 0;

    memcpy(&test_int, data, sizeof(int));
    sg_test_time = NTOHL(test_int);
    printf("set: sg_test_time: %d\r\n", sg_test_time);

    return 0;
}

static int ble_property_t_time_get( char *data, uint16_t len)
{
    int test_int = 0;

    printf("get: sg_test_time: %d\r\n", sg_test_time);
    test_int = HTONL(sg_test_time);
    memcpy(data, &test_int, sizeof(int));

    return sizeof(uint32_t);
}

static int ble_property_t_struct_s_bool_set(const char *data, uint16_t len)
{
    sg_test_struct.m_s_bool = data[0];
    printf("set: sg_test_struct.m_s_bool: %d\r\n", sg_test_struct.m_s_bool);
    return 0;
}

static int ble_property_t_struct_s_bool_get( char *data, uint16_t len)
{
    data[0] = sg_test_struct.m_s_bool;
    printf("get: sg_test_struct.m_s_bool: %d\r\n", sg_test_struct.m_s_bool);
    return sizeof(uint8_t);
}

static int ble_property_t_struct_s_int_set(const char *data, uint16_t len)
{
    int test_int = 0;

    memcpy(&test_int, data, sizeof(int));
    sg_test_struct.m_s_int = NTOHL(test_int);
    printf("set: sg_test_struct.m_s_int: %d\r\n", sg_test_struct.m_s_int);
    return 0;
}

static int ble_property_t_struct_s_int_get( char *data, uint16_t len)
{
    int test_int = 0;

    printf("get: sg_test_int: %d\r\n", sg_test_struct.m_s_int);
    test_int = HTONL(sg_test_struct.m_s_int);
    memcpy(data, &test_int, sizeof(int));

    return sizeof(uint32_t);
}

static int ble_property_t_struct_s_string_set(const char *data, uint16_t len)
{
    memcpy(sg_test_struct.m_s_str, data,
            sizeof(sg_test_struct.m_s_str) > len ? len : (sizeof(sg_test_struct.m_s_str) - 1));
    printf("set: sg_test_struct.m_s_str: %s\r\n", sg_test_struct.m_s_str);
    return 0;
}

static int ble_property_t_struct_s_string_get( char *data, uint16_t len)
{
    memcpy(data, sg_test_struct.m_s_str, strlen(sg_test_struct.m_s_str));
    printf("get: sg_test_struct.m_s_str: %s\r\n", sg_test_struct.m_s_str);
    return strlen(sg_test_struct.m_s_str);
}

static int ble_property_t_struct_s_float_set(const char *data, uint16_t len)
{
    memcpy(&sg_test_struct.m_s_float, data, sizeof(float));
    printf("set: sg_test_struct.m_s_float: %f\r\n", sg_test_struct.m_s_float);
    return 0;
}

static int ble_property_t_struct_s_float_get( char *data, uint16_t len)
{
    memcpy(data, &sg_test_struct.m_s_float, sizeof(float));
    printf("get: sg_test_struct.m_s_float: %f\r\n", sg_test_struct.m_s_float);
    return sizeof(float);
}

static int ble_property_t_struct_s_enum_set(const char *data, uint16_t len)
{
    uint16_t test_enum = 0;

    memcpy(&test_enum, data, sizeof(uint16_t));
    sg_test_struct.m_s_enum = NTOHS(test_enum);
    printf("set: sg_test_struct.m_s_enum: %d\r\n", sg_test_struct.m_s_enum);
    return 0;
}

static int ble_property_t_struct_s_enum_get( char *data, uint16_t len)
{
    uint16_t test_enum = 0;

    printf("get: sg_test_struct.m_s_enum: %d\r\n", sg_test_struct.m_s_enum);
    test_enum = HTONS(sg_test_struct.m_s_enum);
    memcpy(data, &test_enum, sizeof(uint16_t));
    return sizeof(uint16_t);
}

static int ble_property_t_struct_s_time_set(const char *data, uint16_t len)
{
    int test_int = 0;

    memcpy(&test_int, data, sizeof(int));
    sg_test_struct.m_s_time = NTOHL(test_int);
    printf("set: sg_test_struct.m_s_time: %d\r\n", sg_test_struct.m_s_time);
    return 0;
}

static int ble_property_t_struct_s_time_get( char *data, uint16_t len)
{
    int test_int = 0;

    printf("get: sg_test_struct.m_s_time: %d\r\n", sg_test_struct.m_s_time);
    test_int = HTONL(sg_test_struct.m_s_time);
    memcpy(data, &test_int, sizeof(int));
    return sizeof(uint32_t);
}

static ble_property_t sg_ble_t_struct_property_array[6] = {
	{(property_set_cb)ble_property_t_struct_s_bool_set, (property_get_cb)ble_property_t_struct_s_bool_get, 0, BLE_QIOT_DATA_TYPE_BOOL, 1},
	{(property_set_cb)ble_property_t_struct_s_int_set, (property_get_cb)ble_property_t_struct_s_int_get, 0, BLE_QIOT_DATA_TYPE_INT, 1},
	{(property_set_cb)ble_property_t_struct_s_string_set, (property_get_cb)ble_property_t_struct_s_string_get, 0, BLE_QIOT_DATA_TYPE_STRING, 1},
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

static int ble_property_t_array_int_set(const char *data, uint16_t len, uint16_t index)
{
	int tmp_int = 0;
	memcpy(&tmp_int, data, sizeof(int));
	tmp_int = NTOHL(tmp_int);
	printf("set id t_array_int int value %d\r\n", tmp_int);
	return 0;
}

static int ble_property_t_array_int_get( char *data, uint16_t len, uint16_t index)
{
	int tmp_int = 1;
	tmp_int = HTONL(tmp_int);
	memcpy(data, &tmp_int, sizeof(int));
	printf("get id t_array_int int value %d\r\n", 12345678);
	return sizeof(int);
}

static int ble_property_t_array_string_set(const char *data, uint16_t len, uint16_t index)
{
	char tmp_str[128] = "";//copy the actual length of the text
	memcpy(tmp_str, data, 1);
	printf("set id t_array_string string value %s\r\n", data);
	return 0;
}

static int ble_property_t_array_string_get( char *data, uint16_t len, uint16_t index)
{
	char tmp_str[2] = "a";
	memcpy(data, tmp_str, strlen(tmp_str));
	printf("get id t_array_string string value %s\r\n", data);
	return strlen(tmp_str);
}

static int ble_property_t_array_float_set(const char *data, uint16_t len, uint16_t index)
{
	float tmp_float = 0;
	memcpy(&tmp_float, data, sizeof(float));
	printf("set id t_array_float float value %f\r\n", tmp_float);
	return 0;
}

static int ble_property_t_array_float_get( char *data, uint16_t len, uint16_t index)
{
	float tmp_float = 1.23456;
	memcpy(data, &tmp_float, sizeof(float));
	printf("get id t_array_float float value %f\r\n", tmp_float);
	return sizeof(float);
}

static int ble_property_t_array_struct_array_s_bool_set(const char *data, uint16_t len, uint16_t index)
{
	uint8_t tmp_bool = 0;
	tmp_bool = data[0];
	printf("set id array_s_bool bool value %02x\r\n", data[0]);
	return 0;
}

static int ble_property_t_array_struct_array_s_bool_get( char *data, uint16_t len, uint16_t index)
{
	uint8_t tmp_bool = 1;
	data[0] = tmp_bool;
	printf("get id array_s_bool bool value %02x\r\n", data[0]);
	return sizeof(uint8_t);
}

static ble_property_t sg_ble_t_array_struct_property_array[1] = {
	{(property_set_cb)ble_property_t_array_struct_array_s_bool_set, (property_get_cb)ble_property_t_array_struct_array_s_bool_get, 0, BLE_QIOT_DATA_TYPE_BOOL, 1},
};

static int ble_property_t_array_struct_set(const char *data, uint16_t len)
{
	return ble_user_property_struct_array_set(BLE_QIOT_PROPERTY_ID_T_ARRAY_STRUCT, data, len, sg_ble_t_array_struct_property_array, 1);
}

static int ble_property_t_array_struct_get(char *data, uint16_t len)
{
	return ble_user_property_struct_array_get(BLE_QIOT_PROPERTY_ID_T_ARRAY_STRUCT, data, len, sg_ble_t_array_struct_property_array, 1);
}

ble_property_t sg_ble_property_array[11] = {
	{ble_property_t_bool_set, ble_property_t_bool_get, 0, BLE_QIOT_DATA_TYPE_BOOL, 1},
	{ble_property_t_int_set, ble_property_t_int_get, 0, BLE_QIOT_DATA_TYPE_INT, 1},
	{ble_property_t_string_set, ble_property_t_string_get, 0, BLE_QIOT_DATA_TYPE_STRING, 1},
	{ble_property_t_float_set, ble_property_t_float_get, 0, BLE_QIOT_DATA_TYPE_FLOAT, 1},
	{ble_property_t_enum_set, ble_property_t_enum_get, 0, BLE_QIOT_DATA_TYPE_ENUM, 1},
	{ble_property_t_time_set, ble_property_t_time_get, 0, BLE_QIOT_DATA_TYPE_TIME, 1},
	{ble_property_t_struct_set, ble_property_t_struct_get, 0, BLE_QIOT_DATA_TYPE_STRUCT, 1},
	{(property_set_cb)ble_property_t_array_int_set, (property_get_cb)ble_property_t_array_int_get, 0, BLE_QIOT_DATA_TYPE_ARRAY|BLE_QIOT_ARRAY_INT_BIT_MASK, BLE_QIOT_PROPERTY_T_ARRAY_INT_SIZE_MAX},
	{(property_set_cb)ble_property_t_array_string_set, (property_get_cb)ble_property_t_array_string_get, 0, BLE_QIOT_DATA_TYPE_ARRAY|BLE_QIOT_ARRAY_STRING_BIT_MASK, BLE_QIOT_PROPERTY_T_ARRAY_STRING_SIZE_MAX},
	{(property_set_cb)ble_property_t_array_float_set, (property_get_cb)ble_property_t_array_float_get, 0, BLE_QIOT_DATA_TYPE_ARRAY|BLE_QIOT_ARRAY_FLOAT_BIT_MASK, BLE_QIOT_PROPERTY_T_ARRAY_FLOAT_SIZE_MAX},
	{(property_set_cb)ble_property_t_array_struct_set, (property_get_cb)ble_property_t_array_struct_get, 0, BLE_QIOT_DATA_TYPE_ARRAY|BLE_QIOT_ARRAY_STRUCT_BIT_MASK, BLE_QIOT_PROPERTY_T_ARRAY_STRUCT_SIZE_MAX},
};


static int ble_event_get_event_warnning_param_bool_get( char *data, uint16_t len)
{
	uint8_t tmp_bool = 1;
	data[0] = tmp_bool;
	printf("get id param_bool bool value %02x\r\n", data[0]);
	return sizeof(uint8_t);
}

static int ble_event_get_event_warnning_param_int_get( char *data, uint16_t len)
{
	int tmp_int = 1;
	tmp_int = HTONL(tmp_int);
	memcpy(data, &tmp_int, sizeof(int));
	printf("get id param_int int value %d\r\n", 12345678);
	return sizeof(int);
}

static int ble_event_get_event_warnning_param_string_get( char *data, uint16_t len)
{
	char tmp_str[2] = "a";
	memcpy(data, tmp_str, strlen(tmp_str));
	printf("get id param_string string value %s\r\n", data);
	return strlen(tmp_str);
}

static int ble_event_get_event_warnning_param_float_get( char *data, uint16_t len)
{
	float tmp_float = 1.23456;
	memcpy(data, &tmp_float, sizeof(float));
	printf("get id param_float float value %f\r\n", tmp_float);
	return sizeof(float);
}

static int ble_event_get_event_warnning_param_enum_get( char *data, uint16_t len)
{
	uint16_t tmp_enum = 0;
	tmp_enum = HTONS(tmp_enum);
	memcpy(data, &tmp_enum, sizeof(uint16_t));
	printf("get id param_enum int value %d\r\n", 1234);
	return sizeof(uint16_t);
}

static int ble_event_get_event_warnning_param_time_get( char *data, uint16_t len)
{
	uint32_t tmp_time = 12345678;
	tmp_time = HTONL(tmp_time);
	memcpy(data, &tmp_time, sizeof(uint32_t));
	printf("get id param_time time value %d\r\n", 12345678);
	return sizeof(uint32_t);
}

static ble_event_param sg_ble_event_event_warnning_array[6] = {
	{ble_event_get_event_warnning_param_bool_get, BLE_QIOT_DATA_TYPE_BOOL},
	{ble_event_get_event_warnning_param_int_get, BLE_QIOT_DATA_TYPE_INT},
	{ble_event_get_event_warnning_param_string_get, BLE_QIOT_DATA_TYPE_STRING},
	{ble_event_get_event_warnning_param_float_get, BLE_QIOT_DATA_TYPE_FLOAT},
	{ble_event_get_event_warnning_param_enum_get, BLE_QIOT_DATA_TYPE_ENUM},
	{ble_event_get_event_warnning_param_time_get, BLE_QIOT_DATA_TYPE_TIME},
};

static int ble_event_get_event_error_param_bool_get( char *data, uint16_t len)
{
	uint8_t tmp_bool = 1;
	data[0] = tmp_bool;
	printf("get id param_bool bool value %02x\r\n", data[0]);
	return sizeof(uint8_t);
}

static int ble_event_get_event_error_param_string_get( char *data, uint16_t len)
{
	char tmp_str[2] = "a";
	memcpy(data, tmp_str, strlen(tmp_str));
	printf("get id param_string string value %s\r\n", data);
	return strlen(tmp_str);
}

static ble_event_param sg_ble_event_event_error_array[2] = {
	{ble_event_get_event_error_param_bool_get, BLE_QIOT_DATA_TYPE_BOOL},
	{ble_event_get_event_error_param_string_get, BLE_QIOT_DATA_TYPE_STRING},
};

ble_event_t sg_ble_event_array[2] = {
	{sg_ble_event_event_warnning_array, 6},
	{sg_ble_event_event_error_array, 2},
};


static int ble_action_handle_action_test_input_cb(e_ble_tlv *input_param_array, uint8_t input_array_size,uint8_t *output_id_array)
{
    int      i          = 0;
    int      test_int   = 0;
    float    test_float = 0;
    uint16_t test_enum  = 0;
    uint32_t test_time  = 0;

    for (i = 0; i < input_array_size; i++) {
        if (BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_BOOL_INPUT == input_param_array[i].id) {
            printf("input id: %d, val: %d\r\n", BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_BOOL_INPUT, input_param_array[i].val[0]);
        } else if (BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_INT_INPUT == input_param_array[i].id) {
            memcpy(&test_int, input_param_array[i].val, sizeof(int));
            test_int = NTOHL(test_int);
            printf("input id: %d, val: %d\r\n", BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_INT_INPUT, test_int);
        } else if (BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_STRING_INPUT == input_param_array[i].id) {
            printf("input id: %d, val: %s\r\n", BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_STRING_INPUT, input_param_array[i].val);
        } else if (BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_FLOAT_INPUT == input_param_array[i].id) {
            memcpy(&test_float, input_param_array[i].val, sizeof(float));
            printf("input id: %d, val: %f\r\n", BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_FLOAT_INPUT, test_float);
        } else if (BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_ENUM_INPUT == input_param_array[i].id) {
            memcpy(&test_enum, input_param_array[i].val, sizeof(uint16_t));
            test_enum = NTOHS(test_enum);
            printf("input id: %d, val: %d\r\n", BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_ENUM_INPUT, test_enum);
        } else if (BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_TIME_INPUT == input_param_array[i].id) {
            memcpy(&test_time, input_param_array[i].val, sizeof(int));
            test_time = NTOHL(test_time);
            printf("input id: %d, val: %d\r\n", BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_TIME_INPUT, test_time);
        }
        output_id_array[input_param_array[i].id] = true;
    }

    return 0;
}

static int ble_action_handle_action_test_output_cb(uint8_t output_id, char *buf, uint16_t buf_len)
{
    uint16_t ret_len    = 0;
    int      test_int   = HTONL(32);
    int      test_float = 3;
    uint16_t test_enum  = HTONS(1);
    uint32_t test_time  = HTONL(1613059200);

    if (BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_BOOL_OUTPUT == output_id) {
        buf[0]  = true;
        ret_len = 1;
    } else if (BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_INT_OUTPUT == output_id) {
        memcpy(buf, &test_int, sizeof(int));
        ret_len = sizeof(int);
    } else if (BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_STRING_OUTPUT == output_id) {
        memcpy(buf, "output", sizeof("output") - 1);
        ret_len = sizeof("output") - 1;
    } else if (BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_FLOAT_OUTPUT == output_id) {
        memcpy(buf, &test_float, sizeof(float));
        ret_len = sizeof(float);
    } else if (BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_ENUM_OUTPUT == output_id) {
        memcpy(buf, &test_enum, sizeof(uint16_t));
        ret_len = sizeof(uint16_t);
    } else if (BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_TIME_OUTPUT == output_id) {
        memcpy(buf, &test_time, sizeof(int));
        ret_len = sizeof(int);
    }

    return ret_len;
}

static uint8_t sg_ble_action_action_test_input_type_array[6] = {
	BLE_QIOT_DATA_TYPE_BOOL,
	BLE_QIOT_DATA_TYPE_INT,
	BLE_QIOT_DATA_TYPE_STRING,
	BLE_QIOT_DATA_TYPE_FLOAT,
	BLE_QIOT_DATA_TYPE_ENUM,
	BLE_QIOT_DATA_TYPE_TIME,
};

static uint8_t sg_ble_action_action_test_output_type_array[6] = {
	BLE_QIOT_DATA_TYPE_BOOL,
	BLE_QIOT_DATA_TYPE_INT,
	BLE_QIOT_DATA_TYPE_STRING,
	BLE_QIOT_DATA_TYPE_FLOAT,
	BLE_QIOT_DATA_TYPE_ENUM,
	BLE_QIOT_DATA_TYPE_TIME,
};

ble_action_t sg_ble_action_array[1] = {
	{ble_action_handle_action_test_input_cb, ble_action_handle_action_test_output_cb,sg_ble_action_action_test_input_type_array, sg_ble_action_action_test_output_type_array,6,6},
};

#ifdef __cplusplus
}
#endif

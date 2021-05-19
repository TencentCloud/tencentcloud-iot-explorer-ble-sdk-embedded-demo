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

static bool property_bool = false;
static int ble_property_property_bool_set(const char *data, uint16_t len)
{
    property_bool = data[0];
    BLE_QIOT_LOG_PRINT("Set property bool: 0x%0x\n", property_bool);
    return 0;
}

static int ble_property_property_bool_get(char *data, uint16_t buf_len)
{
    data[0] = property_bool;
    BLE_QIOT_LOG_PRINT("Get property bool: 0x%x\n", data[0]);
    return sizeof(uint8_t);
}

static int property_int = 0;
static int ble_property_property_int_set(const char *data, uint16_t len)
{
    int tmp = 0;
    memcpy(&tmp, data, sizeof(int));
    property_int = NTOHL(tmp);
    BLE_QIOT_LOG_PRINT("Set property int: 0x%x\n", property_int);
    return 0;
}

static int ble_property_property_int_get(char *data, uint16_t buf_len)
{
    int tmp = 0;
    BLE_QIOT_LOG_PRINT("Get property int: 0x%x\n", property_int);
    tmp = HTONL(property_int);
    memcpy(data, &tmp, sizeof(int));
    return sizeof(int);
}

static char property_string[128 + 1] = {0};
static int ble_property_property_string_set(const char *data, uint16_t len)
{
    memcpy(property_string, data, len > 128 ? 128 : len);
    BLE_QIOT_LOG_PRINT("Set property string: %s\n", property_string);
    return 0;
}

static int ble_property_property_string_get(char *data, uint16_t buf_len)
{
    BLE_QIOT_LOG_PRINT("Get property string: %s\n", property_string);
    memcpy(data, property_string, strlen(property_string));
    return strlen(property_string);
}

static float property_float = 0.0;
static int ble_property_property_float_set(const char *data, uint16_t len)
{
    memcpy(&property_float, data, sizeof(float));
    BLE_QIOT_LOG_PRINT("Set property float: %.3f\n", property_float);
    return 0;
}

static int ble_property_property_float_get(char *data, uint16_t buf_len)
{
    memcpy(data, &property_float, sizeof(float));
    BLE_QIOT_LOG_PRINT("Get property float: %.3f\n", property_float);
    return sizeof(float);
}

static uint16_t property_enum = 0;
static int ble_property_property_enum_set(const char *data, uint16_t len)
{
    uint16_t tmp = 0;
    memcpy(&tmp, data, sizeof(uint16_t));
    property_enum = NTOHS(tmp);
    BLE_QIOT_LOG_PRINT("Set property enum: 0x%x\n", property_enum);
    return 0;
}

static int ble_property_property_enum_get(char *data, uint16_t buf_len)
{
    uint16_t tmp = 0;
    BLE_QIOT_LOG_PRINT("Get property enum: 0x%x\n", property_enum);
    tmp = HTONS(property_enum);
    memcpy(data, &tmp, sizeof(uint16_t));
    return sizeof(uint16_t);
}

static uint32_t property_time = 0;
static int ble_property_property_time_set(const char *data, uint16_t len)
{
    int tmp = 0;
    memcpy(&tmp, data, sizeof(int));
    property_time = NTOHL(tmp);
    BLE_QIOT_LOG_PRINT("Set property time: 0x%x\n", property_time);
    return 0;
}

static int ble_property_property_time_get(char *data, uint16_t buf_len)
{
    int tmp = 0;
    BLE_QIOT_LOG_PRINT("Get property time: 0x%x\n", property_time);
    tmp = HTONL(property_time);
    memcpy(data, &tmp, sizeof(uint32_t));
    return sizeof(uint32_t);
}

static struct_property_property_struct property_struct;
static int ble_property_property_struct_mem_bool_set(const char *data, uint16_t len)
{
    property_struct.m_mem_bool = data[0];
    BLE_QIOT_LOG_PRINT("Set struct property bool: 0x%x\n", property_struct.m_mem_bool);
    return 0;
}

static int ble_property_property_struct_mem_bool_get(char *data, uint16_t buf_len)
{
    data[0] = property_struct.m_mem_bool;
    BLE_QIOT_LOG_PRINT("Get struct property bool: 0x%x\n", data[0]);
    return sizeof(uint8_t);
}

static int ble_property_property_struct_mem_int_set(const char *data, uint16_t len)
{
    int tmp = 0;
    memcpy(&tmp, data, sizeof(int));
    property_struct.m_mem_int = NTOHL(tmp);
    BLE_QIOT_LOG_PRINT("Set struct property int: 0x%x\n", property_struct.m_mem_int);
    return 0;
}

static int ble_property_property_struct_mem_int_get(char *data, uint16_t buf_len)
{
    int tmp = 0;
    BLE_QIOT_LOG_PRINT("Get struct property int: 0x%x\n", property_struct.m_mem_int);
    tmp = HTONL(property_struct.m_mem_int);
    memcpy(data, &tmp, sizeof(int));
    return sizeof(int);
}

static int ble_property_property_struct_mem_string_set(const char *data, uint16_t len)
{
    memcpy(property_struct.m_mem_string, data, len > 128 ? 128 : len);
    BLE_QIOT_LOG_PRINT("Set struct property string: %s\n", property_struct.m_mem_string);
    return 0;
}

static int ble_property_property_struct_mem_string_get(char *data, uint16_t buf_len)
{
    BLE_QIOT_LOG_PRINT("Get struct property string: %s\n", property_struct.m_mem_string);
    memcpy(data, property_struct.m_mem_string, strlen(property_struct.m_mem_string));
    return strlen(property_struct.m_mem_string);
}

static int ble_property_property_struct_mem_float_set(const char *data, uint16_t len)
{
    memcpy(&property_struct.m_mem_float, data, sizeof(float));
    BLE_QIOT_LOG_PRINT("Set struct property float: %.3f\n", property_struct.m_mem_float);
    return 0;
}

static int ble_property_property_struct_mem_float_get(char *data, uint16_t buf_len)
{
    memcpy(data, &property_struct.m_mem_float, sizeof(float));
    BLE_QIOT_LOG_PRINT("Get struct property float: %.3f\n", property_struct.m_mem_float);
    return sizeof(float);
}

static int ble_property_property_struct_mem_enum_set(const char *data, uint16_t len)
{
    uint16_t tmp = 0;
    memcpy(&tmp, data, sizeof(uint16_t));
    property_struct.m_mem_enum = NTOHS(tmp);
    BLE_QIOT_LOG_PRINT("Set struct property enum: 0x%x\n", property_struct.m_mem_enum);
    return 0;
}

static int ble_property_property_struct_mem_enum_get(char *data, uint16_t buf_len)
{
    uint16_t tmp = 0;
    BLE_QIOT_LOG_PRINT("Get struct property enum: 0x%x\n", property_struct.m_mem_enum);
    tmp = HTONS(property_struct.m_mem_enum);
    memcpy(data, &tmp, sizeof(uint16_t));
    return sizeof(uint16_t);
}

static int ble_property_property_struct_mem_time_set(const char *data, uint16_t len)
{
    int tmp = 0;
    memcpy(&tmp, data, sizeof(int));
    property_struct.m_mem_time = NTOHL(tmp);
    BLE_QIOT_LOG_PRINT("Set struct property time: 0x%x\n", property_struct.m_mem_time);
    return 0;
}

static int ble_property_property_struct_mem_time_get(char *data, uint16_t buf_len)
{
    int tmp = 0;
    BLE_QIOT_LOG_PRINT("Get property time: 0x%x\n", property_struct.m_mem_time);
    tmp = HTONL(property_struct.m_mem_time);
    memcpy(data, &tmp, sizeof(uint32_t));
    return sizeof(uint32_t);
}

static ble_property_t sg_ble_property_struct_property_array[BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_ID_BUTT] = {
    {ble_property_property_struct_mem_bool_set, ble_property_property_struct_mem_bool_get, BLE_QIOT_PROPERTY_AUTH_RW,
     BLE_QIOT_DATA_TYPE_BOOL},
    {ble_property_property_struct_mem_int_set, ble_property_property_struct_mem_int_get, BLE_QIOT_PROPERTY_AUTH_RW,
     BLE_QIOT_DATA_TYPE_INT},
    {ble_property_property_struct_mem_string_set, ble_property_property_struct_mem_string_get,
     BLE_QIOT_PROPERTY_AUTH_RW, BLE_QIOT_DATA_TYPE_STRING},
    {ble_property_property_struct_mem_float_set, ble_property_property_struct_mem_float_get, BLE_QIOT_PROPERTY_AUTH_RW,
     BLE_QIOT_DATA_TYPE_FLOAT},
    {ble_property_property_struct_mem_enum_set, ble_property_property_struct_mem_enum_get, BLE_QIOT_PROPERTY_AUTH_RW,
     BLE_QIOT_DATA_TYPE_ENUM},
    {ble_property_property_struct_mem_time_set, ble_property_property_struct_mem_time_get, BLE_QIOT_PROPERTY_AUTH_RW,
     BLE_QIOT_DATA_TYPE_TIME},
};

static int ble_property_property_struct_set(const char *data, uint16_t len)
{
    return ble_user_property_struct_handle(data, len, sg_ble_property_struct_property_array,
                                           BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_ID_BUTT);
}

static int ble_property_property_struct_get(char *data, uint16_t len)
{
    return ble_user_property_struct_get_data(data, len, sg_ble_property_struct_property_array,
                                             BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_ID_BUTT);
}

static ble_property_t sg_ble_property_array[BLE_QIOT_PROPERTY_ID_BUTT] = {
    {ble_property_property_bool_set, ble_property_property_bool_get, BLE_QIOT_PROPERTY_AUTH_RW,
     BLE_QIOT_DATA_TYPE_BOOL},
    {ble_property_property_int_set, ble_property_property_int_get, BLE_QIOT_PROPERTY_AUTH_RW, BLE_QIOT_DATA_TYPE_INT},
    {ble_property_property_string_set, ble_property_property_string_get, BLE_QIOT_PROPERTY_AUTH_RW,
     BLE_QIOT_DATA_TYPE_STRING},
    {ble_property_property_float_set, ble_property_property_float_get, BLE_QIOT_PROPERTY_AUTH_RW,
     BLE_QIOT_DATA_TYPE_FLOAT},
    {ble_property_property_enum_set, ble_property_property_enum_get, BLE_QIOT_PROPERTY_AUTH_RW,
     BLE_QIOT_DATA_TYPE_ENUM},
    {ble_property_property_time_set, ble_property_property_time_get, BLE_QIOT_PROPERTY_AUTH_RW,
     BLE_QIOT_DATA_TYPE_TIME},
    {ble_property_property_struct_set, ble_property_property_struct_get, BLE_QIOT_PROPERTY_AUTH_RW,
     BLE_QIOT_DATA_TYPE_STRUCT},
};

static bool ble_check_space_enough_by_type(uint8_t type, uint16_t left_size)
{
    switch (type) {
        case BLE_QIOT_DATA_TYPE_BOOL:
            return left_size >= sizeof(uint8_t);
        case BLE_QIOT_DATA_TYPE_INT:
        case BLE_QIOT_DATA_TYPE_FLOAT:
        case BLE_QIOT_DATA_TYPE_TIME:
            return left_size >= sizeof(uint32_t);
        case BLE_QIOT_DATA_TYPE_ENUM:
            return left_size >= sizeof(uint16_t);
        default:
            // string length is unknow, default true
            return true;
    }
}

static uint16_t ble_check_ret_value_by_type(uint8_t type, uint16_t buf_len, uint16_t ret_val)
{
    switch (type) {
        case BLE_QIOT_DATA_TYPE_BOOL:
            return ret_val <= sizeof(uint8_t);
        case BLE_QIOT_DATA_TYPE_INT:
        case BLE_QIOT_DATA_TYPE_FLOAT:
        case BLE_QIOT_DATA_TYPE_TIME:
            return ret_val <= sizeof(uint32_t);
        case BLE_QIOT_DATA_TYPE_ENUM:
            return ret_val <= sizeof(uint16_t);
        default:
            // string length is unknow, default true
            return ret_val <= buf_len;
    }
}

uint8_t ble_get_property_type_by_id(uint8_t id)
{
    if (id >= BLE_QIOT_PROPERTY_ID_BUTT) {
        ble_qiot_log_e("invalid property id %d", id);
        return BLE_QIOT_DATA_TYPE_BUTT;
    }
    return sg_ble_property_array[id].type;
}

int ble_user_property_set_data(const e_ble_tlv *tlv)
{
    POINTER_SANITY_CHECK(tlv, BLE_QIOT_RS_ERR_PARA);
    if (tlv->id >= BLE_QIOT_PROPERTY_ID_BUTT) {
        ble_qiot_log_e("invalid property id %d", tlv->id);
        return BLE_QIOT_RS_ERR;
    }

    if (NULL != sg_ble_property_array[tlv->id].set_cb) {
        if (0 != sg_ble_property_array[tlv->id].set_cb(tlv->val, tlv->len)) {
            ble_qiot_log_e("set property id %d failed", tlv->id);
            return BLE_QIOT_RS_ERR;
        } else {
            return BLE_QIOT_RS_OK;
        }
    }
    ble_qiot_log_e("invalid set callback, id %d", tlv->id);

    return BLE_QIOT_RS_ERR;
}

int ble_user_property_get_data_by_id(uint8_t id, char *buf, uint16_t buf_len)
{
    int ret_len = 0;

    POINTER_SANITY_CHECK(buf, BLE_QIOT_RS_ERR_PARA);
    if (id >= BLE_QIOT_PROPERTY_ID_BUTT) {
        ble_qiot_log_e("invalid property id %d", id);
        return -1;
    }

    if (NULL != sg_ble_property_array[id].get_cb) {
        if (!ble_check_space_enough_by_type(sg_ble_property_array[id].type, buf_len)) {
            ble_qiot_log_e("not enough space get property id %d data", id);
            return -1;
        }
        ret_len = sg_ble_property_array[id].get_cb(buf, buf_len);
        if (ret_len < 0) {
            ble_qiot_log_e("get property id %d data failed", id);
            return -1;
        } else {
            if (ble_check_ret_value_by_type(sg_ble_property_array[id].type, buf_len, ret_len)) {
                return ret_len;
            } else {
                ble_qiot_log_e("property id %d length invalid", id);
                return -1;
            }
        }
    }
    ble_qiot_log_e("invalid callback, property id %d", id);

    return 0;
}

int ble_user_property_report_reply_handle(uint8_t result)
{
    ble_qiot_log_d("report reply result %d", result);

    return BLE_QIOT_RS_OK;
}

int ble_user_property_struct_handle(const char *in_buf, uint16_t buf_len, ble_property_t struct_arr[], uint8_t arr_size)
{
    uint16_t  parse_len = 0;
    uint16_t  ret_len   = 0;
    e_ble_tlv tlv;

    while (parse_len < buf_len) {
        memset(&tlv, 0, sizeof(e_ble_tlv));
        ret_len = ble_lldata_parse_tlv(in_buf + parse_len, buf_len - parse_len, &tlv);
        parse_len += ret_len;
        if (parse_len > buf_len) {
            ble_qiot_log_e("parse struct failed");
            return parse_len;
        }

        if (tlv.id >= arr_size) {
            ble_qiot_log_e("invalid array index %d", tlv.id);
            return parse_len;
        }
        if (NULL == struct_arr[tlv.id].set_cb) {
            ble_qiot_log_e("invalid member id %d", tlv.id);
            return parse_len;
        }
        if (BLE_QIOT_RS_OK != struct_arr[tlv.id].set_cb(tlv.val, tlv.len)) {
            ble_qiot_log_e("user handle property error, member id %d, type %d, len %d", tlv.id, tlv.type, tlv.len);
            return parse_len;
        }
    }

    return 0;
}

int ble_user_property_struct_get_data(char *in_buf, uint16_t buf_len, ble_property_t struct_arr[], uint8_t arr_size)
{
    uint8_t  property_id   = 0;
    uint8_t  property_type = 0;
    int      property_len  = 0;
    char *   data_buf      = in_buf;
    uint16_t data_len      = 0;
    uint16_t string_len    = 0;

    for (property_id = 0; property_id < arr_size; property_id++) {
        property_type = struct_arr[property_id].type;
        if (property_type >= BLE_QIOT_DATA_TYPE_BUTT) {
            ble_qiot_log_e("member id %d type %d invalid", property_id, property_type);
            return BLE_QIOT_RS_ERR;
        }
        data_buf[data_len++] = BLE_QIOT_PACKAGE_TLV_HEAD(property_type, property_id);
        if (BLE_QIOT_DATA_TYPE_STRING == property_type) {
            // reserved 2 bytes for string length
            property_len = struct_arr[property_id].get_cb((char *)data_buf + data_len + 2, buf_len - data_len - 2);
        } else {
            property_len = struct_arr[property_id].get_cb((char *)data_buf + data_len, buf_len - data_len);
        }
        if (property_len < 0) {
            ble_qiot_log_e("too long data, member id %d, data length %d", property_id, data_len);
            return BLE_QIOT_RS_ERR;
        } else if (property_len == 0) {
            // no data to post
            data_len--;
            data_buf[data_len] = '0';
            ble_qiot_log_d("member id %d no data to post", property_id);
        } else {
            if (BLE_QIOT_DATA_TYPE_STRING == property_type) {
                string_len = HTONS(property_len);
                memcpy(data_buf + data_len, &string_len, sizeof(uint16_t));
                data_len += sizeof(uint16_t);
            }
            data_len += property_len;
        }
    }

    return data_len;
}

static bool param_bool = true;
static int ble_event_get_event_warnning_param_bool(char *data, uint16_t buf_len)
{
    BLE_QIOT_LOG_PRINT("Get event param bool: 0x%x\n", param_bool);
    return sizeof(uint8_t);
}

static int param_int = 0x1234;
static int ble_event_get_event_warnning_param_int(char *data, uint16_t buf_len)
{
    int tmp = 0;
    BLE_QIOT_LOG_PRINT("Get event param int: 0x%x\n", param_int);
    tmp = HTONL(param_int);
    memcpy(data, &tmp, sizeof(int));
    return sizeof(int);
}

static char *param_string = "Welcome to LLSync!";
static int ble_event_get_event_warnning_param_string(char *data, uint16_t buf_len)
{
    BLE_QIOT_LOG_PRINT("Get event param string: %s\n", param_string);
    memcpy(data, param_string, strlen(param_string));
    return strlen(param_string);
}

static float param_float = 3.14;
static int ble_event_get_event_warnning_param_float(char *data, uint16_t buf_len)
{
    memcpy(data, &param_float, sizeof(float));
    BLE_QIOT_LOG_PRINT("Get event param float: %.3f\n", param_float);
    return sizeof(float);
}

static uint16_t param_enum = BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_ENUM_PARAM_ENUM1;
static int ble_event_get_event_warnning_param_enum(char *data, uint16_t buf_len)
{
    uint16_t tmp = 0;
    BLE_QIOT_LOG_PRINT("Get event param enum: 0x%x\n", param_enum);
    tmp = HTONS(param_enum);
    memcpy(data, &tmp, sizeof(uint16_t));
    return sizeof(uint16_t);
}

static uint32_t param_time = 1543037250;
static int ble_event_get_event_warnning_param_time(char *data, uint16_t buf_len)
{
    int tmp = 0;
    BLE_QIOT_LOG_PRINT("Get event param time: 0x%x\n", param_time);
    tmp = HTONL(param_time);
    memcpy(data, &tmp, sizeof(uint32_t));
    return sizeof(uint32_t);
}

static ble_event_param sg_ble_event_event_warnning_array[BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_ID_BUTT] = {
    {ble_event_get_event_warnning_param_bool, BLE_QIOT_DATA_TYPE_BOOL},
    {ble_event_get_event_warnning_param_int, BLE_QIOT_DATA_TYPE_INT},
    {ble_event_get_event_warnning_param_string, BLE_QIOT_DATA_TYPE_STRING},
    {ble_event_get_event_warnning_param_float, BLE_QIOT_DATA_TYPE_FLOAT},
    {ble_event_get_event_warnning_param_enum, BLE_QIOT_DATA_TYPE_ENUM},
    {ble_event_get_event_warnning_param_time, BLE_QIOT_DATA_TYPE_TIME},
};

static bool error_param_bool = false;
static int ble_event_get_event_error_param_bool(char *data, uint16_t buf_len)
{
    BLE_QIOT_LOG_PRINT("Get event error param bool: 0x%x\n", error_param_bool);
    return sizeof(uint8_t);
}

static char *error_param_string = "You are right!";
static int ble_event_get_event_error_param_string(char *data, uint16_t buf_len)
{
    BLE_QIOT_LOG_PRINT("Get event error param string: %s\n", error_param_string);
    memcpy(data, error_param_string, strlen(error_param_string));
    return strlen(error_param_string);
}

static ble_event_param sg_ble_event_event_error_array[BLE_QIOT_EVENT_EVENT_ERROR_PARAM_ID_BUTT] = {
    {ble_event_get_event_error_param_bool, BLE_QIOT_DATA_TYPE_BOOL},
    {ble_event_get_event_error_param_string, BLE_QIOT_DATA_TYPE_STRING},
};

static ble_event_t sg_ble_event_array[BLE_QIOT_EVENT_ID_BUTT] = {
    {sg_ble_event_event_warnning_array, sizeof(sg_ble_event_event_warnning_array) / sizeof(ble_event_param)},
    {sg_ble_event_event_error_array, sizeof(sg_ble_event_event_error_array) / sizeof(ble_event_param)},
};

int ble_event_get_id_array_size(uint8_t event_id)
{
    if (event_id >= BLE_QIOT_EVENT_ID_BUTT) {
        ble_qiot_log_e("invalid event id %d", event_id);
        return -1;
    }

    return sg_ble_event_array[event_id].array_size;
}

uint8_t ble_event_get_param_id_type(uint8_t event_id, uint8_t param_id)
{
    if (event_id >= BLE_QIOT_EVENT_ID_BUTT) {
        ble_qiot_log_e("invalid event id %d", event_id);
        return BLE_QIOT_DATA_TYPE_BUTT;
    }
    if (param_id >= sg_ble_event_array[event_id].array_size) {
        ble_qiot_log_e("invalid param id %d", param_id);
        return BLE_QIOT_DATA_TYPE_BUTT;
    }

    return sg_ble_event_array[event_id].event_array[param_id].type;
}

int ble_event_get_data_by_id(uint8_t event_id, uint8_t param_id, char *out_buf, uint16_t buf_len)
{
    int ret_len = 0;

    if (event_id >= BLE_QIOT_EVENT_ID_BUTT) {
        ble_qiot_log_e("invalid event id %d", event_id);
        return -1;
    }
    if (param_id >= sg_ble_event_array[event_id].array_size) {
        ble_qiot_log_e("invalid param id %d", param_id);
        return -1;
    }
    if (NULL == sg_ble_event_array[event_id].event_array[param_id].get_cb) {
        ble_qiot_log_e("invalid callback, event id %d, param id %d", event_id, param_id);
        return 0;
    }

    if (!ble_check_space_enough_by_type(sg_ble_event_array[event_id].event_array[param_id].type, buf_len)) {
        ble_qiot_log_e("not enough space get data, event id %d, param id %d", event_id, param_id);
        return -1;
    }
    ret_len = sg_ble_event_array[event_id].event_array[param_id].get_cb(out_buf, buf_len);
    if (ret_len < 0) {
        ble_qiot_log_e("get event data failed, event id %d, param id %d", event_id, param_id);
        return -1;
    } else {
        if (ble_check_ret_value_by_type(sg_ble_event_array[event_id].event_array[param_id].type, buf_len, ret_len)) {
            return ret_len;
        } else {
            ble_qiot_log_e("evnet data length invalid, event id %d, param id %d", event_id, param_id);
            return -1;
        }
    }
}

int ble_user_event_reply_handle(uint8_t event_id, uint8_t result)
{
    ble_qiot_log_d("event id %d, reply result %d", event_id, result);

    return BLE_QIOT_RS_OK;
}

static bool input_bool = false;
static int input_int = 0;
static char input_string[128] = {0};
static float input_float = 0.0;
static uint16_t input_enum = 0;
static uint32_t input_time = 0;
static int ble_action_handle_action_test_input_cb(e_ble_tlv *input_param_array, uint8_t input_array_size,
                                                  uint8_t *output_id_array)
{
    int      i          = 0;

    for (i = 0; i < input_array_size; i++) {
        if (BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_BOOL_INPUT == input_param_array[i].id) {
            input_bool = input_param_array[i].val[0];
            BLE_QIOT_LOG_PRINT("action test bool input 0x%x\n", input_bool);
        } else if (BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_INT_INPUT == input_param_array[i].id) {
            memcpy(&input_int, input_param_array[i].val, sizeof(int));
            input_int = NTOHL(input_int);
            BLE_QIOT_LOG_PRINT("action test int input 0x%x\n", input_int);
        } else if (BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_STRING_INPUT == input_param_array[i].id) {
            memcpy(input_string, input_param_array[i].val, input_param_array[i].len);
            BLE_QIOT_LOG_PRINT("action test string input %s\n", input_string);
        } else if (BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_FLOAT_INPUT == input_param_array[i].id) {
            memcpy(&input_float, input_param_array[i].val, sizeof(float));
            BLE_QIOT_LOG_PRINT("action test float input %.3f\n", input_float);
        } else if (BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_ENUM_INPUT == input_param_array[i].id) {
            memcpy(&input_enum, input_param_array[i].val, sizeof(uint16_t));
            input_enum = NTOHS(input_enum);
            BLE_QIOT_LOG_PRINT("action test enum input 0x%x\n", input_enum);
        } else if (BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_TIME_INPUT == input_param_array[i].id) {
            memcpy(&input_time, input_param_array[i].val, sizeof(uint32_t));
            input_time = NTOHL(input_time);
            BLE_QIOT_LOG_PRINT("action test time input 0x%x\n", input_time);
        }
        output_id_array[input_param_array[i].id] = true;
    }

    return 0;
}

static int ble_action_handle_action_test_output_cb(uint8_t output_id, char *buf, uint16_t buf_len)
{
    uint16_t ret_len    = 0;
    int      test_int   = HTONL(input_int);
    uint16_t test_enum  = HTONS(input_enum);
    uint32_t test_time  = HTONL(input_time);

    if (BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_BOOL_OUTPUT == output_id) {
        buf[0]  = input_bool;
        ret_len = 1;
    } else if (BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_INT_OUTPUT == output_id) {
        memcpy(buf, &test_int, sizeof(int));
        ret_len = sizeof(int);
    } else if (BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_STRING_OUTPUT == output_id) {
        memcpy(buf, "Received message!", sizeof("Received message!") - 1);
        ret_len = sizeof("Received message!") - 1;
    } else if (BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_FLOAT_OUTPUT == output_id) {
        memcpy(buf, &input_float, sizeof(float));
        ret_len = sizeof(float);
    } else if (BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_ENUM_OUTPUT == output_id) {
        memcpy(buf, &test_enum, sizeof(uint16_t));
        ret_len = sizeof(uint16_t);
    } else if (BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_TIME_OUTPUT == output_id) {
        memcpy(buf, &test_time, sizeof(uint32_t));
        ret_len = sizeof(uint32_t);
    }

    return ret_len;
}

static uint8_t sg_ble_action_action_test_input_type_array[BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_BUTT] = {
    BLE_QIOT_DATA_TYPE_BOOL,  BLE_QIOT_DATA_TYPE_INT,  BLE_QIOT_DATA_TYPE_STRING,
    BLE_QIOT_DATA_TYPE_FLOAT, BLE_QIOT_DATA_TYPE_ENUM, BLE_QIOT_DATA_TYPE_TIME,
};

static uint8_t sg_ble_action_action_test_output_type_array[BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_BUTT] = {
    BLE_QIOT_DATA_TYPE_BOOL,  BLE_QIOT_DATA_TYPE_INT,  BLE_QIOT_DATA_TYPE_STRING,
    BLE_QIOT_DATA_TYPE_FLOAT, BLE_QIOT_DATA_TYPE_ENUM, BLE_QIOT_DATA_TYPE_TIME,
};

static ble_action_t sg_ble_action_array[BLE_QIOT_ACTION_ID_BUTT] = {
    {ble_action_handle_action_test_input_cb, ble_action_handle_action_test_output_cb,
     sg_ble_action_action_test_input_type_array, sg_ble_action_action_test_output_type_array,
     sizeof(sg_ble_action_action_test_input_type_array) / sizeof(uint8_t),
     sizeof(sg_ble_action_action_test_output_type_array) / sizeof(uint8_t)},
};

uint8_t ble_action_get_intput_type_by_id(uint8_t action_id, uint8_t input_id)
{
    if (action_id >= BLE_QIOT_ACTION_ID_BUTT) {
        ble_qiot_log_e("invalid action id %d", action_id);
        return BLE_QIOT_DATA_TYPE_BUTT;
    }
    if (input_id >= sg_ble_event_array[action_id].array_size) {
        ble_qiot_log_e("invalid input id %d", input_id);
        return BLE_QIOT_DATA_TYPE_BUTT;
    }

    return sg_ble_action_array[action_id].input_type_array[input_id];
}

uint8_t ble_action_get_output_type_by_id(uint8_t action_id, uint8_t output_id)
{
    if (action_id >= BLE_QIOT_ACTION_ID_BUTT) {
        ble_qiot_log_e("invalid action id %d", action_id);
        return BLE_QIOT_DATA_TYPE_BUTT;
    }
    if (output_id >= sg_ble_event_array[action_id].array_size) {
        ble_qiot_log_e("invalid output id %d", output_id);
        return BLE_QIOT_DATA_TYPE_BUTT;
    }

    return sg_ble_action_array[action_id].output_type_array[output_id];
}

int ble_action_get_input_id_size(uint8_t action_id)
{
    if (action_id >= BLE_QIOT_ACTION_ID_BUTT) {
        ble_qiot_log_e("invalid action id %d", action_id);
        return -1;
    }

    return sg_ble_action_array[action_id].input_id_size;
}

int ble_action_get_output_id_size(uint8_t action_id)
{
    if (action_id >= BLE_QIOT_ACTION_ID_BUTT) {
        ble_qiot_log_e("invalid action id %d", action_id);
        return -1;
    }

    return sg_ble_action_array[action_id].output_id_size;
}

int ble_action_user_handle_input_param(uint8_t action_id, e_ble_tlv *input_param_array, uint8_t input_array_size,
                                       uint8_t *output_id_array)
{
    if (action_id >= BLE_QIOT_ACTION_ID_BUTT) {
        ble_qiot_log_e("invalid action id %d", action_id);
        return -1;
    }

    if (NULL != sg_ble_action_array[action_id].input_cb) {
        if (0 != sg_ble_action_array[action_id].input_cb(input_param_array, input_array_size, output_id_array)) {
            ble_qiot_log_e("input handle error");
            return -1;
        }
    }

    return 0;
}

int ble_action_user_handle_output_param(uint8_t action_id, uint8_t output_id, char *buf, uint16_t buf_len)
{
    int ret_len = 0;

    if (action_id >= BLE_QIOT_ACTION_ID_BUTT) {
        ble_qiot_log_e("invalid action id %d", action_id);
        return -1;
    }
    if (NULL == sg_ble_action_array[action_id].output_cb) {
        ble_qiot_log_e("invalid callback, action id %d", action_id);
        return 0;
    }

    if (!ble_check_space_enough_by_type(sg_ble_action_array[action_id].output_type_array[output_id], buf_len)) {
        ble_qiot_log_e("not enough space get data, action id %d, output id %d", action_id, output_id);
        return -1;
    }

    ret_len = sg_ble_action_array[action_id].output_cb(output_id, buf, buf_len);
    if (ret_len < 0) {
        ble_qiot_log_e("get action data failed, action id %d, output id %d", action_id, output_id);
        return -1;
    } else {
        if (ble_check_ret_value_by_type(sg_ble_action_array[action_id].output_type_array[output_id], buf_len,
                                        ret_len)) {
            return ret_len;
        } else {
            ble_qiot_log_e("action data length invalid, action id %d, output id %d", action_id, output_id);
            return -1;
        }
    }
}

#ifdef __cplusplus
}
#endif

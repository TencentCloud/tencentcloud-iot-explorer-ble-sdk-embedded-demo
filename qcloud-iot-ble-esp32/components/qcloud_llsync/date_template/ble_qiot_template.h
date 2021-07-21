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
#ifndef BLE_QIOT_TEMPLATE_H_
#define BLE_QIOT_TEMPLATE_H_
#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stdbool.h>

// data type in template, corresponding to type in json file
enum {
  BLE_QIOT_DATA_TYPE_BOOL = 0,
  BLE_QIOT_DATA_TYPE_INT,
  BLE_QIOT_DATA_TYPE_STRING,
  BLE_QIOT_DATA_TYPE_FLOAT,
  BLE_QIOT_DATA_TYPE_ENUM,
  BLE_QIOT_DATA_TYPE_TIME,
  BLE_QIOT_DATA_TYPE_STRUCT,
  BLE_QIOT_DATA_TYPE_ARRAY,
  BLE_QIOT_DATA_TYPE_BUTT,
};

#define BLE_QIOT_ARRAY_INT_BIT_MASK     (1 << 4)
#define BLE_QIOT_ARRAY_STRING_BIT_MASK  (1 << 5)
#define BLE_QIOT_ARRAY_FLOAT_BIT_MASK   (1 << 6)
#define BLE_QIOT_ARRAY_STRUCT_BIT_MASK  (1 << 7)
// message type, reference data template
enum {
  BLE_QIOT_PROPERTY_AUTH_RW = 0,
  BLE_QIOT_PROPERTY_AUTH_READ,
  BLE_QIOT_PROPERTY_AUTH_BUTT,
};

// define message flow direction
enum {
  BLE_QIOT_EFFECT_REQUEST = 0,
  BLE_QIOT_EFFECT_REPLY,
  BLE_QIOT_EFFECT_BUTT,
};

#define	BLE_QIOT_PACKAGE_MSG_HEAD(_TYPE, _REPLY, _ID)	(((_TYPE) << 6) | (((_REPLY) == BLE_QIOT_EFFECT_REPLY) << 5) | ((_ID) & 0X1F))
#define	BLE_QIOT_PACKAGE_TLV_HEAD(_TYPE, _ID)   	    (((_TYPE) << 5) | ((_ID) & 0X1F))

// define tlv struct
typedef struct{	uint8_t type;
  uint8_t id;
  uint16_t len;
  char *val;
}e_ble_tlv;


#define	BLE_QIOT_INCLUDE_PROPERTY

// define property id
enum {
  BLE_QIOT_PROPERTY_ID_T_BOOL,
  BLE_QIOT_PROPERTY_ID_T_INT,
  BLE_QIOT_PROPERTY_ID_T_STR,
  BLE_QIOT_PROPERTY_ID_T_FLOAT,
  BLE_QIOT_PROPERTY_ID_T_ENUM,
  BLE_QIOT_PROPERTY_ID_T_TIME,
  BLE_QIOT_PROPERTY_ID_T_STRUCT,
  BLE_QIOT_PROPERTY_ID_T_STRUCT2,
  BLE_QIOT_PROPERTY_ID_T_INT_ARRAY,
  BLE_QIOT_PROPERTY_ID_T_FLOT_ARRAY,
  BLE_QIOT_PROPERTY_ID_T_STRUCT_ARRAY,
  BLE_QIOT_PROPERTY_ID_T_STR_ARRAY,
  BLE_QIOT_PROPERTY_ID_BUTT,
};

// define t_int attributes
#define BLE_QIOT_PROPERTY_T_INT_MIN	(0)
#define BLE_QIOT_PROPERTY_T_INT_MAX	(2222222222)
#define BLE_QIOT_PROPERTY_T_INT_START	(0)
#define BLE_QIOT_PROPERTY_T_INT_STEP	(1)
// define t_str length limit
#define BLE_QIOT_PROPERTY_T_STR_LEN_MIN	(0)
#define BLE_QIOT_PROPERTY_T_STR_LEN_MAX	(128)
// define t_float attributes
#define BLE_QIOT_PROPERTY_T_FLOAT_MIN	(0)
#define BLE_QIOT_PROPERTY_T_FLOAT_MAX	(12800)
#define BLE_QIOT_PROPERTY_T_FLOAT_START	(0)
#define BLE_QIOT_PROPERTY_T_FLOAT_STEP	(1)
// define t_enum enum
enum {
  BLE_QIOT_PROPERTY_T_ENUM_RED = 0,
  BLE_QIOT_PROPERTY_T_ENUM_GREEN = 1,
  BLE_QIOT_PROPERTY_T_ENUM_BLUE = 2,
  BLE_QIOT_PROPERTY_T_ENUM_BUTT,
};

// define t_struct s_int attributes
#define BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_S_INT_MIN	(0)
#define BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_S_INT_MAX	(100000000)
#define BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_S_INT_START	(0)
#define BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_S_INT_STEP	(1)
// define t_structs_str length limit
#define BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_S_STR_LEN_MIN	(0)
#define BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_S_STR_LEN_MAX	(2048)
// define t_struct s_float attributes
#define BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_S_FLOAT_MIN	(0)
#define BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_S_FLOAT_MAX	(100)
#define BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_S_FLOAT_START	(0)
#define BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_S_FLOAT_STEP	(1)
// define t_struct s_enum enum
enum {
  BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_S_ENUM_R = 0,
  BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_S_ENUM_G = 1,
  BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_S_ENUM_B = 2,
  BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_S_ENUM_BUTT,
};

// define t_struct property id
enum {
  BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_ID_S_BOOL,
  BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_ID_S_INT,
  BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_ID_S_STR,
  BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_ID_S_FLOAT,
  BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_ID_S_ENUM,
  BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_ID_S_TIME,
  BLE_QIOT_STRUCT_T_STRUCT_PROPERTY_ID_BUTT,
};

typedef struct{
  bool m_s_bool;
  int32_t m_s_int;
  char m_s_str[2048];
  float m_s_float;
  uint16_t m_s_enum;
  uint32_t m_s_time;
}struct_property_t_struct;

// define t_struct2 property id
enum {
  BLE_QIOT_STRUCT_T_STRUCT2_PROPERTY_ID_S_BOOL,
  BLE_QIOT_STRUCT_T_STRUCT2_PROPERTY_ID_BUTT,
};

typedef struct{
  bool m_s_bool;
}struct_property_t_struct2;

// define t_int_array attributes
#define BLE_QIOT_PROPERTY_T_INT_ARRAY_MIN	(0)
#define BLE_QIOT_PROPERTY_T_INT_ARRAY_MAX	(100)
#define BLE_QIOT_PROPERTY_T_INT_ARRAY_START	(0)
#define BLE_QIOT_PROPERTY_T_INT_ARRAY_STEP	(1)
//define the actual size of array
#define BLE_QIOT_PROPERTY_T_INT_ARRAY_SIZE_MAX	(3)
#if BLE_QIOT_PROPERTY_T_INT_ARRAY_SIZE_MAX == 0
#error "please define t_int_array array size first"
#endif
typedef struct{
  int32_t m_int_arr[BLE_QIOT_PROPERTY_T_INT_ARRAY_SIZE_MAX];
  uint16_t m_arr_size;
}array_struct_t_int_array;

// define t_flot_array attributes
#define BLE_QIOT_PROPERTY_T_FLOT_ARRAY_MIN	(0)
#define BLE_QIOT_PROPERTY_T_FLOT_ARRAY_MAX	(100)
#define BLE_QIOT_PROPERTY_T_FLOT_ARRAY_START	(0)
#define BLE_QIOT_PROPERTY_T_FLOT_ARRAY_STEP	(1)
//define the actual size of array
#define BLE_QIOT_PROPERTY_T_FLOT_ARRAY_SIZE_MAX	(3)
#if BLE_QIOT_PROPERTY_T_FLOT_ARRAY_SIZE_MAX == 0
#error "please define t_flot_array array size first"
#endif
typedef struct{
  float m_float_arr[BLE_QIOT_PROPERTY_T_FLOT_ARRAY_SIZE_MAX];
  uint16_t m_arr_size;
}array_struct_t_flot_array;

// define t_struct_array t_int attributes
#define BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_T_INT_MIN	(0)
#define BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_T_INT_MAX	(100)
#define BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_T_INT_START	(0)
#define BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_T_INT_STEP	(1)
// define t_struct_arrayt_str length limit
#define BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_T_STR_LEN_MIN	(0)
#define BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_T_STR_LEN_MAX	(32)
// define t_struct_array t_float attributes
#define BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_T_FLOAT_MIN	(0)
#define BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_T_FLOAT_MAX	(100)
#define BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_T_FLOAT_START	(0)
#define BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_T_FLOAT_STEP	(1)
// define t_struct_array t_enum enum
enum {
  BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_T_ENUM_TEST_0 = 0,
  BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_T_ENUM_TEST_1 = 1,
  BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_T_ENUM_BUTT,
};

// define t_struct_array property id
enum {
  BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_ID_T_BOOL,
  BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_ID_T_INT,
  BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_ID_T_STR,
  BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_ID_T_FLOAT,
  BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_ID_T_TIME,
  BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_ID_T_ENUM,
  BLE_QIOT_STRUCT_T_STRUCT_ARRAY_PROPERTY_ID_BUTT,
};

typedef struct{
  bool m_t_bool;
  int32_t m_t_int;
  char m_t_str[32];
  float m_t_float;
  uint32_t m_t_time;
  uint16_t m_t_enum;
}struct_property_t_struct_array;

//define the actual size of array
#define BLE_QIOT_PROPERTY_T_STRUCT_ARRAY_SIZE_MAX	(3)
#if BLE_QIOT_PROPERTY_T_STRUCT_ARRAY_SIZE_MAX == 0
#error "please define t_struct_array array size first"
#endif
typedef struct{
  struct_property_t_struct_array m_struct_arr[BLE_QIOT_PROPERTY_T_STRUCT_ARRAY_SIZE_MAX];
  uint16_t m_arr_size;
}array_struct_t_struct_array;

// define t_str_array length limit
#define BLE_QIOT_PROPERTY_T_STR_ARRAY_LEN_MIN	(0)
#define BLE_QIOT_PROPERTY_T_STR_ARRAY_LEN_MAX	(32)
//define the actual size of array
#define BLE_QIOT_PROPERTY_T_STR_ARRAY_SIZE_MAX	(3)
#if BLE_QIOT_PROPERTY_T_STR_ARRAY_SIZE_MAX == 0
#error "please define t_str_array array size first"
#endif
typedef struct{
  char m_str_arr[BLE_QIOT_PROPERTY_T_STR_ARRAY_SIZE_MAX][32];
  uint16_t m_arr_size;
}array_struct_t_str_array;

// define property set handle return 0 if success, other is error
// sdk call the function that inform the server data to the device
typedef int (*property_set_cb)(const char *data, uint16_t len);
// define property get handle. return the data length obtained, -1 is error, 0 is no data
// sdk call the function fetch user data and send to the server, the data should wrapped by user adn skd just transmit
typedef int (*property_get_cb)(char *buf, uint16_t buf_len);
// each property have a struct ble_property_t, make up a array named sg_ble_property_array
typedef struct{
  property_set_cb set_cb;	//set callback
  property_get_cb get_cb;	//get callback
  uint8_t authority;	//property authority
  uint8_t type;	//data type
  uint16_t elem_num;
}ble_property_t;
typedef int (*property_array_set_cb)(const char *data, uint16_t len, uint16_t index);
typedef int (*property_array_get_cb)(char *buf, uint16_t buf_len, uint16_t index);


#define	BLE_QIOT_INCLUDE_EVENT

// define event id
enum {
  BLE_QIOT_EVENT_ID_T_EVENT,
  BLE_QIOT_EVENT_ID_BUTT,
};

// define event t_event param id
enum {
  BLE_QIOT_EVENT_T_EVENT_PARAM_ID_T_BOOL,
  BLE_QIOT_EVENT_T_EVENT_PARAM_ID_T_INT,
  BLE_QIOT_EVENT_T_EVENT_PARAM_ID_T_STR,
  BLE_QIOT_EVENT_T_EVENT_PARAM_ID_T_ENUM,
  BLE_QIOT_EVENT_T_EVENT_PARAM_ID_T_FLOAT,
  BLE_QIOT_EVENT_T_EVENT_PARAM_ID_T_TIME,
  BLE_QIOT_EVENT_T_EVENT_PARAM_ID_BUTT,
};

// define t_event t_int attributes
#define BLE_QIOT_EVENT_T_EVENT_T_INT_MIN	(0)
#define BLE_QIOT_EVENT_T_EVENT_T_INT_MAX	(100)
#define BLE_QIOT_EVENT_T_EVENT_T_INT_START	(0)
#define BLE_QIOT_EVENT_T_EVENT_T_INT_STEP	(1)
// define t_eventt_str length limit
#define BLE_QIOT_EVENT_T_EVENT_T_STR_LEN_MIN	(0)
#define BLE_QIOT_EVENT_T_EVENT_T_STR_LEN_MAX	(128)
// define t_event t_enum enum
enum {
  BLE_QIOT_EVENT_T_EVENT_T_ENUM_R = 0,
  BLE_QIOT_EVENT_T_EVENT_T_ENUM_G = 1,
  BLE_QIOT_EVENT_T_EVENT_T_ENUM_B = 2,
  BLE_QIOT_EVENT_T_EVENT_T_ENUM_BUTT,
};

// define t_event t_float attributes
#define BLE_QIOT_EVENT_T_EVENT_T_FLOAT_MIN	(0)
#define BLE_QIOT_EVENT_T_EVENT_T_FLOAT_MAX	(100)
#define BLE_QIOT_EVENT_T_EVENT_T_FLOAT_START	(0)
#define BLE_QIOT_EVENT_T_EVENT_T_FLOAT_STEP	(1)
// define event get handle. return the data length obtained, -1 is error, 0 is no data
// sdk call the function fetch user data and send to the server, the data should wrapped by user adn skd just transmit
typedef int (*event_get_cb)(char *buf, uint16_t buf_len);
// each param have a struct ble_event_param, make up a array for the event
typedef struct{
  event_get_cb get_cb;	//get param data callback
  uint8_t type;	//param type
}ble_event_param;
// a array named sg_ble_event_array is composed by all the event array
typedef struct{
  ble_event_param *event_array;	//array of params data
  uint8_t array_size;	//array size
}ble_event_t;


#define	BLE_QIOT_INCLUDE_ACTION

// define action id
enum {
  BLE_QIOT_ACTION_ID_T_ACTION,
  BLE_QIOT_ACTION_ID_BUTT,
};

// define action t_action input id
enum {
  BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_BOOL,
  BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_INT,
  BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_STR,
  BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_FLOAT,
  BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_ENUM,
  BLE_QIOT_ACTION_T_ACTION_INPUT_ID_IN_TIME,
  BLE_QIOT_ACTION_T_ACTION_INPUT_ID_BUTT,
};

// define t_action in_int attributes
#define BLE_QIOT_ACTION_INPUT_T_ACTION_IN_INT_MIN	(0)
#define BLE_QIOT_ACTION_INPUT_T_ACTION_IN_INT_MAX	(100)
#define BLE_QIOT_ACTION_INPUT_T_ACTION_IN_INT_START	(0)
#define BLE_QIOT_ACTION_INPUT_T_ACTION_IN_INT_STEP	(1)
// define t_actionin_str length limit
#define BLE_QIOT_ACTION_INPUT_T_ACTION_IN_STR_LEN_MIN	(0)
#define BLE_QIOT_ACTION_INPUT_T_ACTION_IN_STR_LEN_MAX	(128)
// define t_action in_float attributes
#define BLE_QIOT_ACTION_INPUT_T_ACTION_IN_FLOAT_MIN	(0)
#define BLE_QIOT_ACTION_INPUT_T_ACTION_IN_FLOAT_MAX	(100)
#define BLE_QIOT_ACTION_INPUT_T_ACTION_IN_FLOAT_START	(0)
#define BLE_QIOT_ACTION_INPUT_T_ACTION_IN_FLOAT_STEP	(1)
// define t_action in_enum enum
enum {
  BLE_QIOT_ACTION_INPUT_T_ACTION_IN_ENUM_R = 0,
  BLE_QIOT_ACTION_INPUT_T_ACTION_IN_ENUM_G = 1,
  BLE_QIOT_ACTION_INPUT_T_ACTION_IN_ENUM_B = 2,
  BLE_QIOT_ACTION_INPUT_T_ACTION_IN_ENUM_BUTT,
};

// define action t_action output id
enum {
  BLE_QIOT_ACTION_T_ACTION_OUTPUT_ID_OUT_BOOL,
  BLE_QIOT_ACTION_T_ACTION_OUTPUT_ID_OUT_INT,
  BLE_QIOT_ACTION_T_ACTION_OUTPUT_ID_OUT_STR,
  BLE_QIOT_ACTION_T_ACTION_OUTPUT_ID_OUT_FLOAT,
  BLE_QIOT_ACTION_T_ACTION_OUTPUT_ID_OUT_ENUM,
  BLE_QIOT_ACTION_T_ACTION_OUTPUT_ID_OUT_TIME,
  BLE_QIOT_ACTION_T_ACTION_OUTPUT_ID_BUTT,
};

// define t_action out_int attributes
#define BLE_QIOT_ACTION_OUTPUT_T_ACTION_OUT_INT_MIN	(0)
#define BLE_QIOT_ACTION_OUTPUT_T_ACTION_OUT_INT_MAX	(100)
#define BLE_QIOT_ACTION_OUTPUT_T_ACTION_OUT_INT_START	(0)
#define BLE_QIOT_ACTION_OUTPUT_T_ACTION_OUT_INT_STEP	(1)
// define t_actionout_str length limit
#define BLE_QIOT_ACTION_OUTPUT_T_ACTION_OUT_STR_LEN_MIN	(0)
#define BLE_QIOT_ACTION_OUTPUT_T_ACTION_OUT_STR_LEN_MAX	(128)
// define t_action out_float attributes
#define BLE_QIOT_ACTION_OUTPUT_T_ACTION_OUT_FLOAT_MIN	(0)
#define BLE_QIOT_ACTION_OUTPUT_T_ACTION_OUT_FLOAT_MAX	(100)
#define BLE_QIOT_ACTION_OUTPUT_T_ACTION_OUT_FLOAT_START	(0)
#define BLE_QIOT_ACTION_OUTPUT_T_ACTION_OUT_FLOAT_STEP	(1)
// define t_action out_enum enum
enum {
  BLE_QIOT_ACTION_OUTPUT_T_ACTION_OUT_ENUM_R = 0,
  BLE_QIOT_ACTION_OUTPUT_T_ACTION_OUT_ENUM_G = 1,
  BLE_QIOT_ACTION_OUTPUT_T_ACTION_OUT_ENUM_B = 2,
  BLE_QIOT_ACTION_OUTPUT_T_ACTION_OUT_ENUM_BUTT,
};

#define BLE_QIOT_ACTION_INPUT_ID_BUTT	6
#define BLE_QIOT_ACTION_OUTPUT_ID_BUTT	6
// define action input handle, return 0 is success, other is error.
// input_param_array carry the data from server, include input id, data length ,data val
// input_array_size means how many input id
// output_id_array filling with output id numbers that need obtained, sdk will traverse it and call the action_output_handle to obtained data
typedef int (*action_input_handle)(e_ble_tlv *input_param_array, uint8_t input_array_size, uint8_t *output_id_array);
// define action output handle, return length of the data, 0 is no data, -1 is error
// output_id means which id data should be obtained
typedef int (*action_output_handle)(uint8_t output_id, char *buf, uint16_t buf_len);
// each action have a struct ble_action_t, make up a array named sg_ble_action_array
typedef struct{
  action_input_handle input_cb;	//handle input data
  action_output_handle output_cb;	// get output data in the callback
  uint8_t *input_type_array;	//type array for input id
  uint8_t *output_type_array;	//type array for output id
  uint8_t input_id_size;	//numbers of input id
  uint8_t output_id_size;	//numbers of output id
}ble_action_t;

// property module
#ifdef BLE_QIOT_INCLUDE_PROPERTY
uint8_t ble_get_property_type_by_id(uint8_t id);
int ble_user_property_set_data(const e_ble_tlv *tlv);
int ble_user_property_get_data_by_id(uint8_t id, char *buf, uint16_t buf_len);
int ble_user_property_report_reply_handle(uint8_t result);
int ble_lldata_parse_tlv(const char *buf, int buf_len, e_ble_tlv *tlv);
int ble_user_property_struct_handle(const char *in_buf, uint16_t buf_len, ble_property_t *struct_arr, uint8_t arr_size);
int ble_user_property_struct_get_data(char *in_buf, uint16_t buf_len, ble_property_t *struct_arr, uint8_t arr_size);
int ble_user_property_struct_array_set(uint8_t id, const char *in_buf, uint16_t buf_len, ble_property_t struct_arr[], uint8_t arr_size);
int ble_user_property_struct_array_get(uint8_t id, char *in_buf, uint16_t buf_len, ble_property_t struct_arr[], uint8_t arr_size);
#endif
// event module
#ifdef BLE_QIOT_INCLUDE_EVENT
int     ble_event_get_id_array_size(uint8_t event_id);
uint8_t ble_event_get_param_id_type(uint8_t event_id, uint8_t param_id);
int     ble_event_get_data_by_id(uint8_t event_id, uint8_t param_id, char *out_buf, uint16_t buf_len);
int     ble_user_event_reply_handle(uint8_t event_id, uint8_t result);
#endif
// action module
#ifdef BLE_QIOT_INCLUDE_ACTION
uint8_t ble_action_get_intput_type_by_id(uint8_t action_id, uint8_t input_id);
uint8_t ble_action_get_output_type_by_id(uint8_t action_id, uint8_t output_id);
int     ble_action_get_input_id_size(uint8_t action_id);
int     ble_action_get_output_id_size(uint8_t action_id);
int     ble_action_user_handle_input_param(uint8_t action_id, e_ble_tlv *input_param_array, uint8_t input_array_size, uint8_t *output_id_array);
int     ble_action_user_handle_output_param(uint8_t action_id, uint8_t output_id, char *buf, uint16_t buf_len);
#endif

#ifdef __cplusplus
}
#endif
#endif //BLE_QIOT_TEMPLATE_H_

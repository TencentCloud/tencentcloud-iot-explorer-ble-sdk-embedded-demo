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
	BLE_QIOT_DATA_TYPE_BUTT,
};

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
#define	BLE_QIOT_PACKAGE_TLV_HEAD(_TYPE, _ID)   	(((_TYPE) << 5) | ((_ID) & 0X1F))


// define tlv struct
typedef struct{
	uint8_t type;
	uint8_t id;
	uint16_t len;
	char *val;
}e_ble_tlv;
#define	BLE_QIOT_INCLUDE_PROPERTY               	                                

// define property id
enum {
	BLE_QIOT_PROPERTY_ID_PROPERTY_BOOL = 0,
	BLE_QIOT_PROPERTY_ID_PROPERTY_INT,
	BLE_QIOT_PROPERTY_ID_PROPERTY_STRING,
	BLE_QIOT_PROPERTY_ID_PROPERTY_FLOAT,
	BLE_QIOT_PROPERTY_ID_PROPERTY_ENUM,
	BLE_QIOT_PROPERTY_ID_PROPERTY_TIME,
	BLE_QIOT_PROPERTY_ID_PROPERTY_STRUCT,
	BLE_QIOT_PROPERTY_ID_BUTT,
};

// define property_int attributes
#define	BLE_QIOT_PROPERTY_PROPERTY_INT_MIN      	(-100000)                       
#define	BLE_QIOT_PROPERTY_PROPERTY_INT_MAX      	(100000)                        
#define	BLE_QIOT_PROPERTY_PROPERTY_INT_START    	(0)                             
#define	BLE_QIOT_PROPERTY_PROPERTY_INT_STEP     	(1)                             

// define property_string length limit
#define	BLE_QIOT_PROPERTY_PROPERTY_STRING_LEN_MIN	(0)                             
#define	BLE_QIOT_PROPERTY_PROPERTY_STRING_LEN_MAX	(128)                           

// define property_float attributes
#define	BLE_QIOT_PROPERTY_PROPERTY_FLOAT_MIN    	(-100)                          
#define	BLE_QIOT_PROPERTY_PROPERTY_FLOAT_MAX    	(100)                           
#define	BLE_QIOT_PROPERTY_PROPERTY_FLOAT_START  	(0)                             
#define	BLE_QIOT_PROPERTY_PROPERTY_FLOAT_STEP   	(0.001)                         

// define property property_enum enum
enum {
	BLE_QIOT_PROPERTY_PROPERTY_ENUM_ENUM0 = 0,
	BLE_QIOT_PROPERTY_PROPERTY_ENUM_ENUM1 = 1,
	BLE_QIOT_PROPERTY_PROPERTY_ENUM_ENUM2 = 2,
	BLE_QIOT_PROPERTY_PROPERTY_ENUM_ENUM3 = 3,
	BLE_QIOT_PROPERTY_PROPERTY_ENUM_BUTT = 4,
};

// define property id
enum {
	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_ID_MEM_BOOL = 0,
	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_ID_MEM_INT,
	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_ID_MEM_STRING,
	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_ID_MEM_FLOAT,
	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_ID_MEM_ENUM,
	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_ID_MEM_TIME,
	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_ID_BUTT,
};

// define mem_int attributes
#define	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_INT_MIN	(-10000)                        
#define	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_INT_MAX	(10000)                         
#define	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_INT_START	(0)                             
#define	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_INT_STEP	(1)                             

// define mem_string length limit
#define	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_STRING_LEN_MIN	(0)                             
#define	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_STRING_LEN_MAX	(128)                           

// define mem_float attributes
#define	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_FLOAT_MIN	(-100)                          
#define	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_FLOAT_MAX	(100)                           
#define	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_FLOAT_START	(0)                             
#define	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_FLOAT_STEP	(0.001)                         

// define property mem_enum enum
enum {
	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_ENUM_MEM_ENUM0 = 0,
	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_ENUM_MEM_ENUM1 = 1,
	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_ENUM_MEM_ENUM2 = 2,
	BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_ENUM_BUTT = 3,
};

typedef struct{
	bool m_mem_bool;
	int32_t m_mem_int;
	char m_mem_string[BLE_QIOT_STRUCT_PROPERTY_STRUCT_PROPERTY_MEM_STRING_LEN_MAX];
	float m_mem_float;
	uint16_t m_mem_enum;
	uint32_t m_mem_time;
}struct_property_property_struct;

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
}ble_property_t;
#define	BLE_QIOT_INCLUDE_EVENT                  	                                

// define event id
enum {
	BLE_QIOT_EVENT_ID_EVENT_WARNNING = 0,
	BLE_QIOT_EVENT_ID_EVENT_ERROR,
	BLE_QIOT_EVENT_ID_BUTT,
};

// define param id for event event_warnning
enum {
	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_ID_PARAM_BOOL = 0,
	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_ID_PARAM_INT,
	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_ID_PARAM_STRING,
	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_ID_PARAM_FLOAT,
	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_ID_PARAM_ENUM,
	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_ID_PARAM_TIME,
	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_ID_BUTT,
};

// define param param_int attributes
#define	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_INT_MIN	(-100000)                       
#define	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_INT_MAX	(1000000)                       
#define	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_INT_START	(0)                             
#define	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_INT_STEP	(1)                             

// define range for param param_string
#define	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_STRING_LEN_MIN	(0)                             
#define	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_STRING_LEN_MAX	(128)                           

// define param param_float attributes
#define	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_FLOAT_MIN	(0)                             
#define	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_FLOAT_MAX	(100)                           
#define	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_FLOAT_START	(0)                             
#define	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_FLOAT_STEP	(0.001)                         

// define enum for param param_enum
enum {
	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_ENUM_PARAM_ENUM0 = 0,
	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_ENUM_PARAM_ENUM1 = 1,
	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_ENUM_PARAM_ENUM2 = 2,
	BLE_QIOT_EVENT_EVENT_WARNNING_PARAM_ENUM_BUTT = 3,
};

// define param id for event event_error
enum {
	BLE_QIOT_EVENT_EVENT_ERROR_PARAM_ID_PARAM_BOOL = 0,
	BLE_QIOT_EVENT_EVENT_ERROR_PARAM_ID_PARAM_STRING,
	BLE_QIOT_EVENT_EVENT_ERROR_PARAM_ID_BUTT,
};

// define range for param param_string
#define	BLE_QIOT_EVENT_EVENT_ERROR_PARAM_STRING_LEN_MIN	(0)                             
#define	BLE_QIOT_EVENT_EVENT_ERROR_PARAM_STRING_LEN_MAX	(128)                           

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
	BLE_QIOT_ACTION_ID_ACTION_TEST = 0,
	BLE_QIOT_ACTION_ID_BUTT,
};

// define input id for action action_test
enum {
	BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_BOOL_INPUT = 0,
	BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_INT_INPUT,
	BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_STRING_INPUT,
	BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_FLOAT_INPUT,
	BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_ENUM_INPUT,
	BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_TIME_INPUT,
	BLE_QIOT_ACTION_ACTION_TEST_INPUT_ID_BUTT,
};

// define output id for action action_test
enum {
	BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_BOOL_OUTPUT = 0,
	BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_INT_OUTPUT,
	BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_STRING_OUTPUT,
	BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_FLOAT_OUTPUT,
	BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_ENUM_OUTPUT,
	BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_TIME_OUTPUT,
	BLE_QIOT_ACTION_ACTION_TEST_OUTPUT_ID_BUTT,
};
#define	BLE_QIOT_ACTION_INPUT_ACTION_TEST_INT_INPUT_MIN	(-100000)                       
#define	BLE_QIOT_ACTION_INPUT_ACTION_TEST_INT_INPUT_MAX	(100000)                        
#define	BLE_QIOT_ACTION_INPUT_ACTION_TEST_INT_INPUT_START	(0)                             
#define	BLE_QIOT_ACTION_INPUT_ACTION_TEST_INT_INPUT_STEP	(1)                             

// define input id string_input attributes
#define	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_STRING_INPUT_LEN_MIN	(0)                             
#define	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_STRING_INPUT_LEN_MAX	(128)                           
#define	BLE_QIOT_ACTION_INPUT_ACTION_TEST_FLOAT_INPUT_MIN	(-100)                          
#define	BLE_QIOT_ACTION_INPUT_ACTION_TEST_FLOAT_INPUT_MAX	(100)                           
#define	BLE_QIOT_ACTION_INPUT_ACTION_TEST_FLOAT_INPUT_START	(0)                             
#define	BLE_QIOT_ACTION_INPUT_ACTION_TEST_FLOAT_INPUT_STEP	(1)                             

// define enum for input id enum_input
enum {
	BLE_QIOT_ACTION_INPUT_ACTION_TEST_ENUM_INPUT_INPUT_ENUM0 = 0,
	BLE_QIOT_ACTION_INPUT_ACTION_TEST_ENUM_INPUT_INPUT_ENUM1 = 1,
	BLE_QIOT_ACTION_INPUT_ACTION_TEST_ENUM_INPUT_INPUT_ENUM2 = 2,
	BLE_QIOT_ACTION_INPUT_ACTION_TEST_ENUM_INPUT_BUTT = 3,
};

// define output id int_output attributes
#define	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_INT_OUTPUT_MIN	(-100000)                       
#define	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_INT_OUTPUT_MAX	(1000000)                       
#define	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_INT_OUTPUT_START	(0)                             
#define	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_INT_OUTPUT_STEP	(1)                             

// define output id string_output attributes
#define	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_STRING_OUTPUT_LEN_MIN	(0)                             
#define	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_STRING_OUTPUT_LEN_MAX	(128)                           

// define output id float_output attributes
#define	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_FLOAT_OUTPUT_MIN	(-100)                          
#define	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_FLOAT_OUTPUT_MAX	(100)                           
#define	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_FLOAT_OUTPUT_START	(0)                             
#define	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_FLOAT_OUTPUT_STEP	(1)                             

// define enum for output id enum_output
enum {
	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_ENUM_OUTPUT_OUTPUT_ENUM0 = 0,
	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_ENUM_OUTPUT_OUTPUT_ENUM1 = 1,
	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_ENUM_OUTPUT_OUTPUT_ENUM2 = 2,
	BLE_QIOT_ACTION_OUTPUT_ACTION_TEST_ENUM_OUTPUT_BUTT = 3,
};

// define max input id and output id in all of input id and output id above
#define	BLE_QIOT_ACTION_INPUT_ID_BUTT           	6                               
#define	BLE_QIOT_ACTION_OUTPUT_ID_BUTT          	6                               

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
int     ble_action_user_handle_input_param(uint8_t action_id, e_ble_tlv *input_param_array, uint8_t input_array_size,
                                           uint8_t *output_id_array);
int     ble_action_user_handle_output_param(uint8_t action_id, uint8_t output_id, char *buf, uint16_t buf_len);
#endif


#ifdef __cplusplus
}
#endif
#endif //BLE_QIOT_TEMPLATE_H_

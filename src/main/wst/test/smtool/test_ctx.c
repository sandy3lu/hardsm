#include <stdio.h>
#include <assert.h>
#include "../../proto/sm.pb-c.h"
#include "../../include/sm_api.h"
#include "../../api/hardsm.h"
#include "smtool.h"


static void test_init();
static void test_final();
static void test_print_context();
static void test_login_device();
static void test_logout_device();
static void test_device_status();
static int test_ctx_info();
static void test_protect_key(int flag);


void test_ctx() {
    test_init();

    test_ctx_info();

    test_login_device();

    test_device_status(0);
    test_crypto();
    test_device_status(0);

    test_logout_device();

    test_final();
}

static void test_init() {
    uint8_t out[1024 * 32]  ={0};

    int l = api_init(out);
    Response *response = response__unpack(NULL, l, out);
    check_response(response);
    response__free_unpacked(response, NULL);
}

static void test_final() {
    uint8_t out[1024 * 32]  ={0};
    int l = api_final(out);
    Response *response = response__unpack(NULL, l, out);
    check_response(response);
    response__free_unpacked(response, NULL);
}

static void test_print_context() {
    uint8_t out[1024 * 32]  ={0};

    int l = api_print_context(true, out);
    Response *response = response__unpack(NULL, l, out);
    check_response(response);
    StrValue *str_value = (StrValue *)response->str_value;
    printf("%s", str_value->value);
    response__free_unpacked(response, NULL);
}

static void test_login_device() {
    uint8_t out[1024 * 32]  ={0};

    int l = api_login_device(0, "11111111", out);
    Response *response = response__unpack(NULL, l, out);
    check_response(response);
    response__free_unpacked(response, NULL);
}

static void test_logout_device() {
    uint8_t out[1024 * 32]  ={0};

    int l = api_logout_device(0, out);
    Response *response = response__unpack(NULL, l, out);
    check_response(response);
    response__free_unpacked(response, NULL);
}

static void test_device_status(int device_index) {
    uint8_t out[1024 * 32]  ={0};

    int l = api_device_status(device_index, out);
    Response *response = response__unpack(NULL, l, out);
    check_response(response);
    DevStatus *device_status = (DevStatus *)response->device_status;
    print_dev_status(device_status);
    response__free_unpacked(response, NULL);
}

static int test_ctx_info() {
    uint8_t out[1024 * 32]  ={0};

    int l = api_ctx_info(out);
    Response *response = response__unpack(NULL, l, out);
    check_response(response);
    CtxInfo *ctx_info = (CtxInfo *)response->ctx_info;
    print_ctx_info(ctx_info);
    int device_count = ctx_info->device_count;
    response__free_unpacked(response, NULL);
    return device_count;
}

static void test_protect_key(int flag) {
    uint8_t out[1024 * 32]  ={0};

    int l = api_protect_key(flag, out);
    Response *response = response__unpack(NULL, l, out);
    check_response(response);
    response__free_unpacked(response, NULL);
}

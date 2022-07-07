#include <napi.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "genomus-core/library/decoded_genotype.hpp"
#include "genomus-core/library/genomus-core.hpp"
#include "genomus-core/library/parser.hpp"
#include "genomus_core_native.hpp"
#include "node_api.h"
#include "node_api_types.h"

using namespace Napi;
using namespace std;

static napi_status STATUS;

void log(auto message) {
    cout << "\n##################### BEGIN C++ LOG\n\n";
    cout << message << endl;
    cout << "\n##################### END C++ LOG\n\n";
}

float getOneFloatParameter(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    double result;
    
    STATUS = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);

    if (STATUS != napi_ok) throw 1;

    STATUS = napi_get_value_double(env, argv[0], &result);

    if (STATUS != napi_ok) throw 1;

    return result;
}

string getOneStringParameter(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    static const size_t buff_size = 1024;
    char buffer[buff_size - 1];
    char result_buffer[buff_size] = {0};
    size_t result_size;

    
    STATUS = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);

    if (STATUS != napi_ok) throw 1;

    STATUS = napi_get_value_string_utf8(env, argv[0], buffer, buff_size, &result_size);

    if (STATUS != napi_ok) throw 1;

    memcpy(result_buffer, buffer, result_size * sizeof(char));

    return string(result_buffer);
}

void registerFunction(function<void(string)> f, napi_env *env, napi_value* exports, napi_property_descriptor* pd) {
    napi_callback cb = [](napi_env env, napi_callback_info info) -> napi_value { 
        const string parameter = getOneStringParameter(env, info);
        stringstream ss;
        ss << " - Decoded Genotype: " << parseString(parameter).toString() << endl;
        ss << " - Encoded Phenotype: " << parseString(parameter).evaluate().toString() << endl;
        return Napi::String::New(env, ss.str()); 
    };

    pd -> utf8name = NULL;
    pd -> name = Napi::String::New(*env, "interpreter"); 
    pd -> method = cb,
    pd -> getter = NULL;
    pd -> setter = NULL;
    pd -> value = NULL;
    pd -> attributes = napi_enumerable;
    pd -> data = NULL;

    STATUS = napi_define_properties(*env, *exports, 1, pd);
}

napi_value Init(napi_env env, napi_value exports) {
    napi_property_descriptor long_life_pd;

    init_genomus();

    registerFunction(parseString, &env, &exports, &long_life_pd);

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
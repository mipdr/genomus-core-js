#include <napi.h>
#include <iostream>
#include "genomus_core_native.hpp"

using namespace Napi;

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

map<std::string, napi_callback> ParameterMapperWrappers({
    { "NoteValueF", [](napi_env env, napi_callback_info info) -> napi_value { 
        const double parameter = getOneFloatParameter(env, info);
        return Napi::Number::New(env, (double)(NoteValueF << parameter)); 
    } }
});

napi_property_descriptor* GetParameterMapperDescriptor(napi_env env, std::string name, napi_property_descriptor* pd) {
    pd -> utf8name = NULL;
    pd -> name = Napi::String::New(env, name); 
    pd -> method = ParameterMapperWrappers.find("NoteValueF") -> second,
    pd -> getter = NULL;
    pd -> setter = NULL;
    pd -> value = NULL;
    pd -> attributes = napi_writable; // Regular object property
    pd -> data = NULL;

    return pd;
}

napi_property_descriptor* GetPropertyDescriptor(napi_env env, std::string name, napi_value value, napi_property_descriptor* pd) {
    pd -> utf8name = NULL;
    pd -> name = Napi::String::New(env, name); 
    pd -> method = NULL,
    pd -> getter = NULL;
    pd -> setter = NULL;
    pd -> value = value;
    pd -> attributes = napi_writable; // Regular object property
    pd -> data = NULL;

    return pd;
}

napi_value Init(napi_env env, napi_value exports) {
    napi_property_descriptor pd;

    STATUS = napi_define_properties(env, exports, 1, GetPropertyDescriptor(env, "message", Napi::String::New(env, "Hola desde c++!!"), &pd));
    if (STATUS != napi_ok) return NULL;

    STATUS = napi_define_properties(env, exports, 1, GetParameterMapperDescriptor(env, "parameterMapper", &pd));
    if (STATUS != napi_ok) return NULL;

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
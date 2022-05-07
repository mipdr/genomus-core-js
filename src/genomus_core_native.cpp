#include <napi.h>
#include <iostream>
#include "genomus_core_native.hpp"

using namespace Napi;

map<std::string, function<napi_value(napi_env, napi_callback_info)>> ParameterMapperWrappers({
    { "NoteValueF", [](napi_env env, napi_callback_info info) -> napi_value { return Napi::String::New(env, "Hola desde el function wrapper"); } }
});

// napi_property_descriptor* GetParameterMapperDescriptor(napi_env env, std::string name, napi_property_descriptor* pd) {

//     *pd = {
//         .utf8name = NULL,
//         .name = Napi::String::New(env, name), 

//         .method = &(ParameterMapperWrappers.find("NoteValueF") -> second),
//         .getter = NULL,
//         .setter = NULL,
//         .value = NULL,

//         .attributes = napi_default_jsproperty, // Regular object property
//         .data = NULL,
//     };

//     return pd;
// }

napi_property_descriptor* GetPropertyDescriptor(napi_env env, std::string name, napi_value value, napi_property_descriptor* pd) {
    *pd = {
        .utf8name = NULL,
        .name = Napi::String::New(env, name), 

        .method = NULL,
        .getter = NULL,
        .setter = NULL,
        .value = value,

        .attributes = napi_default_jsproperty, // Regular object property
        .data = NULL,
    };

    return pd;
}

napi_value Init(napi_env env, napi_value exports) {
    cout << "\n##################### Init function from native addon module\n\n";
    napi_status status;
    napi_property_descriptor pd;

    status = napi_define_properties(env, exports, 1, GetPropertyDescriptor(env, "message", Napi::String::New(env, "Hola desde c++!!"), &pd));
    if (status != napi_ok) return NULL;

    // status = napi_define_properties(env, exports, 1, GetParameterMapperDescriptor(env, "parameterMapper", &pd));
    // if (status != napi_ok){
    //     cout << status << endl;
    //     return NULL;
    // }

    cout << (ParameterMapperWrappers.find("NoteValueF") -> second)(env, NULL) << endl;   

    cout << "\n#####################\n\n";
    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
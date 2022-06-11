#include <napi.h>
#include <iostream>
#include <stdexcept>
#include "genomus_core_native.hpp"
#include "node_api_types.h"

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

// This object is just a workaround untill we find a way to dynamically declare callbacks at runtime
map<std::string, napi_callback> ParameterMapperWrappers({
    { "NoteValueF", [](napi_env env, napi_callback_info info) -> napi_value { 
        const double parameter = getOneFloatParameter(env, info);
        return Napi::Number::New(env, (double)(NoteValueF << parameter)); 
    }},
    { "ParamF", [](napi_env env, napi_callback_info info) -> napi_value { 
        const double parameter = getOneFloatParameter(env, info);
        return Napi::Number::New(env, (double)(ParamF << parameter)); 
    }},
    { "DurationF", [](napi_env env, napi_callback_info info) -> napi_value { 
        const double parameter = getOneFloatParameter(env, info);
        return Napi::Number::New(env, (double)(DurationF << parameter)); 
    }},
    { "MidiPitchF", [](napi_env env, napi_callback_info info) -> napi_value { 
        const double parameter = getOneFloatParameter(env, info);
        return Napi::Number::New(env, (double)(MidiPitchF << parameter)); 
    }},
    { "FrequencyF", [](napi_env env, napi_callback_info info) -> napi_value { 
        const double parameter = getOneFloatParameter(env, info);
        return Napi::Number::New(env, (double)(FrequencyF << parameter)); 
    }},
    { "ArticulationF", [](napi_env env, napi_callback_info info) -> napi_value { 
        const double parameter = getOneFloatParameter(env, info);
        return Napi::Number::New(env, (double)(ArticulationF << parameter)); 
    }},
    { "IntensityF", [](napi_env env, napi_callback_info info) -> napi_value { 
        const double parameter = getOneFloatParameter(env, info);
        return Napi::Number::New(env, (double)(IntensityF << parameter)); 
    }},
    { "GoldenintegerF", [](napi_env env, napi_callback_info info) -> napi_value { 
        const double parameter = getOneFloatParameter(env, info);
        double return_value;

        // TODO (GM-19) Generalize error handling
        try {
            return_value = GoldenintegerF << parameter;
        } catch (runtime_error& e) {
            napi_throw(env, Napi::String::New(env, e.what()));
        }
        return Napi::Number::New(env, (double)(return_value)); 
    }},
    { "QuantizedF", [](napi_env env, napi_callback_info info) -> napi_value { 
        const double parameter = getOneFloatParameter(env, info);
        return Napi::Number::New(env, (double)(QuantizedF << parameter)); 
    }},
});

void registerParameterMapper(ParameterMapper& feature, napi_env *env, napi_value* exports, napi_property_descriptor* pd) {
    napi_callback cb = ParameterMapperWrappers.find(feature.getName()) -> second;

    pd -> utf8name = NULL;
    pd -> name = Napi::String::New(*env, feature.getName()); 
    pd -> method = cb,
    pd -> getter = NULL;
    pd -> setter = NULL;
    pd -> value = NULL;
    pd -> attributes = napi_enumerable;
    pd -> data = NULL;

    STATUS = napi_define_properties(*env, *exports, 1, pd);
}

void registerGenomusFeature(GenomusFeature& feature, napi_env *env, napi_value *exports, napi_property_descriptor* pd) {
    switch(feature.getType()) {
        case parameter_mapper:
            registerParameterMapper((ParameterMapper &)feature, env, exports, pd);
            break;
        default:
            throw runtime_error("Invalid enum value");
    }
};

void test() {
    auto e = Event({ .parameters = {
        Parameter({duration, 1.0}),
        Parameter({pitch, 0.5}),
        Parameter({intensity, 0.7})
    } }, CURRENT_SPECIES);
}

napi_value Init(napi_env env, napi_value exports) {
    // test();
    napi_property_descriptor long_life_pd;

    for (auto feature_p : genomusFeatures) {
        registerGenomusFeature(*feature_p, &env, &exports, &long_life_pd);
    }

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
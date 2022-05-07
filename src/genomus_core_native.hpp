#ifndef __GENOMUS_CORE_NAPI__
#define __GENOMUS_CORE_NAPI__

#include <napi.h>
#include "genomus-core/library/genomus-core.hpp"

#ifndef napi_default_jsproperty
#define napi_default_jsproperty (napi_writable | napi_enumerable | napi_configurable)
#endif

enum PropertyDescriptorType {
    function_pd,
    int_pd,
    string_pd
};

#endif
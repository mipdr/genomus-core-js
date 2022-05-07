#ifndef __GENOMUS_CORE_NAPI__
#define __GENOMUS_CORE_NAPI__

#include <napi.h>
#include "genomus-core/library/genomus-core.hpp"

enum PropertyDescriptorType {
    function_pd,
    int_pd,
    string_pd
};

#endif
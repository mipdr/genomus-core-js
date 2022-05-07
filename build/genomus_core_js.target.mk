# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := genomus_core_js
DEFS_Debug := \
	'-DNODE_GYP_MODULE_NAME=genomus_core_js' \
	'-DUSING_UV_SHARED=1' \
	'-DUSING_V8_SHARED=1' \
	'-DV8_DEPRECATION_WARNINGS=1' \
	'-DV8_DEPRECATION_WARNINGS' \
	'-DV8_IMMINENT_DEPRECATION_WARNINGS' \
	'-D_GLIBCXX_USE_CXX11_ABI=1' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-DBUILDING_NODE_EXTENSION' \
	'-DDEBUG' \
	'-D_DEBUG' \
	'-DV8_ENABLE_CHECKS'

# Flags passed to all source files.
CFLAGS_Debug := \
	-fPIC \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-std=gnu++1y

INCS_Debug := \
	-I/home/miguel/.cache/node-gyp/16.0.0/include/node \
	-I/home/miguel/.cache/node-gyp/16.0.0/src \
	-I/home/miguel/.cache/node-gyp/16.0.0/deps/openssl/config \
	-I/home/miguel/.cache/node-gyp/16.0.0/deps/openssl/openssl/include \
	-I/home/miguel/.cache/node-gyp/16.0.0/deps/uv/include \
	-I/home/miguel/.cache/node-gyp/16.0.0/deps/zlib \
	-I/home/miguel/.cache/node-gyp/16.0.0/deps/v8/include \
	-I/home/miguel/TFG/genomus-core-js/node_modules/node-addon-api

DEFS_Release := \
	'-DNODE_GYP_MODULE_NAME=genomus_core_js' \
	'-DUSING_UV_SHARED=1' \
	'-DUSING_V8_SHARED=1' \
	'-DV8_DEPRECATION_WARNINGS=1' \
	'-DV8_DEPRECATION_WARNINGS' \
	'-DV8_IMMINENT_DEPRECATION_WARNINGS' \
	'-D_GLIBCXX_USE_CXX11_ABI=1' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-DBUILDING_NODE_EXTENSION'

# Flags passed to all source files.
CFLAGS_Release := \
	-fPIC \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-O3 \
	-fno-omit-frame-pointer

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-std=gnu++1y

INCS_Release := \
	-I/home/miguel/.cache/node-gyp/16.0.0/include/node \
	-I/home/miguel/.cache/node-gyp/16.0.0/src \
	-I/home/miguel/.cache/node-gyp/16.0.0/deps/openssl/config \
	-I/home/miguel/.cache/node-gyp/16.0.0/deps/openssl/openssl/include \
	-I/home/miguel/.cache/node-gyp/16.0.0/deps/uv/include \
	-I/home/miguel/.cache/node-gyp/16.0.0/deps/zlib \
	-I/home/miguel/.cache/node-gyp/16.0.0/deps/v8/include \
	-I/home/miguel/TFG/genomus-core-js/node_modules/node-addon-api

OBJS := \
	$(obj).target/$(TARGET)/src/genomus_napi.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# Make sure our dependencies are built before any of us.
$(OBJS): | $(builddir)/nothing.a $(obj).target/node_modules/node-addon-api/src/nothing.a

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-rdynamic \
	-m64

LDFLAGS_Release := \
	-pthread \
	-rdynamic \
	-m64

LIBS :=

$(obj).target/genomus_core_js.node: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/genomus_core_js.node: LIBS := $(LIBS)
$(obj).target/genomus_core_js.node: TOOLSET := $(TOOLSET)
$(obj).target/genomus_core_js.node: $(OBJS) $(obj).target/node_modules/node-addon-api/src/nothing.a FORCE_DO_CMD
	$(call do_cmd,solink_module)

all_deps += $(obj).target/genomus_core_js.node
# Add target alias
.PHONY: genomus_core_js
genomus_core_js: $(builddir)/genomus_core_js.node

# Copy this to the executable output path.
$(builddir)/genomus_core_js.node: TOOLSET := $(TOOLSET)
$(builddir)/genomus_core_js.node: $(obj).target/genomus_core_js.node FORCE_DO_CMD
	$(call do_cmd,copy)

all_deps += $(builddir)/genomus_core_js.node
# Short alias for building this executable.
.PHONY: genomus_core_js.node
genomus_core_js.node: $(obj).target/genomus_core_js.node $(builddir)/genomus_core_js.node

# Add executable to "all" target.
.PHONY: all
all: $(builddir)/genomus_core_js.node


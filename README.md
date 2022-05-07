# `genomus-core-js`

## _Dev Setup_

The `compile_flags.txt` is created specifically for `clangd` to correctly locate Node-API header files.

If you want to use `clangd` as your language server, please locate your **system** `node_api.h` file and add its parent directory to the `compile_flags.txt` file by substituting the <NODE_SYSTEM_HEADERS> tag with the path of the directory.
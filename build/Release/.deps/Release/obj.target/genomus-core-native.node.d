cmd_Release/obj.target/genomus-core-native.node := g++ -o Release/obj.target/genomus-core-native.node -shared -pthread -rdynamic -m64  -Wl,-soname=genomus-core-native.node -Wl,--start-group Release/obj.target/genomus-core-native/src/genomus_napi.o Release/obj.target/node_modules/node-addon-api/src/nothing.a -Wl,--end-group 

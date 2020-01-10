#include <nan.h>
#include "object_wrap.h"

void InitAll(Local<Object> exports) {
    object_wrap::Init(exports);
}

NODE_MODULE(addon, InitAll)
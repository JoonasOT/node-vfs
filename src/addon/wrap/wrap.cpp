#include <napi.h>

#include "../vfs/lib.h"

static Napi::Object Init(Napi::Env env, Napi::Object exports) {
    return createObject(env);
}

// init the cool NAPI module
NODE_API_MODULE(cool, Init)
#include <napi.h>
#include <string>
#include <vector>

static Napi::String echo(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    return Napi::String::New(env, (std::string)info[0].ToString());
}

static Napi::Object createObject(const Napi::Env& env) {
    Napi::Object obj = Napi::Object::New(env);

    obj.Set("foo", Napi::String::New(env, "bar"));
    obj.Set(
        "echo",
        Napi::Function::New(env, echo, "echo")
    );
    return obj;
}

static Napi::Object Init(Napi::Env env, Napi::Object exports) {
    return createObject(env);
}

// init the cool NAPI module
NODE_API_MODULE(cool, Init)
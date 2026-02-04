#include <napi.h>
#include <string>
#include <vector>


static Napi::Object createObject(const Napi::Env& env) {
    // Create a new instance
    Napi::Object obj = Napi::Object::New(env);

    // Assign values to properties
    obj.Set("foo", Napi::String::New(env, "bar"));

    return obj;
}

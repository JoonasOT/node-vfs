#include <napi.h>
#include <string>
#include <vector>
#include <iostream>

#include <windows.h>
#include <fileapi.h>

// TODO: investigate this madness
#include <projectedfslib.h>

static std::string createFile() {
    HANDLE handle = CreateFileA(
        "TEST2.txt",
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_TEMPORARY,
        NULL
    );

    if (handle == INVALID_HANDLE_VALUE)
    {
        return "INVALID_HANDLE_VALUE";
    }
    
    const char msg[] = "Hello World!";
    DWORD dwBytesWritten = 0;

    BOOL writeError = WriteFile(
        handle,
        msg,
        strlen(msg),
        &dwBytesWritten,
        NULL);
    
    std::cout << "Bytes written: " << dwBytesWritten << std::endl;

    if (writeError == FALSE) {
        std::cout << "Write error" << std::endl;
        CloseHandle(handle);
        return "Write error";
    }

    CloseHandle(handle);

    return "ok";
}

static Napi::String createFileWrapped(const Napi::CallbackInfo& info) {
    return Napi::String::New(info.Env(), createFile());
}

static Napi::String echo(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    return Napi::String::New(env, (std::string)info[0].ToString());
}

static Napi::Object createExportObject(const Napi::Env& env) {
    Napi::Object obj = Napi::Object::New(env);

    obj.Set("foo", Napi::String::New(env, "bar"));
    obj.Set(
        "echo",
        Napi::Function::New(env, echo, "echo")
    );
    obj.Set(
        "createFile",
        Napi::Function::New(env, createFileWrapped, "createFile")
    );
    return obj;
}

static Napi::Object Init(Napi::Env env, Napi::Object exports) {
    return createExportObject(env);
}

NODE_API_MODULE(cool, Init)
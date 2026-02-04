{
    "targets": [
        {
            "target_name": "node-vfs",
            "cflags!": [ "-fno-exceptions" ],
            "cflags_cc!": [ "-fno-exceptions", '-std=c++23', '-Wextra' ],
            "sources": [
                "./src/addon/**"
            ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
        }
    ]
}
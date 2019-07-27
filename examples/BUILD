licenses(["notice"])  # Apache 2

package(default_visibility = ["//visibility:public"])

# top-level EF placeholder

py_library(
    name = "examples",
    srcs = glob(
        [
            "*.py",
        ],
    ),
    deps = ["//jax"],
)

config_setting(
    name = "linux_x86_64",
    values = {"cpu": "k8"},
    visibility = ["//visibility:public"],
)

config_setting(
    name = "windows",
    values = {"cpu": "x64_windows"},
    visibility = ["//visibility:public"],
)

#boost_library(
#    name = "python",
#    deps = [
#        ":bind",
#        ":config",
#        ":conversion",
#        ":core",
#        ":detail",
#        ":foreach",
#        ":function",
#        ":iterator",
#        ":lexical_cast",
#        ":mpl",
#        ":numeric_conversion",
#        ":preprocessor",
#        ":smart_ptr",
#        ":static_assert",
#        ":tuple",
#        ":type_traits",
#        ":utility",
#    ],
#)

#cc_library(
#    name = "boost",
#    srcs = glob(["lib/*.so*"]),
#    hdrs = glob([
#        "include/**/*.hpp",
#        "include/**/*.h",
#    ]),
#    includes = ["include"],
#    linkstatic = 1,
#    visibility = ["//visibility:public"],
#)

cc_binary(
    name = "run_python",
    srcs = ["run_python.cpp"],
    deps = [
        "@boost",
        "@python_linux//:python36-lib",
    ],
    #    deps = select({
    #        "//:linux_x86_64": [
    #            "@python_linux//:python36-lib",
    #        ],
    #        "//:windows": [
    #            "@python_win//:python36-lib",
    #        ],
    #    }),
)

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

cc_binary(
    name = "run_python",
    srcs = ["run_python.cpp"],
)

#local_repository(
#    name = "jax",
#    path = "/home/coolivie/src/jax/jax",
#)
#
#local_repository(
#    name = "build_project",
#    path = "/home/coolivie/src/jax/build",
#)

#local_repository(
#    name = "org_tensorflow",
#    path = "tensorflow",
#)

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "io_bazel_rules_closure",
    sha256 = "e0a111000aeed2051f29fcc7a3f83be3ad8c6c93c186e64beb1ad313f0c7f9f9",
    strip_prefix = "rules_closure-cf1e44edb908e9616030cc83d085989b8e6cd6df",
    urls = [
        "http://mirror.tensorflow.org/github.com/bazelbuild/rules_closure/archive/cf1e44edb908e9616030cc83d085989b8e6cd6df.tar.gz",
        "https://github.com/bazelbuild/rules_closure/archive/cf1e44edb908e9616030cc83d085989b8e6cd6df.tar.gz",  # 2019-04-04
    ],
)

http_archive(
    name = "bazel_skylib",
    sha256 = "2ef429f5d7ce7111263289644d233707dba35e39696377ebab8b0bc701f7818e",
    urls = ["https://github.com/bazelbuild/bazel-skylib/releases/download/0.8.0/bazel-skylib.0.8.0.tar.gz"],
)  # https://github.com/bazelbuild/bazel-skylib/releases

# To update TensorFlow to a new revision,
# a) update URL and strip_prefix to the new git commit hash
# b) get the sha256 hash of the commit by running:
#    curl -L https://github.com/tensorflow/tensorflow/archive/<git hash>.tar.gz | sha256sum
#    and update the sha256 with the result.
http_archive(
    name = "org_tensorflow",
    sha256 = "5df36fdc286d4d7055866f6d946cc843feb91d4f6ac98441e71816d5e784789f",
    strip_prefix = "tensorflow-531dd124b71d1de6d75f2b5ec0b2ca08e12ead24",
    urls = [
        "https://github.com/tensorflow/tensorflow/archive/531dd124b71d1de6d75f2b5ec0b2ca08e12ead24.tar.gz",
    ],
)

# For development, one can use a local TF repository instead.
#local_repository(
#    name = "org_tensorflow",
#    path = "tensorflow",
#)

load("@org_tensorflow//tensorflow:workspace.bzl", "tf_bind", "tf_workspace")

tf_workspace(
    path_prefix = "",
    tf_repo_name = "org_tensorflow",
)

tf_bind()

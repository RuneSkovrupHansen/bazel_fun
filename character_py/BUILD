py_library(
    name = "character",
    srcs = ["character.py"],
)

py_binary(
    name = "demo_character",
    srcs = ["demo_character.py"],
    deps = [
        ":character"
    ]
)

py_test(
    name = "test_character",
    srcs = ["test_character.py"],
    deps = [
        ":character"
    ]
)
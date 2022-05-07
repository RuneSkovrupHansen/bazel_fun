cc_library(
    name = "character",
    srcs = [
        "src/character.cpp"
    ],
    hdrs = [
        "include/character/character.hpp"
    ],
    includes = [
        "include/",
    ]
)

"""Since only "include/" is listed as include, and the files are placed in include/character, the import of the .hpp must be done using the path character/characer.hpp. Including include/character would change this to only require character.hpp"""

cc_test(
    name = "test_character",
    srcs = [
        "test/test_character.cpp",
    ],
    deps = [
        ":character",
        "@com_google_googletest//:gtest_main",
    ]
)

"""The dependency @com_google_googletest//:gtest_main simply contains a main function which runs all gtests. If you want to write the main yourself, you can depend on gtest. gtest_main includes everything from gtest and a main function. 

https://github.com/google/googletest/blob/main/googletest/src/gtest_main.cc
"""

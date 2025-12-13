#!/usr/bin/bash
SHELL_FOLDER=$(dirname "$0")
BUILD_FOLDER="${SHELL_FOLDER}/../build"
(
    cd ${BUILD_FOLDER};
    make -j32 | tee Compile.log;
)
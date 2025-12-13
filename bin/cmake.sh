#!/usr/bin/bash
SHELL_FOLDER=$(dirname "$0")
BUILD_FOLDER="${SHELL_FOLDER}/../build"
(
    cd ${BUILD_FOLDER};
    rm -r *;
    cmake ..;
)
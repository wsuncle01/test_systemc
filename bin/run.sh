#!/usr/bin/bash
SHELL_FOLDER=$(dirname "$0")
BUILD_FOLDER="${SHELL_FOLDER}/../build"

(
    ${BUILD_FOLDER}/MAIN
)
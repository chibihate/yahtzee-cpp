#!/bin/bash
_ROOT_DIR=$(pwd)
alias build='cmake -S $_ROOT_DIR -B $_ROOT_DIR/build && cmake --build $_ROOT_DIR/build'
alias clean_build='rm -rf $_ROOT_DIR/build/*'
alias run='$_ROOT_DIR/build/src/yatzii'
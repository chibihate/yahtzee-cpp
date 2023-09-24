#!/bin/bash
_ROOT_DIR=$(pwd)
alias build='cmake -S $_ROOT_DIR -B $_ROOT_DIR/build && cmake --build $_ROOT_DIR/build'
alias clean_build='rm -rf $_ROOT_DIR/build/*'
alias run='$_ROOT_DIR/build/src/yatzii'
alias gtest_unittest='$_ROOT_DIR/build/test/unittest/unittest'
alias ctest_unittest='ctest --test-dir $_ROOT_DIR/build/test'
alias coverage='gcovr -r $_ROOT_DIR -f $_ROOT_DIR/src --html-nested -o $_ROOT_DIR/coverage/report.html'
alias clean_coverage='rm -rf $_ROOT_DIR/coverage/*'
#!/usr/bin/env bats

pipeable() {
    13-pattern-pipeable/build/cpp-exercise-13-demo-01
}

@test 'pipeable-demo-01' {
    run pipeable
    echo "${status}"
    echo "${output}"
    [ "${status}" -eq 0 ]
}
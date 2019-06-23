#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )" 
ROOT=$DIR/..

success=0
failure=1

cd $ROOT

for d in */ ; do
    if test -f "$d/CMakeLists.txt"; then
        echo "processing $d" && cd $d && mkdir -p build && cd build && cmake .. && make && cd ../..
        ret=$?
        if ! [ $ret == 0 ]; then
            echo "processing $d FAILED! exiting"
            exit $failure
        else
            echo "processing $d SUCCESS"
        fi
    fi
done

cd $DIR

exit $?
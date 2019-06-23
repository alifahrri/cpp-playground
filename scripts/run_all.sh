#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )" 
ROOT=$DIR/..

success=0
failure=1

cd $ROOT

for d in */ ; do
    if test -f "$d/CMakeLists.txt"; then
        echo "entering directory $d/build" && cd $d/build
        for e in $(find . -maxdepth 1 -executable -type f) ; do
            echo "processing $d/$e"
            $e
            ret=$?
            if ! [ $ret == 0 ]; then
                echo "processing $e FAILED! exiting"
                exit $failure
            else
                echo "processing $e SUCCESS"
            fi
        done
    fi
    cd $ROOT
done

cd $DIR

exit $?
#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )" 
ROOT=$DIR/..

cd $ROOT

docker build -t cpp-playground -f docker/Dockerfile .
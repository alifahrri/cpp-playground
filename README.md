# CPP-Playgound [![Build Status](https://travis-ci.org/alifahrri/cpp-playground.svg?branch=master)](https://travis-ci.org/alifahrri/cpp-playground)   
A c++ exercise on generic codes, concurrency, patterns, and idioms.   

## Quick Start  
### build docker image
from root directory, build docker images, using provided scripts :
```
$ bash docker/build.sh
```
or 
```
$ docker build -t cpp-exercise -f docker/Dockerfile .
```
### run docker image
```
$ bash docker/run.sh
```
or
```
$ docker run --rm cpp-playgound
```
or, go inside the container 
```
$ docker run -it --name cpp-playground cpp-playground bash
```
and from the container
```
# bash scripts/run_all.sh
```   
## Topics 
#### Tag Dispatch
#### Copy Elision
#### Move Semantics
#### Concurency (Thread)
#### Concurency (Async)
#### Type Erasure
#### Non-Virtual Interfaces
#### Return Type Resolver
#### Thread Pool
#### Metafunctions   

## TODO  
- update regularly
- add snippet
- complete this readme

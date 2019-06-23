# CPP-Playgound   
A c++ exercise on generic codes, concurrency, patterns, and idioms.   
### Tag Dispatch
### Copy Elision
### Move Semantics
### Concurency (Thread)
### Concurency (Async)
### Type Erasure
### Non-Virtual Interfaces
### Return Type Resolver
### Thread Pool
### Metafunctions   

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
## TODO  
- update regularly
- add snippet
- complete this readme
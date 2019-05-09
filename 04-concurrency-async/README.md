## Concurency - Async

### Results
```
./cpp-exercise-04-demo-01 
```
```
main thread id : 140540883703616
parallel sum with async policy : 
parallel_sum : 140540883703616
parallel_sum : 140540883703616
parallel_sum : 140540883703616
parallel_sum : 140540858193664
parallel_sum : 140540866586368
parallel_sum : 140540866586368
parallel_sum : 140540849800960
The sum is 10000
Computed on 3 threads
parallel sum with deferred policy : 
parallel_sum : 140540883703616
parallel_sum : 140540883703616
parallel_sum : 140540883703616
parallel_sum : 140540883703616
parallel_sum : 140540883703616
parallel_sum : 140540883703616
parallel_sum : 140540883703616
The sum is 10000
```
```
./cpp-exercise-04-demo-02
```
```
main thread id : 140134700238656
T F<T>::operator()(const T&, Args ...) [with Args = {}; T = int] : 140134683121408
T F<T>::operator()(const T&, Args ...) [with Args = {int, int}; T = int] : 140134674728704
T F<T>::operator()(const T&, Args ...) [with Args = {int}; T = int] : 140134674728704
T F<T>::operator()(const T&, Args ...) [with Args = {}; T = int] : 140134674728704
s : 3
T F<T>::operator()(const T&, Args ...) [with Args = {double}; T = int]s : 12 : 
140134666336000
T F<T>::operator()(const T&, Args ...) [with Args = {}; T = int] : 140134666336000
s : -8
T F<T>::operator()(const T&, Args ...) [with Args = {int, int, int}; T = int] : 140134700238656
T F<T>::operator()(const T&, Args ...) [with Args = {int, int}; T = int] : 140134700238656
T F<T>::operator()(const T&, Args ...) [with Args = {int}; T = int] : 140134700238656
T F<T>::operator()(const T&, Args ...) [with Args = {}; T = int] : 140134700238656
s : 25
sum : 32
```
```
./cpp-exercise-04-demo-03
```
```
main thread id : 139735526180672
operator() : 139735526180672
task_lambda:	512
f : 139735526180672
task_bind:	2048
f : 139735509063424
task_thread:	1024
```
### References
[1] https://en.cppreference.com/w/cpp/thread/async   
[2] https://en.cppreference.com/w/cpp/thread/packaged_task   
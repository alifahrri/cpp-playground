## Concurrency (Thread)

### Results
#### Condition Variable
```
./cpp-exercise-03-demo-05
```
```
thread 140699628525376 starting worker thread
thread 140699611408128 process loop, waiting for data ready signal
thread 140699628525376 signals data ready for processing
thread 140699628525376 waits for processed data
Worker thread 140699611408128 is processing data
Worker thread 140699611408128 signals data processing completed
main thread (140699628525376); data = Example data after processing
```
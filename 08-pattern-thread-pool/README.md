## Thread Pool

### Results
```
fahri@fahri-X441UV:~/dev/exercise/cpp-exercise/08-pattern-thread-pool/build$ ./cpp-exercise-05-demo-01 
```
```
main thread id : 140501053310784
main(int, char**)::<lambda()> from thread : 140501019408128; i : 2
main(int, char**)::<lambda()> from thread : 140501027800832; i : 1
main(int, char**)::<lambda()> from thread : 140501036193536; i : 0
main(int, char**)::<lambda()> from thread : 140501011015424; i : 3
main(int, char**)::<lambda()> from thread : 140501027800832; i : 5
main(int, char**)::<lambda()> from thread : 140501019408128; i : 4
main(int, char**)::<lambda()> from thread : 140501011015424; i : 6
main(int, char**)::<lambda()> from thread : 140501036193536; i : 7
0; 1; 4; 9; 16; 25; 36; 49; 

```
### References
[1] https://stackoverflow.com/questions/15252292/extend-the-life-of-threads-with-synchronization-c11   
[2] https://en.cppreference.com/w/cpp/thread/packaged_task   
[3] https://en.cppreference.com/w/cpp/thread/condition_variable   
[4] http://progsch.net/wordpress/   
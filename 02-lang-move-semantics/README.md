### results
```
$ ./cpp-exercise-00-demo-01 
```
```
String0 s1("s1") => [0x7fff59514d10] : constructor called!
String0 s2(s1) => [0x7fff59514d18] : copy constructor called!
String0 s3 = s1 => [0x7fff59514d20] : copy constructor called!
String0 s4((String0&&)s3) => [0x7fff59514d28] : move contructor called!
String0 s5(String0("s5")) => [0x7fff59514d30] : constructor called!
String0 s6(std::move(s5)) => [0x7fff59514d38] : move contructor called!
String0 s7(s1+s2) => [0x7fff59514d10] : operator + called!
[0x7fff59514d40] : constructor called!
String0 s8(std::move(s1+s2)) => [0x7fff59514d10] : operator + called!
[0x7fff59514d50] : constructor called!
[0x7fff59514d48] : move contructor called!
[0x7fff59514d50] : destructor called!
s1 : s1
s2 : s1
s3 : 
s4 : s1
s5 : 
s6 : s5
s7 : s1s1
s8 : s1s1
[0x7fff59514d48] : destructor called!
[0x7fff59514d40] : destructor called!
[0x7fff59514d38] : destructor called!
[0x7fff59514d30] : destructor called!
[0x7fff59514d28] : destructor called!
[0x7fff59514d20] : destructor called!
[0x7fff59514d18] : destructor called!
[0x7fff59514d10] : destructor called!
```
#### explainations
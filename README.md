# pl-lightning-test-cpp
Very simple C++ project testing PennyLane-Lightning

One can compile the project as follows:

```bash
$ mkdir build && cd build
$ cmake -DCMAKE_CXX_COMPILER="g++-10" ..
$ make -j4
```

Running the program will show
```bash
$ ./main
(0.707107+0I)|000>+(0.707107+0I)|100>
```

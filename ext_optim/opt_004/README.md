## Data structure alignment

### Overview
Data structure alignment is the way data is arranged and accessed in computer memoery. Data alignment means putting the data points in memory at some addresses to fix some multiple of the `word size`, in order to increase CPU handling performance. To align data, it is a need to add some extra bytes between the end or the start data structures. For example,  
```c++
// consider this structure
struct Struct1 {
    short s;
    int i;
    char c;
};
// the size is 12 bytes
// s = 2 bytes, padding 2 bytes
// i = 4 bytes,
// c = 1 byte, padding 3 bytes
```

There is a way to reduce the size of structure, re-arraning items of the structure will decrease the  bytes size.
```c++
struct Struct2 {
    int i;
    char c;
    short s;
};
// the size is 8 bytes
// i = 4 bytes
// c = 1 byte, padding 1 byte
// s = 2 bytes
```

### Run with bazel
```bash
bazel run //ext_optim/opt_004:exec
```

### Experiment
```
size of Struct1: 12
size of Struct2: 8
```

### References
- [https://leimao.github.io/](https://leimao.github.io/blog/CPP-Data-Alignment/)
- [geeksforgeeks](https://www.geeksforgeeks.org/data-structure-alignment-how-data-is-arranged-and-accessed-in-computer-memory/)
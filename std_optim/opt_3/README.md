## `variant` class template

### Short introduce
The class template `std::variant` represents a type-safe [union](https://en.cppreference.com/w/cpp/language/union).  
A union is a special class type that can hold only one of its non-static data members **at a time**.

### Why we need to use `variant`
Saving memory (if it is necessary).  

With `struct`  
```c++
struct {int a, float b};
/*
+-----+-----+
|  a  |  b  |
+-----+-----+
  100   105  (memory location)
*/
```
With `variant`
```c++
variant<int, float>
/*
+-----+-----+
|  a  |     |
|  b  |     |
+-----+-----+
  100   105  (memory location)
*/
```

### Run with bazel
```bash
bazel run //std_optim/opt_3:exec
```

### Experiment
```bash
Get int from variant: 100
Get index 0 from variant: 100
Get string from variant: Unexpected index
Get string from variant: abc
Get index 1 from variant: abc
Get index 0 from variant: Unexpected index
```

### References
- [cppreference](https://en.cppreference.com/w/cpp/utility/variant)
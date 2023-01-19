## Using `static_cast` instead of C-Style cast
### Overview
(`static_cast` or C++ style cast) and C-style cast are C++ conversion, using in converting between types.
Why `static_cast` is outweigh C-style cast:  
- C++ style casts are checked by the compiler. C style casts aren't and **can fail at runtime**.  
- `static_cast` is the same as C-style cast but it is more restrictive. Check the [code](code.cpp) for more information.
- Intentions are conveyed much better using C++ casts.

### Run with bazel
```bash
bazel run //std_optim/opt_004:exec
```

### Experiment
```bash
p = 1889
q = 7
-------------------
p = 4660
i = 18
q = 18
```

### References
- [stackoverflow](https://stackoverflow.com/questions/1609163/what-is-the-difference-between-static-cast-and-c-style-casting)
- [static_cast cppreference](https://en.cppreference.com/w/cpp/language/static_cast)
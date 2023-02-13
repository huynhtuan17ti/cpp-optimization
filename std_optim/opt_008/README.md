
## `string_view` (since C++17)

### Short introduce
Conceptually, `string_view` is only a view of the string and cannot be used to modify the actual string. When a `string_view` is created, there’s no need to copy the data (unlike when you create a copy of a string). 
Furthermore, in terms of size on the heap, `string_view` is smaller than `string`.

### Why we should use `string_view`?
- As mentioned above, `string_view` does not perform any copy operations or memory allocation, `string_view` construction does not require a dynamic allocation as well. Therefore, `string_view` can be used to avoid unnecessary copies.
- `string_view` also provides built-in operations same as `string`, so we can construct a `string_view` from `string` and apply operations without dynamic allocations. The example code is an example of applying `string_view` to upgrade `substr` operation.

### Run with bazel
```bash
bazel run //std_optim/opt_008:exec
```

### Experiment
```bash
RUN #1
Time: 5967 nanosecs (string)
Time: 166 nanosecs (string_view)
---------------
RUN #2
Time: 11028 nanosecs (string)
Time: 149 nanosecs (string_view)
---------------
RUN #3
Time: 22061 nanosecs (string)
Time: 137 nanosecs (string_view)
---------------
RUN #4
Time: 7637 nanosecs (string)
Time: 154 nanosecs (string_view)
---------------
RUN #5
Time: 12501 nanosecs (string)
Time: 151 nanosecs (string_view)
---------------
```

### References
- [cppreference](https://en.cppreference.com/w/cpp/string/basic_string_view)
- [educative.io article](https://www.educative.io/answers/what-is-the-cpp-string-view-in-cpp-17)

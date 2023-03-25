## execution poilicies (since C++17)

### Short introduce
Execution policies are a C++17 feature which allows programmers to ask for algorithms to be parallelised. There are 3 execution policies available in C++17:
- `std::execution::seq` - sequential
- `std::execution::par_unseq` - parallelise and vetorise
- `std::execution::par` - parallelise

### Note
To use `<execution>` library, on some gcc versions, you have to install `libtbb`.  
```bash
# example on linux machines
sudo apt install libtbb
```
And add `-ltbb` flag before compiling. 

### Run with bazel
```bash
bazel run //std_optim/opt_010::exec
```

### Experiment
```bash
# std::reduce is equivalent to std::accumulate but std::reduce allows to apply parallel execution policy.
[+] std::reduce
Time: 816208 nanosecs ( not parallelise )
Time: 790057 nanosecs ( parallelise and vectorise )
Time: 371727 nanosecs ( parallelise )
[+] std::sort
Time: 23041297 nanosecs ( not parallelise )
Time: 8528167 nanosecs ( parallelise and vectorise )
Time: 7590876 nanosecs ( parallelise )
```

### References
- [cppreference](https://en.cppreference.com/w/cpp/algorithm/execution_policy_tag)
- [stackoverflow - linking tbb library](https://stackoverflow.com/a/36535986)

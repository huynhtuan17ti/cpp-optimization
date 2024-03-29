## Bitset optimization

### Short introduce
Bitset is a class template represents a fixed-sequence of N bits. In some particular problems, we can use bitsetws to optimize the runtime of programs. So instance, please see a problem below:
> Give an array A with the size of N, the maximum element is not greater than 100 . Count the number of sums that can be obtained by these elements in the given array.

In native solution (not native at all), I'm using a dp solution, the time complexity is `O(N^2 * 100)`. 
However, with bitset optimization, we can reduce to `O(N^2 * 100 / 64)`.

### Run with bazel
```bash
bazel run //ext_optim/opt_006:exec
```

### Experiment
```bash
-------------------------------------------------------
Benchmark             Time             CPU   Iterations
-------------------------------------------------------
BM_normal_dp 2566331863 ns   2566302482 ns            1
BM_biset_dp   625287533 ns    625278591 ns            2
```
### References
- [cppreference](https://en.cppreference.com/w/cpp/utility/bitset)
- [codeforce blog](https://codeforces.com/blog/entry/45576)

## SIMD (Single instruction, multiple data)

### Short introduce
Single Instruction, Multiple Data (SIMD) units refer to hardware components that perform the same operation on multiple data operands concurrently.

### Run with bazel
```bash
bazel run //ext_optim/opt_005:exec
```

### Experiment
```bash
----------------------------------------------------------------
Benchmark                      Time             CPU   Iterations
----------------------------------------------------------------
BM_regular_vector_add     461053 ns       461052 ns         1517
BM_simd_vector_add        336029 ns       336026 ns         2071
```
### References
- [wikipedia](https://en.wikipedia.org/wiki/Single_instruction,_multiple_data)
- [WolfSound video instruction](https://www.youtube.com/watch?v=XiaIbmMGqdg)

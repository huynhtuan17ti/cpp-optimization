## Advantage of cache coherency

### Overview
By iterating elements or pointers contiguously in memory allocation, the running time will be speeded up.

### Run with bazel
```bash
bazel run //ext_optim/opt_003:exec
```

### Experiment
```bash
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
BM_cache_conherency           11538390 ns     11520296 ns           60
BM_without_cache_conherency   73996782 ns     73862733 ns           10
```

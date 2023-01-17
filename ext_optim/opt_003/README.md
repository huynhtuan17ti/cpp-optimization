## Advantage of cache coherency

### Overview
By iterating elements or pointers contiguously in memory allocation, the running time will be speeded up.

### Run with bazel
```bash
bazel run //ext_optim/opt_003:exec
```

### Experiment
```bash
12502814
Time: 114 nanosecs (without cache coherency)
12502814
Time: 32 nanosecs (with cache coherency)
```
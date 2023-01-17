## Explicitly disallow the use of compiler-generated functions you do not want

### Overview
Take object `HouseForSale` as an example, each object will have a respective price so you do not want this object has a copy constructor or copy assignment. However, the compiler will auto generate these operators automatically although you do not implement inside the code. This optimization will show how to handle this problem.

### Run with bazel
```bash
bazel run //ext_optim/opt_001:exec
```

### Experiment
```bash
Price of h1: 5
Price of h2: 5
# HomeForSaleV2 h2_v2(h1); ----> error here
# HomeForSaleV3 h2_v3 = h1_v3; ----> error here
```

### References
- Effective C++ 3rd Edition (page 37).
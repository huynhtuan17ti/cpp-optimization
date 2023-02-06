## SIMD (Single instruction, multiple data)

### Short introduce
Single Instruction, Multiple Data (SIMD) units refer to hardware components that perform the same operation on multiple data operands concurrently.

### Run with bazel
```bash
bazel run //ext_optim/opt_005:exec
```

### Experiment
```bash
Time: 10713053 nanosecs (regular vector adding operation)
Time: 4840055 nanosecs (SIMD vector adding operation)
```
### References
- [wikipedia](https://en.wikipedia.org/wiki/Single_instruction,_multiple_data)
- [WolfSound video instruction](https://www.youtube.com/watch?v=XiaIbmMGqdg)

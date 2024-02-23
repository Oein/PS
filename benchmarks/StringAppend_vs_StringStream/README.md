# StringAppend vs StringStream

String을 +=를 통해 추가하는것과 stream을 통해 << 하는것중 어느것이 더 빠른지 알아보기위한 benchmark.

```
----------------------------------------------------------
Benchmark                Time             CPU   Iterations
----------------------------------------------------------
BM_StringAdd          2162 ns         2144 ns       326724
BM_StringStream       6411 ns         6328 ns       110844
```

## 결과

StringStream을 사용하는것이 더 느리다. StringStream은 추가적인 메모리 할당과 해제가 발생하기 때문이다.

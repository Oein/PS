## Build

```sh
g++ --std=c++17 name.cpp -g
```

## LLDB

```sh
lldb ./a.out
```

### LLDB 시작

```sh
run
```

### LLDB 중단점 걸기

```sh
br set -l [Line number]
```

### LLDB 조건부 중단점 걸기

```sh
br set -l [Line number] -c "i == 3"
```

### LLDB 다음줄

```sh
n
```

### LLDB 다음 중단점 까지 계속 실행

```sh
continue
```

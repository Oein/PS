#include <benchmark/benchmark.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

static void BM_DIVIDE_2(benchmark::State &state)
{
    for (auto _ : state)
    {
        long long a = 1927281829283;
        long long b = a / 2;
    }
}

static void BM_SHIFT_2(benchmark::State &state)
{
    for (auto _ : state)
    {
        long long a = 1927281829283;
        long long b = a >> 1;
    }
}

static void BM_DIVIDE_N(benchmark::State &state)
{
    for (auto _ : state)
    {
        long long a = 1927281829283;
        long long b = a / 2024;
    }
}

static void BM_MOD_N(benchmark::State &state)
{
    for (auto _ : state)
    {
        long long a = 1927281829283;
        long long b = a % 2024;
    }
}

BENCHMARK(BM_DIVIDE_2);
BENCHMARK(BM_SHIFT_2);
BENCHMARK(BM_DIVIDE_N);
BENCHMARK(BM_MOD_N);
BENCHMARK_MAIN();
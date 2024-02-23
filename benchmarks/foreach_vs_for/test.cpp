#include <benchmark/benchmark.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

static void BM_FOREACH(benchmark::State &state)
{
    int a[1000] = {
        0,
    };
    for (int i = 0; i < 1000; i++)
    {
        a[i] = i;
    }

    for (auto _ : state)
    {
        int sum = 0;
        for (int i : a)
        {
            sum += i;
        }
    }
}

static void BM_FOR(benchmark::State &state)
{
    int a[1000] = {
        0,
    };
    for (int i = 0; i < 1000; i++)
    {
        a[i] = i;
    }

    for (auto _ : state)
    {
        int sum = 0;
        for (int i = 0; i < 1000; i++)
        {
            sum += a[i];
        }
    }
}

BENCHMARK(BM_FOREACH);
BENCHMARK(BM_FOR);
BENCHMARK_MAIN();
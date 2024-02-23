#include <benchmark/benchmark.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

static void BM_StringAdd(benchmark::State &state)
{
    for (auto _ : state)
    {
        string x = "";
        for (int i = 0; i < 100; i++)
            x += "world";
    }
}

static void BM_StringStream(benchmark::State &state)
{
    for (auto _ : state)
    {
        ostringstream ss;
        for (int i = 0; i < 100; i++)
            ss << "world";
        string x = ss.str();
    }
}

BENCHMARK(BM_StringAdd);
BENCHMARK(BM_StringStream);
BENCHMARK_MAIN();
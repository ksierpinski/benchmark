#include <benchmark/benchmark.h>
#include "example.cpp"

std::vector<int> x = {1, 2, 3, 4, 5, 6 ,7, 8};

static void BM_TrivialFinder(benchmark::State& state)
{
    x.resize(100000);
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(finderTrivial(x, 16));
    }
}
BENCHMARK(BM_TrivialFinder);

static void BM_UnorderedSetFinder(benchmark::State& state)
{
    x.resize(100000);
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(finderUnorderedSet(x, 16));
    }
}
BENCHMARK(BM_UnorderedSetFinder);

BENCHMARK_MAIN();

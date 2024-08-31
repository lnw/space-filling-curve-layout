#include "benchmark/benchmark.h"

#include <random>

#include "src/hilbert.h"
#include "src/morton.h"

std::random_device seed;
std::mt19937 gen(seed());
std::uniform_int_distribution<> distrib8(0, (1 << 8) - 1);
std::uniform_int_distribution<> distrib16(0, (1 << 15) - 1);

static void bm_8_0(benchmark::State& state) {
  for (auto _ : state) {
    uint16_t x = distrib8(gen);
    uint16_t y = distrib8(gen);
    benchmark::DoNotOptimize(x);
    benchmark::DoNotOptimize(y);
  }
}
static void bm_16_0(benchmark::State& state) {
  for (auto _ : state) {
    uint16_t x = distrib16(gen);
    uint16_t y = distrib16(gen);
    benchmark::DoNotOptimize(x);
    benchmark::DoNotOptimize(y);
  }
}
BENCHMARK(bm_8_0);
BENCHMARK(bm_16_0);

static void bm_hilbert8_1(benchmark::State& state) {
  for (auto _ : state) {
    uint16_t x = distrib8(gen);
    uint16_t y = distrib8(gen);
    auto res = hilbert8(x, y);
    benchmark::DoNotOptimize(res);
  }
}
static void bm_hilbert8_2(benchmark::State& state) {
  for (auto _ : state) {
    uint16_t x = distrib8(gen);
    uint16_t y = distrib8(gen);
    auto res1 = hilbert8(x, y);
    auto res2 = hilbert8(y, x);
    benchmark::DoNotOptimize(res1);
    benchmark::DoNotOptimize(res2);
  }
}
static void bm_hilbert8_4(benchmark::State& state) {
  // state.PauseTiming();
  // state.ResumeTiming();
  for (auto _ : state) {
    uint16_t x = distrib8(gen);
    uint16_t y = distrib8(gen);
    // state.ResumeTiming();
    auto res1 = hilbert8(x, y);
    auto res2 = hilbert8(y, x);
    auto res3 = hilbert8(x + 1, y + 1);
    auto res4 = hilbert8(y + 1, x + 1);
    benchmark::DoNotOptimize(res1);
    benchmark::DoNotOptimize(res2);
    benchmark::DoNotOptimize(res3);
    benchmark::DoNotOptimize(res4);
  }
}
BENCHMARK(bm_hilbert8_1);
BENCHMARK(bm_hilbert8_2);
BENCHMARK(bm_hilbert8_4);


static void bm_morton8_1(benchmark::State& state) {
  // state.PauseTiming();
  for (auto _ : state) {
    uint16_t x = distrib8(gen);
    uint16_t y = distrib8(gen);
    // state.ResumeTiming();
    auto res = morton8(x, y);
    benchmark::DoNotOptimize(res);
    // state.PauseTiming();
  }
}
static void bm_morton8_2(benchmark::State& state) {
  // state.PauseTiming();
  for (auto _ : state) {
    uint16_t x = distrib8(gen);
    uint16_t y = distrib8(gen);
    // state.ResumeTiming();
    auto res1 = morton8(x, y);
    auto res2 = morton8(y, x);
    benchmark::DoNotOptimize(res1);
    benchmark::DoNotOptimize(res2);
    // state.PauseTiming();
  }
}
static void bm_morton8_4(benchmark::State& state) {
  // state.PauseTiming();
  for (auto _ : state) {
    uint16_t x = distrib8(gen);
    uint16_t y = distrib8(gen);
    // state.ResumeTiming();
    auto res1 = morton8(x, y);
    auto res2 = morton8(y, x);
    auto res3 = morton8(x + 1, y + 1);
    auto res4 = morton8(y + 1, x + 1);
    benchmark::DoNotOptimize(res1);
    benchmark::DoNotOptimize(res2);
    benchmark::DoNotOptimize(res3);
    benchmark::DoNotOptimize(res4);
  }
}
BENCHMARK(bm_morton8_1);
BENCHMARK(bm_morton8_2);
BENCHMARK(bm_morton8_4);


static void bm_morton16_1(benchmark::State& state) {
  // state.PauseTiming();
  for (auto _ : state) {
    uint16_t x = distrib16(gen);
    uint16_t y = distrib16(gen);
    // state.ResumeTiming();
    auto res = morton16(x, y);
    benchmark::DoNotOptimize(res);
    // state.PauseTiming();
  }
}
static void bm_morton16_2(benchmark::State& state) {
  // state.PauseTiming();
  for (auto _ : state) {
    uint16_t x = distrib16(gen);
    uint16_t y = distrib16(gen);
    // state.ResumeTiming();
    auto res1 = morton16(x, y);
    auto res2 = morton16(y, x);
    benchmark::DoNotOptimize(res1);
    benchmark::DoNotOptimize(res2);
    // state.PauseTiming();
  }
}
static void bm_morton16_4(benchmark::State& state) {
  // state.PauseTiming();
  for (auto _ : state) {
    uint16_t x = distrib16(gen);
    uint16_t y = distrib16(gen);
    // state.ResumeTiming();
    auto res1 = morton16(x, y);
    auto res2 = morton16(y, x);
    auto res3 = morton16(x + 1, y + 1);
    auto res4 = morton16(y + 1, x + 1);
    benchmark::DoNotOptimize(res1);
    benchmark::DoNotOptimize(res2);
    benchmark::DoNotOptimize(res3);
    benchmark::DoNotOptimize(res4);
    // state.PauseTiming();
  }
}
BENCHMARK(bm_morton16_1);
BENCHMARK(bm_morton16_2);
BENCHMARK(bm_morton16_4);

BENCHMARK_MAIN();

#pragma once

#include <cstdint>

// borrowed from http://graphics.stanford.edu/~seander/bithacks.html

constexpr uint64_t morton8_aux(uint64_t x) noexcept {
  return (x * 0x0101010101010101ULL & 0x8040201008040201ULL) * 0x0102040810204081ULL;
}

constexpr uint16_t morton8(uint8_t x_in, uint8_t y_in) noexcept {
  uint64_t x = x_in;
  uint64_t y = y_in;
  return ((morton8_aux(x) >> 49) & 0x5555) | ((morton8_aux(y) >> 48) & 0xAAAA);
}


constexpr uint32_t morton16_aux(uint32_t x) noexcept {
  uint32_t B[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF};
  uint32_t S[] = {1, 2, 4, 8};
  x = (x | (x << S[3])) & B[3];
  x = (x | (x << S[2])) & B[2];
  x = (x | (x << S[1])) & B[1];
  x = (x | (x << S[0])) & B[0];
  return x;
}

constexpr uint32_t morton16(uint16_t x_in, uint16_t y_in) noexcept {
  uint32_t x = x_in;
  uint32_t y = y_in;
  x = morton16_aux(x);
  y = morton16_aux(y);
  return x | (y << 1);
}

template <int B>
constexpr size_t morton(size_t x, size_t y) noexcept;

template <> constexpr size_t morton<8>(size_t x, size_t y) noexcept {
  return morton8(x, y);
}
template <> constexpr size_t morton<16>(size_t x, size_t y) noexcept {
  return morton16(x, y);
}

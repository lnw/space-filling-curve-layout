#pragma once

#include <cstdint>

// following lawder-king-2000

constexpr uint16_t hilbert8(uint8_t x, uint8_t y) noexcept {
  constexpr uint16_t R[4][4] = {{0, 1, 3, 2}, {0, 3, 1, 2}, {2, 1, 3, 0}, {2, 3, 1, 0}};
  constexpr uint16_t S[4][4] = {{1, 0, 2, 0}, {0, 3, 1, 1}, {2, 2, 0, 3}, {3, 1, 3, 2}};
  uint16_t state = 0;
  uint16_t res = 0;
  uint16_t bits0 = ((y & 0x80) >> 7) | ((x & 0x80) >> 6);
  res |= R[state][bits0] << 14;
  state = S[state][bits0];
  uint16_t bits1 = ((y & 0x40) >> 6) | ((x & 0x40) >> 5);
  res |= R[state][bits1] << 12;
  state = S[state][bits1];
  uint16_t bits2 = ((y & 0x20) >> 5) | ((x & 0x20) >> 4);
  res |= R[state][bits2] << 10;
  state = S[state][bits2];
  uint16_t bits3 = ((y & 0x10) >> 4) | ((x & 0x10) >> 3);
  res |= R[state][bits3] << 8;
  state = S[state][bits3];
  uint16_t bits4 = ((y & 0x08) >> 3) | ((x & 0x08) >> 2);
  res |= R[state][bits4] << 6;
  state = S[state][bits4];
  uint16_t bits5 = ((y & 0x04) >> 2) | ((x & 0x04) >> 1);
  res |= R[state][bits5] << 4;
  state = S[state][bits5];
  uint16_t bits6 = ((y & 0x02) >> 1) | ((x & 0x02) >> 0);
  res |= R[state][bits6] << 2;
  state = S[state][bits6];
  uint16_t bits7 = ((y & 0x01) >> 0) | ((x & 0x01) << 1);
  res |= R[state][bits7] << 0;
  return res;
}

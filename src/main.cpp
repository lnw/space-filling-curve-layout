#include <iostream>

#include "src/hilbert.h"
#include "src/morton.h"

#include "src/hilbert-layout.h"
#include "src/morton-layout.h"

namespace stx = std::experimental;

int main() {

  std::array<int, 256*256> d;
  std::iota(d.begin(), d.end(), 0);

  stx::mdspan<int, stx::extents<uint64_t, 3, 3>, layout_hilbert> mh{d.data()};
  stx::mdspan<int, stx::extents<uint64_t, 3, 3>, layout_morton> mm{d.data()};
  static_assert(mh.rank()==2,"Rank is two");
  stx::mdspan<int, stx::extents<uint64_t, 3, 3>, stx::layout_left> ml{d.data()};
  stx::mdspan<int, stx::extents<uint64_t, 3, 3>, stx::layout_right> mr{d.data()};

  for (int y = 0; y < 16; y++) {
    for (int x = 0; x < 16; x++) {
      std::cout << mh[x, y] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
  for (int y = 0; y < 16; y++) {
    for (int x = 0; x < 16; x++) {
      std::cout << mm[x, y] << " ";
    }
    std::cout << std::endl;
  }

}
// based on the Kokkos / mdspan layout-left header

#pragma once

#include "mdspan/include/experimental/mdspan"

#include "src/hilbert.h"

namespace stx = std::experimental;

struct layout_hilbert {
  template <class Extents>
  class mapping;
};

template <class Extents>
requires(Extents::rank() == 2) class layout_hilbert::mapping {
public:
  using extents_type = Extents;
  using index_type = typename extents_type::index_type;
  using size_type = typename extents_type::size_type;
  using rank_type = typename extents_type::rank_type;
  using layout_type = layout_hilbert;

private:
  static_assert(stx::detail::__is_extents_v<extents_type>, "std::experimental::layout_hilbert::mapping must be instantiated with a specialization of std::experimental::extents.");

  template <class>
  friend class mapping;

public:
  constexpr mapping() noexcept = default;
  constexpr mapping(mapping const&) noexcept = default;

  constexpr mapping(extents_type const& __exts) noexcept
      : __extents(__exts) {}

  MDSPAN_TEMPLATE_REQUIRES(
      class OtherExtents,
      /* requires */ (
          _MDSPAN_TRAIT(std::is_constructible, extents_type, OtherExtents)))
  explicit(!std::is_convertible<OtherExtents, extents_type>::value) constexpr mapping(mapping<OtherExtents> const& other) noexcept
      : __extents(other.extents()) {
    /*
     * TODO: check precondition
     * other.required_span_size() is a representable value of type index_type
     */
  }

  constexpr mapping& operator=(mapping const&) noexcept = default;

  constexpr const extents_type& extents() const noexcept {
    return __extents;
  }

  constexpr index_type operator()(uint8_t x, uint8_t y) const noexcept {
    return hilbert8(x, y);
  }

  static constexpr bool is_always_unique() noexcept { return true; }
  static constexpr bool is_always_exhaustive() noexcept { return true; }
  static constexpr bool is_always_strided() noexcept { return false; }

  constexpr bool is_unique() const noexcept { return true; }
  constexpr bool is_exhaustive() const noexcept { return true; }
  constexpr bool is_strided() const noexcept { return false; }

  template <class OtherExtents>
  friend constexpr bool operator==(mapping const& lhs, mapping<OtherExtents> const& rhs) noexcept {
    return lhs.extents() == rhs.extents();
  }

  // In C++ 20 the not equal exists if equal is found
#if !(MDSPAN_HAS_CXX_20)
  template <class OtherExtents>
  friend constexpr bool operator!=(mapping const& lhs, mapping<OtherExtents> const& rhs) noexcept {
    return lhs.extents() != rhs.extents();
  }
#endif

private:
  extents_type __extents{};
};

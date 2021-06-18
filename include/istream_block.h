#pragma once

#include <sstream>
#include <string>

namespace block_iter {

template <class T, class charT = char, class traits = std::char_traits<charT>, class Distance = std::ptrdiff_t>
class istream_block_iterator : public std::iterator<std::input_iterator_tag, T, Distance, const T*, const T&> {
  using istream_iterator = std::istream_iterator<std::string::value_type>;

  std::basic_istream<charT, traits>* in_stream;
  T value;
  size_t block_size;
  istream_iterator siter;
  istream_iterator send;

public:
  using char_type = charT;
  using traits_type = traits;
  using istream_type = std::basic_istream<charT, traits>;
  istream_block_iterator() : in_stream(0), block_size(0) {}
  istream_block_iterator(istream_type& s, const int n) : in_stream(&s), block_size(n), siter(s), send() { ++*this; }
  istream_block_iterator(const istream_block_iterator<T, charT, traits, Distance>& x)
      : in_stream(x.in_stream), value(x.value), block_size(x.block_size), siter(x.siter), send(x.send) {}
  ~istream_block_iterator() = default;

  const T& operator*() const { return value; }
  const T* operator->() const { return &value; }

  bool operator==(istream_block_iterator const& other) const { return in_stream == other.in_stream; }

  istream_block_iterator<T, charT, traits, Distance>& operator++() {
    if (in_stream != 0 && siter != send) {
      T sub{};
      for (auto n = 0; siter != send && n < block_size; ++siter, ++n) {
        sub.push_back(*siter);
      }
      value = std::move(sub);
    } else {
      in_stream = 0;
    }
    return *this;
  }
  istream_block_iterator<T, charT, traits, Distance> operator++(int) {
    istream_block_iterator<T, charT, traits, Distance> tmp = *this;
    ++*this;
    return tmp;
  }
};

} // namespace block_iter

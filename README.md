# istream_block_iterator

An implementation of a 'chunked' stream iterator with configurable chunk size `n`

# Example

# given an input stream, split it into a vector of strings at most 3 in lenght
```
constexpr auto N = 3;
const auto example = "AAABBBCCC";
std::istringstream ss(example);
std::vector<std::string> blocks{};
std::copy(istream_block_iterator<std::string>(ss, N), istream_block_iterator<std::string>(),std::back_inserter(blocks));
```

`blocks` now has three entries, `"AAA"`, `"BBB"` and `"CCC"`.

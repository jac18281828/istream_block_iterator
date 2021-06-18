#include <sstream>

#include "gtest/gtest.h"

#include "istream_block.h"

using namespace std::literals::string_literals;

using namespace block_iter;

TEST(IStream, Test) {
  constexpr auto N = 3;
  const auto example = "AAABBBCCC"s;

  std::istringstream ss(example);
  std::vector<std::string> blocks{};

  std::copy(istream_block_iterator<std::string>(ss, N), istream_block_iterator<std::string>(),
            std::back_inserter(blocks));

  ASSERT_EQ(std::size(example) / N, blocks.size());
  ASSERT_EQ("AAA"s, blocks[0]);
  ASSERT_EQ("BBB"s, blocks[1]);
  ASSERT_EQ("CCC"s, blocks[2]);
}

TEST(IStream, ShortOne) {
  constexpr auto N = 3;
  const auto example = "AAABBBCC"s;

  std::istringstream ss(example);
  std::vector<std::string> blocks{};

  std::copy(istream_block_iterator<std::string>(ss, N), istream_block_iterator<std::string>(),
            std::back_inserter(blocks));

  ASSERT_EQ(std::size(example) / N + 1, blocks.size());
  ASSERT_EQ("AAA"s, blocks[0]);
  ASSERT_EQ("BBB"s, blocks[1]);
  ASSERT_EQ("CC"s, blocks[2]);
}

TEST(IStream, EmptyOne) {
  constexpr auto N = 3;
  const auto example = ""s;

  std::istringstream ss(example);
  std::vector<std::string> blocks{};

  std::copy(istream_block_iterator<std::string>(ss, N), istream_block_iterator<std::string>(),
            std::back_inserter(blocks));

  ASSERT_TRUE(blocks.empty());
}

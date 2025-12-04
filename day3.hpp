#include "day.hpp"

class Day3 : public Day {
 public:
  Day3() : Day{"input/day3.txt"} {}
  ~Day3() override = default;

  auto findJolt(const std::string& line, int length) {
    std::string jolt{};
    auto searchString = line;
    while (jolt.size() < length) {
      int pos{};
      char n{};
      for (int i{}; i <= searchString.size() - (length - jolt.size()); ++i) {
        if (searchString[i] > n) {
          n = searchString[i];
          pos = i;
        }
      }

      jolt += n;
      searchString = searchString.substr(pos + 1, searchString.size());
    }

    return std::stoull(jolt);
  }

  void run() override {
    uint64_t part1{};
    uint64_t part2{};
    for (const auto& line : lines) {
      part1 += findJolt(line, 2);
      part2 += findJolt(line, 12);
    }

    std::cout << part1 << std::endl
              << part2 << std::endl;
  }

};

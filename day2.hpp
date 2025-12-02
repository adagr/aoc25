#include "day.hpp"

class Day2 : public Day {
 public:
  Day2() : Day{"input/day2.txt"} {}
  ~Day2() override = default;

  void run() override {
    int64_t part1{}, part2{};
    auto ids = getFromLine(lines[0], ",");
    for (const auto id : ids) {
      auto ranges = getFromLine(id, "-");
      auto from = std::stoll(ranges[0]);
      auto to = std::stoll(ranges[1]);

      // Part 1
      for (auto i{from}; i <= to; ++i) {
        auto value = std::to_string(i);
        if (value.size() % 2 == 1)
          continue;

        auto left = value.substr(0, value.size() / 2);
        auto right = value.substr(value.size() / 2, value.size() / 2);
        if (left == right)
          part1 += i;
      }

      // Part 2
      for (auto i{from}; i <= to; ++i) {
        auto value = std::to_string(i);
        auto len = 1;
        while (len <= value.size() / 2) {
          if (value.size() % len != 0) {
            ++len;
            continue;
          }

          auto number = value.substr(0, len);
          auto invalid{true};
          for (int j = len; j < value.size(); j += len) {
            if (number != value.substr(j, len)) {
              invalid = false;
              break;
            }
          }

          if (invalid) {
            part2 += i;
            break;
          }

          ++len;
        }
      }
    }

    std::cout << part1 << std::endl
              << part2 << std::endl;
  }
};

#include "day.hpp"

class Day1 : public Day {
 public:
  Day1() : Day{"input/day1.txt"} {}
  ~Day1() override = default;

  void run() override {
    int part1{}, part2{};
    int dial = 50;
    bool startingZero{};
    for (const auto& line : lines) {
      int rotations = std::stoi(line.substr(1, line.size() - 1));
      dial += line[0] == 'R' ? rotations : -rotations;
      if (dial > 99 || (dial < 1))
        part2 += std::abs(dial) / 100 + (dial < 1 && !startingZero ? 1 : 0);

      dial %= 100;
      dial += 100;
      dial %= 100;
      startingZero = dial == 0;

      if (dial == 0)
        ++part1;
    }

    std::cout << part1 << std::endl
              << part2 << std::endl;
  }
};

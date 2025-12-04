#include "day.hpp"

class Day4 : public Day {
 public:
  Day4() : Day{"input/day4.txt"} {}
  ~Day4() override = default;

  auto canAccess(const std::vector<std::string>& grid, int x, int y) {
    int rollsOfPaper{};
    for (int i = std::max(x - 1, 0); i <= std::min(x + 1, static_cast<int>(grid[0].size() - 1)); ++i)
      for (int j = std::max(y - 1, 0); j <= std::min(y + 1, static_cast<int>(grid.size() - 1)); ++j)
        if (grid[j][i] == '@' && (i != x || j != y))
          ++rollsOfPaper;

    return rollsOfPaper < 4;
  }

  void run() override {
    int part1{};
    for (int y{}; y < lines.size(); ++y)
      for (int x{}; x < lines[0].size(); ++x)
        if (lines[y][x] == '@' && canAccess(lines, x, y))
          ++part1;

    int part2{};
    auto grid = lines;
    bool updated{true};
    while (updated) {
      updated = false;
      for (int y{}; y < grid.size(); ++y) {
        for (int x{}; x < grid[0].size(); ++x) {
          if (grid[y][x] == '@' && canAccess(grid, x, y)) {
            ++part2;
            updated = true;
            grid[y][x] = '.';
          }
        }
      }
    }

    std::cout << part1 << std::endl
              << part2 << std::endl;
  }

};

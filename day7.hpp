#include "day.hpp"

class Day7 : public Day {
 public:
  Day7() : Day{"input/day7.txt"} {}
  ~Day7() override = default;
  
  void run() override {
    uint64_t part1{};
    uint64_t part2{};
    bool once{true};
    for (int y{}; y < lines.size() - 1; ++y) {
      for (int x{}; x < lines[y].size(); ++x) {
        auto pos = lines[y][x];
        if (pos == 'S')
          lines[y + 1][x] = '|';
        else if (pos == '|') {
          if (lines[y + 1][x] == '^') {
            lines[y + 1][x - 1] = '|';
            lines[y + 1][x + 1] = '|';
            ++part1;
            if (once) {
              part2 = split(x - 1, y + 1) + split(x + 1, y + 1);
              once = false;
            }
          } else
            lines[y + 1][x] = '|';
        }
      }
    }

    std::cout << part1 << std::endl
              << part2 << std::endl;
  }

 private:
  std::map<std::pair<int, int>, uint64_t> results{};

  uint64_t split(int xx, int yy) {
    lines[yy][xx] = '|';
    for (int y{yy}; y < lines.size() - 1; ++y) {
      if (lines[y][xx] == '|') {
        if (lines[y + 1][xx] == '^') {
          auto coord = std::make_pair(y, xx);
          if (results.find(coord) != results.end())
            return results[coord];

          auto timelines = split(xx - 1, y + 1) + split(xx + 1, y + 1);
          results[coord] = timelines;
          return timelines;
        } else
          lines[y + 1][xx] = '|';
      }
    }

    return 1;
  }

};

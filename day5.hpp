#include "day.hpp"

class Day5 : public Day {
 public:
  Day5() : Day{"input/day5.txt"} {}
  ~Day5() override = default;

  void run() override {
    int part1{};
    bool availableIngredient{};
    std::vector<std::pair<int64_t, int64_t>> ingredientRanges{};
    for (const auto& line : lines) {
      if (line == "") {
        availableIngredient = true;
        continue;
      }

      if (!availableIngredient) {
        auto ranges = getNumbersInLine<int64_t>(line, '-');
        ingredientRanges.emplace_back(std::make_pair(ranges[0], ranges[1]));
      } else {
        auto id = stoull(line);
        for (const auto& range : ingredientRanges) {
          if (id >= range.first && id <= range.second) {
            ++part1;
            break;
          }
        }
      }
    }

    int64_t part2{};
    for (int i{}; i < ingredientRanges.size(); ++i) {
      for (int j = i + 1; j < ingredientRanges.size(); ++j) {
        if (ingredientRanges[i].first <= ingredientRanges[j].first &&
            ingredientRanges[i].second >= ingredientRanges[j].second) {
          ingredientRanges[j].first = 0;
          ingredientRanges[j].second = -1;
        } else if (ingredientRanges[i].first >= ingredientRanges[j].first &&
                   ingredientRanges[i].second <= ingredientRanges[j].second) {
          ingredientRanges[i].first = 0;
          ingredientRanges[i].second = -1;
        } else if (ingredientRanges[i].first <= ingredientRanges[j].first &&
                   ingredientRanges[i].second >= ingredientRanges[j].first) {
          ingredientRanges[i].second = ingredientRanges[j].first - 1;
        } else if (ingredientRanges[i].first >= ingredientRanges[j].first &&
                   ingredientRanges[i].first <= ingredientRanges[j].second) {
          ingredientRanges[i].first = ingredientRanges[j].second + 1;
        }
      }

      part2 += ingredientRanges[i].second - ingredientRanges[i].first + 1;
    }

    std::cout << part1 << std::endl
              << part2 << std::endl;
  }

};

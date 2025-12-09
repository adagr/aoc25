#include "day.hpp"

class Day6 : public Day {
 public:
  Day6() : Day{"input/day6.txt"} {}
  ~Day6() override = default;

  void run() override {
    int64_t part1{};
    int64_t part2{};
    std::map<int, std::vector<int64_t>> input{};
    for (int i{}; i < lines.size() - 1; ++i) {
      auto line = getNumbersInLine<int64_t>(lines[i], ' ');
      for (int j{}; j < line.size(); ++j)
        input[j].emplace_back(line[j]);
    }

    std::map<int, std::map<int, std::string>> inputPart2{};
    for (int i{}; i < lines.size() - 1; ++i) {
      std::vector<std::string> line{};
      auto s = lines[i];
      auto last = lines[lines.size() - 1];
      last = last.substr(1, last.size());
      while(s.size() > 0) {
        auto length = std::min(last.find('*'), last.find('+'));
        if (length == std::string::npos)
          length = s.size();
        else
          last = last.substr(length + 1, last.size());

        auto& insertedString = line.emplace_back(s.substr(0, length));
        std::reverse(insertedString.begin(), insertedString.end());
        s = s.substr(std::min(length + 1, s.size()), s.size());
      }

      for (int j{}; j < line.size(); ++j)
        for (int k{}; k < line[j].size(); ++k)
          if (line[j][k] != ' ')
            inputPart2[j][k].push_back(line[j][k]);
    }

    std::vector<bool> multiply{};
    for (const auto& c : lines[lines.size() - 1])
      if (c == '*')
        multiply.emplace_back(true);
      else if (c == '+')
        multiply.emplace_back(false);

    for (int i{}; i < multiply.size(); ++i) {
      int64_t sum{};
      int64_t sumPart2{};
      if (multiply[i]) {
        sum = 1;
        sumPart2 = 1;
      }

      for (const auto& number : input[i]) {
        if (multiply[i])
          sum *= number;
        else
          sum += number;
      }

      for (const auto& number : inputPart2[i]) {
        if (multiply[i])
          sumPart2 *= std::stoll(number.second);
        else
          sumPart2 += std::stoll(number.second);
      }

      part1 += sum;
      part2 += sumPart2;
    }

    std::cout << part1 << std::endl
              << part2 << std::endl;
  }

};

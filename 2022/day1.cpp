#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>

#include "../common.hpp"

int func(std::vector<std::string> lines)
{
  // lines.push_back("");
  std::vector<int> caloriesSums;
  int sum = 0;
  for (const auto &l : lines)
  {
    if (l.empty())
    {
      caloriesSums.push_back(sum);
      sum = 0;
    }
    else
    {
      sum += stringToInt(l);
    }
  }
  caloriesSums.push_back(sum);

  printVector(caloriesSums);
  return *std::max_element(caloriesSums.begin(), caloriesSums.end());
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
    return 1;
  }
  std::string input_file(argv[1]);

  auto input = readFile(input_file);

  int answer = 0;

  const auto result = func(input);

  answer = result;

  std::cout << '\n'
            << "Answer: "
            << answer << std::endl;

  return 0;
}

#include "../class/PmergeMe.hpp"

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cerr << "Error: Please provide a sequence of positive integers." << std::endl;
    return 1;
  }

  std::list<int> inputList;
  std::deque<int> inputDeque;

  for (int i = 1; i < argc; ++i)
  {
    char *endPtr;
    long num = std::strtol(argv[i], &endPtr, 10);

    if (*endPtr != '\0' || num <= 0 || num > 2147483647)
    {
      std::cerr << "Error: Invalid input. Numbers must be positive integers." << std::endl;
      return 1;
    }

    inputList.push_back(static_cast<int>(num));
    inputDeque.push_back(static_cast<int>(num));
  }

  PmergeMe sorter;
  sorter.sortAndMeasure(inputList);
  sorter.sortAndMeasureDeque(inputDeque);

  return 0;
}

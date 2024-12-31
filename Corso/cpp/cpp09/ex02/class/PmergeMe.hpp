#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <sys/time.h>
#include <deque>
#include <stdlib.h>

class PmergeMe
{
  void mergeInsertSortList(std::list<int> &data);
  void mergeInsertSortDeque(std::deque<int> &data);
  void printResults(const std::list<int> &before, const std::list<int> &after, double time);
  void printResultsDeque(const std::deque<int> &before, const std::deque<int> &after, double time);

public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  void sortAndMeasure(const std::list<int> &input);
  void sortAndMeasureDeque(const std::deque<int> &input);
};
#endif

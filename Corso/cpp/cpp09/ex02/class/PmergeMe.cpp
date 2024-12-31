#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
  (void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
  (void)other;
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::mergeInsertSortList(std::list<int> &data)
{
  if (data.size() <= 1)
    return;
  std::list<int> left, right;
  std::list<int>::iterator it = data.begin();
  for (size_t i = 0; i < data.size() / 2; ++i)
    ++it;
  left.splice(left.begin(), data, data.begin(), it);
  right.splice(right.begin(), data);
  mergeInsertSortList(left);
  mergeInsertSortList(right);
  data.clear();
  std::list<int>::iterator leftIt = left.begin();
  std::list<int>::iterator rightIt = right.begin();
  while (leftIt != left.end() && rightIt != right.end())
  {
    if (*leftIt <= *rightIt)
    {
      data.push_back(*leftIt);
      ++leftIt;
    }
    else
    {
      data.push_back(*rightIt);
      ++rightIt;
    }
  }
  while (leftIt != left.end())
  {
    data.push_back(*leftIt);
    ++leftIt;
  }
  while (rightIt != right.end())
  {
    data.push_back(*rightIt);
    ++rightIt;
  }
}

void PmergeMe::printResults(const std::list<int> &before, const std::list<int> &after, double time)
{
  std::cout << "Before: ";
  for (std::list<int>::const_iterator it = before.begin(); it != before.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "After: ";
  for (std::list<int>::const_iterator it = after.begin(); it != after.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "Time to process a range of " << before.size() << " elements with std::list: " << time << " us" << std::endl;
}

void PmergeMe::sortAndMeasure(const std::list<int> &input)
{
  std::list<int> data = input;
  struct timeval start, end;
  gettimeofday(&start, NULL);
  mergeInsertSortList(data);
  gettimeofday(&end, NULL);
  double time = (end.tv_sec - start.tv_sec) * 1000000.0;
  time += (end.tv_usec - start.tv_usec);
  printResults(input, data, time);
}

void PmergeMe::sortAndMeasureDeque(const std::deque<int> &input)
{
  std::deque<int> data = input;
  struct timeval start, end;
  gettimeofday(&start, NULL);
  mergeInsertSortDeque(data);
  gettimeofday(&end, NULL);
  double time = (end.tv_sec - start.tv_sec) * 1000000.0;
  time += (end.tv_usec - start.tv_usec);
  printResultsDeque(input, data, time);
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &data)
{
  if (data.size() <= 1)
    return;

  std::deque<int> left, right;
  size_t mid = data.size() / 2;

  // Split the deque into two parts
  for (size_t i = 0; i < mid; ++i)
    left.push_back(data[i]);
  for (size_t i = mid; i < data.size(); ++i)
    right.push_back(data[i]);

  mergeInsertSortDeque(left);
  mergeInsertSortDeque(right);

  data.clear();
  size_t leftIdx = 0, rightIdx = 0;

  // Merge the sorted deques
  while (leftIdx < left.size() && rightIdx < right.size())
  {
    if (left[leftIdx] <= right[rightIdx])
    {
      data.push_back(left[leftIdx]);
      ++leftIdx;
    }
    else
    {
      data.push_back(right[rightIdx]);
      ++rightIdx;
    }
  }

  // Add remaining elements
  while (leftIdx < left.size())
  {
    data.push_back(left[leftIdx]);
    ++leftIdx;
  }
  while (rightIdx < right.size())
  {
    data.push_back(right[rightIdx]);
    ++rightIdx;
  }
}

void PmergeMe::printResultsDeque(const std::deque<int> &before, const std::deque<int> &after, double time)
{
  std::cout << "Before: ";
  for (std::deque<int>::const_iterator it = before.begin(); it != before.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << "After: ";
  for (std::deque<int>::const_iterator it = after.begin(); it != after.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << "Time to process a range of " << before.size()
            << " elements with std::deque: " << time << " us" << std::endl;
}

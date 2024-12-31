#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
  std::map<std::string, double> database;
  std::string findClosestDate(const std::string &date) const;
  double stringToDouble(const std::string &str) const;
  bool isValidDate(const std::string &date) const;
  bool isValidValue(const double value) const;

public:
  BitcoinExchange();
  BitcoinExchange(const std::string &dbFile);
  BitcoinExchange(const BitcoinExchange &other);
  ~BitcoinExchange();

  BitcoinExchange &operator=(const BitcoinExchange &other);

  void loadDatabase(const std::string &dbFile);
  void processInput(const std::string &inputFile);
};
#endif

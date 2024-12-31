#include "./BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &dbFile)
{
  loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : database(other.database) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
  if (this != &other)
  {
    database = other.database;
  }
  return *this;
}

double BitcoinExchange::stringToDouble(const std::string &str) const
{
  std::istringstream iss(str);
  double value;
  if (!(iss >> value))
  {
    throw std::runtime_error("Invalid number format");
  }
  return value;
}

void BitcoinExchange::loadDatabase(const std::string &dbFile)
{
  std::ifstream file(dbFile.c_str());
  if (!file.is_open())
  {
    throw std::runtime_error("Error: could not open database file.");
  }

  std::string line;
  std::getline(file, line); // Skip header

  while (std::getline(file, line))
  {
    size_t comma = line.find(',');
    if (comma != std::string::npos)
    {
      std::string date = line.substr(0, comma);
      double rate = stringToDouble(line.substr(comma + 1));
      database[date] = rate;
    }
  }
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
  if (date.length() != 10)
    return false;
  if (date[4] != '-' || date[7] != '-')
    return false;

  std::string yearStr = date.substr(0, 4);
  std::string monthStr = date.substr(5, 2);
  std::string dayStr = date.substr(8, 2);

  int year = atoi(yearStr.c_str());
  int month = atoi(monthStr.c_str());
  int day = atoi(dayStr.c_str());

  if (month < 1 || month > 12)
    return false;
  if (day < 1 || day > 31)
    return false;
  if (year < 2009)
    return false;

  return true;
}

bool BitcoinExchange::isValidValue(const double value) const
{
  return value >= 0 && value <= 1000;
}

std::string BitcoinExchange::findClosestDate(const std::string &date) const
{
  std::map<std::string, double>::const_iterator it = database.upper_bound(date);
  if (it == database.begin())
  {
    return it->first;
  }
  --it;
  return it->first;
}

void BitcoinExchange::processInput(const std::string &inputFile)
{
  std::ifstream file(inputFile.c_str());
  if (!file.is_open())
  {
    throw std::runtime_error("Error: could not open file.");
  }

  std::string line;
  std::getline(file, line); // Skip header

  while (std::getline(file, line))
  {
    size_t separator = line.find(" | ");
    if (separator == std::string::npos)
    {
      std::cout << "Error: bad input => " << line << std::endl;
      continue;
    }
    std::string date = line.substr(0, separator);
    std::string valueStr = line.substr(separator + 3);
    if (!isValidDate(date))
    {
      std::cout << "Error: bad input => " << date << std::endl;
      continue;
    }
    double value;
    try
    {
      value = stringToDouble(valueStr);
    }
    catch (...)
    {
      std::cout << "Error: invalid value." << std::endl;
      continue;
    }
    if (value < 0)
    {
      std::cout << "Error: not a positive number." << std::endl;
      continue;
    }
    if (value > 1000)
    {
      std::cout << "Error: too large a number." << std::endl;
      continue;
    }
    std::string closestDate = findClosestDate(date);
    double rate = database[closestDate];
    double result = value * rate;
    std::cout << date << " => " << value << " = " << result << std::endl;
  }
}

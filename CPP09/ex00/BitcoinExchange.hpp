#ifndef BITCOINEXCHNAGE_HPP
#define BITCOINEXCHNAGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>

#define CSV "data.csv"

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        bool is_valid_date(const std::string& data);
        void processFile(const std::string& filename);
};

#endif

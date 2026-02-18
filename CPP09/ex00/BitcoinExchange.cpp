#include "BitcoinExchange.hpp"

bool BitcoinExchange::is_valid_date(const std::string& data){
    if(data.size() != 10)
        return false;
    for(size_t i = 0;i < data.size(); ++i){
        if(i == 4 || i == 7){
            if(data[i] != '-')
                return false;
        }else if(!std::isdigit(data[i])){
            return false;
        }
    }
    int year = std::stoi(data.substr(0, 4));
    int month = std::stoi(data.substr(5, 2));
    int day = std::stoi(data.substr(8, 2));
    if (year < 0|| month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    else if(month%2 == 0 &&  month < 8 && day > 30)
        return false;
    else if(month%2 == 1 && month >= 8 && day > 30)
        return false;
    else if(month == 2){
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            if(day > 29)
                return false;
        }else if(day > 28)
            return false;
    }
    return true;
}

void BitcoinExchange::processFile(const std::string& filename)
{
    std::ifstream data(CSV);
    if(!data.is_open()) {
        std::cerr << "Error: could not open csv." << std::endl;
        return;
    }
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << filename << std::endl;
        return;
    }
    std::map<std::string, float> exchangeRates;
    std::string csvLine;
    getline(data, csvLine);
    while(std::getline(data, csvLine)){
        size_t commaPos = csvLine.find(',');
        if(commaPos != std::string::npos){
            std::string date = csvLine.substr(0, commaPos);
            float rate = std::stof(csvLine.substr(commaPos + 1));
            exchangeRates[date] = rate;
        }else{
            std::cerr << "Error: invalid csv format." << std::endl;
            return;
        }       
    }
    std::string line;
    std::getline(file, line);
    while(std::getline(file, line)){
        size_t pipePos = line.find('|');
        if(pipePos == std::string::npos){
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pipePos);
        if(pipePos > 0 && date[date.size() - 1] == ' ')
            date.erase(date.size() - 1);
        if(!is_valid_date(date)){
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        std::string valueStr = line.substr(pipePos + 1);
        float value;
        try {
            value = std::stof(valueStr);
        } catch (const std::exception& e) {
            std::cerr << "Error: invalid value => " << valueStr << std::endl;
            continue;
        }
        if(value < 0){
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }else if(value > 1000){
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);
        if(it == exchangeRates.end() || it->first != date){
            if(it == exchangeRates.begin()){
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
             --it;
        }
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
    }
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {(void)src;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {(void)src; return *this;}

BitcoinExchange::~BitcoinExchange() {}


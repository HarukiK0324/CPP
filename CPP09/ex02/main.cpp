#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>

double get_time_us() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (static_cast<double>(tv.tv_sec) * 1000000.0) + static_cast<double>(tv.tv_usec);
}

int main(int argc, char** argv)
{
    
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe [numbers...]" << std::endl;
        return 1;
    }
    std::vector<int> init_vec;
    for (int i = 1; i < argc; ++i) {
        try {
            std::istringstream ss(argv[i]);
            std::string leftover;
            int num;
            if(!(ss >> num) || (ss >> leftover))
                throw std::invalid_argument("Error");
            if(num <= 0)
                throw std::invalid_argument("Error");
            init_vec.push_back(num);
        } catch (const std::exception& e) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }
    std::cout << "Before:   ";
    for (std::size_t i = 0; i < init_vec.size(); ++i)
        std::cout << init_vec[i] << " ";
    std::cout << std::endl;
    PmergeMe sorter;
    double start_vec = get_time_us();
    std::vector<std::vector<int> > vec;
    for (int i = 1; i < argc; ++i) {
        try {
            std::istringstream ss(argv[i]);
            std::string leftover;
            int num;
            if(!(ss >> num) || (ss >> leftover))
                throw std::invalid_argument("Error");
            if(num <= 0)
                throw std::invalid_argument("Error");
            vec.push_back(std::vector<int>(1, num));
        } catch (const std::exception& e) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }
    std::vector<std::vector<int> > sorted = sorter.sort(vec, vec.size());
    double end_vec = get_time_us();
    double start_deq = get_time_us();
    std::deque<std::deque<int> > deq;
    for (int i = 1; i < argc; ++i) {
        try {
            std::istringstream ss(argv[i]);
            std::string leftover;
            int num;
            if(!(ss >> num) || (ss >> leftover))
                throw std::invalid_argument("Error");
            if(num <= 0)
                throw std::invalid_argument("Error");
            deq.push_back(std::deque<int>(1, num));
        } catch (const std::exception& e) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }
    std::deque<std::deque<int> > sorted_deq = sorter.sort(deq, deq.size());
    double end_deq = get_time_us();
    std::cout << "After:    ";
    for (std::size_t i = 0; i < sorted.size(); ++i)
        std::cout << sorted[i][0] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << (end_vec - start_vec) << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << (end_deq - start_deq) << " us" << std::endl;
    return 0;
}

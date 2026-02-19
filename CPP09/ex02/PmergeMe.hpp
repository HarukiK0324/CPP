#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>
#include <deque>
#include <map>
#include <vector>

#define TK(k) ((1 << (k + 1)) - 2 * ((k%2 == 0) ? 1 : -1))/3

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        std::vector<int> vector_sort(std::vector<int> argv, size_t size);
        std::deque<int> deque_sort(std::deque<int> argv, size_t size);

        template <typename T> T sort(T& con, size_t size){
            if(size <= 1)
                return con;
            std::multimap<int, int> mp;
            T a;
            for(size_t i = 0; i < size - 1; i += 2){
                if(con[i] >= con[i + 1])
                {
                    mp.insert(std::make_pair(con[i], con[i + 1]));
                    a.push_back(con[i]);
                }   
                else
                {
                    mp.insert(std::make_pair(con[i + 1], con[i]));
                    a.push_back(con[i + 1]);
                }   
            }
            a = sort(a, a.size());
            T b;
            for(size_t i = 0; i < a.size(); ++i){
                std::multimap<int, int>::iterator it = mp.find(a[i]);
                b.push_back(it->second);
                if(it != mp.end())
                    mp.erase(it);
            }
            if(size%2 == 1)
                b.push_back(con[size - 1]);
            int k = 2,tk = std::min(2, (int)b.size() - 1);
            a.insert(a.begin(), b[0]);
            b.erase(b.begin());
            while(!b.empty())
            {
                size_t bound = std::min((1 << k) - 1, (int)a.size());
                while(tk > 0)
                {
                    this->binary_insert(a, b[tk - 1], bound);
                    b.erase(b.begin() + tk - 1);
                    tk--;
                }
                tk = std::min(TK(k), (int)b.size());
                k++;
            }
            return a;
        }
        
        template <typename T> void binary_insert(T& container, int value, size_t bound) {
            typename T::iterator it = std::lower_bound(container.begin(), container.begin() + bound, value);
            container.insert(it, value);
        }
};

#endif

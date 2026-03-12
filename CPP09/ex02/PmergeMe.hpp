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

        template <typename T> 
        T sort(T& con, std::size_t size){
            if(size <= 1)
                return con;
            T a;
            for(std::size_t i = 0; i < size - 1; i += 2){
                if(con[i][0] >= con[i + 1][0]){
                    a.push_back(con[i]);
                    a.back().insert(a.back().end(), con[i + 1].begin(), con[i + 1].end());
                }else{
                    a.push_back(con[i + 1]);
                    a.back().insert(a.back().end(), con[i].begin(), con[i].end());
                }
            }
            a = sort(a, a.size());
            size_t elements = a[0].size();
            T b;
            T new_a;
            for(std::size_t i = 0; i < a.size(); ++i){
                typename T::value_type main_part(a[i].begin(), a[i].begin() + elements/2);
                typename T::value_type pend_part(a[i].begin() + elements/2, a[i].end());
                new_a.push_back(main_part);
                b.push_back(pend_part);
            }
            a = new_a;
            if(size%2 == 1)
                b.push_back(con[size - 1]);
            int k = 2,tk = std::min(2, (int)b.size() - 1);
            a.insert(a.begin(), b[0]);
            b.erase(b.begin());
            while(!b.empty())
            {
                while(tk > 0)
                {
                    this->binary_insert(a, b[tk - 1], std::min((1 << k) - 1, (int)a.size()));
                    b.erase(b.begin() + tk - 1);
                    tk--;
                }
                tk = std::min(TK(k), (int)b.size());
                k++;
            }
            return a;
        }

        template <typename U>
        struct CompareContainer {
            bool operator()(const U& a, const U& b) const {
                return a.front() < b.front();
            }
        };
        
        template <typename T, typename U>
        void binary_insert(T& container, const U& con, std::size_t bound) {
            typename T::iterator it = std::lower_bound(container.begin(), container.begin() + bound, con, CompareContainer<U>());
            container.insert(it, con);
        }
};

#endif

#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <stdlib.h>
#include <vector>
#include <stack>
#include <map>
#include <time.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */








int main()
{
    std::cout << "################################################################\n";
    std::cout << "##########################     FT     ##########################\n";
    std::cout << "################################################################\n\n";
    int start = clock();

    ft::vector<int> ft_vector_first;
    ft::vector<int> ft_vector_second (4,100);
    ft::vector<int> ft_vector_third (ft_vector_second.begin(),ft_vector_second.end());
    ft::vector<int> ft_vector_fourth (ft_vector_third);


    ft_vector_first = ft_vector_fourth;

    ft_vector_first[1] = 200;
    ft_vector_first[2] = 300;
    ft_vector_first[3] = 400;

    std::cout << "ft_vector_first : " << *ft_vector_first.begin() << std::endl;
    std::cout << "ft_vector_first : " << *(ft_vector_first.end() - 1) << std::endl;
    std::cout << "ft_vector_first : " << *(ft_vector_first.rbegin()) << std::endl;
    std::cout << "ft_vector_first : " << *(ft_vector_first.rend() - 1) << std::endl;
    std::cout << "ft_vector_first : " << ft_vector_first.size() << std::endl;
    std::cout << "ft_vector_first : " << ft_vector_first.max_size() << std::endl;
    ft_vector_first.resize(6, 200);
    std::cout << "ft_vector_first : " << ft_vector_first.capacity() << std::endl;
    std::cout << "ft_vector_first : " << std::boolalpha << ft_vector_first.empty() << std::endl;
    ft_vector_first.reserve(8);
    std::cout << "ft_vector_first : " << ft_vector_first.capacity() << std::endl;
    std::cout << "ft_vector_first : " << ft_vector_first.at(2) << std::endl;
    std::cout << "ft_vector_first : " << ft_vector_first.front() << std::endl;
    std::cout << "ft_vector_first : " << ft_vector_first.back() << std::endl;
    ft_vector_first.assign(ft_vector_second.begin(),ft_vector_second.end());
    ft_vector_first.assign(4, 200);
    ft_vector_first.push_back(500);
    ft_vector_first.pop_back();
    ft_vector_first.insert(ft_vector_first.begin(), 300);
    ft_vector_first.insert(ft_vector_first.begin(), 4, 400);
    ft_vector_first.insert(ft_vector_first.begin(), ft_vector_second.begin(),ft_vector_second.end());
    ft_vector_first.erase(ft_vector_first.begin() + 4);
    ft_vector_first.erase(ft_vector_first.begin(), ft_vector_first.begin() + 3);
    ft_vector_first.swap(ft_vector_second);
    std::cout << "ft_vector_first : " << ft_vector_first.get_allocator().max_size() << std::endl;
    std::cout << "ft_vector_first : " << std::boolalpha << (ft_vector_first == ft_vector_second) << std::endl;
    std::cout << "ft_vector_first : " << std::boolalpha << (ft_vector_first != ft_vector_second) << std::endl;
    std::cout << "ft_vector_first : " << std::boolalpha << (ft_vector_first < ft_vector_second) << std::endl;
    std::cout << "ft_vector_first : " << std::boolalpha << (ft_vector_first <= ft_vector_second) << std::endl;
    std::cout << "ft_vector_first : " << std::boolalpha << (ft_vector_first > ft_vector_second) << std::endl;
    std::cout << "ft_vector_first : " << std::boolalpha << (ft_vector_first >= ft_vector_second) << std::endl;
    ft_vector_first.clear();
    ft_vector_second.clear();
    ft_vector_third.clear();
    ft_vector_fourth.clear();
    int end = clock();
    std::cout << BOLDGREEN << "\nExecution time (FT Vector): " << ((float)end - start)/CLOCKS_PER_SEC << " seconds"  << RESET << std::endl;
    start = clock();

    ft::vector<int> ft_stack_first (5,200);   
    ft::stack<int,ft::vector<int> > ft_stack_second (ft_stack_first);
    ft::stack<int,ft::vector<int> > ft_stack_third;
    std::cout << "ft_stack_third : " << std::boolalpha << ft_stack_third.empty() << std::endl;
    ft_stack_third = ft_stack_second;
    std::cout << "ft_stack_third : " << std::boolalpha << ft_stack_third.empty() << std::endl;
    std::cout << "ft_stack_second : " << std::boolalpha << ft_stack_second.size() << std::endl;
    std::cout << "ft_stack_second : " << std::boolalpha << ft_stack_second.top() << std::endl;
    ft_stack_second.push(50);
    std::cout << "ft_stack_second : " << std::boolalpha << ft_stack_second.top() << std::endl;
    ft_stack_second.pop();
    ft_stack_second.pop();
    std::cout << "ft_stack_second : " << std::boolalpha << ft_stack_second.top() << std::endl;
    std::cout << "ft_stack_second : " << (ft_stack_second == ft_stack_third) << std::endl;
    std::cout << "ft_stack_second : " << (ft_stack_second != ft_stack_third) << std::endl;
    std::cout << "ft_stack_second : " << (ft_stack_second < ft_stack_third) << std::endl;
    std::cout << "ft_stack_second : " << (ft_stack_second <= ft_stack_third) << std::endl;
    std::cout << "ft_stack_second : " << (ft_stack_second > ft_stack_third) << std::endl;
    std::cout << "ft_stack_second : " << (ft_stack_second >= ft_stack_third) << std::endl;


    end = clock();
    std::cout << BOLDGREEN << "\nExecution time (FT Stack): " << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << RESET << std::endl;
    start = clock();

    ft::map<char,int> ft_map_first;
    ft_map_first['a']=10;
    ft_map_first['b']=30;
    ft_map_first['c']=50;
    ft_map_first['d']=70;
    ft::map<char,int> ft_map_second (ft_map_first.begin(),ft_map_first.end());
    ft::map<char,int> ft_map_third (ft_map_second);
    ft::map<char,int> ft_map_fourth;
    ft_map_fourth = ft_map_first;
    std::cout << "ft_map_first : " <<  ft_map_first.begin()->first << "->" << ft_map_first.begin()->second << std::endl;
    std::cout << "ft_map_first : " << (--ft_map_first.end())->first << "->" << (--ft_map_first.end())->second << std::endl;
    std::cout << "ft_map_first : " << ft_map_first.rbegin()->first << "->" << ft_map_first.rbegin()->second << std::endl;
    std::cout << "ft_map_first : " << (--ft_map_first.rend())->first << "->" << (--ft_map_first.rend())->second << std::endl;
    std::cout << "ft_map_first : " << std::boolalpha << ft_map_first.empty() << std::endl;
    std::cout << "ft_map_first : " << ft_map_first.size() << std::endl;
    std::cout << "ft_map_first : " << ft_map_first.max_size() << std::endl;
    ft_map_first['d'] = 200;
    ft_map_first.insert(ft::make_pair('e', 300));
    ft_map_first.insert(++ft_map_first.begin(), ft::make_pair('f', 500));
    ft_map_second.insert(ft_map_first.begin(), ft_map_first.end());
    ft_map_second.erase(ft_map_second.begin());
    ft_map_second.erase('c');
    ft_map_second.erase(ft_map_second.begin(), ft_map_second.end());
    ft_map_first.swap(ft_map_second);
    ft_map_first.swap(ft_map_second);
    ft_map_third.clear();
    ft::map<char, int>::key_compare ft_comp = ft_map_first.key_comp();
    ft::map<char, int>::iterator ft_t1 = ft_map_first.begin();
    ft::map<char, int>::iterator ft_t2 = ++ft_map_first.begin();
    std::cout << "ft : " << ft_comp(ft_t1->first, ft_t2->first) << std::endl;
    std::cout << "" << std::endl;
    std::cout << "ft_map_first : " << ft_map_first.value_comp()(*ft_t1, *ft_t2) << std::endl;
    std::cout << "ft_map_first : " << ft_map_first.find('c')->first << "->" << ft_map_first.find('c')->second << std::endl;
    ft_map_first['i'] = 1000;
    char c;
    for (c = 'e'; c < 'j'; c++)
    {
        std::cout << c;
        if (ft_map_first.count(c) > 0)
            std::cout << " is an element of ft_map_first\n";
        else 
            std::cout << " is not an element of ft_map_first\n";
    }
    std::cout << "ft_map_first : " << ft_map_first.lower_bound('b')->first << "->" << ft_map_first.lower_bound('b')->second << std::endl;
    std::cout << "ft_map_first : " << ft_map_first.upper_bound('b')->first << "->" << ft_map_first.upper_bound('b')->second << std::endl;
    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ft_ret;
    ft_ret = ft_map_first.equal_range('b');
    std::cout << "ft_map_first : " << ft_ret.first->first << "->" << ft_ret.first->second << "    " << ft_ret.second->first << "->" << ft_ret.second->second << std::endl;
    std::cout << "ft_map_first : " << ft_map_first.get_allocator().max_size() << std::endl;

    end = clock();
    std::cout << BOLDGREEN << "\nExecution time (FT Map): " << ((float)end - start)/CLOCKS_PER_SEC << " seconds\n" << RESET << std::endl;


    std::cout << "#################################################################\n";
    std::cout << "##########################     STD     ##########################\n";
    std::cout << "#################################################################\n\n";


    start = clock();

    std::vector<int> std_vector_first;
    std::vector<int> std_vector_second (4,100);
    std::vector<int> std_vector_third (std_vector_second.begin(),std_vector_second.end());
    std::vector<int> std_vector_fourth (std_vector_third);


    std_vector_first = std_vector_fourth;

    std_vector_first[1] = 200;
    std_vector_first[2] = 300;
    std_vector_first[3] = 400;

    std::cout << "std_vector_first : " << *std_vector_first.begin() << std::endl;
    std::cout << "std_vector_first : " << *(std_vector_first.end() - 1) << std::endl;
    std::cout << "std_vector_first : " << *(std_vector_first.rbegin()) << std::endl;
    std::cout << "std_vector_first : " << *(std_vector_first.rend() - 1) << std::endl;
    std::cout << "std_vector_first : " << std_vector_first.size() << std::endl;
    std::cout << "std_vector_first : " << std_vector_first.max_size() << std::endl;
    std_vector_first.resize(6, 200);
    std::cout << "std_vector_first : " << std_vector_first.capacity() << std::endl;
    std::cout << "std_vector_first : " << std::boolalpha << std_vector_first.empty() << std::endl;
    std_vector_first.reserve(8);
    std::cout << "std_vector_first : " << std_vector_first.capacity() << std::endl;
    std::cout << "std_vector_first : " << std_vector_first.at(2) << std::endl;
    std::cout << "std_vector_first : " << std_vector_first.front() << std::endl;
    std::cout << "std_vector_first : " << std_vector_first.back() << std::endl;
    std_vector_first.assign(std_vector_second.begin(),std_vector_second.end());
    std_vector_first.assign(4, 200);
    std_vector_first.push_back(500);
    std_vector_first.pop_back();
    std_vector_first.insert(std_vector_first.begin(), 300);
    std_vector_first.insert(std_vector_first.begin(), 4, 400);
    std_vector_first.insert(std_vector_first.begin(), std_vector_second.begin(),std_vector_second.end());
    std_vector_first.erase(std_vector_first.begin() + 4);
    std_vector_first.erase(std_vector_first.begin(), std_vector_first.begin() + 3);
    std_vector_first.swap(std_vector_second);
    std::cout << "std_vector_first : " << std_vector_first.get_allocator().max_size() << std::endl;
    std::cout << "std_vector_first : " << std::boolalpha << (std_vector_first == std_vector_second) << std::endl;
    std::cout << "std_vector_first : " << std::boolalpha << (std_vector_first != std_vector_second) << std::endl;
    std::cout << "std_vector_first : " << std::boolalpha << (std_vector_first < std_vector_second) << std::endl;
    std::cout << "std_vector_first : " << std::boolalpha << (std_vector_first <= std_vector_second) << std::endl;
    std::cout << "std_vector_first : " << std::boolalpha << (std_vector_first > std_vector_second) << std::endl;
    std::cout << "std_vector_first : " << std::boolalpha << (std_vector_first >= std_vector_second) << std::endl;
    std_vector_first.clear();
    std_vector_second.clear();
    std_vector_third.clear();
    std_vector_fourth.clear();
    
    end = clock();
    std::cout << BOLDGREEN << "\nExecution time (STD Vector): " << ((float)end - start)/CLOCKS_PER_SEC << " seconds"  << RESET << std::endl;
    start = clock();

    std::vector<int> std_stack_first (5,200);   
    std::stack<int,std::vector<int> > std_stack_second (std_stack_first);
    std::stack<int,std::vector<int> > std_stack_third;
    std::cout << "std_stack_third : " << std::boolalpha << std_stack_third.empty() << std::endl;
    std_stack_third = std_stack_second;
    std::cout << "std_stack_third : " << std::boolalpha << std_stack_third.empty() << std::endl;
    std::cout << "std_stack_second : " << std::boolalpha << std_stack_second.size() << std::endl;
    std::cout << "std_stack_second : " << std::boolalpha << std_stack_second.top() << std::endl;
    std_stack_second.push(50);
    std::cout << "std_stack_second : " << std::boolalpha << std_stack_second.top() << std::endl;
    std_stack_second.pop();
    std_stack_second.pop();
    std::cout << "std_stack_second : " << std::boolalpha << std_stack_second.top() << std::endl;
    std::cout << "std_stack_second : " << (std_stack_second == std_stack_third) << std::endl;
    std::cout << "std_stack_second : " << (std_stack_second != std_stack_third) << std::endl;
    std::cout << "std_stack_second : " << (std_stack_second < std_stack_third) << std::endl;
    std::cout << "std_stack_second : " << (std_stack_second <= std_stack_third) << std::endl;
    std::cout << "std_stack_second : " << (std_stack_second > std_stack_third) << std::endl;
    std::cout << "std_stack_second : " << (std_stack_second >= std_stack_third) << std::endl;


    end = clock();
    std::cout << BOLDGREEN << "\nExecution time (STD Stack): " << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << RESET << std::endl;
    start = clock();

    std::map<char,int> std_map_first;
    std_map_first['a']=10;
    std_map_first['b']=30;
    std_map_first['c']=50;
    std_map_first['d']=70;
    std::map<char,int> std_map_second (std_map_first.begin(),std_map_first.end());
    std::map<char,int> std_map_third (std_map_second);
    std::map<char,int> std_map_fourth;
    std_map_fourth = std_map_first;
    std::cout << "std_map_first : " <<  std_map_first.begin()->first << "->" << std_map_first.begin()->second << std::endl;
    std::cout << "std_map_first : " << (--std_map_first.end())->first << "->" << (--std_map_first.end())->second << std::endl;
    std::cout << "std_map_first : " << std_map_first.rbegin()->first << "->" << std_map_first.rbegin()->second << std::endl;
    std::cout << "std_map_first : " << (--std_map_first.rend())->first << "->" << (--std_map_first.rend())->second << std::endl;
    std::cout << "std_map_first : " << std::boolalpha << std_map_first.empty() << std::endl;
    std::cout << "std_map_first : " << std_map_first.size() << std::endl;
    std::cout << "std_map_first : " << std_map_first.max_size() << std::endl;
    std_map_first['d'] = 200;
    std_map_first.insert(std::make_pair('e', 300));
    std_map_first.insert(++std_map_first.begin(), std::make_pair('f', 500));
    std_map_second.insert(std_map_first.begin(), std_map_first.end());
    std_map_second.erase(std_map_second.begin());
    std_map_second.erase('c');
    std_map_second.erase(std_map_second.begin(), std_map_second.end());
    std_map_first.swap(std_map_second);
    std_map_first.swap(std_map_second);
    std_map_third.clear();
    std::map<char, int>::key_compare std_comp = std_map_first.key_comp();
    std::map<char, int>::iterator std_t1 = std_map_first.begin();
    std::map<char, int>::iterator std_t2 = ++std_map_first.begin();
    std::cout << "std : " << std_comp(std_t1->first, std_t2->first) << std::endl;
    std::cout << "" << std::endl;
    std::cout << "std_map_first : " << std_map_first.value_comp()(*std_t1, *std_t2) << std::endl;
    std::cout << "std_map_first : " << std_map_first.find('c')->first << "->" << std_map_first.find('c')->second << std::endl;
    std_map_first['i'] = 1000;
    for (c = 'e'; c < 'j'; c++)
    {
        std::cout << c;
        if (std_map_first.count(c) > 0)
            std::cout << " is an element of std_map_first\n";
        else 
            std::cout << " is not an element of std_map_first\n";
    }
    std::cout << "std_map_first : " << std_map_first.lower_bound('b')->first << "->" << std_map_first.lower_bound('b')->second << std::endl;
    std::cout << "std_map_first : " << std_map_first.upper_bound('b')->first << "->" << std_map_first.upper_bound('b')->second << std::endl;
    std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> std_ret;
    std_ret = std_map_first.equal_range('b');
    std::cout << "std_map_first : " << std_ret.first->first << "->" << std_ret.first->second << "    " << std_ret.second->first << "->" << std_ret.second->second << std::endl;
    std::cout << "std_map_first : " << std_map_first.get_allocator().max_size() << std::endl;

    end = clock();
    std::cout << BOLDGREEN << "\nExecution time (STD Map): " << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;



    return (0);
}
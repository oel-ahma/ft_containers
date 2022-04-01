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




template <typename T>
void printVector(T vector, std::string name)
{
	typename T::iterator iter;

	iter = vector.begin();
    std::cout << name << " : ";
    std::cout << '[';
	while (iter != vector.end())
	{
		std::cout << *iter;
		if (iter + 1 != vector.end())
			std::cout << ",";
		iter++;
	}
    std::cout << ']';
	std::cout << std::endl;
}

template <class T>
void printMap(T &map, std::string name)
{
	typename T::iterator iter = map.begin();
    std::cout << name << " : ";
    std::cout << '[';
	while (iter != map.end())
	{
		std::cout << iter->first << "->" << iter->second;
        iter++;
        if (iter != map.end())
			std::cout << " , ";
	}
    std::cout << ']';
	std::cout << std::endl;
}





int main()
{
    int start = clock();

    std::cout << "\n#################################################################\n";
    std::cout << "\n##########                    VECTOR                   ##########\n";
    std::cout << "\n#################################################################\n";

    std::cout << "Constructor [Initialisation des vector]" << std::endl;
    ft::vector<int> ft_vector_first;
    std::vector<int> std_vector_first;
    ft::vector<int> ft_vector_second (4,100);
    std::vector<int> std_vector_second (4,100);
    ft::vector<int> ft_vector_third (ft_vector_second.begin(),ft_vector_second.end());
    std::vector<int> std_vector_third (std_vector_second.begin(),std_vector_second.end()); 
    ft::vector<int> ft_vector_fourth (ft_vector_third);
    std::vector<int> std_vector_fourth (std_vector_third);

    system("Color 0A");
    printVector(ft_vector_first, "ft_vector_first");
    printVector(std_vector_first, "std_vector_first");
    printVector(ft_vector_second, "ft_vector_second");
    printVector(std_vector_second, "std_vector_second");
    printVector(ft_vector_third, "ft_vector_third");
    printVector(std_vector_third, "std_vector_third");
    printVector(ft_vector_fourth, "ft_vector_fourth");
    printVector(std_vector_fourth, "std_vector_fourth");

    std::cout << "\n#################################################################\n\n";

    std::cout << "Operator= [ft_vector_first = ft_vector_fourth :]" << std::endl;
    ft_vector_first = ft_vector_fourth;
    std_vector_first = std_vector_fourth;
    printVector(ft_vector_first, "ft_vector_first");
    printVector(std_vector_first, "std_vector_first");

    std::cout << "\n#################################################################\n\n";

    std::cout << "Operator[] [Modification des trois derniers éléments]" << std::endl;
    ft_vector_first[1] = 200;
    ft_vector_first[2] = 300;
    ft_vector_first[3] = 400;
    printVector(ft_vector_first, "ft_vector_first");
    std_vector_first[1] = 200;
    std_vector_first[2] = 300;
    std_vector_first[3] = 400;
    printVector(std_vector_first, "std_vector_first");

    std::cout << "\n#################################################################\n\n";

    std::cout << "begin() [Retourne le premier element de ft_vector_first]" << std::endl;
    std::cout << "ft_vector_first : " << *ft_vector_first.begin() << std::endl;
    std::cout << "std_vector_first : " << *std_vector_first.begin() << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "end() [Retourne le dernier element de ft_vector_first]" << std::endl;
    std::cout << "ft_vector_first : " << *(ft_vector_first.end() - 1) << std::endl;
    std::cout << "std_vector_first : " << *(std_vector_first.end() - 1) << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "rbegin() [Retourne le dernier element de ft_vector_first]" << std::endl;
    std::cout << "ft_vector_first : " << *(ft_vector_first.rbegin()) << std::endl;
    std::cout << "std_vector_first : " << *(std_vector_first.rbegin()) << std::endl;


    std::cout << "\n#################################################################\n\n";

    std::cout << "rend() [Retourne le premier element de ft_vector_first]" << std::endl;
    std::cout << "ft_vector_first : " << *(ft_vector_first.rend() - 1) << std::endl;
    std::cout << "std_vector_first : " << *(std_vector_first.rend() - 1) << std::endl;
    
    std::cout << "\n#################################################################\n\n";

    std::cout << "size() [Taille de ft_vector_first]" << std::endl;
    std::cout << "ft_vector_first : " << ft_vector_first.size() << std::endl;
    std::cout << "std_vector_first : " << std_vector_first.size() << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "size_max() [Taille maximale d'un vector int]" << std::endl;
    std::cout << "ft_vector_first : " << ft_vector_first.max_size() << std::endl;
    std::cout << "std_vector_first : " << std_vector_first.max_size() << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "resize(6,200) [Ajoute des cases contenant la valeur 200 si la len est inférueur à 6]" << std::endl;
    ft_vector_first.resize(6, 200);
    printVector(ft_vector_first, "ft_vector_first");
    std_vector_first.resize(6, 200);
    printVector(std_vector_first, "std_vector_first");

    std::cout << "\n#################################################################\n\n";

    std::cout << "capacity() [Taille maximale de ft_vector_first]" << std::endl;
    std::cout << "ft_vector_first : " << ft_vector_first.capacity() << std::endl;
    std::cout << "std_vector_first : " << std_vector_first.capacity() << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "empty() [verifie si ft_vector_first est vide]" << std::endl;
    std::cout << "ft_vector_first : " << std::boolalpha << ft_vector_first.empty() << std::endl;
    std::cout << "std_vector_first : " << std::boolalpha << std_vector_first.empty() << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "reserve(8) [Agrandi la taille maximale de ft_vector_first]" << std::endl;
    ft_vector_first.reserve(8);
    std::cout << "ft_vector_first : " << ft_vector_first.capacity() << std::endl;
    std_vector_first.reserve(8);
    std::cout << "std_vector_first : " << std_vector_first.capacity() << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "at(2) [Retourne l'élément à l'indice 2 de ft_vector_first]" << std::endl;
    std::cout << "ft_vector_first : " << ft_vector_first.at(2) << std::endl;
    std::cout << "std_vector_first : " << std_vector_first.at(2) << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "front() [Retourne le premier element de ft_vector_first]" << std::endl;
    std::cout << "ft_vector_first : " << ft_vector_first.front() << std::endl;
    std::cout << "std_vector_first : " << std_vector_first.front() << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "back() [Retourne le dernier element de ft_vector_first]" << std::endl;
    std::cout << "ft_vector_first : " << ft_vector_first.back() << std::endl;
    std::cout << "std_vector_first : " << std_vector_first.back() << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "assign(ft_vector_second.begin(),ft_vector_second.end()) [Copie ft_vector_second dans ft_vector_first]" << std::endl;
    ft_vector_first.assign(ft_vector_second.begin(),ft_vector_second.end());
    printVector(ft_vector_first, "ft_vector_first");
    std_vector_first.assign(std_vector_second.begin(),std_vector_second.end());
    printVector(std_vector_first, "std_vector_first");

    std::cout << "\n#################################################################\n\n";

    std::cout << "assign(4, 200) [Copie 4 fois le nombre 200 dans ft_vector_first]" << std::endl;
    ft_vector_first.assign(4, 200);
    printVector(ft_vector_first, "ft_vector_first");
    std_vector_first.assign(4, 200);
    printVector(std_vector_first, "std_vector_first");

    std::cout << "\n#################################################################\n\n";

    std::cout << "push_back(500) [Ajoute le nombre 500 dans ft_vector_first]" << std::endl;
    ft_vector_first.push_back(500);
    printVector(ft_vector_first, "ft_vector_first");
    std_vector_first.push_back(500);
    printVector(std_vector_first, "std_vector_first");

    std::cout << "\n#################################################################\n\n";

    std::cout << "pop_back() [Enlève le dernier élément dans ft_vector_first]" << std::endl;
    ft_vector_first.pop_back();
    printVector(ft_vector_first, "ft_vector_first");
    std_vector_first.pop_back();
    printVector(std_vector_first, "std_vector_first");

    std::cout << "\n#################################################################\n\n";

    std::cout << "insert(ft_vector_first.begin(), 300) [Insère le nombre 300 au début de ft_vector_first]" << std::endl;
    ft_vector_first.insert(ft_vector_first.begin(), 300);
    printVector(ft_vector_first, "ft_vector_first");
    std_vector_first.insert(std_vector_first.begin(), 300);
    printVector(std_vector_first, "std_vector_first");

    std::cout << "\n#################################################################\n\n";

    std::cout << "insert(ft_vector_first.begin(), 4, 400) [Insère le nombre 400 quatre fois au début de ft_vector_first]" << std::endl;
    ft_vector_first.insert(ft_vector_first.begin(), 4, 400);
    printVector(ft_vector_first, "ft_vector_first");
    std_vector_first.insert(std_vector_first.begin(), 4, 400);
    printVector(std_vector_first, "std_vector_first");

    std::cout << "\n#################################################################\n\n";

    std::cout << "insert(ft_vector_first.begin(), ft_vector_second.begin(),ft_vector_second.end() [Insère ft_vector_second au début de ft_vector_first]" << std::endl;
    ft_vector_first.insert(ft_vector_first.begin(), ft_vector_second.begin(),ft_vector_second.end());
    printVector(ft_vector_first, "ft_vector_first");
    std_vector_first.insert(std_vector_first.begin(), std_vector_second.begin(),std_vector_second.end());
    printVector(std_vector_first, "std_vector_first");

    std::cout << "\n#################################################################\n\n";

    std::cout << "erase(ft_vector_first.begin() + 4) [Enleve l'élément à l'indice 4 de ft_vector_first]" << std::endl;
    ft_vector_first.erase(ft_vector_first.begin() + 4);
    printVector(ft_vector_first, "ft_vector_first");
    std_vector_first.erase(std_vector_first.begin() + 4);
    printVector(std_vector_first, "std_vector_first");

    std::cout << "\n#################################################################\n\n";

    std::cout << "erase(ft_vector_first.begin(), ft_vector_first.begin() + 3) [Enleve tout les éléments de l'indice 0 à l'indice 2 de ft_vector_first]" << std::endl;
    ft_vector_first.erase(ft_vector_first.begin(), ft_vector_first.begin() + 3);
    printVector(ft_vector_first, "ft_vector_first");
    std_vector_first.erase(std_vector_first.begin(), std_vector_first.begin() + 3);
    printVector(std_vector_first, "std_vector_first");

    std::cout << "\n#################################################################\n\n";

    std::cout << "swap(ft_vector_second) [swap ft_vector_first et ft_vector_second]" << std::endl;
    ft_vector_first.swap(ft_vector_second);
    printVector(ft_vector_first, "ft_vector_first");
    printVector(ft_vector_second, "ft_vector_second");
    std_vector_first.swap(std_vector_second);
    printVector(std_vector_first, "std_vector_first");
    printVector(std_vector_second, "std_vector_second");

    std::cout << "\n#################################################################\n\n";

    std::cout << "ft_vector_first.get_allocator() [Retourne l'allocator]" << std::endl;
    std::cout << "ft_vector_first : " << ft_vector_first.get_allocator().max_size() << std::endl;
    std::cout << "std_vector_first : " << std_vector_first.get_allocator().max_size() << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "ft_vector_first == ft_vector_second [Vérifie si ft_vector_first est égale à ft_vector_second]" << std::endl;
    std::cout << "ft_vector_first : " << std::boolalpha << (ft_vector_first == ft_vector_second) << std::endl;
    std::cout << "std_vector_first : " << std::boolalpha << (std_vector_first == std_vector_second) << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "ft_vector_first != ft_vector_second [Vérifie si ft_vector_first est différend de ft_vector_second]" << std::endl;
    std::cout << "ft_vector_first : " << std::boolalpha << (ft_vector_first != ft_vector_second) << std::endl;
    std::cout << "std_vector_first : " << std::boolalpha << (std_vector_first != std_vector_second) << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "ft_vector_first < ft_vector_second [Vérifie si ft_vector_first est inférieur à ft_vector_second]" << std::endl;
    std::cout << "ft_vector_first : " << std::boolalpha << (ft_vector_first < ft_vector_second) << std::endl;
    std::cout << "std_vector_first : " << std::boolalpha << (std_vector_first < std_vector_second) << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "ft_vector_first <= ft_vector_second [Vérifie si ft_vector_first est inférieur ou égale à ft_vector_second]" << std::endl;
    std::cout << "ft_vector_first : " << std::boolalpha << (ft_vector_first <= ft_vector_second) << std::endl;
    std::cout << "std_vector_first : " << std::boolalpha << (std_vector_first <= std_vector_second) << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "ft_vector_first > ft_vector_second [Vérifie si ft_vector_first est supérieure à ft_vector_second]" << std::endl;
    std::cout << "ft_vector_first : " << std::boolalpha << (ft_vector_first > ft_vector_second) << std::endl;
    std::cout << "std_vector_first : " << std::boolalpha << (std_vector_first > std_vector_second) << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "ft_vector_first >= ft_vector_second [Vérifie si ft_vector_first est supérieure ou égale à ft_vector_second]" << std::endl;
    std::cout << "ft_vector_first : " << std::boolalpha << (ft_vector_first >= ft_vector_second) << std::endl;
    std::cout << "std_vector_first : " << std::boolalpha << (std_vector_first >= std_vector_second) << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "clear() [Efface toutes les données du vector]" << std::endl;
    ft_vector_first.clear();
    printVector(ft_vector_first, "ft_vector_first");
    std_vector_first.clear();
    printVector(std_vector_first, "std_vector_first");
    ft_vector_second.clear();
    printVector(ft_vector_second, "ft_vector_second");
    std_vector_second.clear();
    printVector(std_vector_second, "std_vector_second");
    ft_vector_third.clear();
    printVector(ft_vector_third, "ft_vector_third");
    std_vector_third.clear();
    printVector(std_vector_third, "std_vector_third");
    ft_vector_fourth.clear();
    printVector(ft_vector_fourth, "ft_vector_fourth");
    std_vector_fourth.clear();
    printVector(std_vector_fourth, "std_vector_fourth");




    int end = clock();
    std::cout << BOLDGREEN << "\nExecution time (Vector): " << ((float)end - start)/CLOCKS_PER_SEC << " seconds"  << RESET << std::endl;

    start = clock();

    std::cout << "\n#################################################################\n";
    std::cout << "\n##########                    STACK                    ##########\n";
    std::cout << "\n#################################################################\n";

    std::cout << "Constructor  [Initialisation des stack]" << std::endl;
    ft::vector<int> ft_stack_first (5,200);   
    ft::stack<int,ft::vector<int> > ft_stack_second (ft_stack_first);
    ft::stack<int,ft::vector<int> > ft_stack_third;
    std::vector<int> std_stack_first (5,200);      
    std::stack<int,std::vector<int> > std_stack_second (std_stack_first);
    std::stack<int,std::vector<int> > std_stack_third;

    std::cout << "\n#################################################################\n\n";

    std::cout << "empty() [verifie si ft_stack_third est vide]" << std::endl;
    std::cout << "ft_stack_third : " << std::boolalpha << ft_stack_third.empty() << std::endl;
    std::cout << "std_stack_third : " << std::boolalpha << std_stack_third.empty() << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "Operator= [ft_stack_third = ft_stack_second :]" << std::endl;
    ft_stack_third = ft_stack_second;
    std_stack_third = std_stack_second;
    std::cout << "ft_stack_third : " << std::boolalpha << ft_stack_third.empty() << std::endl;
    std::cout << "std_stack_third : " << std::boolalpha << std_stack_third.empty() << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "size() [Taille de ft_stack_second]" << std::endl;
    std::cout << "ft_stack_second : " << std::boolalpha << ft_stack_second.size() << std::endl;
    std::cout << "std_stack_second : " << std_stack_second.size() << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "top() [Retourne le dernier element de ft_stack_second]" << std::endl;
    std::cout << "ft_stack_second : " << std::boolalpha << ft_stack_second.top() << std::endl;
    std::cout << "std_stack_second : " << std_stack_second.top() << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "push(50) [Ajoute le nombre 50 dans ft_stack_second]" << std::endl;
    ft_stack_second.push(50);
    std_stack_second.push(50);
    std::cout << "ft_stack_second : " << std::boolalpha << ft_stack_second.top() << std::endl;
    std::cout << "std_stack_second : " << std_stack_second.top() << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "pop() [Enlève le dernier élément dans ft_stack_second]" << std::endl;
    ft_stack_second.pop();
    ft_stack_second.pop();
    std_stack_second.pop();
    std_stack_second.pop();
    std::cout << "ft_stack_second : " << std::boolalpha << ft_stack_second.top() << std::endl;
    std::cout << "std_stack_second : " << std_stack_second.top() << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "ft_stack_second == ft_stack_third [Vérifie si ft_stack_second est égale à ft_stack_third]" << std::endl;
    std::cout << "ft_stack_second : " << (ft_stack_second == ft_stack_third) << std::endl;
    std::cout << "std_stack_second : " << (std_stack_second == std_stack_third) << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "ft_stack_second != ft_stack_third [Vérifie si ft_stack_second est différend de ft_stack_third]" << std::endl;
    std::cout << "ft_stack_second : " << (ft_stack_second != ft_stack_third) << std::endl;
    std::cout << "std_stack_second : " << (std_stack_second != std_stack_third) << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "ft_stack_second < ft_stack_third [Vérifie si ft_stack_second est inférieur à ft_stack_third]" << std::endl;
    std::cout << "ft_stack_second : " << (ft_stack_second < ft_stack_third) << std::endl;
    std::cout << "std_stack_second : " << (std_stack_second < std_stack_third) << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "ft_stack_second <= ft_stack_third [Vérifie si ft_stack_second est inférieur ou égale à ft_stack_third]" << std::endl;
    std::cout << "ft_stack_second : " << (ft_stack_second <= ft_stack_third) << std::endl;
    std::cout << "std_stack_second : " << (std_stack_second <= std_stack_third) << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "ft_stack_second > ft_stack_third [Vérifie si ft_stack_second est supérieure à ft_stack_third]" << std::endl;
    std::cout << "ft_stack_second : " << (ft_stack_second > ft_stack_third) << std::endl;
    std::cout << "std_stack_second : " << (std_stack_second > std_stack_third) << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "ft_stack_second >= ft_stack_third [Vérifie si ft_stack_second est supérieure ou égale à ft_stack_third]" << std::endl;
    std::cout << "ft_stack_second : " << (ft_stack_second >= ft_stack_third) << std::endl;
    std::cout << "std_stack_second : " << (std_stack_second >= std_stack_third) << std::endl;


    end = clock();
    std::cout << BOLDGREEN << "\nExecution time (Stack): " << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << RESET << std::endl;
    start = clock();

    std::cout << "\n#################################################################\n";
    std::cout << "\n##########                     MAP                     ##########\n";
    std::cout << "\n#################################################################\n\n";

    std::cout << "Constructor [Initialisation des vector]" << std::endl;

    ft::map<char,int> ft_map_first;
    ft_map_first['a']=10;
    ft_map_first['b']=30;
    ft_map_first['c']=50;
    ft_map_first['d']=70;
    ft::map<char,int> ft_map_second (ft_map_first.begin(),ft_map_first.end());
    ft::map<char,int> ft_map_third (ft_map_second);
    ft::map<char,int> ft_map_fourth;
    std::map<char,int> st_map_first;
    st_map_first['a']=10;
    st_map_first['b']=30;
    st_map_first['c']=50;
    st_map_first['d']=70;
    std::map<char,int> st_map_second (st_map_first.begin(),st_map_first.end());
    std::map<char,int> st_map_third (st_map_second);
    std::map<char,int> st_map_fourth;
    printMap(ft_map_first, "ft_map_first");
    printMap(st_map_first, "std_map_first");
    printMap(ft_map_second, "ft_map_second");
    printMap(st_map_second, "std_map_second");
    printMap(ft_map_third, "ft_map_third");
    printMap(st_map_third, "std_map_third");
    printMap(ft_map_fourth, "ft_map_fourth");
    printMap(st_map_fourth, "std_map_fourth");

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "Operator= [ft_map_fourth = ft_map_first :]" << std::endl;
    ft_map_fourth = ft_map_first;
    st_map_fourth = st_map_first;
    printMap(ft_map_fourth, "ft_map_fourth");
    printMap(st_map_fourth, "std_map_fourth");

    std::cout << "\n#################################################################\n\n";

    std::cout << "begin() [Retourne le premier element de ft_map_first]" << std::endl;
    std::cout << "ft_map_first : " <<  ft_map_first.begin()->first << "->" << ft_map_first.begin()->second << std::endl;
    std::cout << "std_map_first : " << st_map_first.begin()->first << "->" << st_map_first.begin()->second << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "end() [Retourne le dernier element de ft_map_first]" << std::endl;
    std::cout << "ft_map_first : " << (--ft_map_first.end())->first << "->" << (--ft_map_first.end())->second << std::endl;
    std::cout << "std_map_first : " << (--st_map_first.end())->first << "->" << (--st_map_first.end())->second << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "rbegin() [Retourne le dernier element de ft_map_first]" << std::endl;
    std::cout << "ft_map_first : " << ft_map_first.rbegin()->first << "->" << ft_map_first.rbegin()->second << std::endl;
    std::cout << "std_map_first : " << st_map_first.rbegin()->first << "->" << st_map_first.rbegin()->second << std::endl;


    std::cout << "\n#################################################################\n\n";

    std::cout << "rend() [Retourne le premier element de ft_map_first]" << std::endl;
    std::cout << "ft_map_first : " << (--ft_map_first.rend())->first << "->" << (--ft_map_first.rend())->second << std::endl;
    std::cout << "std_map_first : " << (--st_map_first.rend())->first << "->" << (--st_map_first.rend())->second << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "empty() [verifie si ft_map_first est vide]" << std::endl;
    std::cout << "ft_map_first : " << std::boolalpha << ft_map_first.empty() << std::endl;
    std::cout << "std_map_first : " << std::boolalpha << st_map_first.empty() << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "size() [Taille de ft_map_first]" << std::endl;
    std::cout << "ft_map_first : " << ft_map_first.size() << std::endl;
    std::cout << "std_map_first : " << st_map_first.size() << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "max_size() [Taille maximale d'une map char->string]" << std::endl;
    std::cout << "ft_map_first : " << ft_map_first.max_size() << std::endl;
    std::cout << "std_map_first : " << st_map_first.max_size() << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "Operator[] [Modification de l'élément 'd']" << std::endl;
    ft_map_first['d'] = 200;
    st_map_first['d'] = 200;
    printMap(ft_map_first, "ft_map_first");
    printMap(st_map_first, "std_map_first");

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "insert(ft::make_pair('e', 300)) [Insère l'élément 'e' dans ft_map_first]" << std::endl;
    ft_map_first.insert(ft::make_pair('e', 300));
    st_map_first.insert(std::make_pair('e', 300));
    printMap(ft_map_first, "ft_map_first");
    printMap(st_map_first, "std_map_first");

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "insert(++ft_map_first.begin(), ft::make_pair('f', 500)) [Insère l'élément 'f' dans ft_map_first en lui donnant une position de départ]" << std::endl;
    ft_map_first.insert(++ft_map_first.begin(), ft::make_pair('f', 500));
	st_map_first.insert(++st_map_first.begin(), std::make_pair('f', 500));
    printMap(ft_map_first, "ft_map_first");
    printMap(st_map_first, "std_map_first");

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "insert(++ft_map_first.begin(), ft_map_first.end()) [Insère tout les éléments de l'argument 1 à l'argument 2 de ft_map_first dans ft_map_second]" << std::endl;
    ft_map_second.insert(ft_map_first.begin(), ft_map_first.end());
    st_map_second.insert(st_map_first.begin(), st_map_first.end());
    printMap(ft_map_second, "ft_map_second");
    printMap(st_map_second, "std_map_second");

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "erase(ft_map_second.begin()) [Enleve le premier élément de ft_map_second]" << std::endl;
    ft_map_second.erase(ft_map_second.begin());
    st_map_second.erase(st_map_second.begin());
    printMap(ft_map_second, "ft_map_second");
    printMap(st_map_second, "std_map_second");

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "erase('c') [Enleve l'élément 'c' de ft_map_second]" << std::endl;
    ft_map_second.erase('c');
    st_map_second.erase('c');
    printMap(ft_map_second, "ft_map_second");
    printMap(st_map_second, "std_map_second");

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "erase(ft_map_second.begin(), ft_map_second.end()) [Enleve tout les élément de ft_map_second]" << std::endl;
    ft_map_second.erase(ft_map_second.begin(), ft_map_second.end());
    st_map_second.erase(st_map_second.begin(), st_map_second.end());
    printMap(ft_map_second, "ft_map_second");
    printMap(st_map_second, "std_map_second");

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "swap(ft_vector_second) [swap ft_map_first et ft_map_second]" << std::endl;
    ft_map_first.swap(ft_map_second);
    st_map_first.swap(st_map_second);
    printMap(ft_map_first, "ft_map_first");
    printMap(st_map_first, "std_map_first");
    printMap(ft_map_second, "ft_map_second");
    printMap(st_map_second, "std_map_second");
    ft_map_first.swap(ft_map_second);
    st_map_first.swap(st_map_second);

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "clear() [Efface tout les éléments ft_map_third]" << std::endl;
    ft_map_third.clear();
    st_map_third.clear();
    printMap(ft_map_third, "ft_map_third");
    printMap(st_map_third, "std_map_third");
    
    std::cout << "\n#################################################################\n\n";

    std::cout << "key_comp() [Vérifie si l'argument 1 est avant l'argument 2 en utilisant les iterators]" << std::endl;
    ft::map<char, int>::key_compare ft_comp = ft_map_first.key_comp();
    std::map<char, int>::key_compare st_comp = st_map_first.key_comp();
    ft::map<char, int>::iterator ft_t1 = ft_map_first.begin();
    ft::map<char, int>::iterator ft_t2 = ++ft_map_first.begin();
    std::map<char, int>::iterator st_t1 = st_map_first.begin();
    std::map<char, int>::iterator st_t2 = ++st_map_first.begin();
    std::cout << "ft : " << ft_comp(ft_t1->first, ft_t2->first) << std::endl;
    std::cout << "std: " << st_comp(st_t1->first, st_t2->first) << std::endl;
    
    std::cout << "" << std::endl;
    
    std::cout << "value_comp() [Vérifie si l'argument 1 est avant l'argument 2 en utilisant les key]" << std::endl;
    std::cout << "ft_map_first : " << ft_map_first.value_comp()(*ft_t1, *ft_t2) << std::endl;
    std::cout << "std_map_first : " << st_map_first.value_comp()(*st_t1, *st_t2) << std::endl;
    
    std::cout << "\n#################################################################\n\n";
    
    std::cout << "find('c') [Renvoie l'élément 'c' dans ft_map_first]" << std::endl;
    std::cout << "ft_map_first : " << ft_map_first.find('c')->first << "->" << ft_map_first.find('c')->second << std::endl;
    std::cout << "std_map_first : " << st_map_first.find('c')->first << "->" << st_map_first.find('c')->second << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "count(c) [Vérifie si c est un élément de ft_map_first]" << std::endl;
    ft_map_first['i'] = 1000;
    st_map_first['i'] = 1000;
    char c;
    for (c = 'e'; c < 'j'; c++)
    {
        std::cout << c;
        if (ft_map_first.count(c) > 0)
            std::cout << " is an element of ft_map_first\n";
        else 
            std::cout << " is not an element of ft_map_first\n";
        std::cout << c;
        if (st_map_first.count(c) > 0)
            std::cout << " is an element of std_map_first\n";
        else 
            std::cout << " is not an element of std_map_first\n";
    }

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "lower_bound('b') [Renvoie le premier élément qui n'est pas inferieur à 'b']" << std::endl;
    std::cout << "ft_map_first : " << ft_map_first.lower_bound('b')->first << "->" << ft_map_first.lower_bound('b')->second << std::endl;
    std::cout << "std_map_first : " << st_map_first.lower_bound('b')->first << "->" << st_map_first.lower_bound('b')->second << std::endl;

    std::cout << "\n#################################################################\n\n";
    
    std::cout << "upper_bound('b') [Renvoie le premier élément qui est supérieur à 'b']" << std::endl;
    std::cout << "ft_map_first : " << ft_map_first.upper_bound('b')->first << "->" << ft_map_first.upper_bound('b')->second << std::endl;
    std::cout << "std_map_first : " << st_map_first.upper_bound('b')->first << "->" << st_map_first.upper_bound('b')->second << std::endl;

    std::cout << "\n#################################################################\n\n";

    std::cout << "equal_range('b') [Renvoie une paire avec comme premier élément lower_bound() et comme second élément upper_bound()]" << std::endl;
    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ft_ret;
    std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> st_ret;
    ft_ret = ft_map_first.equal_range('b');
    st_ret = st_map_first.equal_range('b');
    std::cout << "ft_map_first : " << ft_ret.first->first << "->" << ft_ret.first->second << "    " << ft_ret.second->first << "->" << ft_ret.second->second << std::endl;
    std::cout << "std_map_first : " << st_ret.first->first << "->" << st_ret.first->second << "    " << st_ret.second->first << "->" << st_ret.second->second << std::endl;
    
    std::cout << "\n#################################################################\n\n";
    
    std::cout << "get_allocator() [Retourne l'allocator]" << std::endl;

    std::cout << "ft_map_first : " << ft_map_first.get_allocator().max_size() << std::endl;
    std::cout << "std_map_first : " << st_map_first.get_allocator().max_size() << std::endl;
    end = clock();
    
    std::cout << BOLDGREEN << "\nExecution time (Map): " << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;



    return (0);
}
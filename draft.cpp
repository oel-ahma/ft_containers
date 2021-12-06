#include <vector>
#include <iostream>
#include <string>
#include <limits>


int main()
{
    std::vector<int> arr(10, 100);

    std::cout << std::numeric_limits<size_t>::max() << "\t|\t" << arr.max_size() << "\t|\t" << arr[500] << std::endl;

    return 0;
}
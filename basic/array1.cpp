#include <string>
#include <iterator>
#include <iostream>
#include <array>
int main()
{
    int const x = 10;
    std::array a{1, 2, 3, 5, x}; // OK, creates std::array<int, 5>
 
//  std::array b{1, 2u}; // Error, all arguments must have same type


    for(const auto& s: a)
        std::cout << s << ' ' << '\n';

    for(int n : a)
        std::cout << n << '\n';

}

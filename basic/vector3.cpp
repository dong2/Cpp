#include <iostream>
#include <vector>
struct obj
{
   obj(int, double) {}
};

int main()
{
   std::vector<obj> v;
   v.emplace_back(1, 3.14); // obj in created in place in the vector

    for(const auto& n: v)
        std::cout << n << std::endl;
}

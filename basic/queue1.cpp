#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

int main() {
   std::vector<int> v = {1,2,3,4};
   std::queue s{v};    // guide #1 deduces std::queue<int, vector<int>>
   s.push(666);
   std::cout << s.front() << '\n';
   std::cout << s.back() << '\n';
}

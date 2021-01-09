#include <iostream>
#include <vector>
 
int main()
{
    // Create a vector containing integers
    std::vector<int> v = {7, 5, 16, 8};
 
    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);


   for(int i = 0; i < 5; i++) {
      std::cout << v[i] << std::endl;
   }

   std::vector<int>::iterator n = v.begin();
   while( n != v.end()) {
      std::cout << *n << std::endl;
      n++;
   }
 
    // Iterate and print values of vector
    for(int n : v) {
        std::cout << n << std::endl;
    }

    for(const auto& n: v)
        std::cout << n << std::endl;

}

#include <iostream>
#include <iterator>
#include <deque>
#include <vector>
int main() {
   std::vector<int> v = {1, 2, 3, 4};
 
   // uses explicit deduction guide to deduce std::deque<int>
   std::deque x(v.begin(), v.end()); 

    x.push_front(13);
    x.push_back(25);

    for(int n : x)
    	std::cout << n << '\n';
 
   // deduces std::deque<std::vector<int>::iterator>
   // first phase of overload resolution for list-initialization selects the candidate
   // synthesized from the initializer-list constructor; second phase is not performed and
   // deduction guide has no effect

   std::deque y{v.begin(), v.end()}; 

    //for(int n : y)
    //	std::cout << n << '\n';


}

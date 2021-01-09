#include <iostream>  
using namespace std;  
  
template < typename T >  
class stack_  
{  
    T * arr;  
    int sz; // size  
    int num_of_elements;  
public:  
     stack_(int s)  
     {  
         arr = new T[s];  
         sz=s;  
         num_of_elements = 0; // zero elements at start  
     }  
  
     void push(T x)  
     {  
         if(num_of_elements == sz)  
         {  
             cout << "Stack Full : Can't be inserted\n";  
             return;  
         }  
  
         arr[num_of_elements] = x;  
         num_of_elements++;  
     }  
     T pop()  
     {  
         if(num_of_elements == 0)  
         {  
             cout << "Stack Empty : Can't be popped\n";  
             return -1;  
         }  
         T value = arr[num_of_elements-1];  
         num_of_elements--;  
         return value;  
     }  
};  
int main()  
{  
   // Sample use of stack template class  
   stack_<int> s(5);  
   s.push(1);  
   s.push(2);  
   s.push(3);  
   s.push(4);  
   s.push(5);  
   int v = s.pop();  
   cout << v << "\n";  
  
  
    return 0;  
}

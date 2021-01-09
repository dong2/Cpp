#include <iostream>  
using namespace std;  
  
template < typename T, typename U>  
void sum(T a[],int n,U b[],int m)  
{  
    // two different types of array can be passed  
    T sum_type1 = 0;  
    int i;  
    for(i=0;i<n;i++)  
        sum_type1 += a[i];  
  
    cout << "Sum of Array of Type 1 : " << sum_type1 << "\n";  
  
    U sum_type2 =0;  
    for(i=0;i<m;i++)  
        sum_type2 += b[i];  
    cout << "Sum of Array of Type 2 : " << sum_type2 << "\n";  
  
}  
  
  
int main()  
{  
   // Sample use of template function with two data types  
  
    int a[3] = {1,2,3};  
    float b[3] = {3.6,5.1,4.5};  
  
    sum<int,float>(a,3,b,3);  
  
  
    return 0;  
}

const int func() {
    return 10;
}
main(){
  int arr[func()];
}
//error : 函数调用在常量表达式中必须具有常量值


constexpr func() {
    return 10;
}
main(){
  int arr[func()];
}
//编译通过


constexpr int func(const int n){
  return 10+n;
}
main(){
 const  int i = cin.get();
 cout<<func(i);
}
//编译通过


//https://www.jianshu.com/p/34a2a79ea947

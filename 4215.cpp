#include <iostream>
using namespace std;

int feynman(int n){
  int sum=0;
  for (int i=n;i>0;i--){
    sum+=i*i;
  }
  return sum;
}

int main(){
  int input;
  while(cin>>input){
    if (input==0)break;
    cout<<feynman(input)<<endl;
  }
  return 0;
}

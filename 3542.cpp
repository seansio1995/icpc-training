#include <iostream>

using namespace std;

bool checker(int n){
  if (n==1) return false;

  if (n%10!=3 && n%10!=9 && n%10!=7 && n%10!=1) return false;

  for (int i=2;n!=1;i++){
    if (n%i==0){
      if (i%10!=3) return false;
      while (n%i==0){
        n/=i;
      }
    }
  }
  return true;
}


int main(){
  int input;
  while (cin>>input){
    if (input==-1) break;
    if (checker(input)){
      cout<<input<<" "<<"YES"<<endl;
    }
    else{
      cout<<input<<" "<<"NO"<<endl;
    }
  }
  return 0;
}

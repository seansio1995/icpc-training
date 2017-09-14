#include <cstdio>
#include <string>
#include <stack>
#include <iostream>
using namespace std;



int dToB(int num, int base){
  string res="";
  stack<string> mystack;
  int rem;
  while (num > 0){
    rem=num%base;
    mystack.push(to_string(rem));
    num/=base;
  }
  while(! mystack.empty()){

    res=res+mystack.top();
    mystack.pop();
  }
  return atoi(res.c_str());
}


int bToD(int num, int base){
  string num_str=to_string(num);
  int res=(int) num_str[0]-48;
  int i=1;
  while (i<num_str.length()){
    int tmp=(int) num_str[i]-48;
    res=res*base+tmp;
    i++;
  }
  return res;
}


int moduSum(int num1, int num2, int base){
  int digit1;
  int digit2;
  int rem;
  stack<string> mystack;
  while (num1>0 || num2 >0){
    digit1=num1%10;
    digit2=num2%10;
    num1/=10;
    num2/=10;
    int rem=(digit1+digit2)%base;
    mystack.push(to_string(rem));
  }
  string res="";
  while(!mystack.empty()){
    res=res+mystack.top();
    mystack.pop();
  }
  return atoi(res.c_str());
}



int main(){
  //cout<<bToD(11120,3);
//cout<<moduSum(11120,121220,3)<<endl;
  int num;
  cin>>num;
  int index;
  int base;
  int num1;
  int num2;
  int convert1;
  int convert2;
  int modSum;
  int result;
  for(int i=0;i<num;i++){
    cin>>index;
    cin>>base;
    cin>>num1;
    cin>>num2;
    convert1=dToB(num1,base);
    convert2=dToB(num2,base);
    modSum=moduSum(convert1,convert2,base);
    result=bToD(modSum,base);
    cout<<index<<" "<<result<<endl;
  }
  return 0;
}

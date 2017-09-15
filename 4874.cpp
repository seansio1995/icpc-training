#include <cstdio>
#include <string>
#include <stack>
#include <iostream>
using namespace std;



stack<string> dToB(int num, int base){

  stack<string> mystack;
  if (num==0){
    mystack.push("0");
  }
  int rem;
  while (num > 0){
    rem=num%base;
    mystack.push(to_string(rem));
    num/=base;
  }
  // while(! mystack.empty()){
  //
  //   res=res+mystack.top();
  //   mystack.pop();
  // }
  return mystack;
}


int bToD(stack<string> num, int base){

  int res=atoi((num.top()).c_str());
  num.pop();
  while (!num.empty()){
    int tmp=atoi((num.top()).c_str());
    res=res*base+tmp;
    num.pop();
  }
  return res;
}


stack<string> moduSum(stack<string> input1, stack<string> input2, int base){
  int digit1;
  int digit2;
  int rem;
  stack<string> num1;
  stack<string> num2;

  while (!input1.empty()){
    num1.push(input1.top());
    input1.pop();
  }
  while (!input2.empty()){
    num2.push(input2.top());
    input2.pop();
  }
  stack<string> mystack;
  while (!num1.empty() || !num2.empty()){
    digit1=num1.empty()? 0:atoi(num1.top().c_str());
    digit2=num2.empty()? 0:atoi(num2.top().c_str());
    if (!num1.empty()){
    num1.pop();
  }
    if (!num2.empty()){
    num2.pop();
  }
    int rem=(digit1+digit2)%base;
    mystack.push(to_string(rem));
  }

  return mystack;
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
  stack<string> convert1;
  stack<string> convert2;
  stack<string> modSum;
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

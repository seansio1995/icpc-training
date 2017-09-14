#include <iostream>
#include <string>
using namespace std;

int result[8]={0};
int main()
{
  int num_lines;
  int index;
  int penny;
  cin>>num_lines;

  for (int i=0;i<num_lines;i++){
    cin>>index;
    string str;
    cin>>str;

    for (int j=0;j<8;j++){
      result[j]=0;

    }
    for (int k=0;k<38;k++){
      penny=(str[k]=='H'?4:0)+
      (str[k+1]=='H'?2:0)+
      (str[k+2]=='H'?1:0);
    result[penny]+=1;
    }

    cout<<index;
    for (int i=0;i<8;i++){
      cout<<" "<<result[i];
    }
    cout<<endl;
  }
  return 0;
}

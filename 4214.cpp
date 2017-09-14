#include <iostream>
#include <cstdio>
using namespace std;


int end(int m, int y){
  if (m==2){
    if ((y%4==0 && y%100!=0) || y%400==0){
      return 29;
    }
    else{
      return 28;
    }
  }
  else if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
    return 31;
  }
  else {
    return 30;
  }
}


bool consecutive(int &d1, int &m1, int &y1, int &d2, int &m2, int &y2){
  // by day
  if (y1==y2 && m1==m2 && (d2-d1)==1){
    return true;
  }

  // by month
  if (y1==y2 && (m2-m1)==1 && d1==end(m1,y1) && d2==1){
    return true;
  }

  // by year
  if ((y2-y1)==1 && m1==12 && d1==31 && m2==1 && d2==1){
  return true;
}
return false;
}


int main(){
  while (true){
    int n;
    scanf("%d",&n);
    if (n==0) break;
    int d1,m1,y1,c1,d2,m2,y2,c2,count,consumption;
    count=0;
    consumption=0;
    scanf("%d %d %d %d", &d1,&m1,&y1,&c1);

    for (int i=1;i<n;i++){
      scanf("%d %d %d %d", &d2,&m2,&y2,&c2);
      if (consecutive(d1,m1,y1,d2,m2,y2)){
        count+=1;
        consumption+=(c2-c1);
      }
      d1=d2;
      m1=m2;
      y1=y2;
      c1=c2;
    }
    printf("%d %d\n",count, consumption );
  }
  return 0;
}

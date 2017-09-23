/*
 * Let F(N) be the number of recursively palindromic partitions of N
 * if N is even, we can get a recursively palindromic partition by putting
 * any even number K <= N in the center and then a recursively palindromic
 * partition of (N-K)/2 on either side so
 * F(N) = 1 + F(2) + ... + F(N/2) = F(N-2) + F(N/2) (1 is the case where K = N)
 * if N is odd, we can get a recursively palindromic partition by putting
 * any odd number K <= N in the center and then a recursively palindromic
 * partition of (N-K)/2 on either side so
 * F(N) = 1 + F(2) + ... + F((N-1)/2) = F(N-1) (1 is the case where K = N)
 *
 */

/*
 * remember to use dynamic programming,otherwise, the recursion will exceed
 * time limit 
 */
#include <iostream>
using namespace std;

int lastMax;
int results[10000];

int palindromeCount(int n){


  if (n<=lastMax){
    return results[n];
  }
  for (int i=lastMax+1;i<=n;i++){
  if (i%2==0){
    results[i]=results[i-2]+results[i/2];
  }
  else{
    results[i]=results[i-1];
  }
}
lastMax=n;
return results[n];
}
int main(){
  results[0]=1;
  results[1]=1;
  lastMax=1;
  int n;
  int input;
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>input;
    cout<<i+1<<" "<<palindromeCount(input)<<endl;

  }

  return 0;

}

/*
求最长公共子序列的长度

*/
#include<iostream>
#include<string>
#include<string.h>

using namespace std;

inline int MAX(int a, int b){
  return a>b ?a:b;
}
int memo[100][100];  //暂存结果的集合

int LCS_1(const string &a, const string &b, int i, int j){
   if(i==0||j==0){
    return 0;
   }

   if(memo[i][j]==-1){    //缓存中没有结果，需要自己计算
       if(a[i-1]==b[j-1]){
         return LCS_1(a,b,i-1,j-1)+1;
       }
       return MAX(LCS_1(a,b,i,j-1), LCS_1(a,b,i-1,j));
   }else{                //直接返回结果
       return memo[i][j];
   }
}

int LCS_2(const string &a, const string &b){
    int memo[100][100];    //暂存结果
 
    //memo[i][0]=0
    for(int i=0;i<=a.size();++i){
        memo[i][0]=0;
    }
    for(int j=0;j<=b.size();++j){
        memo[0][j]=0;
    }
    for(int i=1; i<=a.size(); ++i){
      for(int j=1; j<=b.size(); ++j){
         if(a[i-1]==b[j-1]){
             memo[i][j]=memo[i-1][j-1]+1;
            }else{
             memo[i][j]=MAX(memo[i-1][j],memo[i][j-1]);
            }
       }
    }
    return memo[a.size()][b.size()];
}
int main(int argc, char **argv){
     memset(memo, 0xff, 100*100*sizeof(int));

     string a="ipone";
     string b="iphone";
      int ret=LCS_1(a, b, a.size(), b.size());
      cout<<ret<<endl;
     ret=LCS_2(a,b);
     cout<<ret<<endl;

      return 0;
}

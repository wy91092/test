/*

最小编辑距离
*/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;


inline int min(int a, int b, int c){
   int t= a<b? a: b;
   return t<c?t:c;
}
int ED(const wstring &a, const wstring &b){
   int len1=a.size();
   int len2=b.size();
   int d[len1+1][len2+1];
   int i,j;
   for(i=0;i<=len1;i++)
      d[i][0]=i;
   for(j=0;j<=len2;j++)
      d[0][j]=j;
   for(i=1;i<=len1;i++){
      for(j=1;j<=len2;j++){
       int cost=(a[i-1]==b[j-1])?0:1;
       int deletion=d[i-1][j]+1;
       int insertion=d[i][j-1]+1;
       int substitution=d[i-1][j-1]+cost;
       d[i][j]=min(deletion, insertion, substitution);
      }

   }
   for(i=0;i<=len1;i++){
    for(j=0;j<=len2;j++){
       cout<<d[i][j]<<" ";
     }
     cout<<endl;
   }
   return d[len1][len2];
}

int main()
{
   wstring a=L"中国龙";
   wstring b=L"中国人";
   int ret=ED(a, b);
   cout<<ret<<endl;
   return 0;
}

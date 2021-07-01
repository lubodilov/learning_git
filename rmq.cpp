#include <bits/stdc++.h>
using namespace std;
int lookup[500][500];
struct Query
{
   int l, r;
};
void preprocess(int a[], int n)
{
   for(int i=0; i<n; ++i)
   {
      lookup[i][0]=i;
   }
   for(int j=1; (1<<j)<n; ++j)
   {
      for(int i=0; i+(1<<j)-1<n; ++i)
      {
         if(a[lookup[i][j-1]]<a[lookup[i+(1<<j-1)][j-1]])
         {
            lookup[i][j]=lookup[i][j-1];
         }
         else
         {
            lookup[i][j]=lookup[i+(1<<j-1)][j-1];
         }
      }
   }
}
int query(int a[], int l, int r)
{
   int j=log(r-l+1);
   if(a[lookup[l][j]]<a[lookup[r-(1<<j)+1][j]])
   {
      return a[lookup[l][j]];
   }
   else
   {
      return a[lookup[r-(1<<j)+1][j]];
   }
}
void RMQ(int n, int a[], Query q[], int m)
{
   preprocess(a, n);

   for(int i=0; i<m; ++i)
   {
      int l=q[i].l, r=q[i].r;

      cout << "Min of [" << l << ", " << r << "] is -> " << query(a, l, r) << endl;
   }
}
int main() {

int a[]={7, 2, 3, 0, 5, 10, 3 ,12, 18};
int n = sizeof(a)/sizeof(a[0]);
Query q[] = {{0, 4}, {4, 7}, {7, 8}};
int m = sizeof(q)/sizeof(q[0]);
RMQ(n, a, q ,m);


return 0;
}


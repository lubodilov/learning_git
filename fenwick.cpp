#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

   int get_sum(int index, int Bit_tree[])
   {
      index++;
      int sum=0;
      while(index>0)
      {
         sum+=Bit_tree[index];
         index-=index&(-index);
      }
      return sum;
   }
   void update(int index, int val, int n, int Bit_tree[])
   {
      index++;
      while(index<=n)
      {
         Bit_tree[index]+=val;
         index+=index&(-index);
      }
   }
   int* build_Tree(int a[], int n)
   {
      int* Bit_tree=new int(n+1);
      for(int i=0; i<n; ++i)
      {
         Bit_tree[i]=0;
      }
      for(int i=0; i<n; ++i)
      {
         update(i, a[i], n, Bit_tree);
      }
      return Bit_tree;
   }
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);
    int *BITree = build_Tree(freq, n);
    cout << "Sum of elements in arr[0..5] is "
        << get_sum(5, BITree);

    freq[3] += 6;
    update(3, 6, n, BITree);

    cout << "\nSum of elements in arr[0..5] after update is "
        << get_sum(5, BITree);




return 0;}

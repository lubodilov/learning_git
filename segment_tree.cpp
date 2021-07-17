#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1000;
int t[4*maxn];
void build(int a[], int curr, int tl, int tr)
{
    if(tl==tr)
    {
        t[curr]=a[tl];
    }
    else
    {
        int tmid=(tl+tr)/2;
        build(a, curr*2, tl, tmid);
        build(a, curr*2+1, tmid+1, tr);
        t[curr]=t[curr*2]+t[curr*2+1];
    }
}
int sum(int curr, int tl ,int tr, int l, int r)
{
    if(l>r)
    {
        return 0;
    }
    if(tl==l && tr==r)
    {
        return t[curr];
    }
    int tmid=(tl+tr)/2;
    return sum(curr*2, tl, tmid, l, min(r, tmid)) + sum(curr*2+1, tmid+1, tr, max(l, tmid+1), r);
}
void update(int curr, int tl, int tr, int index, int val)
{
    if(tl==tr)
    {
        t[curr]=val;
    }
    else
    {
        int tmid=(tl+tr)/2;
        if(tmid<index)
        {
            update(curr*2+1, tmid+1, tr, index, val);
        }
        else
        {
            update(curr*2, tl, tmid, index, val);
        }
        t[curr]=t[curr*2]+t[curr*2+1];
    }
}
int main(){
    int n;
    int arr[maxn];
    cin >> n;
    for(int i=0; i<n; ++i)
    {
        cin >> arr[i];
    }
    build(arr, 1, 0, n-1);
    cout << sum(1, 0, n-1, 2, 3);
    update(1, 0, n-1, 2, 10);
    arr[2]=10;
    cout << "\n" << sum(1, 0, n-1, 2, 3);

return 0;
}

#include<bits/stdc++.h>
using namespace std;

int sumval(vector<int>& arr,int val)
{
    int sum=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>val)
            break;
        sum+=arr[i];
    }
    return sum;
}

int books_num(vector<int>& arr,int k)
{
    int s=0;
    int e=arr.size()-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]<=k)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return s;
}

int Numbook(int n,vector<int>& desk1,int m,vector<int>& desk2,int k)
{
    int s=min(desk1[0],desk2[0]);
    int e=max(desk1[n-1],desk2[m-1]),
    int ans=0;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(sumval(desk1,mid)+sumval(desk2,mid)<=k)
        {
            ans=books_num(desk1,mid);
            ans+=books_num(desk2,mid);
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return ans;
}

int main()
{
    int n,m,k;
    cin>>n;
    cin>>m;
    cin>>k;
    vector<int> desk1;
    vector<int> desk2;
    for(int i=0;i<n;i++){
     int num;
     cin>> num;
     desk1.push_back(num);
    }

    for(int i=0;i<m;i++){
     int num;
     cin>> num;
     desk2.push_back(num);
    }

    int val=Numbook(n,desk1,m,desk2,k);
    cout<<val<<endl;
    return 0;
}

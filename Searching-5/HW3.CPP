#include<bits/stdc++.h>
using namespace std;


int div_test(int a,int b,int c,int d)
{
    return ((d / a) + (d / b) + (d / c)
            - (d / lcm(a, b))
            - (d / lcm(b, c))
            - (d / lcm(a, c))
            + (d / lcm(a, lcm(b, c))));
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
 
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int divisible_term(int a,int b,int c,int n)
{
    int s=1,high=INT_MAX;
    while(low<=high)
    {
        int mid=s+(e-s)/2;
        if(div_test(a,b,c,mid)<n)
        {
            s=mid+1;
        }
        else
            e=mid;
    }
    return s;
}

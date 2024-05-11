#include<bits/stdc++.h>
using namespace std;

int maxsum(int a[], int n, int x, int y, int z){
    int ex1=INT_MIN;
    int ex2=INT_MIN;
    int ex3=INT_MIN;

    for(int i=0;i<n;i++){

        ex1=max(ex1,x*a[i]);
        ex2=max(ex2,y*a[i]);
        ex3=max(ex3,z*a[i]);
    }

    return ex1+ex2+ex3;
}
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n1=s.size();
        int n2=t.size();

        if(n1!=n2)
        {
            return false;
        }
        vector<int>arr;
        for(int i=0;i<n1;i++)
        {
            int val=abs(s[i]-t[i]);
            arr.push_back(val);
            cout<<val<<" ";
        }

        int sum=0;
        int maxlen=0;
        int i=0;
        int j=0;

        while(i<n1)
        {
            sum=sum+arr[i];
            while(sum>maxCost)
            {
                sum=sum-arr[j];
                j++;
            }

            maxlen=max(maxlen,i-j+1);
            i++;
        }

        return maxlen;

        
    }
};

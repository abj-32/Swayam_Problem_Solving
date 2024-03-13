bool blackbox(vector<int> &boards, int k, int mid){

    int Count=1;

    int sum =0;
    for(int i=0;i<boards.size();i++){

        if(sum+boards[i]<=mid){
          sum +=boards[i];
        }

        else{
        Count++;
        sum =boards[i];
        }

    }

    if(Count<=k){
        return true;
    }

    return false;

}


int findLargestMinDistance(vector<int> &boards, int k)

{

   int s=0;
   int sum =0;
   int ans=-1;

   for(int i=0;i<boards.size();i++){
       sum+= boards[i];
   } 

   int e=sum;
   int mid= s+(e-s)/2;

   while(s<=e){

       if (blackbox(boards, k, mid)) {
           ans= mid;
         e = mid - 1;
       }
       else{
           s=mid+1;
       }
       mid = s+(e-s)/2;
   }

   return ans;

}
class Solution {
public:

    bool canplace(vector<int>& position,int m,int gap){
        int cnt=1;
        int last=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last>=gap){
                cnt++;
                if(cnt==m)  return true;
                last=position[i];
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=1;
        int high=position[position.size()-1]-position[0];
        int ans=1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canplace(position,m,mid)){
                ans=mid;
                low=mid+1;
            }
            else    high=mid-1;
        }
        return ans;
    }
};

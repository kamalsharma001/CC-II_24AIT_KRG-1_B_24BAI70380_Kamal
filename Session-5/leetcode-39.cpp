class Solution {
public:

    void solve(vector<int>& nums,int idx,vector<vector<int>>& ans,vector<int>& curr,int sum,int target,set<vector<int>>& st){
        if(sum==target){
            if(st.find(curr)==st.end()){
                ans.push_back(curr);
                st.insert(curr);    
            }   
            return;
        }
        if(idx==nums.size())    return;
        if(nums[idx]>target-sum)    solve(nums,idx+1,ans,curr,sum,target,st);
        else{
            curr.push_back(nums[idx]);
            solve(nums,idx,ans,curr,sum+nums[idx],target,st);
            solve(nums,idx+1,ans,curr,sum+nums[idx],target,st);
            curr.pop_back();
            solve(nums,idx+1,ans,curr,sum,target,st);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int sum=0;
        set<vector<int>> st;
        solve(candidates,0,ans,curr,0,target,st);
        return ans;
    }
};

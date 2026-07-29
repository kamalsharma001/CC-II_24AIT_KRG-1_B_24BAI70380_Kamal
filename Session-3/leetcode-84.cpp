class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int maxm=0;
        for(int i=0;i<=n;i++){
            int curr=(i==n)?0:heights[i];
            while(!st.empty() && heights[st.top()]>curr){
                int idx=st.top();
                st.pop();
                int height=heights[idx];
                int pse=st.empty()?-1:st.top();
                int width=i-pse-1;
                int area=height*width;
                maxm=max(maxm,area);
            }
            st.push(i);
        }
        return maxm;
    }
};

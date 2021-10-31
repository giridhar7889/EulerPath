class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        int n=nums.size();
        int dp[n];
        dp[0]=nums[0];
        priority_queue<pair<int,int>>pq;
        pq.push(make_pair(nums[0],0));
        for(int i=1;i<n;i++)
        {
            while(pq.top().second+k<i)
            {
                pq.pop();
            }
            dp[i]=nums[i]+pq.top().first;
            pq.push(make_pair(dp[i],i));
        }
        return dp[n-1];
        
    }
};
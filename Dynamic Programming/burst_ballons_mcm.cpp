class Solution {
public:
    const static int N=1e3;
    int dp[N][N];
    int maxCoins(vector<int>& nums) 
    {
        
       
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=-1; 
            }
        }
       return burst(nums,1,nums.size()-2);
        
        
        
    }
    int burst(vector<int>&temp,int l,int r)
    {
        if(l>r)
        {
            return 0;
        }
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        for(int i=l;i<=r;i++)
        {
            dp[l][r]=max(dp[l][r],burst(temp,l,i-1)+burst(temp,i+1,r)+temp[l-1]*temp[i]*temp[r+1]);
        }
        return dp[l][r];
    }
    
};
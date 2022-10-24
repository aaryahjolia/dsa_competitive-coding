class Solution {
public:
    int dp[110];
    int helper(vector<int>& nums,int n,int i)
    {
        if(n==0 || n==-1 || n==-2)
            return 0;
        
        if(dp[n]!=-1)
            return dp[n];
        
        if(n==2 && i==0)
        {
            return dp[n] = 0;
        }
        else if(n==2 && i==1)
        {
            return dp[n] = nums[n-2]+helper(nums,n-2,i);
        }
        if(n==1)
        {
            return dp[n]=0;
        }
        if(i==0 && n==3)
        {
            return dp[n] = nums[n-2]+helper(nums,n-2,i);
        }
        else if(i==1 && n==3)
        {
            return dp[n] = max(nums[n-2]+helper(nums,n-2,i),nums[n-3]+helper(nums,n-3,i));
        }
        return dp[n] = max(nums[n-2]+helper(nums,n-2,i),nums[n-3]+helper(nums,n-3,i));
    }
    int rob(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        int size=nums.size();
        int max1=0,max2=0,max3=0;
        if(size>=1)
        max1=nums[size-1]+helper(nums,size-1,0);
        memset(dp,-1,sizeof(dp));
        if(size>=2)
        max2=nums[size-2]+helper(nums,size-2,1);
        if(size>=3)
        max3=nums[size-3]+helper(nums,size-3,1);   
        return max(max1,max(max2,max3));
    }
};

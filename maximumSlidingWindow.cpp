#include<bits/stdc++.h>
using namespace std;
class Solution {


public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> q(k);
        for(int i = 0; i < k; i++){
            while(!(q.empty()) && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }

        for(int i = k; i < n; i++){
            ans.push_back(nums[q.front()]);
            while(!(q.empty()) && q.front() <= i-k){
                q.pop_front();
            }

            while(!(q.empty()) && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i= 0; i < n; i++){
        cin>>nums[i];
    }

   
    int k; 
    cin>>k;
    Solution S;
    vector<int> res = S.maxSlidingWindow(nums,k);
    for(int i = 0 ;i < res.size(); i++){
        cout<<res[i]<<" ";
    }cout<<endl;
    return 0;
}
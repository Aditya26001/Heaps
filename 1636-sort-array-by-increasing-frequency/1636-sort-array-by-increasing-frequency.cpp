class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        //create minheap
       priority_queue<pair<int,int>>maxh;
        
        //traverse the map
        for(auto i = mp.begin();i!=mp.end();i++){
            maxh.push({-i->second,i->first}); //i is a iterator
        }
        
        while(maxh.size()!=0){
            int freq = maxh.top().first;
            int ele = maxh.top().second;
            for(int i=0;i<abs(freq);i++){  //abs for negative elements
                ans.push_back(ele);
            }
            
             maxh.pop();
        }
        return ans;
    }
};
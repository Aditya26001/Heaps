class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        //create minheap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        
        //traverse the map
        for(auto i = mp.begin();i!=mp.end();i++){
            minh.push({i->second,i->first}); //i is a iterator
            if(minh.size()>k) minh.pop();
            
        }
        
        while(minh.size()!=0){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};
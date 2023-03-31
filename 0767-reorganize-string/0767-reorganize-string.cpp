class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>maxh;
        
        for(auto i:s){
            mp[i]++;
        }
        
        for(auto i:mp){
            maxh.push({i.second,i.first});
        }
        
        while(maxh.size()>1){
            auto t1 = maxh.top();
            maxh.pop();
            auto t2 = maxh.top();
            maxh.pop();
            ans+=t1.second;
            ans+=t2.second;
            t1.first-=1;
            t2.first-=1;
            
            if(t1.first>0) maxh.push(t1);
            if(t2.first>0) maxh.push(t2);
            
        }
        
        if(!maxh.empty()){
            if(maxh.top().first>1) return "";
            else ans+=maxh.top().second;
        }
        return ans;
    }
};

//frequency related so hashmaps
//heaps with freq require pairs in it
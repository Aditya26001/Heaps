class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        
        unordered_map<int,int>mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        
        sort(hand.begin(),hand.end());
        
        for(int i=0;i<hand.size();i++){
            if(mp[hand[i]]==0) continue;
            for(int j=0;j<groupSize;j++){
                int temp = hand[i]+j;
                if(mp[temp]==0) return false;
                mp[temp]--;
            }
        }
        return true;
    }
};
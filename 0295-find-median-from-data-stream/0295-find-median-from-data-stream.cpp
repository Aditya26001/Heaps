class MedianFinder {
public:
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //if no. of elements is odd, then maxh will have 1 more element than minh.
        //so first we add into maxh
        if(maxh.empty()||num<maxh.top()) maxh.push(num);
        else minh.push(num);
        
        if(maxh.size()>minh.size()+1){
            minh.push(maxh.top());
            maxh.pop();
        }
        else if(minh.size()>maxh.size()+1){
            maxh.push(minh.top());
            minh.pop();
        }
        
        
    }
    
    double findMedian() {
        if(minh.size()==maxh.size()) {
            return (maxh.top()+minh.top())/2.0;
        }
        else{
            if(maxh.size()>minh.size()) return maxh.top();
        }
        return minh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
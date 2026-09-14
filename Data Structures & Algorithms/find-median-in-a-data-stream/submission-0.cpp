class MedianFinder {

private:
priority_queue<int, vector<int>, greater<int>> minP;
priority_queue<int> maxP;     
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {

       int n1= minP.size(); int n2 = maxP.size();
        if(minP.empty() || minP.top() < num) {
            minP.push(num);
            if(n1 - n2 > 0) {
                maxP.push(minP.top());
                minP.pop();
            }
        }
        else{
            maxP.push(num);
            if(n2 - n1 > 0) {
                minP.push(maxP.top());
                maxP.pop();
            }
        } 
    }
    
    double findMedian() {
        
        int n1 = minP.size(); int n2 = maxP.size();
        if((n1+n2)%2 == 0) {
            int res = 0;
            if(!minP.empty()) res+= minP.top();
            if(!maxP.empty()) res+= maxP.top();

            return (double) res/2;
        }
        else{
            return n1>n2 ? minP.top() : maxP.top();
        }
    }
};

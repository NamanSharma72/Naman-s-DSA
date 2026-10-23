class MedianFinder {
public:
    priority_queue<int> maxq;
    priority_queue<int , vector<int> , greater<int>> minq;
    MedianFinder() {}
    void addNum(int num) {
        if(maxq.empty() && minq.empty()) maxq.push(num);
        else if(minq.empty()){
            int median = maxq.top();
            if(num > median) minq.push(num);
            else maxq.push(num);
        }
        else if(maxq.empty()){
            int median = minq.top();
            if(num > median) minq.push(num);
            else maxq.push(num);
        }
        else{
            int total = maxq.size() + minq.size();
            if(total%2 == 0){
                double median = (maxq.top() + minq.top())/2.0;
                if(num > median) minq.push(num);
                else maxq.push(num);
            }
            else{
                int median = -1;
                if(maxq.size() > minq.size()) median = maxq.top();
                else median = minq.top();
                if(num > median) minq.push(num);
                else maxq.push(num);
            }
        }
        
        if(maxq.size()-minq.size() == 2){
            minq.push(maxq.top());
            maxq.pop();
        }

        if(minq.size() - maxq.size() == 2){
            maxq.push(minq.top());
            minq.pop();
        }
    }
    double findMedian() {
        if(maxq.size() > minq.size()){
            return (double)maxq.top();
        }
        else if(maxq.size() < minq.size()){
            return (double)minq.top();
        }
        else{
            double median = (minq.top() + maxq.top())/2.0;
            return median;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
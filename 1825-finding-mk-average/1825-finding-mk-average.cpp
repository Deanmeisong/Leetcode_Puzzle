class MKAverage {
    int m, k;
    multiset<int> left, right, mid;
    long sum = 0;
    queue<int> q;
public:
    MKAverage(int m, int k) {
        this->m = m; this->k = k;
    }
    
    void addElement(int num) {
        if(q.size() < m) {
            q.push(num);
            mid.insert(num);
            sum += num;
            if(q.size() == m) {
                while(left.size() < k) {
                    sum -= *mid.begin();
                    shiftLeft(left, mid);
                }
                while(right.size() < k) {
                    sum -= *mid.rbegin();
                    shiftRight(mid, right);
                }
            }
        } 
       else if(q.size() == m) {
            q.push(num);
            if(!left.empty() && num <= *left.rbegin()) left.insert(num);
            else if(!right.empty() && num >= *right.begin()) right.insert(num);
            else {
                mid.insert(num);
                sum += num;
            }  
            if(left.size() > k) {
                sum += *left.rbegin();
                shiftRight(left, mid);
            }
            if(right.size() > k) {
                sum += *right.begin();
                shiftLeft(mid, right);
            }
            
            int x = q.front(); q.pop();
            if(left.find(x) != left.end()) left.erase(left.find(x));
            else if(right.find(x) != right.end()) right.erase(right.find(x));
            else {
                sum -= x;
                mid.erase(mid.find(x));
            }
            
            if(left.size() < k) {
                sum -= *mid.begin();
                shiftLeft(left, mid);
            }
            if(right.size() < k) {
                sum -= *mid.rbegin();
                shiftRight(mid, right);
            }                                 
        }
        
    }
    
    int calculateMKAverage() {
        if(q.size() < m) return -1;
        else return sum / (m - 2*k);
    }
    
    void shiftLeft(multiset<int>& A, multiset<int>& B) {
        A.insert(*B.begin());
        B.erase(B.begin());
    }
    
    void shiftRight(multiset<int>& A, multiset<int>& B) {
        B.insert(*A.rbegin());
        A.erase(--A.end());
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
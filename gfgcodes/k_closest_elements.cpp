class Solution {
  public:
    class compare{
        public :
        bool operator()(pair<int,int> &p1, pair<int,int> &p2){
            if(p1.first == p2.first) return p1.second > p2.second;
            return p1.first < p2.first;
        }
    };
    vector<int> printKClosest(vector<int> &arr, int n, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare>maxh;
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
               int diff = abs(arr[i]-x);
               
              if(diff==0)continue;
              
            maxh.push({abs(arr[i] - x), i});
            
            if(maxh.size() > k){
                maxh.pop();
            }
        }
        
        while(maxh.size() > 0){
            ans.push_back(arr[maxh.top().second]);
            maxh.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

class Solution {

    private:
    vector<int>nextsmallerElement(vector<int> arr, int n){
       stack<int>st;
       vector<int>ans(n);
       st.push(-1);
    
        int p;
       for(int i = n-1; i>=0; i--){
          p  = arr[i];
          while(st.top() != -1 && arr[st.top()]>=p){
            st.pop();
          }
    
    
       ans[i] = st.top();
       st.push(i);
        
    
       }
    
       return ans;
    
    
    
    }
    
    
    vector<int>presmallerElement(vector<int> arr, int n){
       stack<int>st;
       vector<int>ans(n);
       st.push(-1);
    
        int p;
       for(int i = 0; i<n; i++){
          p  = arr[i];
          while(st.top() != -1 && arr[st.top()]>=p){
            st.pop();
          }
    
    
       ans[i] = st.top();
       st.push(i);
        
    
       }
    
       return ans;
    
    
    
    }
    
    
    public:
        int largestRectangleArea(vector<int>& heights) {
            
            int n = heights.size();
              
              vector<int>next(n);
              vector<int>pre(n);
    
              next = nextsmallerElement(heights,n);
              pre = presmallerElement(heights,n);
                int area = INT_MIN;
             for(int i  = 0; i<n; i++){
              int length  = heights[i];
    
              if(next[i] == -1){
                next[i] = n;
              }
              int width  = next[i] - pre[i] - 1;
              int newarea  = (length*width);
                 area  = max(newarea,area);
    
             }
    
       
    
          return area;
        }
    };
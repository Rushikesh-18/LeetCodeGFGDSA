class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int i=0;
          int n=temperatures.size();
         vector<int>v;
         stack<int>s;
         int count=0;
       
         for(int i=n-1;i>=0;i--){
             if(s.empty()){
                 
                 v.push_back(0);
                 
             }
             else if(s.size()>0 && temperatures[s.top()]>temperatures[i]){
        v.push_back(1);
        
    }
             else if(s.size()>0  && temperatures[s.top()]<=temperatures[i]){
                 while(s.size()>0 &&  temperatures[s.top()]<=temperatures[i]){
                         count++;
                         s.pop();
                 }
                         if(s.empty()){
                             v.push_back(0);
                             count=0;
                            
                         }
                         else{
                             v.push_back(s.top()-i);
                            count=0;
                         }
                 }
                  s.push(i);
             }
             reverse(v.begin(),v.end());
         return v;
    
            
         }
         
};
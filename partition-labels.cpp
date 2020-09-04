class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> output;
      string &s=S;
      int n=s.length();
        if(s.length()==0) return output;
      
        vector<int> last_indices(26);
      for(int i=0;i<n;i++){
        last_indices.at(s[i]-'a')=i;
      }
      
      int start=0;
      int end=0;
      
      for(int i=0;i<n;i++){
        end= max(end,last_indices.at(s[i]-'a'));
        if(i==end){
          output.emplace_back(end-start+1);
          start=end+1;
        }
      }
      
      return output;
    }
};

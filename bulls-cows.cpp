class Solution {
public:
    string getHint(string secret, string guess) 
    {
      string ans="";
      unordered_map<char,int> dict;
      int bull=0,cow=0;
      int len=secret.length();
      for(int i=0;i<len;i++){
        if(secret[i]==guess[i]) {
          bull++; guess[i]='$';
        }
        else{
          if(dict.find(secret[i])!=dict.end()) dict[secret[i]]++;
          else dict[secret[i]]=1;
        }
      }
      for(int i=0;i<len;i++){
        if(guess[i]=='$') continue;
        if(dict.find(guess[i])!=dict.end() && dict[guess[i]]>0){
          cow++;
          dict[guess[i]]--;
        }
      }
      ans=to_string(bull)+'A'+to_string(cow)+'B';
      return ans;
    }
};

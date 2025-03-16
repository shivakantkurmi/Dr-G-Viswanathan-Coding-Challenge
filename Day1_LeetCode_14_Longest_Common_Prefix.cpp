class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix="";
        string current=strs[0];
        int i;
        bool flag=false;
        for(i=0 ;i<current.length();i++){
            for(int ind=1;ind<strs.size();ind++){
                if(strs[ind].length()>i && strs[ind][i]==current[i]) continue ;
                else{ 
                    flag=true;
                    break;}
            }
            if (flag) break;
        }
        return current.substr(0,i);
    }
};

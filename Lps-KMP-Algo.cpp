//https://leetcode.com/problems/shortest-palindrome/submissions/
//lps table is main it give info -> longest proper prefix that is also  proper suffiix of same string;
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s=s;
        reverse(rev_s.begin(),rev_s.end());
        if(s=="" || rev_s==s)
            return s;
        
        string comb=s+'-'+rev_s;  //used special char to avoid operlapping 
        
        
        vector<int>lps(comb.size());
        
        int i=1;
        int left=0;
        while(i<comb.size()){
            
            if(comb[i]==comb[left]){
                left++;
                lps[i]=left;
                i++;
            }
            else{
                if(left!=0)
                left=lps[left-1];
                else {
                    lps[i]=0;
                    i++;
                }
                
            }
        }
        
        int maxLps=lps[comb.size()-1];
       
        string str=rev_s.substr(0,s.size()-maxLps);
        return str+s;
    }
};

#include<iostream> 
#include<stack> 
#include<string> 


using namespace std; 

class Solution{
public: 
    string minRemoveToMakeValid(string s){
       stack<int> st; 
       for(int i=0; i<s.size();++i){
         if(s[i]=='(') st.push(i); 
         else if(s[i]==')'){
           if(!st.empty()) st.pop(); 
           else s[i]='!'; 
         }
       }

       string ans=""; 
       while(!st.empty()){
         s[st.top()]='!'; 
         st.pop(); 
       }
       for(int i=0; i<s.size();++i){
          if(s[i]!='!') ans+=s[i];
       }
       return ans; 
      
    }
};
int main(){
   string s = "lee(t(c)o)de)"; 
   Solution sol; 
   cout << sol.minRemoveToMakeValid(s) << endl; 
   return 0; 
}

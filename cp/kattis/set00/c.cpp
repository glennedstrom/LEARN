#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  char c;
  string s;

  unordered_map<char,bool> correct;
  unordered_map<char,int> time;

  while(cin >> n >> c >> s){
    if (n == -1){break;}
    
    if(s == "right"){
      correct[c] = true;
      time[c] += n;
    }
    else if(correct[c] == false){
      time[c] += 20;
    }
  }
  int endcorrect = 0;
  int endtime = 0;
  for(auto& [a,c] : correct){
    endcorrect += c;
    if (c){
      endtime += time[a];
    }
  }
  cout << endcorrect << " " << endtime << endl;
}

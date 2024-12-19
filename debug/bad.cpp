#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const ll mod = 1e9+7;
void solve()
{
  int n,k; cin>>n>>k;
  string s; cin>>s;
  vector<pair<int,int>> pos_segment;
  int left = 0;
  while(left<n){
    int right = left;
    while(right<n && s[right]==s[left]){
      right++;
    }
    if(s[left]=='1'){
      pos_segment.push_back({left,right-1});
    }
    left = right;
  }
  dbg(pos_segment);
  int pos = pos_segment.size();
  string result(n,'0');
  if(pos>=3){
    pos_segment[pos-3].second += pos_segment[pos-2].second-pos_segment[pos-2].first+1;
    for(int i=0;i<pos;i++){
    if(i==pos-2)continue;
    for(int j=pos_segment[i].first;j<=pos_segment[i].second;j++){
      result[j]='1';
    }
    }
    cout<<result<<'\n';
  }else{
    pos_segment[pos-2].second+=pos_segment[pos-1].second-pos_segment[pos-1].first+1;
    for(int i=0;i<pos;i++){
    if(i==pos-1)continue;
    for(int j=pos_segment[i].first;j<=pos_segment[i].second;j++){
      result[j]='1';
    }
    }
    cout<<result<<'\n';
  }
    dbg(pos_segment);
}
int main()
{
    cpu();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

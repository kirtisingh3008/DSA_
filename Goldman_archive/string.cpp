// Reduce the string by removing k consecutive identical characters
#include<bits/stdc++.h>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>> 
#define ll long long int
using namespace std;
void solve(string s, int k)
{
    string ans;
    if(k==1)
    {
        cout<<ans<<endl;
        return;
    }
    stack<pair<char,int>> st;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(st.empty()==true)
        {
            st.push(make_pair(s[i],1));
        }
        else
        {
            if((st.top()).first==s[i])
            {
                st.push({s[i],st.top().second+1});
                if(st.top().second==k)
                {
                int x=k;
                while(x)
                {
                    st.pop();
                    x--;
                }
                }
            }
            else 
            {
                st.push(make_pair(s[i],1));
            }
        }
    }
    while(st.empty()==false)
    {
        ans+=st.top().first;
        st.pop();

    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;


}
int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    solve(s,k);
    return 0;
}

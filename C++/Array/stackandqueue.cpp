#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Stack"<<endl;
    stack<int> s;
    s.push(20);
    s.push(15);
    s.push(60);
    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<"Queue"<<endl;
    queue<int> q;
    q.push(20);
    q.push(15);
    q.push(60);
    while (!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}

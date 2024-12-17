#include <bits/stdc++.h>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    stack<long long> nums;
    stack<char> s;
    string n = "";
    map<char, int> m;
    string rank[6] = {"*+-", "*-+", "+*-", "+-*", "-*+", "-+*"};
    
    for(string r : rank) {
        n = "";
        m[r[0]] = 0;
        m[r[1]] = 1;
        m[r[2]] = 2;
        for(char ch : expression) {
            if(ch == '*' || ch == '+' || ch == '-') {
                nums.push(stoll(n));
                n = "";
                
                if(s.empty() || m[ch] < m[s.top()]) s.push(ch);
                else {
                    while(!s.empty() && m[ch] >= m[s.top()]) {
                        long long second = nums.top();
                        nums.pop();
                        
                        long long front = nums.top();
                        nums.pop();
                        
                        long long res;
                        
                        if(s.top() == '*') res = front * second;
                        else if(s.top() == '+') res = front + second;
                        else res = front - second;
                        
                        nums.push(res);
                        s.pop();
                    }
                    s.push(ch);
                }
            } else {
                n.push_back(ch);
            }
        }
        nums.push(stoll(n));
        
        while(!s.empty()) {
                long long second = nums.top();
                nums.pop();
                        
                long long front = nums.top();
                nums.pop();
                        
                long long res;
                        
                if(s.top() == '*') res = front * second;
                else if(s.top() == '+') res = front + second;
                else res = front - second;
                        
                nums.push(res);
                s.pop();
        }
        
        answer = max(answer, abs(nums.top()));
        nums.pop();
    }
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int mod, res;
    
    for(int i = 0; i < n; i++) {
        string s1 = "", sum = "";
        mod, res = arr1[i];
        
        for(int j = 0; j < n; j++) {
            mod = res % 2;
            res = res >> 1;
            
            if(mod == 1) {
                s1 = "#" + s1;
            } else {
                s1 = " " + s1;
            }
        }
        
        res = arr2[i];
        
        for(int j = 0; j < n; j++) {
            mod = res % 2;
            res = res >> 1;
            
            if(mod == 1 || s1[n - j - 1] == '#') {
                sum = "#" + sum;
            } else {
                sum = " " + sum;
            }
        }
        
        answer.push_back(sum);
    }
    return answer;
}
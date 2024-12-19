#include <bits/stdc++.h>

using namespace std;

inline bool check(char ch1, char ch2) {
    bool pass = false;
    if(('a' <= ch1 && ch1 <= 'z') || ('A' <= ch1 && ch1 <= 'Z')) pass = true;
    if(pass && (('a' <= ch2 && ch2 <= 'z') || ('A' <= ch2 && ch2 <= 'Z'))) return true;
    return false;
}

int solution(string str1, string str2) {
    int answer = 0;
    double res = 0.0;
    char ch1, ch2;
    string tmp = "";
    vector<string> s1, s2;
    
    for(int i = 0; i < str1.size() - 1; i++) {
        ch1 = str1[i], ch2 = str1[i + 1];
        
        if(check(ch1, ch2)) {
            ch1 = tolower(ch1);
            ch2 = tolower(ch2);
            tmp.push_back(ch1);
            tmp.push_back(ch2);
            s1.push_back(tmp);
            tmp.clear();
        }
    }
    
    for(int i = 0; i < str2.size() - 1; i++) {
        ch1 = str2[i], ch2 = str2[i + 1];
        
        if(check(ch1, ch2)) {
            ch1 = tolower(ch1);
            ch2 = tolower(ch2);
            tmp.push_back(ch1);
            tmp.push_back(ch2);
            s2.push_back(tmp);
            tmp.clear();
        }
    }
    
    if(s1.empty() && s2.empty()) return 65536;
    
    vector<string> uni(s1.size() + s2.size()), inter(s1.size() + s2.size());
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    auto iter1 = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inter.begin());
    inter.erase(iter1, inter.end());

    auto iter2 = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), uni.begin());
    uni.erase(iter2, uni.end());
    
    double size1 = inter.size();
    double size2 = uni.size();
    
    res = size1 / size2;
    answer = res * 65536;
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for(int i = 0; i < phone_book.size() - 1; i++) {
        string now = phone_book[i];
        string next = phone_book[i + 1];
        
        if(next.find(now) == 0) return false;
    }
    
    return true;
}
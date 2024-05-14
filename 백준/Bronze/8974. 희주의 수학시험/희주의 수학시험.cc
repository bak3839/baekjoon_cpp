
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
 
    int a,b;
    cin>>a>>b;
 
    vector<int> vec;
 
    for(int i=1; i<=1000; i++){
        for(int j=1; j<=i; j++){
            vec.push_back(i);
        }
    }
 
    int sum=0;
 
    for(int i=a-1; i<=b-1; i++){
        sum+=vec[i];
    }
 
    cout<<sum;
    return 0;
}

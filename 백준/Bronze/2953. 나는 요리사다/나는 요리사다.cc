#include <iostream>

using namespace std;

int main(void) {
	int total[5]; 
	int num, max = 0, idx;
	
	for(int i = 0; i < 5; i++) {
		total[i] = 0;
        
		for(int j = 0; j <4; j++) {
			cin>>num;
			total[i] += num;
		}
        
		if(max<total[i]) {
			max = total[i];
			idx = i;
		}
	}
    
	cout << idx+1 << " " << max << "\n";
	return 0;
}
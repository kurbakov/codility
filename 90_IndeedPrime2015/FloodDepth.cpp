#include <iostream>
#include <vector>

int solution(std::vector<int> &A){
    int res=0;
    int low=0;
    int high=0;

    for(int i=0; i< A.size(); i++){
        if (A[i] >= high) {
            res = res < (high-low) ? (high-low) : res;
            low = high = A[i];
        } else if (A[i] < low) {
            low = A[i];
        } else if (A[i] > low) {
            res = res < (A[i]-low) ? (A[i]-low) : res;
        }
    }

    return res;
}


int main() {
    std::vector<int> v = {1,3,2,1,2,1,5,3,3,4,2};
    std::cout << solution(v) << "\n";
    return 0;
}

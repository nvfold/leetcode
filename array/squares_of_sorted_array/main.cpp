#include <iostream>
#include<vector>
using namespace std;

const int overMax =100000001;
    int posOfMaxSquare(vector<int>& nums){
        int pos = 0;
        for(;pos < nums.size() - 1; pos++){
          if(nums[pos]*nums[pos] < nums[pos+1]*nums[pos+1])
              break;
        }
        return pos;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>result;
        int pos = posOfMaxSquare(nums);
        result.push_back(nums[pos]*nums[pos]);
        int right = pos -1;
        int left = pos +1;
        while(right >=0 || left < nums.size()){
            int rightS = right >= 0 ? (nums[right]*nums[right]):overMax;
            int leftS = left < nums.size()?(nums[left]*nums[left]):overMax;
            if(rightS <= leftS){
                result.push_back(rightS);
                right--;
            }else{
                result.push_back(leftS);
                left++;
            }
        }
        return result;
    }
int main() {
    vector<int> test;
    test.push_back(-4);
    test.push_back(-4);
    test.push_back(-3);
    vector<int>result = sortedSquares(test);
    return 0;
}

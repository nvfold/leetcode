#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool checkIfExist(vector<int>& arr) {
    unordered_set<int> element;
    bool zero_is_found = false;

    for(int i = 0; i < arr.size(); i++){
        // bo qua phan tu 0 dau tien
        if(!zero_is_found && arr[i] == 0)
            continue;
        element.insert(arr[i]);
    }

    for(int i = 0; i < arr.size(); i++){
        if(element.find(arr[i] * 2) != element.end())
            return true;

        if(arr[i] % 2 == 0 && element.find(arr[i]/2) != element.end())
            return true;
    }
    return false;
}
int main() {
    vector<int> arr = {-2,0,10,-19,4,6,-8};
    cout << checkIfExist(arr) << endl;
    return 0;
}

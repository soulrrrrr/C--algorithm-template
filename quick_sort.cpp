#include <iostream>
#include <vector>
using namespace std;

// l, r 左閉右開
template<typename T>
void quick_sort(vector<T> &nums, int l, int r) {
    if (l >= r-1)
        return;
    
    int pivot = nums[r-1]; // choose pivot
    int i = l; // index of pivot will be
    for (int j = l; j < r-1; j++) {
        if (nums[j] < pivot) {
            swap(nums[i], nums[j]); // put smaller element to left
            i++;
        }
    }
    swap(nums[r-1], nums[i]);   // swap pivot to right place

    quick_sort(nums, l, i);     // l ~ i-1
    quick_sort(nums, i+1, r);   // i+1 ~ r-1
    return;
}


int main() {
    vector<int> a = {1, 5, 3, 6, 0, 45, 454, 3, 43, 4, 4543}; // demo
    quick_sort(a, 0, a.size());
    for (auto n : a) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
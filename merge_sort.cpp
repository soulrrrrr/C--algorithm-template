#include <iostream>
#include <vector>
#define MAX_NUM 10000
#define MAX_ITEM 100
using namespace std;

// l, r 左閉右開
template<typename T>
void merge_sort(vector<T> &nums, int l, int r, vector<T> &temp) {
    if (l >= r-1)
        return;
    int mid = l + (r - l) / 2;
    
    merge_sort(nums, l, mid, temp); // l ~ mid-1
    merge_sort(nums, mid, r, temp); // mid ~ r-1

    vector<T> left, right;
    for (int i = l; i < mid; i++) {
        left.push_back(nums[i]);
    }
    for (int i = mid; i < r; i++) {
        right.push_back(nums[i]);
    }
    int nv = l, nl = 0, nr = 0;
    while(nl < left.size() && nr < right.size()) {
        if (left[nl] < right[nr]) {
            nums[nv++] = left[nl++];
        }
        else
            nums[nv++] = right[nr++];
    }
    while(nl < left.size())
        nums[nv++] = left[nl++];
    while(nr < right.size())
        nums[nv++] = right[nr++];
    return;
}

int main() {
    vector<int> a;
    for(int i = 0; i < MAX_ITEM; i++) {
        a.push_back(rand() % MAX_NUM);
    }
    vector<int> temp(a.size(), 0);
    merge_sort(a, 0, MAX_ITEM, temp);
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}
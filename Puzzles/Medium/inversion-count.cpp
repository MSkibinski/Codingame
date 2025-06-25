// https://www.codingame.com/training/medium/inversion-count

#include <iostream>
#include <vector>

using namespace std;

long long merge_and_count_inversions(vector<int>& arr, int beg, int mid, int end) {
    long long inversions = 0;

    vector<int> left_arr(arr.begin() + beg, arr.begin() + mid + 1);
    vector<int> right_arr(arr.begin() + mid + 1, arr.begin() + end + 1);

    int i = 0, j = 0;
    int k = beg;
    const int leftSize = left_arr.size();
    const int rightSize = right_arr.size();
    while (i < leftSize && j < rightSize) {
        if (left_arr[i] <= right_arr[j])
            arr[k] = left_arr[i++];
        else {
            inversions += (leftSize - i);
            arr[k] = right_arr[j++];
        }
        k++;
    }
    while (i < leftSize)
        arr[k++] = left_arr[i++];
    while (j < rightSize)
        arr[k++] = right_arr[j++];

    return inversions;
}

long long merge_sort_and_count_inversions(vector<int>& arr, int beg, int end) {
    long long inversions = 0;
    if (beg < end) {
        int mid = (beg + end) / 2;
        inversions += merge_sort_and_count_inversions(arr, beg, mid);
        inversions += merge_sort_and_count_inversions(arr, mid + 1, end);
        inversions += merge_and_count_inversions(arr, beg, mid, end);
    }
    return inversions;
}

int main()
{
    long long M, A, X, N;
    cin >> M >> A >> X >> N;

    vector<int> arr(N);
    for (auto& elem : arr)
        elem = X = A * X % M;

    cout << merge_sort_and_count_inversions(arr, 0, N - 1) << endl;
}

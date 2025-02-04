#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define p pair<int, int>

stringstream ss;

void input(vi &container) {
    for (int i = 0; i < container.size(); i++) {
        cin >> container[i];
    }
}

void saveChangeContainer(vi &container, int left, int right) {
    for (int i = 0; i < container.size(); i++) {
        if (i == left) {
            ss << "[ " << container[i] << ' ';
        } else if (i == right) {
            ss << container[i] << " ] ";
        } else {
            ss << container[i] << ' ';
        }
    }
    ss << '\n';
}

void merge(vi &container, int left, int right, int partition) {
    vi vectorLeft(container.begin() + left, container.begin() + partition + 1);
    vi vectorRight(container.begin() + partition + 1, container.begin() + right + 1);

    int i = 0, j = 0, indexInContainer = left;
    while (i < vectorLeft.size() && j < vectorRight.size()) {
        if (vectorLeft[i] <= vectorRight[j]) {
            container[indexInContainer] = vectorLeft[i];
            i++; indexInContainer++;
        } else {
            container[indexInContainer] = vectorRight[j];
            j++; indexInContainer++;
        }

    }

    while (i < vectorLeft.size()) {
        container[indexInContainer] = vectorLeft[i];
        i++; indexInContainer++;
    }

    while (j < vectorRight.size()) {
        container[indexInContainer] = vectorRight[j];
        j++; indexInContainer++;
    }
}

void mergeSort(vi &container, int left, int right) {
    if (left >= right) {
        return;
    }

    int partition = (left + right) / 2;

    mergeSort(container, left, partition);
    mergeSort(container, partition + 1, right);

    merge(container, left, right, partition);
    saveChangeContainer(container, left, right);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vi container(n);
    input(container);
    mergeSort(container, 0, container.size() - 1);
    cout << ss.str();
}

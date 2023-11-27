#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Lecture {
    int start, end, index;
};

bool compareLectures(const Lecture &a, const Lecture &b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;

    vector<Lecture> lectures(n);

    for (int i = 0; i < n; i++) {
        cin >> lectures[i].start >> lectures[i].end;
        lectures[i].index = i + 1;
    }

    sort(lectures.begin(), lectures.end(), compareLectures);

    vector<int> chosenLectures;
    vector<int> backupLectures;

    int lastEnd = 0;

    for (int i = 0; i < n; i++) {
        if (lectures[i].start > lastEnd) {
            chosenLectures.push_back(lectures[i].index);
            lastEnd = lectures[i].end;
        } else {
            backupLectures.push_back(lectures[i].index);
        }
    }

    cout << chosenLectures.size() << endl;
    for (int i = 0; i < chosenLectures.size(); i++) {
        cout << chosenLectures[i] << " ";
        if (i < backupLectures.size()) {
            cout << backupLectures[i] << endl;
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}

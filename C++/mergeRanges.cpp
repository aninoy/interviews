#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Meeting {
private:
	unsigned int startTime;
	unsigned int endTime;

public:
	Meeting(unsigned int x, unsigned int y) : startTime(x),
		endTime(y) {
	}

	unsigned int getStartTime() const {
		return startTime;
	}

	unsigned int getEndTime() const {
		return endTime;
	}

	bool operator < (const Meeting& other) {
		return (startTime <= other.startTime);
	}
};

vector<Meeting> mergeSort(const vector<Meeting>& a) {

	if(a.size() < 2) {
		return a;
	}

	vector<Meeting> left(a.begin(), a.begin() + a.size() / 2);
	vector<Meeting> right(a.begin() + a.size()/2, a.end());

	left = mergeSort(left);
	right = mergeSort(right);
	int l = 0, r = 0;
	vector<Meeting> sorted;
	while(l < left.size() || r < right.size()) {
		if(l < left.size() && (r >= right.size() || left[l] < right[r])) {
			sorted.push_back(left[l]);
			l++;
		}
		else {
			sorted.push_back(right[r]);
			r++;
		}
	}

	return sorted;
}

vector<Meeting> mergeRanges(const vector<Meeting>& m) {
	int rangeStart = m.front().getStartTime();
	int rangeEnd = m.front().getEndTime();
	vector<Meeting> merged;

	for(int i = 1; i < m.size(); i++) {
		int curStart = m[i].getStartTime();
		int curEnd = m[i].getEndTime();

		if(curStart > rangeEnd) {
			merged.push_back(Meeting(rangeStart, rangeEnd));
			rangeStart = curStart;
			rangeEnd = curEnd;
		}
		else if(curStart < rangeStart && curEnd <= rangeEnd) {
			rangeStart = curStart;
		}
		else if(curEnd > rangeEnd && curStart >= rangeStart) {
			rangeEnd = curEnd;
		}
	}

	merged.push_back(Meeting(rangeStart, rangeEnd));
	return merged;
}

void printList(const vector<Meeting>& list) {
	for(int i = 0; i < list.size(); i++) {
		cout<<"("<<list[i].getStartTime()<<", "<<list[i].getEndTime()<<") ";
	}
	cout<<"\n";
}

int main(int argc, char const *argv[]) {
	vector<Meeting> meetings;
	meetings.push_back(Meeting(2,6));
	meetings.push_back(Meeting(1,10));
	meetings.push_back(Meeting(9,10));
	meetings.push_back(Meeting(3,5));
	meetings.push_back(Meeting(7,9));
	printList(meetings);
	meetings = mergeSort(meetings);
	printList(meetings);
	vector<Meeting> merged = mergeRanges(meetings);
	printList(merged);
	return 0;
}

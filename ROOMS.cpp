#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX_N = 1e5;

struct Event {
    int index, _time;
    bool isStart;
};

vector <Event> events;
int n;

void initEvents() {
    scanf("%d", &n);
    int _start, _finish;
    for (int i=1; i<=n; ++i) {
        scanf("%d%d", &_start, &_finish);
        events.push_back({i, _start, true});
        events.push_back({i, _finish, false});
    }
}

stack <int> availRooms;
vector < vector <int> > rooms(MAX_N);
int inProcess(0), maxRoom(-1), roomOfEvents[MAX_N+7];

void processEvents() {
    int roomNumber(0);
    for (auto &event: events) {
        if (event.isStart) {
            if (availRooms.empty())
                availRooms.emplace(++roomNumber);

            maxRoom = max(maxRoom, ++inProcess);

            rooms[availRooms.top()].emplace_back(event.index);
            roomOfEvents[event.index] = availRooms.top();
            availRooms.pop();
        }
        else {
            --inProcess;
            availRooms.emplace(roomOfEvents[event.index]);
        }
    }
}

void answer() {
    cout << maxRoom << '\n';
    for (int i=1; i<=n; ++i) {
        if (rooms[i].empty()) break;
        for (auto &eventIndex: rooms[i])
            cout << eventIndex << ' ';
        cout << '\n';
    }
}

int main() {
    freopen("ROOMS.INP", "r", stdin);
    freopen("ROOMS.OUT", "w", stdout);

    initEvents();
    sort(begin(events), end(events), [] (const Event &a, const Event &b) {
        return a._time < b._time || a._time == b._time && !a.isStart;
    });
    processEvents();
    answer();
}
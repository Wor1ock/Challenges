#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int time_to_park(int k, vector<int> &floors)
{
    int total_people = 0;
    for (int people_on_floor : floors)
        total_people += people_on_floor;

    int total_trips = ceil(static_cast<double>(total_people) / k);
    int trip_time = total_trips * 2;

    int max_floor = 0;
    for (int i = 0; i < floors.size(); i++)
        if (floors[i] > floors[max_floor])
            max_floor = i;

    return (total_trips - 1) * 2 * max_floor + trip_time;
}

int main()
{
    int k, n;
    cin >> k >> n;

    vector<int> floors(n);
    for (int i = 0; i < n; i++)
        cin >> floors[i];

    cout << time_to_park(k, floors) << endl;

    return 0;
}

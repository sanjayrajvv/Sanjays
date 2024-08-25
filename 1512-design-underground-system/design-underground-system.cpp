class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkInTime; 
    unordered_map<string, pair<double, int>> totalTime;
public:
    UndergroundSystem() {

    }
    
    void checkIn(int id, string stationName, int t) {
        checkInTime[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn = checkInTime[id];
        checkInTime.erase(id);

        string routName = checkIn.first + "#" + stationName;
        totalTime[routName].first += (t - checkIn.second);
        totalTime[routName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routName = startStation + "#" + endStation;
        auto route = totalTime[routName];

        return route.first / route.second;
    }
};
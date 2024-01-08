#include "../lib/metrics.hpp"

using namespace marcelb;

int main() {

    Metrics metrika;

    cout << " access " << metrika["access"]++ << endl;
    cout << " access " << metrika["access"]++ << endl;
    cout << " error " << metrika["error"] << endl;
    cout << " access " << metrika["access"] << endl;

    metrika.keys();

    cout << " error " << metrika["error"] << endl;
    cout << " access " << metrika["access"] << endl;

    // // init
    // Metrics stats;
    // // operator [] and increment ++
    // stats["access"]++;
    // // print couter access
    // cout << stats["access"];
    // // get counters names
    // auto listCounterNames = stats.keys();
    // // get all couters
    // auto data = stats.get_data();
    // // reset counters
    // stats.clear();
    // // set counters
    // map<string, uint> MyStats = {{"access", 3},{ "error", 0}};
    // stats.set(MyStats);
    // // get and clear all counters
    // auto dataWithClear = stats.get_data_and_clear();

    return 0;
}

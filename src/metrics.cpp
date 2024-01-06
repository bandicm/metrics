#include "../lib/metrics.hpp"

marcelb::Metrics::Metrics() {
}

marcelb::Metrics::Metrics(map<string, uint> _counters) {
    set(_counters);
}

void marcelb::Metrics::clear() {
    lock_guard<mutex> _io(io);
    counters.clear();
    return;
}

vector<string> marcelb::Metrics::keys() {
    vector<string> _keys;
    for (auto counter : counters) {
        _keys.push_back(counter.first);
    }

    return _keys;
}


map<string, uint> marcelb::Metrics::get_data() {
    return counters;
}


map<string, uint> marcelb::Metrics::get_data_and_clear() {
    auto data = counters;
    clear();
    return counters;
}
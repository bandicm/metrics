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


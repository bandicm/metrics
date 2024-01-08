
# A library for tracking statistics and metrics

A simple library for measuring incremental parameters in C++ programs based on the key-value principle.

## Features

- Object oriented
- Thread safe
- Easy access to counters using the [] operator
- Simple incrementing of counters using the ++ operator
- Initial setup of the list of counters and values
- List of counter names
- Retrieving the status of all counters
- Reset all counters
- Retrieving the state of all counters and resetting the counters
## Installation

Just download the latest release and unzip it into your project. You can turn it on with:

```
#include "metrics/lib/metrics.hpp"
using namespace marcelb;
```

## Usage

```c++
// init
Metrics stats;
// operator [] and increment ++
stats["access"]++;
// print couter access
cout << stats["access"];
// get counters names
auto listCounterNames = stats.keys();
// get all couters
auto data = stats.get_data();
// reset counters
stats.clear();
// set counters
map<string, uint> MyStats = {{"access", 3},{ "error", 0}};
stats.set(MyStats);
// get and clear all counters
auto dataWithClear = stats.get_data_and_clear();
```
## License

[APACHE 2.0](http://www.apache.org/licenses/LICENSE-2.0/)


## Support & Feedback

For support and any feedback, contact the address: marcelb96@yahoo.com.

## Contributing

Contributions are always welcome!

Feel free to fork and start working with or without a later pull request. Or contact for suggest and request an option.


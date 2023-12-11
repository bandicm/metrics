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


    return 0;
}
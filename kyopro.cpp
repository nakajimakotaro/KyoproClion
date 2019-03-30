#include <boost/algorithm/string/join.hpp>
#include <iostream>

using namespace std;
using namespace boost;

void Resolve(istream &is, ostream &os) {
    int i;
    is >> i;
    os << i * 2;
}

#if LOCAL
int main() { cin.tie(0); ios::sync_with_stdio(false); Resolve(cin, cout); cout.flush(); return 0;}
#endif


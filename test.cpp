#define BOOST_TEST_MAIN
#include <boost/algorithm/string/trim.hpp>
#include <boost/test/unit_test.hpp>
#include <regex>
#include "kyopro.h"

using namespace std;

struct Data;
void test(Data data);

struct Data
{
    std::string In;
    std::string Ok;
};

Data Data1 = {
        R"(
1
)",
        R"(
2
)",
};
Data Data2 = {
        R"(
5
)",
        R"(
10
)",
};
Data Data3 = {
        R"(
-3
)",
        R"(
-6
)",
};

BOOST_AUTO_TEST_CASE(Test1) {
    test(Data1);
}
BOOST_AUTO_TEST_CASE(Test2) {
    test(Data2);
}
BOOST_AUTO_TEST_CASE(Test3) {
    test(Data3);
}

void test(Data data)
{
    std::stringstream is;
    std::stringstream os;

    regex trimRegex(R"(\s*\n\s*)");
    auto inStr = regex_replace(data.In, trimRegex, "\n", regex_constants::match_any);
    boost::trim(inStr);
    is << inStr << '\n';

    Resolve(is, os);

    auto outData = regex_replace(os.str(), trimRegex, "\n");
    boost::trim(outData);
    auto okData = regex_replace(data.Ok, trimRegex, "\n");
    boost::trim(okData);

    BOOST_CHECK_EQUAL(outData, okData);
}
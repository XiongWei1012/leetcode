#define BOOST_TEST_MODULE SolutionTest

#include "solution.hpp"

//#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(SolutionSuite)

BOOST_AUTO_TEST_CASE(PlainTest1)
{
    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = Solution().merge(intervals);

    vector<vector<int>> expected{{1,6},{8,10},{15,18}};

    BOOST_REQUIRE_EQUAL(result.size(), expected.size());
    for (int i = 0; i < result.size(); ++i)
        BOOST_CHECK_EQUAL_COLLECTIONS(result[i].begin(), result[i].end(), expected[i].begin(), expected[i].end());
}

BOOST_AUTO_TEST_CASE(PlainTest2)
{
    vector<vector<int>> intervals{{1,4},{4,5}};
    vector<vector<int>> result = Solution().merge(intervals);

    vector<vector<int>> expected{{1,5}};

    BOOST_REQUIRE_EQUAL(result.size(), expected.size());
    for (int i = 0; i < result.size(); ++i)
        BOOST_CHECK_EQUAL_COLLECTIONS(result[i].begin(), result[i].end(), expected[i].begin(), expected[i].end());
}

BOOST_AUTO_TEST_SUITE_END()
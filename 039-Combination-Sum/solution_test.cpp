#define BOOST_TEST_MODULE SolutionTest

#include "solution.hpp"

//#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

struct less_than_key {
    inline bool operator() (const vector<int>& vec1, const vector<int>& vec2) {
        if (vec1.size() == vec2.size()) {
            for (int i = 0; i < vec1.size(); i++) {
                if (vec1[i] < vec2[i]) return true;
                else if (vec1[i] > vec2[i]) return false;
            }
            return true;
        } else if (vec1.size() < vec2.size()) {
            return true;
        } else {
            return false;
        }
    }
};

BOOST_AUTO_TEST_SUITE(SolutionSuite)

BOOST_AUTO_TEST_CASE(PlainTest1)
{
    vector<int> candidates{2,3,6,7};
    int target = 7;
    vector<vector<int>> result = Solution().combinationSum(candidates, target);

    vector<vector<int>> expected{
        {7},
        {2,2,3}
    };
    BOOST_CHECK_EQUAL(result.size(), expected.size());
    sort(result.begin(), result.end(), less_than_key());
    sort(expected.begin(), expected.end(), less_than_key());
    for (int i = 0; i < result.size(); i++)
        BOOST_CHECK_EQUAL_COLLECTIONS(result[i].begin(), result[i].end(), expected[i].begin(), expected[i].end());
}

BOOST_AUTO_TEST_SUITE_END()
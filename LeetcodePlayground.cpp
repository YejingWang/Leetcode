// Testing

#include "Problems/1_Two_Sum.h"	// change/add headers correspoding to different problems
#include <iostream>

int main()
{
    Solution s;

    // change the input according to the problem
    std::vector<int> input{ 3, 2, 4 };
    int target = 6;

    auto res = s.twoSum(input, target);

    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i] << std::endl;
    }

    return 0;
}

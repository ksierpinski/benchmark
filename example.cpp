#include <vector>
#include <unordered_set>

bool finderTrivial(const std::vector<int>& vec, int NUM)
{
    for (auto el1 = vec.begin(); el1 != vec.end(); ++el1)
    {
        for (auto el2 = el1 + 1; el2 != vec.end(); ++el2)
        {
            if (*el1 + *el2 == NUM)
            {
                return true;
            }
        }
    }
    return false;
}

bool finderUnorderedSet(const std::vector<int>& vec, int NUM)
{
    std::unordered_set<int> uset(vec.begin(), vec.end());

    for (const int el : uset)
    {
        const auto search = uset.find(NUM - el);
        if (search != uset.end())
            return true;
    }

    return false;
}


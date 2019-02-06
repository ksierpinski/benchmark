#include <gtest/gtest.h>
#include "example.cpp"

class ShortVectorTest : public ::testing::Test
{
protected:
    const std::vector<int> vec = {1, 2, 3};
};

TEST_F(ShortVectorTest, trivial)
{
    ASSERT_EQ(true, finderTrivial(vec, 3));
    ASSERT_EQ(true, finderTrivial(vec, 4));
    ASSERT_EQ(true, finderTrivial(vec, 5));

    ASSERT_EQ(false, finderTrivial(vec, 0));
    ASSERT_EQ(false, finderTrivial(vec, 1));
    ASSERT_EQ(false, finderTrivial(vec, 6));
}

TEST_F(ShortVectorTest, UnorderedSet)
{
    ASSERT_EQ(true, finderUnorderedSet(vec, 3));
    ASSERT_EQ(true, finderUnorderedSet(vec, 4));
    ASSERT_EQ(true, finderUnorderedSet(vec, 5));

    ASSERT_EQ(false, finderUnorderedSet(vec, 0));
    ASSERT_EQ(false, finderUnorderedSet(vec, 1));
//    ASSERT_EQ(false, finderUnorderedSet(vec, 6));
}


class ShortVectorWithDuplicationTest : public ::testing::Test
{
protected:
    void SetUp() override {}
    std::vector<int> vec = {1, 2, 3, 3};
};

TEST_F(ShortVectorWithDuplicationTest, trivial)
{
    ASSERT_EQ(true, finderTrivial(vec, 3));
    ASSERT_EQ(true, finderTrivial(vec, 4));
    ASSERT_EQ(true, finderTrivial(vec, 5));
    ASSERT_EQ(true, finderTrivial(vec, 6));

    ASSERT_EQ(false, finderTrivial(vec, 0));
    ASSERT_EQ(false, finderTrivial(vec, 1));
    ASSERT_EQ(false, finderTrivial(vec, 7));
}

TEST_F(ShortVectorWithDuplicationTest, UnorderedSet)
{
    ASSERT_EQ(true, finderUnorderedSet(vec, 3));
    ASSERT_EQ(true, finderUnorderedSet(vec, 4));
    ASSERT_EQ(true, finderUnorderedSet(vec, 5));
    ASSERT_EQ(true, finderUnorderedSet(vec, 6));

    ASSERT_EQ(false, finderUnorderedSet(vec, 0));
    ASSERT_EQ(false, finderUnorderedSet(vec, 1));
    ASSERT_EQ(false, finderUnorderedSet(vec, 7));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

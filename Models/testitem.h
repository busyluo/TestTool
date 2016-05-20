#ifndef TESTITEM_H
#define TESTITEM_H

/**
 * @brief 所有测试项的基类
 */

class TestItem {
    DISABLE_COPY(TestItem);
public:
    explicit TestItem();
    virtual ~TestItem();

    virtual void doTest() = 0;
    virtual void getTestResult() = 0;
};

#endif // TESTITEM_H

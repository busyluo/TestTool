#ifndef TESTITEM_H
#define TESTITEM_H

/**
 * @brief ���в�����Ļ���
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

#ifndef TESTMACHINE_H
#define TESTMACHINE_H

#include <vector>
#include <memory>

#include "testunit.h"

/**
 * @brief 代表一个测试机箱
 */

class TestMachine {
    DISABLE_COPY(TestMachine);
public:
    TestMachine();
    virtual ~TestMachine();

private:
    std::vector<std::unique_ptr<TestUnit>> _testUnits;
};

#endif // TESTMACHINE_H

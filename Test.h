#ifndef MERETDD_TEST_H
#define MERETDD_TEST_H

#include <string_view>
#include <iostream>
#include <vector>
#include <string>

namespace MereTDD {
    class TestBase {
    public:
        TestBase(std::string_view name)
                : mName(name), mPassed(true) {}

        virtual ~TestBase() = default;

        virtual void run() = 0;

        std::string_view name() const {
            return mName;
        }

        bool passed() const {
            return mPassed;
        }

        std::string_view reason() const {
            return mReason;
        }

        void setFailed(std::string_view reason) {
            mPassed = false;
            mReason = reason;
        }

    private:
        std::string mName;
        bool mPassed;
        std::string mReason;
    };

    inline std::vector<TestBase *> &getTests() {
        static std::vector<TestBase *> tests;
        return tests;
    }

    inline void runTests() {
        for (auto *test: getTests()) {
            std::cout << "---------------\n"
                      << test->name()
                      << std::endl;
            try {
                test->run();
            }
            catch (...) {
                test->setFailed("Unexpected exception thrown.");
            }
            if (test->passed()) {
                std::cout << "Passed"
                          << std::endl;
            } else {
                std::cout << "Failed\n"
                          << test->reason()
                          << std::endl;
            }
        }
    }
} // namespace MereTDD


#define TEST \
class Test : public MereTDD::TestBase \
{ \
public: \
    Test (std::string_view name) \
    : TestBase(name) \
    { \
        MereTDD::getTests().push_back(this); \
    } \
    void run () override; \
private: \
    std::string mName; \
    bool mResult; \
}; \
Test test("testCanBeCreated"); \
void Test::run ()
#endif // MERETDD_TEST_H

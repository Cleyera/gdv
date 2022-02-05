#ifndef GDV_UNIT_TEST_H_
#define GDV_UNIT_TEST_H_

class test_result {
public:

private:
};

class unit_test {
public:

private:
};

template <typename TestType>
class test_case {
public:
    test_case() = default;
    virtual ~test_case() {}
    test_result run() {return {};}
};

class test_fixture {
public:
    test_fixture()
};


#define GDV_TEST_CASE_NAME(test_name, test_suite) \
    test_case ## test_name ## test_suite


#define GDV_TEST_CASE(test_name, test_suite, test_fixture)          \
    template <typename TestType>                                    \
    class GDV_TEST_CASE_NAME(test_name, test_suite)                 \
        : public test_case<TestType> {                              \
    public:                                                         \
        test_result run();                                          \
    private:                                                        \
    };                                                              \
    test_result GDV_TEST_CASE_NAME(test_name, test_suite)::run()    \

#define TEST_CASE(test_name, test_suite)

#define TEST_CASE_F(test_name, test_fixture)

#endif

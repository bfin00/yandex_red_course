#include "test_runner.h"
#include <vector>

using namespace std;

// Реализуйте здесь шаблонный класс Table
template <typename T>
class Table
{
private:
    vector<vector<T>> data;
    size_t _i;
    size_t _j;
public:
    Table(const size_t& i, const size_t& j): _i(i), _j(j)
    {
        data.resize(i);
        for (auto& x: data)
            x.resize(j);
    }
    void Resize(const size_t& i, const size_t& j);
    pair<size_t, size_t> Size() const;
    vector<T> operator[](int i) const;
    vector<T>& operator[](int i);
};

template <typename T>
void Table<T>::Resize(const size_t& i, const size_t& j)
{
    data.resize(i);
    for (auto& x: data)
        x.resize(j);
    _i = i;
    _j = j;
}

template <typename T>
pair<size_t, size_t> Table<T>::Size() const
{
    if (_i == 0 || _j == 0)
        return make_pair<size_t, size_t>(0, 0);
    return make_pair(_i, _j);
}

template <typename T>
vector<T> Table<T>::operator[](int i) const
{
    return data.at(i);
}

template <typename T>
vector<T>& Table<T>::operator[](int i)
{
    return data.at(i);
}

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}


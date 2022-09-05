#include <stdexcept>
#include <vector>

using namespace std;


template <typename T>
class Deque
{
private:
    vector<T> _front;
    vector<T> _back;
public:
    Deque()
    {}
    bool Empty() const;
    size_t Size() const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    T& At(size_t index);
    const T& At(size_t index) const;

    T& Front();
    const T& Front() const;

    T& Back();
    const T& Back() const;

    void PushFront(const T& value);
    void PushBack(const T& value);

};
template <typename T>
void Deque<T>::PushFront(const T& value)
{
    _front.push_back(value);
}
template <typename T>
void Deque<T>::PushBack(const T& value)
{
    _back.push_back(value);
}
template <typename T>
T& Deque<T>::Front()
{
    if (!_front.empty())
        return _front.back();
    else
        return _back.front();
}
template <typename T>
const T& Deque<T>::Front() const
{
    if (!_front.empty())
        return _front.back();
    else
        return _back.front();
}

template <typename T>
T& Deque<T>::Back()
{
    if (!_back.empty())
        return _back.back();
    else
        return _front.front();
}
template <typename T>
const T& Deque<T>::Back() const
{
    if (!_back.empty())
        return _back.back();
    else
        return _front.front();
}

template <typename T>
bool Deque<T>::Empty() const
{
    return (_front.empty() && _back.empty());
}

template  <typename T>
size_t Deque<T>::Size() const
{
    return _front.size() + _back.size();
}

template <typename T>
T& Deque<T>::operator[](size_t index)
{
    if (index < _front.size())
        return _front.at(_front.size() - index - 1);
    else
        return _back.at(index - _front.size());
}

template  <typename T>
const T& Deque<T>::operator[](size_t index) const
{
    if (index < _front.size())
        return _front.at(_front.size() - index - 1);
    else
        return _back.at(index - _front.size());
}

template <typename T>
T& Deque<T>::At(size_t index)
{
    if (index > (_back.size() + _front.size() - 1))
        throw out_of_range("out of range");
    if (index < _front.size())
        return _front.at(_front.size() - index - 1);
    else
        return _back.at(index - _front.size());
}

template  <typename T>
const T& Deque<T>::At(size_t index) const
{
    if (index > (_back.size() + _front.size() - 1))
        throw out_of_range("out of range!");
    if (index < _front.size())
        return _front.at(_front.size() - index - 1);
    else
        return _back.at(index - _front.size());
}

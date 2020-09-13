#pragma once
#include <stddef.h>

template <typename T, int L>
class Iter; //Iter前置声明以定义CacheQueue中的begin, end迭代器

//模板参数T是数据元素的类型，L是CacheQueue可以包含的元素的最大数量
template <typename T, int L>
class CacheQueue
{
public:
    //类型别名
    using iterator = Iter<T, L>;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;

    //CacheQueue的默认构造函数
    CacheQueue()
    {
        size = 0;
    }

    //下标访问操作符的重载函数，返回元素的引用
    //下标的顺序由小到大，表示上次使用时间由远及近（即下标为0的元素是最长时间没有使用的元素）
    //例如，队列元素从最久未使用到最近使用的元素依次为2 7 3 4，那么2的偏移量就是0，7的偏移量就是1，依次类推
    reference operator[](size_type idx)
    {
        return queue[idx];
    }

    //使用值为val的元素，如果有多个元素具有相同的值，则本次使用的是最久未被使用过的元素
    void use(value_type val)
    {
        int i;
        for (i = 0; i < size; i++)
        {
            if (queue[i] == val)
                break;
        }
        if (i == size)
            return;
        T temp = queue[i];
        for (int j = i; j < size - 1; j++)
        {
            queue[j] = queue[j + 1];
        }
        queue[size - 1] = temp;
    }

    //向CacheQueue添加元素
    //当CacheQueue已满时，先pop出最长时间没有使用的元素，再加入新的元素
    //返回true表示添加前队列未满，返回false表示添加前队列已满
    bool push(value_type val)
    {
        if (L == 0)
            return false;
        if (size == L)
        {
            for (int i = 0; i < size - 1; i++)
            {
                queue[i] = queue[i + 1];
            }
            queue[size - 1] = val;
            return false;
        }
        else
        {
            queue[size] = val;
            size++;
            return true;
        }
    }

    //从CacheQueue取出元素
    //将最长时间没有使用到的元素pop出来
    //返回true表示取出成功，false表示队列调用pop前为空
    bool pop()
    {
        if (size == 0)
            return false;
        for (int i = 0; i < size - 1; i++)
        {
            queue[i] = queue[i + 1];
        }
        queue[size - 1] = {};
        size--;
        return true;
    }

    //返回迭代器对象begin，即指向最长时间未使用的元素的位置
    iterator begin()
    {
        Iter<T, L> iter(*this, 0);
        return iter;
    }

    //返回迭代器对象end，按照C++标准，end返回的迭代器对象指向最后一个元素的下一个位置，所以容器数据范围实际上是[begin,end)
    iterator end()
    {
        Iter<T, L> iter(*this, size);
        return iter;
    }

private:
    //...
    T queue[L + 1] = {};
    int size;
};

#pragma once
#include <stddef.h>
#include <iterator>
#include "CacheQueue.h"

template <typename T, int L>
class Iter
{
public:
    //���ͱ���������ɾ��������STL����Ϊ�������ڵ�����
    using container_type = CacheQueue<T, L>;
    using iterator = Iter<T, L>;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using iterator_category = std::forward_iterator_tag; //ǰ���������־

    //�������Ĺ��캯��
    //cq�ǵ�������Ӧ����������offset�ǵ�����ָ���������Ԫ�ص�λ�ã����õ�����ָ��Ԫ�ص��±�
    Iter(container_type& cq, difference_type offset)
    {
        val = &(cq[offset]);
    }

    //���ص�����������

    //�ж������������Ƿ���ȣ����Ƿ�ָ����ͬһ��������ͬһ��λ��
    bool operator==(const iterator& iter)
    {
        return val == iter.val;
    }
    bool operator!=(const iterator& iter)
    {
        return val != iter.val;
    }

    //��ֵ�����������غ���������ָ��ͬһ�������ĵ�����������ǰ��������������Ϊָ����iter��ͬ��λ�ã����ص�ǰ������������
    iterator& operator=(const iterator& iter)
    {
        val = iter.val;
        return *this;
    }

    //��ӷ��ʲ����������غ������൱�ڶ�ָ��ptr�ļ�ӷ��ʲ���*ptr�����ص�����ָ����������Ԫ�ص�����
    reference operator*()
    {
        return *val;
    }

    //ǰ����������������غ�������ʹ������ָ��ǰ����Ԫ�ص���һ��λ�ã��ٷ��ص�����������
    iterator& operator++()
    {
        ++val;
        return *this;
    }
    //������������������غ�����ʹ������ָ��ǰ����Ԫ�ص���һ��λ�ã������ص��ǵ���ǰ�ĵ������Ŀ���
    iterator operator++(int)
    {
        iterator temp = *this;
        ++(*this);
        return temp;
    }

private:
    //...
    T *val;
};

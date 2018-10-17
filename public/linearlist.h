#pragma once


/*
һ�����Ա�ĳ�����
*/
template<class T>
class LinearList
{
public:
	virtual ~LinearList() {}
	//����Ƿ�Ϊ��
	virtual bool empty()const = 0;
	//Ԫ�ظ���
	virtual int size()const = 0;
	//������������Ԫ��
	virtual T& get(int theIndex)const = 0;
	//����Ԫ�ص�һ�γ��ֵ�����
	virtual int indexOf(const T& theElement)const = 0;
	//��������ɾ��Ԫ��
	virtual void erase(int theIndex) = 0;
	//ָ����������Ԫ��
	virtual void insert(int theIndex, const T& theElement) = 0;
	//���
	virtual void output(std::ostream& out)const = 0;
};
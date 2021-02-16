#pragma once
/// <summary>
/// smart pointers
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class SmartPointer
{
public:
	SmartPointer(T* ptr)
	{
		this->ptr = ptr;
		cout << "Constructor" << endl;
	}
	~SmartPointer()
	{
		delete ptr;
		cout << "Destructor" << endl;
	}

	T& operator*()
	{
		return *ptr;
	}

private:
	T* ptr;
};
#pragma once

template<typename T>
class CSingleton
{
protected:
	CSingleton() noexcept = default;
	CSingleton(const CSingleton&) = delete;
	CSingleton& operator=(const CSingleton&) = delete;
	virtual ~CSingleton() = default;
public:
	static T& get() noexcept(std::is_nothrow_constructible<T>::value)
	{
		static T s;
		return s;
	}
};

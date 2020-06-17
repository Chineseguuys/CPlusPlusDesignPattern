// C++ 11 版本之后的跨平台的实现 （volatile）
#include <atomic>
#include <mutex>

class Singleton{
private:
	/**
	 * 将构造函数和拷贝构造函数设置为私有，防止外部公开声明这个对象
	*/
	Singleton();
	Singleton(const Singleton& other);
public:
	static std::atomic<Singleton*>		m_instance;
	static std::mutex 					m_mutex;
	static Singleton* 					getInstance();
};

// C++ 11 所实现的双检查锁
Singleton*  Singleton::getInstance(){
	Singleton* temp = m_instance.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);    // 获取内存 fence
	if (temp == nullptr)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		temp = m_instance.load(std::memory_order_relaxed);
		if (temp == nullptr)
		{
			temp = new Singleton();
			std::atomic_thread_fence(std::memory_order_release);
			m_instance.store(temp, std::memory_order_relaxed);  // 释放内存 fence
		}
	}
	return temp;
}
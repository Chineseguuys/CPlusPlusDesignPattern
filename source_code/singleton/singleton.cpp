class Singleton{
private:
	/**
	 * 将构造函数和拷贝构造函数设置为私有，防止外部公开声明这个对象
	*/
	Singleton();
	Singleton(const Singleton& other);
public:
	static Singleton*   getInstance();
	static Singleton*   m_instance;
};

Singleton* Singleton::m_instance = nullptr;

//线程非安全版本
/**
 * 如果有多个线程同时访问这个函数，可能会导致
 * 生成多个 Singleton 对象
*/
Singleton* Singleton::getInstance(){
	if (Singleton::m_instance == nullptr)
		m_instance = new Singleton();
	
	return Singleton::m_instance;
}

// 线程安全版本，但是锁的代价过高
Singleton* Singleton::getInstance(){
	Lock lock;	// 表示加锁的动作，实际锁不是这样实现的
	if (Singleton::m_instance == nullptr)
		m_instance = new Singleton();
	
	return Singleton::m_instance;
}

// 双检查锁，但是由于内存的 reorder 不安全 不可以使用
/**
 * Reorder:
 * 编译器在进行优化的过程中，可能会改变代码原有的执行逻辑顺序，比方说，new Singleton() 的过程从
 * 逻辑上讲应该是三个步骤：第一步，分配堆上的内存空间，第二步，调用相应的构造器进行构造，第三步，返回相应内存地址的指针
 * 但是编译器可能会对这样的过程进行优化，reorder之后的步骤可能变成下面的：
 * 第一步，分配堆上的内存；第二步，返回这段内存的地址；第三步，调用相应的构造器
 * 
 * 使用双检查锁的话，就会出现相应的问题。thread_a 构建对象，返回了内存的指针，但是还没有调用相应的构造器，
 * 此时 thread_b 读取发现对象不是 nullptr,认为对象完成了构造，返回对象地址，并进行使用，就会出错
*/
Singleton* Singleton::getInstance(){
	if (Singleton::m_instance == nullptr)
	{
		Lock lock;
		if (Singleton::m_instance == nullptr)
			Singleton::m_instance = new Singleton();
	}
	return Singleton::m_instance;
}
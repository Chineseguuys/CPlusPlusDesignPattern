/**
 * 目标接口（新的接口）
*/
class ITarget{
public:
	virtual void process() = 0;
};

// 遗留接口（旧的接口）
class IAdaptee{
public:
	virtual void foo(int data) = 0;
	virtual int bar() = 0;
};

// 遗留的具体类
class OldClass : public IAdaptee{
public:
	virtual void foo(int data){
		// ....
	}
	virtual int bar() {
		// ....
	}
};

// 对象适配器
class IAdaptor : public ITarget{	// 继承
protected:
	IAdaptee* pAdaptee;	// 组合
	/**
	 * 对象适配器：通过组合对象来实现的
	*/
public:

	IAdaptor(IAdaptee * adaptor){
		this->pAdaptee = adaptor;
	}

	virtual void process(){
		/**
		 * 这只是简单的表示一种可能的形式，实际当中的实现往往非常的复杂
		 * 有时候可能需要多个旧的接口来实现一个新的接口的功能
		*/
		int data = pAdaptee->bar();
		pAdaptee->foo(data);
	}
};

// 类适配器
/**
 * 类适配器往往采用的是多继承的实现方案，所以不推荐使用
*/
class Adaptor : public ITarget, protected OldClass{	// 多继承
public:
	virtual void process(){
		/**
		 * 这只是简单的表示一种可能的形式，实际当中的实现往往非常的复杂
		 * 有时候可能需要多个旧的接口来实现一个新的接口的功能
		*/
		int data = OldClass::bar();
		OldClass::foo(data);
	}
};

int main()
{
	IAdaptee* pAdaptor = new OldClass();
	
	ITarget* pTarget = new IAdaptor(pAdaptor);
	pTarget->process();
	// ....
}

/**
 * 比如说在 stl 当中，stl 首先实现了一个双端队列的基类  __split_buffer，并实现了一系列的高效的插入
 * __split_buffer 是一个以块为单位管理内存空间的对象，每一个块具有合适的大小，可以存储多个数据
 * 删除迭代操作的方法。
 * dequeue / stack / queue 都在这个基类的基础上进行设计，完成自己相应的操作逻辑。这实际上也可以看作是一种
 * 适配器模式的应用
*/
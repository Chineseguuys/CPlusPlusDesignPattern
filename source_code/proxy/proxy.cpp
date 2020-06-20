class ISubject
{
public:
	virtual void process();
};

/**
 * Proxy 的设计往往十分的复杂，大部分的情况下都是使用某些工具来自动的生成
 * 这里只是一个简单的示例
*/
class SubjectProxy : public ISubject
{
	//RealSubject		realSubject;
	/**
	 * 如果只是处于安全设计方面的考虑 或者效率方面的考虑（保护代理，智能指引等），可能这里会保留真正的对象的实例
	 * 如果是分布式的，可能这个实例都没有，只能通过一些网络访问获取某些实例相关的信息
	*/
	/**
	 * 远程代理使用网络协议，向客户端隐藏了对象不在本地计算机的事实，让客户程序感觉本地存在一个实例对象。
	*/
	/**
	 * 保护代理往往会设置对象访问的权限，让拥有不同权限的客户端访问不同的服务。
	*/
public:
	virtual void process()
	{
		// 对 realsubject 的间接访问
		// ...
		/**
		 * 这种间接的访问往往很复杂，比如说分布式的程序中，可能要完成一些网络协议和数据传输
		*/
	}
};

class ClientApp{
	ISubject* subject;
public:
	ClientApp(){
		this->subject = new SubjectProxy();
	}
	void doTask(){
		// .....
		this->subject->process();
		// .....
	}
};

/**
 * copy-on-write:
 * 	以字符串类型作为例子，某些字符串的实现往往在拷贝的过程中是进行浅拷贝，即拷贝的对象只维持原始对象的一个指针，自己并不
 * 开辟新的空间去存储字符串。这种拷贝的问题就在于当要修改字符串的时候，就面临着可能导致多个字符串对象的内容同时被修改。
 * copy-on-write:指的就是在进行字符串的修改的时候，进行一次字符串的深拷贝，丢弃以前使用的指针。在深拷贝的对象上进行修改
*/

/**
 * WEB 当中的 REST 架构
*/
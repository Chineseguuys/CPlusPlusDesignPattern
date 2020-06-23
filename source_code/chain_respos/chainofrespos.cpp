#include <iostream>
#include <string>

using namespace std;

enum class ResquestType
{
	REQ_HANDLER1,
	REQ_HANDLER2,
	REQ_HANDLER3
};

class Reqest
{
	string description;
	ResquestType  reqType;
public:
	Reqest(const string& desc, ResquestType type): description(desc), reqType(type) {}
	ResquestType getReqType() const { return this->reqType; }
	const string& getDescription() const { return this->description; }
};

class ChainHandler
{
	/**
	 * 一个多态的链表
	*/
	ChainHandler* nextChain;
	/**
	 * 自己处理不了，把请求送给链表的下一个对象
	*/
	void sendReqestToNoextHandler(const Reqest& req)
	{
		if (nextChain != nullptr)
			nextChain->handle(req);
	}

protected:
	/**
	 * 具体类应该实现这个方法
	*/
	virtual bool canHandleRequest(const Reqest& req) = 0;
	virtual void processRequest(const Reqest& req) = 0;
public:
	ChainHandler() { this->nextChain = nullptr; }
	void setNextChain(ChainHandler* next) { this->nextChain = next; }
	/**
	 * 整体的处理逻辑：如果我可以处理请求，我就进行处理；如果我处理不了的话，那么我们就将请求传递给下一个节点处理
	*/
	void handle(const Reqest& req)
	{
		if (canHandleRequest(req))
			processRequest(req);
		else 
			sendReqestToNoextHandler(req);
	}
};


class Handle1 : public ChainHandler
{
protected:
	bool canHandleRequest(const Reqest& req){
		/**
		 * 当然子类中判断是否处理请求有很多的方法，这里采用了一种简单的方式。
		 * 做一次简单的类型检查，类型匹配上就进行处理
		*/
		return req.getReqType() == ResquestType::REQ_HANDLER1;
	}
	void processRequest(const Reqest& req){
		cout << req.getDescription() << endl;	/*非常简单的处理逻辑，打印一行字符*/
	}
};


class Handle2 : public ChainHandler
{
protected:
	bool canHandleRequest(const Reqest& req){
		/**
		 * 当然子类中判断是否处理请求有很多的方法，这里采用了一种简单的方式。
		 * 做一次简单的类型检查，类型匹配上就进行处理
		*/
		return req.getReqType() == ResquestType::REQ_HANDLER2;
	}
	void processRequest(const Reqest& req){
		cout << req.getDescription() << endl;	/*非常简单的处理逻辑，打印一行字符*/
	}
};

class Handle3 : public ChainHandler
{
protected:
	bool canHandleRequest(const Reqest& req){
		/**
		 * 当然子类中判断是否处理请求有很多的方法，这里采用了一种简单的方式。
		 * 做一次简单的类型检查，类型匹配上就进行处理
		*/
		return req.getReqType() == ResquestType::REQ_HANDLER3;
	}
	void processRequest(const Reqest& req){
		cout << req.getDescription() << endl;	/*非常简单的处理逻辑，打印一行字符*/
	}
};

int main()
{
	Handle1 h1;
	Handle2 h2;
	Handle2 h3;
	h1.setNextChain(&h2);
	h2.setNextChain(&h3);

	Reqest req("process task ...", ResquestType::REQ_HANDLER2);
	h1.handle(req);
	return 0;
}
#include <iostream>
using namespace std;

#define SAFE_DELETE(p) if (p) { delete p; p = NULL; }

class Mediator;	/**这是一个中介者接口，负责各个实例类之间的交互过程*/

/**
 * 是实例类的接口
*/
class Colleague
{
public:
	Colleague(Mediator *pMediator) : m_pMediator(pMediator){}

	virtual void Send(wchar_t *message) = 0;

protected:
	/**
	 * 关键
	*/
	Mediator *m_pMediator;	/*接口中存储中介对象的接口*/
};

class ConcreteColleague1 : public Colleague
{
public:
	ConcreteColleague1(Mediator *pMediator) : Colleague(pMediator){}

	void Send(wchar_t *message);

	void Notify(wchar_t *message)
	{
		wcout<<message<<endl;
	}
};

class ConcreteColleague2 : public Colleague
{
public:
	ConcreteColleague2(Mediator *pMediator) : Colleague(pMediator){}

	void Send(wchar_t *message);

	void Notify(wchar_t *message)
	{
		cout<<"ConcreteColleague2 is handling the message."<<endl;
		wcout<<message<<endl;
	}
};

/**
 * 中介者的接口
*/
class Mediator
{
public:
	virtual void Sent(wchar_t *message, Colleague *pColleague) = 0;
};

class ConcreteMediator : public Mediator
{
public:
	// The mediator forward the message
	 void Sent(wchar_t *message, Colleague *pColleague)
	{
		ConcreteColleague1 *pConcreteColleague1 = dynamic_cast<ConcreteColleague1 *>(pColleague);
		/**
		 * 动态类型转化会进行类型的检测，如果 pColleague 的实际类型是 ConcreteColleague1 类型，那么可以转化成功
		 * 否则的话，返回 NULL
		*/
		if (pConcreteColleague1)
		{
			/**ConcreteColleague1 给 ConcreteColleague2 发送消息*/
			cout<<"The message is from ConcreteColleague1. Now mediator forward it to ConcreteColleague2"<<endl;
			if (m_pColleague2)
			{
				m_pColleague2->Notify(message);
			}
		}
		else
		{
			/*ConcreteColleague2 给 ConcreteColleague1 发送消息*/
			if (m_pColleague1)
			{
				m_pColleague1->Notify(message);
			}
		}
	}

	void SetColleague1(Colleague *pColleague)
	{
		m_pColleague1 = dynamic_cast<ConcreteColleague1 *>(pColleague);
	}

	void SetColleague2(Colleague *pColleague)
	{
		m_pColleague2 = dynamic_cast<ConcreteColleague2 *>(pColleague);
	}

private:
	/**
	 * 关键：
	 * Mediator 要有能力联系到所有的相互关联的对象
	*/
	ConcreteColleague1 *m_pColleague1;
	ConcreteColleague2 *m_pColleague2;
};
/**
 * 实际当中，相互交互的类可能不止有两种，另外两者之间的交互也不仅仅是简单的消息传递的过程
 * 上面的例子用两个类简单的说明其原理
 * 实际当中相互交互的类，往往没有共同的接口
*/

void ConcreteColleague1::Send(wchar_t *message)
{
	/**
	 * 第二个参数告诉了中介者，消息来自于哪里
	*/
	m_pMediator->Sent(message, this);
}

void ConcreteColleague2::Send(wchar_t *message)
{
	m_pMediator->Sent(message, this);
}

int main()
{
	 // Create the mediator
	 Mediator *pMediator = new ConcreteMediator();

	 Colleague *pColleague1 = new ConcreteColleague1(pMediator);
	 Colleague *pColleague2 = new ConcreteColleague2(pMediator);

	 ConcreteMediator *pConcreteMediator = dynamic_cast<ConcreteMediator *>(pMediator);
	 pConcreteMediator->SetColleague1(pColleague1);
	 pConcreteMediator->SetColleague2(pColleague2);

	 wchar_t message[260] = L"Where are you from?";
	 pColleague1->Send(message);

	 return 0;
}
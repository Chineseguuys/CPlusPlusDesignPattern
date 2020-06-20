class ISubject
{
public:
	virtual void process();
};


class RealSubject : public ISubject
{
public:
	virtual void process()
	{
		// .......
	}
};

class ClientApp{
	ISubject* subject;
public:
	ClientApp(){
		this->subject = new RealSubject();
		/**
		 * 在某些情况下，我们可能由于各种原因，导致我们无法拿到这个 RealSubject
		 * 可能是分布式的原因，因可能是安全控的原因
		*/
	}

	void doTask(){
		// .....
		this->subject->process();
		// .....
	}
};
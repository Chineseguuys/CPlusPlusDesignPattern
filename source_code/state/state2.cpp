class NetworkState
{
public:
	NetworkState* pNext;
	virtual void Operator1() = 0;
	virtual void Operator2() = 0;
	virtual void Operator3() = 0;

	virtual ~NetworkState() {}
};

class OpenState : public NetworkState
{
	static NetworkState* m_instance;
public:
	static NetworkState* get_instance(){
		if (m_instance == nullptr){
			m_instance = new OpenState();
		}
		return m_instance;
	}

	virtual void Operator1(){
		// *******
		pNext = CloseState::get_instance();
	}

	virtual void Operator2(){
		// *******
		pNext = ConnectState::get_instance();
	}

	virtual void Operator3(){
		// ******
		pNext = OpenState::get_instance();
	}
};

class CloseState : public NetworkState
{
	static NetworkState* m_instance;
public:
	static NetworkState* get_instance(){
		if (m_instance == nullptr){
			m_instance = new CloseState();
		}
		return m_instance;
	}

	virtual void Operator1(){
		// ********
		pNext = ConnectState::get_instance();
	}

	virtual void Operator2(){
		// *******
		pNext = OpenState::get_instance();
	}

	virtual void Operator3(){
		// ******
		pNext = CloseState::get_instance();
	}
};

class ConnectState : public NetworkState
{
	static NetworkState* m_instance;
public:
	static NetworkState* get_instance(){
		if (m_instance == nullptr){
			m_instance = new CloseState();
		}
		return m_instance;
	}

	virtual void Operator1(){
		// ********
		pNext = OpenState::get_instance();
	}

	virtual void Operator2(){
		// *******
		pNext = CloseState::get_instance();
	}

	virtual void Operator3(){
		// ******
		pNext = ConnectState::get_instance();
	}
};

/**
 * 如果这个时候我们增加了一个状态 Network_Wait
*/
// 扩展（变化的部分）
class WaitState : public NetworkState{
	/* 实现相应的方法就可以了，其他的地方不需要进行任何的变化*/
};

/*稳定*/
class NetworkProcessor{
	NetworkState* pState;
public:
	NetworkProcessor(NetworkState* state){
		this->pState = state;
	}

	void Operator1(){
		// *******
		pState->Operator1();
		pState = pState->pNext;	/*这里实现了状态的转换*/
		// *******
	}

	void Operator2(){
		// *******
		pState->Operator2();
		pState = pState->pNext;	/*这里实现了状态的转换*/
		// *******
	}

	void Operator3(){
		// *******
		pState->Operator3();
		pState = pState->pNext;	/*这里实现了状态的转换*/
		// *******
	}
};
enum NetworkState
{
	Network_Open,
	Network_Closed,
	Network_Connect
	/**
	 * 如果这里面再增加状态的话，如何进行处理
	 * 例如 : Network_Wait
	*/
};

class NetworkProcessor{
	NetworkState state;
public:
	void operator1(){
		/**
		 * 操作会造成状态之间的转换
		 * 不同的操作，会造成不同逻辑的状态转换
		*/
		if (state == Network_Open)
		{
			// *****
			state = Network_Closed;
		}
		else if (state == Network_Closed)
		{
			// *****
			state = Network_Connect;
		}
		else if (state == Network_Connect)
		{
			// ******
			state = Network_Open;
		}
	}

	void operator2(){
		/**
		 * 另外一种状态的改变
		*/
		if (state == Network_Closed){
			// *******
			state = Network_Open;
		}
		else if (state == Network_Connect)
		{
			// *******
			state = Network_Closed;
		}
		else if (state == Network_Open){
			// *******
			state = Network_Connect;
		}
	}
};
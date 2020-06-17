class House{
public:
	/**
	 * 流程是稳定的
	*/
	void Init(){
		this->BuildPart1();

		for (int i = 0; i < 4; ++i)
		{
			this->BuildPart2();
		}
		bool flag = this->BuildPart3();
		if (flag)
			this->BuildPart4();
		this->BuildPart5();
	}

protected:
	/**
	 * 每个步骤内部又是变化的
	*/
	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual bool BuildPart3() = 0;
	virtual void BuildPart4() = 0;
	virtual void BuildPart5() = 0;
};


class StoneHouse : public House{
protected:
	virtual void BuildPart1(){
		// ....
	}
	virtual void BuildPart2(){
		// ....
	}
	virtual bool BuildPart3(){
		// ....
	}
	virtual void BuildPart4(){
		// ....
	}
	virtual void BuildPart5(){
		// ....
	}
};


int main(int argc, char* argv[], char* env[])
{
	House* pHouse = new StoneHouse();
	pHouse->Init();
	// ....
}
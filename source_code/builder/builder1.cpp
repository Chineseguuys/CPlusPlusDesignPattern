/**
 * 属性和状态，属性和状态是稳定的
*/
class House{
	// ....
	/**
	 * House 当中有大量的属性，门，窗，墙，地砖，屋顶等等
	*/
};


/**
 * 抽象
*/
class HouseBuilder{
public:
	House* GetResult(){
		return this->pHouse;
	}
	virtual ~HouseBuilder() {}

	friend class HouseDirector;		// ...

protected:
	House* pHouse;
	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual bool BuildPart3() = 0;
	virtual void BuildPart4() = 0;
	virtual void BuildPart5() = 0;
};

/**
 * 具体类，不同类型的房子的构建过程是变化的
*/
class StoneHouseBuilder : public HouseBuilder{
protected:
	virtual void BuildPart1(){
		//pHouse->......... = ........
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

/**
 * 具体类
*/
class DiamondHouserBuilder : public HouseBuilder{
	// 也要实现上面的 5 个方法 BuildPart*()
};

/**
 * 这一部分是稳定的，这一部分不随着需求的变化而发生变化
*/
class HouseDirector{
public:
	HouseBuilder* pHouseBuilder;

	HouseDirector(HouseBuilder* houseBuilder)
	{
		this->pHouseBuilder = houseBuilder;
	}
	 
	House* Construct(){
		pHouseBuilder->BuildPart1();

		for (int i = 0; i < 4; ++i)
		{
			pHouseBuilder->BuildPart2();
		}
		bool flag = pHouseBuilder->BuildPart3();
		if (flag)
			pHouseBuilder->BuildPart4();
		pHouseBuilder->BuildPart5();

		return pHouseBuilder->GetResult();
	}
};



int main(int argc, char* argv[], char* env[])
{
	StoneHouseBuilder*	stoneHouseBuilder = new StoneHouseBuilder();	// 变化的部分 main 中，依赖处在最上层
	HouseDirector		houseDirector(stoneHouseBuilder);
	House* 				house = houseDirector.Construct();
}
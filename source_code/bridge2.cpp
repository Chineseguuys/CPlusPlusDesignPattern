
class string {/*具体的实现省略*/};
class Image {/*具体的实现省略*/};

/**
 * 将 bridge1 中的 Messager 拆分为两个抽象基类
 * 将两部分的实现分割开
*/
class Messager{
protected:
	MessagerImp* messagerImp;
public:
	Messager(MessagerImp* imp) : messagerImp(imp) {}
	/**
	 * 这里的几个方法是抽象层面的方法，其不考虑平台的差异性
	*/
	virtual void Login(string username, string password) = 0;
	virtual void SendMessage(string message) = 0;
	virtual void SendPicture(Image image) = 0;

	virtual ~Messager() {}
};

class MessagerImp{
public:
	/**
	 * 这几个函数在不同的平台下具有不同的实现方法
	*/
	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~MessagerImp() {}
};

//平台实现 n
/**
 * 平台的实现是一个需求变化的方向
 * 除了 PC 端，mobile 端，可能以后还会增加 Linux 端， Mac 端等等
*/
class PCMessagerImp : public MessagerImp{
public:
	virtual void PlaySound(){
		// ********
	}
	virtual void DrawShape(){
		// **********
	}
	virtual void WriteText(){
		// **********
	}
	virtual void Connect(){
		// **********
	}
};

class MobileMessagerImp : public MessagerImp{
public:
	virtual void PlaySound(){
		// =========
	}
	virtual void DrawShape(){
		// =========
	}
	virtual void WriteText(){
		// =========
	}
	virtual void Connect(){
		// =========
	}
};

// 业务抽象 m
/**
 * 业务层面上，我们的软件设计有一个简洁版本 lite,和一个华丽版本 Perfect
 * 比如 ： 轻聊版 / 完整版
 * 实际当中可能有更加复杂的分类方式
*/
/**
 * 业务的抽象也是一个需求变化的方向
 * 除了 Lite 版和 Perfect 版， 以后可能会增加 企业版，学校版，监狱版等等
*/
/**
 * 上面的两种需求结合起来就会有构成大量的需求类别：例如 企业Lite版，监狱Perfect版
*/
// 类的数目 1 + n + m

class MessagerLite : public Messager{
public:

	MessagerLite(MessagerImp* imp) : Messager(imp){}

	virtual void Login(string username, string password){
		messagerImp->Connect();
		// ...........
	}
	virtual void SendMessage(string message){
		messagerImp->WriteText();
		// ...............
	}
	virtual void SendPicture(Image image){
		messagerImp->DrawShape();
		// ............
	}
};

class MessagerPerfect : public Messager{
public:

	MessagerPerfect(MessagerImp* imp) : Messager(imp) {}

	virtual void Login(string username, string password){
		messagerImp->PlaySound();
		// ***********
		messagerImp->Connect();
		// ...........
	}
	virtual void SendMessage(string message){
		messagerImp->PlaySound();
		// *********
		messagerImp->WriteText();
		// ...............
	}
	virtual void SendPicture(Image image){
		messagerImp->PlaySound();
		// ***********
		messagerImp->DrawShape();
		// ............
	}
};


void process(){
	// 运行时装配
	MessagerImp* pcImp = new PCMessagerImp();
	MessagerImp* mImp = new MobileMessagerImp();

	Messager* m1 = new MessagerLite(pcImp);	// lite 版本 PC 端
	Messager* m2 = new MessagerLite(mImp);	// lite 版本 mobile 端

	Messager* m3 = new MessagerPerfect(pcImp); // perfect 版本 PC 端
} 
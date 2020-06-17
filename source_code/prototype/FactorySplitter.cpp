//抽象
class ISplitter{
public:
	virtual void split() = 0;
	virtual ISplitter* clone() = 0; // 通过克隆自己来创建对象
	virtual ~ISplitter() {}
};

// 具体类
class BinarySplitter : public ISplitter{
public:
	virtual void split(){
		//.....
	}
	virtual ISplitter* clone(){
		return new BinarySplitter(*this);	// 调用自身的拷贝构造函数
	}
};

class TxtSplitter : public ISplitter{
public:
	virtual void split(){
		// ******
	}
	virtual ISplitter* clone(){
		return new TxtSplitter(*this);	// 调用自身的拷贝构造函数
	}
};

class PictureSplitter : public ISplitter{
public:
	virtual void split(){
		// ....
	}
	virtual ISplitter* clone(){
		return new PictureSplitter(*this);	// 调用自身的拷贝构造函数
	}
};

class VideoSplitter : public ISplitter{
public:
	virtual void split(){
		// .......
	}
	virtual ISplitter* clone(){
		return new VideoSplitter(*this);	// 调用自身的拷贝构造函数
	}
};



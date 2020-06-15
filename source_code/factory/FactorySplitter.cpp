//抽象
class ISplitter{
public:
	virtual void split() = 0;
	virtual ~ISplitter() {}
};

//抽象
class SplitterFactory{
public:
	virtual ISplitter* CreateSplitter() = 0;
	virtual ~SplitterFactory() {}
};

// 具体类
class BinarySplitter : public ISplitter{
public:
	virtual void split(){
		//.....
	}
};

class TxtSplitter : public ISplitter{
public:
	virtual void split(){
		// ******
	}
};

class PictureSplitter : public ISplitter{
public:
	virtual void split(){
		// ....
	}
};

class VideoSplitter : public ISplitter{
public:
	virtual void split(){
		// .......
	}
};

/**
 * 每一个具体的类，都有一个自己具体的工厂类
*/
// 具体工厂
class BinarySplitterFactory : public SplitterFactory{
public:
	virtual ISplitter* CreateSplitter(){
		return new BinarySplitter();
	}
};

class TxtSplitterFactory : public SplitterFactory{
public:
	virtual ISplitter* CreateSplitter(){
		return new TxtSplitter();
	}
};
 
class PictureSplitterFactory : public SplitterFactory{
public:
	virtual ISplitter* CreateSplitter(){
		return new PictureSplitter();
	}
};

class VideoSplitterFactory : public SplitterFactory{
public:
	virtual ISplitter* CreateSplitter(){
		return new VideoSplitter();
	}
};


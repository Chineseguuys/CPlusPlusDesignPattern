class ISplitter{
public:
	virtual void split() = 0;
	virtual ~ISplitter() {}
};

class BinarySplitter : public ISplitter{
public:
	// 构造方法
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
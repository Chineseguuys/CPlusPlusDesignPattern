// 业务操作
class Stream{
public:
	virtual char Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;

	virtual ~Stream() {}
};

/**
 * 不同的数据流的实现是各不相同的，但是加密的操作和缓冲的操作往往都是针对的二进制的数据流，对于不同的
 * 数据流的类型，加密的操作和缓冲的操作的过程往往是相同的，这有利于我们减少一定的冗余
*/
/**
 * 对于不同的流，具有不同的实现的方式
*/
//主体类
class FileStream : public Stream{
public:
	virtual char Read(int number){
		// 读文件
	}

	virtual void Seek(int position){
		//定位文件流
	}

	virtual void Write(char data){
		// 写文件
	}
};

class NetworkStream : public Stream{
public:
	virtual char Read(int number){
		// 读网络流
	}

	virtual void Seek(int position){
		//定位网络流
	}

	virtual void Write(char data){
		// 写网络流
	}
};

class MemoryStream : public Stream{
public:
	virtual char Read(int number){
		// 读内存流
	}

	virtual void Seek(int position){
		//定位内存流
	}

	virtual void Write(char data){
		// 写内存流
	}
};

/**
 * 让代码在编译时期具有相同的结构，而变化通过运行时期的多态的动态绑定来实现
*/
//扩展操作
class CryptoStream : public Stream{

	/*关键*/
	Stream* stream; // = new ***Stream();

public:

	CryptoStream(Stream* stm) : stream(stm){}

	virtual char Read(int number){
		//额外的加密操作
		stream->Read(number);
		//额外的加密操作
	}
	virtual void Seek(int position){
		//额外的加密操作
		stream->Seek(position);
		//额外的加密操作
	}
	virtual void Write(char data){
		//额外的加密操作
		stream->Write(data);
		//额外的加密操作
	}
};

/**
 * 如果我们还有对于流的缓冲操作的需求的话
*/

class BufferedStream : public Stream{
	Stream* stream; // = new ***stream();

public:
	BufferedStream(Stream* stm) : stream(stm) {}
	// .....
	virtual char Read(int number) {// ....
	}
	virtual void Seek(int position){ // ....
	}
	virtual void Write(char data){// ....
	}
};

/**
 * 上面的这一系列的操作实际上已经完成了整个代码的重构的过程
 * 但是，我们可以看到，在 CryptoStream 和 BufferedStream 中有公用的字段 Stream* 
 * 因此我们可以考虑将这个字段提取到更高层的一个类中
*/

void process(){
	// 运行时装配
	FileStream* s1 = new FileStream();
	CryptoStream* s2 = new CryptoStream(s1);

	BufferedStream* s3 = new BufferedStream(s1);	// 文件缓存流

	BufferedStream* s4 = new BufferedStream(s2);	// 文件的加密缓存流
}
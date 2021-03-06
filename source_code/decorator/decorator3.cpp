// 业务操作
class Stream{
public:
	virtual char Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;

	virtual ~Stream() {}
};
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
 * 添加一个中间的装饰类，将CryptoStream 类和 BufferedStream 类中的
 * Stream* 变量提取到这个类当中
*/
class DecoratorStream : public Stream{
protected:
	Stream* stream;

	DecoratorStream(Stream* stm) : stream(stm){}
};

/**
 * 让代码在编译时期具有相同的结构，而变化通过运行时期的多态的动态绑定来实现
*/
//扩展操作
class CryptoStream : public DecoratorStream{
public:

	CryptoStream(Stream* stm) : DecoratorStream(stm){}	// 调用装饰类的构造函数

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

class BufferedStream : public DecoratorStream{
public:
	BufferedStream(Stream* stm) : DecoratorStream(stm) {}
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
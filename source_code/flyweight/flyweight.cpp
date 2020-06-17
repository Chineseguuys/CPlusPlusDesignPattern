#include <string>
#include <map>
using namespace std;

/**
 * 共享的内容往往是只读的，并且内容比较大的对象
 * Font 对象就是一个例子，一种字体具有非常大的字库，存储每一个符号的形状信息，我们不可能为每一个字使用
 * 一个 Font 对象。所以需要进行共享，一般情况下，字体的数据是不能进行修改的，是只读的数据
*/
class Font{
private:
	// unique object key
	string key;

	//object state
	// ....
public:
	Font(const string& key){
		// .....
	}
};


class FontFactory{
private:
	map<string, Font*> fontpool;
public:
	Font* getFont(const string& key){
		map<string, Font*>::iterator item = fontpool.find(key);
		if (item != fontpool.end())
			return fontpool[key];
		else
		{
			Font* font = new Font(key);
			fontpool[key] = font;
			return font;
		}
	}

	void clear(){
		// ....
	}
};
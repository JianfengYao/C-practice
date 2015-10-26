#include "DEFINE.h"
#include "QueryResult.h"

class TextQuery{

public:

	//读取文件的每一行，把每一个单词对应的行号都存在相应的map中
	TextQuery(ifstream &input);
	//查询，返回结果
	QueryResult Query(string &check) const;
	
private:
	
	//文件内容数组,需要共享
	shared_ptr<vector<string>> array_file;

	//存储对应单词的行号，需要共享行号集合
	map<string, shared_ptr<set<lineno>>> word_line;
};
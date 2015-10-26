#include "DEFINE.h"

class QueryResult{
	friend ostream &print(ostream &os, const QueryResult &qr);
private:
	
	//查询的单词
	string word;

	//单词所在的vector
	shared_ptr<vector<string>> result_vector_ptr;

	//查询单词所在的行号集合
	shared_ptr<set<lineno>> result_set_ptr;
public:

	QueryResult(string s, shared_ptr<set<lineno>>p, shared_ptr<vector<string>>f):word(s),result_vector_ptr(f),result_set_ptr(p){}
};
#include"TextQuery.h"

TextQuery::TextQuery(ifstream &inputfile) :array_file(new vector<string>){

	string text;
	int no_line;
	while (getline(inputfile, text)){

		//保存文件文本
		array_file->push_back(text);

		//确定行号
		no_line = array_file->size() - 1;

		//准备分割单词
		istringstream split_word(text);
		string single_word;

		//插入单词所在的行号
		while (split_word >> single_word){

			auto &temp = word_line[single_word];

			//如果这个指针还没有指向任何东西
			if (!temp)
				temp.reset(new set<lineno>);

			temp->insert(no_line);
		}
	}
}


QueryResult TextQuery::Query(string &check)const{

	static shared_ptr<set<lineno>> nodata(new set<lineno>);

	auto location = word_line.find(check);

	if (location == word_line.end())
		return QueryResult(check, nodata, array_file);
	else
		return QueryResult(check,location->second, array_file);
}
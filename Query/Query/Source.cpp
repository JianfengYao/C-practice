
int main()
{
	string user_input;
	cin >> user_input;
	ifstream input(user_input);
	runQueries(input);
	return 0;
}

void runQueries(ifstream &inputfile) {

	//创建对象，并且完成初始化操作
	TextQuery textquery(inputfile);

	string check_word;
	while (cin >> check_word || check_word == "q") {

		print(cout, textquery.Query(check_word)) << endl;
	}
}
ostream &print(ostream &os, const QueryResult &qr) {

	os << qr.word << " occurs " << qr.result_set_ptr->size() << " " << "times" << endl;

	for (auto &temp : *qr.result_set_ptr) {

		os << "\t( line : " << temp + 1 << " ) " << (*qr.result_vector_ptr)[temp] << endl;

	}
	return os;
}
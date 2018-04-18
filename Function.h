#include <vector>
#include <map>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <deque>
#include <fstream>
#include <list>
#include <functional>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <memory>
#include <set>
int LogFlag = 0;
using namespace ::std;
using std::allocator;
using std::cin;
using std::cin;
using std::cout;
using std::cout;
using std::deque;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::list;
using std::map;
using std::ostream;
using std::placeholders::_1;
using std::runtime_error;
using std::set;
using std::shared_ptr;
using std::string;
using std::uninitialized_copy;
using std::vector;
template <typename TYPE>
void print(const TYPE &p);
bool SecondSearch(vector<int> &test, int Elem, vector<int>::iterator begin, vector<int>::iterator end);
bool SecondSearch(vector<int> &test, int Elem, vector<int>::iterator begin, vector<int>::iterator end)
{
	vector<int>::iterator mid;
	mid = test.begin() + (end - begin) / 2;
	while (mid <= end && *mid != Elem)
	{
		if (*mid > Elem)
			SecondSearch(test, Elem, begin, mid);
		else
			SecondSearch(test, Elem, mid + 1, end);
	}
	//printf("*mid=%d\n",*mid);
	cout << *mid << endl;
	return true;
}
bool IsShorter(const string &lhs, const string &rhs)
{ /*
	string ls = lhs;
	string rs = rhs;*/
	return lhs.size() < rhs.size();
}
/*
* Cpp Primer 9.18
*/
void PrintDeque()
{
	cout << "Enter into PrintDeque" << endl;
	deque<string> StrInput;
	string str;
	while (cin >> str)
	{
		cout << "Enter into while\n";
		StrInput.push_back(str);
	}
	for (auto iter : StrInput)
		cout << iter << endl;
}

/*
* Cpp Primer 9.19
*/
void PrintList()
{
	cout << "Enter into PrintList" << endl;
	list<string> StrInput;
	string str;
	/*while (cin >> str)
	{
		cout << "Enter into while\n";
		StrInput.push_back(str);
	}*/
	for (string str; cin >> str; StrInput.push_back(str))
		; 
	for (auto iter : StrInput)
		cout << iter << endl;
}

/*
*CppPrimer 9.20
*/
void CopyFormDeque_odd_even()
{
	list<int> elems;
	deque<int> elem_odds, elem_evens;
	for (int input; cin >> input; elems.push_back(input))
		; //
	for (auto iter : elems)
	{
		if (iter % 2)
			elem_odds.push_back(iter);
		else
		{
			elem_evens.push_back(iter);
		}
	}
	cout << "odds:" << endl;
	print(elem_odds);
	cout << "evens:" << endl;
	print(elem_evens);
}
/*
 * Cpp Primer9.22
 */
void double_and_insert(vector<int> &InserElem, int Elem)
{
	cout << "Enter Into founction:double_and_insert" << endl;
	//auto mid = InserElem.begin() + (InserElem.end()-InserElem.begin()) / 2;
	auto mid = [&] { return InserElem.begin() + InserElem.size() / 2; }; //
	//cout << "*mid=" << *mid << endl;
	for (auto it = InserElem.begin(); it < mid(); ++it)
	{
		cout << "mid=" << *mid() << endl;
		cout << "it=" << *it << endl;
		if (*it == Elem)
		{
			cout << "find Elem" << endl;
			it = InserElem.insert(it, 2 * Elem);
			++it;
		}
	}
	for (auto it : InserElem)
		cout << it << endl;
	for (vector<int>::iterator it = InserElem.begin(); it != InserElem.end(); it++)
		cout << &*it << endl; //
}

template <typename TYPE>
void log(TYPE &Refer)
{
	cout << "The " << LogFlag << " Place"
		 << ":" << Refer << " Test" << endl;
	LogFlag++;
}

//extern friend ();
class FriendTest
{
  public:
	FriendTest(int x);
	~FriendTest();
	void print()
	{
		printf("I am Joker\n");
	}

  private:
	int tx;
};
FriendTest::FriendTest(int x)
{
	tx = x;
}
FriendTest::~FriendTest()
{
}

class Account
{
  public:
	Account(double interestRate); //
	Account();					  //
	/*friend  ostream&operator<<(ostream &out, const Account &account)
	{
		out << "interestRate=" << account.interestRate << ",InterInterestRate= " << account.InterInterestRate;
		return out;
	}*/
	void print();
	~Account();
	//

  private:
	static double interestRate;
	static double InitRate();
	double InterInterestRate;
};
Account::Account(double interestRate) //
{
	InterInterestRate = interestRate;
}
Account::Account()
{
}
Account::~Account()
{
}
double Account::interestRate = InitRate();
double Account::InitRate()
{
	srand(0);
	return (rand() + 0.0);
}
void Account::print()
{
	printf("The interestrate=%f\n", interestRate);
}

/*
*
*/
template <typename TYPE>
void print(const TYPE &p)
{
	for (auto it : p)
	{
		cout << (it) << endl; //static_cast< char*> 
							  //	printf("%s\n",*it);
	}
	return;
}
//static void initrate()
//{
//	interestrate = 0.6;
//}

class Sale_Data
{
  public:
	Sale_Data(string isbn, double price, int mount);
	~Sale_Data();
	//bool operator !=(const Sale_Data &lhs,const Sale_Data &rhs)//
	//{
	//	cons
	//}
	string isbn()
	{
		return Isbn;
	}

  private:
	string Isbn;  //
	double Price; //
	int Mount;	//
};
Sale_Data::Sale_Data(string isbn, double price, int mount)

	: Isbn(isbn), Price(price), Mount(mount)
{
}

Sale_Data::~Sale_Data()
{
}

/*
* 
*/
void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	//
	auto end_unique = unique(words.begin(), words.end()); //
	words.erase(end_unique, words.end());
}

auto f = [] {
	cout << "This is lambda" << endl;
};

/*
*lambda		
*/

/*
* 
*/

//void biggies(vector<string> &words, vector<string>::size_type sz)
//{
//	for (auto it : words)
//	{
//		if (it.size() > sz)
//			it = words.erase(it);
//	}
//
//}

/*
* lambda test
*/

/*
* bigges,
*/
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);																							   //
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); }); //,
	auto wc = find_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });			   //
	auto count = words.end() - wc;																				   //
	//
	for_each(wc, words.end(), [](const string &s) { cout << s << " "; });

	cout << endl;
}

/*
* biggies lambda trans into three pramerter
*/
void biggies1(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char c = ' ')
{
	elimDups(words);																							   //
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); }); //
	auto wc = find_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });			   //
	auto count = words.end() - wc;																				   //
																												   //
	for_each(wc, words.end(), [&os, c](const string &s) { os << s << c; });
	cout << endl;
}

/*
*	
*/
//void transform(vector<int>::iterator begin, vector<int>::iterator end, [](int i)->int {if (i < 0) return -i;else return i;});

bool check_size(string &s, vector<int>::size_type sz)
{
	return s.size() <= sz;
}
//void check_size2()

/*
*  biggies--->blind
*/

void biggies2(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);																							   //
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); }); //
	auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz));									   //
	auto count = words.end() - wc;																				   //
																												   //
	for_each(wc, words.end(), [](const string &s) { cout << s << " "; });
	cout << endl;
}

/*
* there is a string,find a nummer in a vector which is largeer than the length of string
*/
int FindSpecialNum(string &str, vector<int> &vec)
{
	auto wc = find_if(vec.begin(), vec.end(), bind(check_size, str, _1));
	if (wc != vec.end())
		return *wc;
}

map<string, string> BuildMap(ifstream &mapfile)
{
	map<string, string> bulidmap;
	string key, value;
	while (mapfile >> key && getline(mapfile, value))
		if (value.size() > 1)
			bulidmap[key] = value.substr(1); //
		else
			throw runtime_error("no rule for" + key);
	return bulidmap;
}

const string &transform(const string &key, map<string, string> &buildmap)
{
	auto MapFindIterator = buildmap.find(key);
	if (MapFindIterator != buildmap.cend())
	{
		return MapFindIterator->second; //
	}
	else
		return key;
}

void word_transform(ifstream &mapfile, ifstream &input)
{
	auto RuleMap = BuildMap(mapfile); //
	string text;
	while (getline(input, text)) //
	{
		string word;
		istringstream stream(text); //
		bool firstword = true;		//
		while (stream >> word)
		{
			if (firstword) //
				firstword = false;
			else
				cout << " ";
			cout << transform(word, RuleMap);
		}
		cout << endl;
	}
}

/*
*    
*/
class QueryResult;
class TextQuery
{
  public:
	TextQuery();
	~TextQuery();
	using line_no = std::vector<string>::size_type;
	TextQuery(ifstream &);
	QueryResult query(const string &) const;

  private:
	ifstream &ifs;
	shared_ptr<vector<string>> File;
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) : File(new vector<string>), ifs(is)
{
	string text;
	while (getline(is, text))
	{
		//cout << text << endl;
		File->push_back(text);
		int n = File->size() - 1;
		istringstream line(text); // 
		string word;
		while (line >> word)
		{
			//print(word);
			cout << word << endl;
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}
//   
TextQuery::~TextQuery()
{
}

class QueryResult
{
	friend std::ostream &print(std::ostream &, const QueryResult &);
	using line_no = vector<string>::size_type;

  public:
	QueryResult(string s, shared_ptr<vector<string>> out, shared_ptr<set<line_no>> outlines);
	~QueryResult();

  private:
	string QueryString;								//
	std::shared_ptr<std::vector<std::string>> file; //
	shared_ptr<set<line_no>> lines;					//
};
QueryResult::QueryResult(string s, shared_ptr<vector<string>> out, shared_ptr<set<line_no>> outlines) : QueryString(s), file(out), lines(outlines)
{
}
QueryResult::~QueryResult()
{
}

QueryResult TextQuery::query(const string &QueryString) const
{

	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	/*for (auto it:wm)
	{
		if (it.first == QueryString)
		{
			nodata=it.second;
		}
	}*/
	auto loc = wm.find(QueryString);
	//if(!nodata)
	if (loc == wm.end())
	{
		log("Not Find it");
		return QueryResult(QueryString, File, nodata);
	}
	else
	{
		log(" Find it");
		return QueryResult(QueryString, File, loc->second);
	}
}

std::ostream &print(std::ostream &out, const QueryResult &OutResult) //
{
	cout << OutResult.lines->size() << endl;
	out << OutResult.QueryString << "occurs " << OutResult.lines->size() << "times" << endl;
	for (auto num : *OutResult.lines)
	{
		out << "line num " << num + 1 << ":" << *(OutResult.file->begin() + num) << endl;
	}
	return out;
}
/*
*  拷贝构造
*/
class HasPtr
{
  public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) //默认拷贝构造函数
	{
	}
	HasPtr(const HasPtr &hasptr) : ps(new string(*hasptr.ps)), i(hasptr.i) //拷贝构造
	{
	}
	HasPtr &operator=(const HasPtr &hp) //拷贝赋值
	{
		auto np = new string(*hp.ps);
		delete ps;
		ps = np;
		i = hp.i;
		return *this;
	}

  private:
	string *ps;
	int i;
};

/*
*	LeetCode Question:K-th Smallest Prime Fraction
*/
class Solution
{
  public:
	vector<int> kthSmallestPrimeFraction(vector<int> &A, int k)
	{
		int Length = A.size();
		vector<int> Answer;
		//vector<vector<int>> TempIter;
		vector<double> TempVector;
		int numerator, denominator;
		for (vector<int>::iterator it = A.begin(); it != A.end(); it++)
			for (vector<int>::iterator next = it + 1; next != A.end(); next++)
			{
				TempVector.push_back(double(*it) / (*next));
				//	TempIter[numerator].push_back(denominator);
			}

		sort(TempVector.begin(), TempVector.end());
		for (vector<int>::iterator it = A.begin(); it != A.end(); it++)
			for (vector<int>::iterator next = it + 1; next != A.end(); next++)
			{
				if (*(TempVector.begin() + k - 1) == (double(*it) / (*next))) //注意第k个的意思
				{
					Answer.push_back(*it);
					Answer.push_back(*next);
					return Answer;
				}
				//TempVector.push_back(*it / (*next));
				//	TempIter[numerator].push_back(denominator);
			}
		// for(auto row=TempIter.begin(),numerator=1;row!=TempIter.end();row++,numerator++)
		// 	for(vector<int>::iterator col=TempIter[row],denominator=1;col!=TempIter[row].end();col++,denominator++)
		// 		if(*(TempVector.begin()+k)==numerator/denominator)
		// 		{
		// 			Answer.push_back(numerator);
		// 			Answer.push_back(denominator);
		// 		}
		// return Answer;
	}

  private:
	vector<int> A;
	int k;
};

/*
*	拷贝构造函数
*/

// class numbered
// {
// 	public:
// 		void f(numbered s)
// 		{
// 			cout<<s.mysn<<endl;
// 		}
// 	private:

// }

/*
*  类vector
*/

static std::allocator<std::string> alloc; //分配元素,静态数据，所有对象实例共享

class StrVec
{
  public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {} //默认构造
	StrVec(const StrVec &);											   // 拷贝构造
	StrVec &operator=(const StrVec &rhs);							   //拷贝赋值
	~StrVec();
	void push_back(const std::string &);				  //添加元素
	size_t size() const { return first_free - elements; } //空间大小
	size_t capacity() { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }

  private:
	std::pair<string *, string *> alloc_n_copy(const string *, const string *); //工具函数，用于拷贝
	void chk_n_alloc()
	{
		if (size() == capacity())
			reallocate();
	}
	void free(); //释放空间
	void reallocate();

	std::string *first_free; //第一个空闲元素的指针
	string *elements;		 //指向数组首元素的指针
	string *cap;			 //指向内存最后一个单元的指针(数组尾后元素)
};
StrVec::StrVec(const StrVec &s) // 拷贝构造
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

void StrVec::free()
{
	if (elements)
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
	alloc.deallocate(elements, cap - elements); //销毁空间
}
StrVec::~StrVec()
{
	free();
}
StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = data.second;
	return *this;
}
void StrVec::push_back(const string &s)
{
	chk_n_alloc(); //确保有空间容纳新元素
	alloc.construct(first_free++, s);
}
std::pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e) //工具函数，用于拷贝
{
	//分配空间保存给定范围内的元素
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}
void StrVec::reallocate()
{
	auto newcapacity = size() ? size() : 1;
	//分配新内存
	auto newdata = alloc.allocate(newcapacity);
	//将数据从旧内存移到新内存
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free(); //一旦移动完成，释放旧内存
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

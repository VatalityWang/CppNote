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
//#include<match>
#include<stack>
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
int ForkNum=0;
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
	friend std::istream& operator>>(std::istream &,Sale_Data&);//input
	friend std::ostream& operator<<(std::ostream &,const Sale_Data&);//output
	friend Sale_Data& operator+(const Sale_Data&,const Sale_Data&);//addition
	
  public:
	Sale_Data(const string &s, unsigned  n, double p):bookNo(s),units_sold(n),revenue(n*p){}
	Sale_Data():Sale_Data("",0,0.0f){}
	Sale_Data(const std::string &s):Sale_Data(s,0,0.0f){}
	Sale_Data(std::istream &is);
	Sale_Data& operator+=(const Sale_Data&);
	string isbn() const {return bookNo;}
	~Sale_Data();
	//bool operator !=(const Sale_Data &lhs,const Sale_Data &rhs)//
	//{
	//	cons
	//}
  private:
    inline double avg_price() const;
	std::string bookNo;
	double revenue=0.0;
	unsigned units_sold=0;
};
inline double Sale_Data::avg_price() const
{
	return units_sold?revenue/units_sold:0;
}
Sale_Data::Sale_Data(std::istream &is):Sale_Data()
{
	is>>*this;
}
Sale_Data& Sale_Data::operator+=(const Sale_Data&rhs)
{
	revenue+=rhs.revenue;
	units_sold+=rhs.units_sold;
	//bookNo+=rhs.bookNo;//书名不用变
	return *this;
}
Sale_Data::~Sale_Data()
{
}
std::istream& operator>>(std::istream &is,Sale_Data&item)//input
{
	double price=0.0;
	is>>item.bookNo>>item.units_sold>>price;
	if(is)
		item.revenue=price*item.revenue;
	else 
		item=Sale_Data();
}
 std::ostream& operator<<(std::ostream &os,const Sale_Data&item)//output
{
	os<<item.isbn()<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
	return os;
}
 Sale_Data& operator+(const Sale_Data&lhs,const Sale_Data&rhs)//addition
{
	Sale_Data sum=lhs;
	sum+=rhs;
	return sum;
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
	void Push_back(const std::string &);				  //添加元素
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
void StrVec::Push_back(const string &s)
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

/*
*	饱汉式 单线程，多线程可以加锁
*/
class singleton
{
	private:
		static singleton *pInstance;
		singleton()
		{
			cout<<"This is constructer"<<endl;	
		}
		~singleton(){}
	public:
		static singleton * GetInstance()
		{
			if (!pInstance)
			{
				pInstance = new singleton();
			}
			return pInstance;
		}
		static void DestroyPinstance()
		{
			if(!pInstance)
			{
				delete pInstance;
				pInstance=NULL;
			}			
		}
};
class String
{	
	public:
		String():String(""){}
		String(const char *);//
		String(const String &);//拷贝构造
		String &operator=(const String&);//拷贝赋值
		~String();

		const char *c_str() const {return elements;}
		size_t size() const {return end-elements;}
		size_t length() { return end-elements-1;}
	private:
		std::pair<char *,char *>alloc_n_copy(const char*,const char *);
		void range_initalizer(const char*,const char*);
		void free();
	private:
		char *elements;
		char * end;
		std::allocator<char> alloc;
};

 String::String(const char *str)
{

	char* tmpstr=const_cast<char*>(str);
	while(*tmpstr)
		++tmpstr;
	range_initalizer(str,++tmpstr);//把'\0'字符串也拷贝进去

}
String::String(const String& rhs)
{
    range_initalizer(rhs.elements, rhs.end);
    std::cout << "copy constructor" << std::endl;
}

String& String::operator=(const String& rhs)
{
	auto newdata = alloc_n_copy(rhs.elements, rhs.end);
	elements = newdata.first;
	end= newdata.second;
	  std::cout << "copy-assignment" << std::endl;
}
String::~String()
{
	free();
}
void String::free()
{
	for(auto p=elements;p!=end;)
		alloc.destroy(++p);
	elements=NULL;
	end=NULL;
}
void String::range_initalizer(const char*b,const char*e)
{
	auto data = alloc_n_copy(b,e);
	elements=data.first;
	end=data.second;
}

std::pair<char* ,char*>String::alloc_n_copy(const char*b,const char*e)
{
	auto str=alloc.allocate(e-b);
	return{str,std::uninitialized_copy(b,e,str)};
}





class ownstring
{
	public:
		  ownstring();
		  ownstring(const ownstring &rhs);
		  ownstring(const char *);
		  ownstring& operator=(const ownstring &rhs);
		  ~ownstring();
		  void showstring();
	private:
		  char *m_data;
};

ownstring::ownstring()
{
	m_data=NULL;
}
ownstring::ownstring(const char *s)
{	

	if(s==NULL)//初始串不存在，为m_data申请一个空间存放'\0'
	{
		m_data=new char(1);
		m_data='\0';
	}
	else 
	{
		int length = strlen(s);
		m_data = (char*)malloc(length * sizeof(char));
		strcpy(m_data, s);
	}
}
ownstring::ownstring(const ownstring &rhs)
{
	int length=strlen(rhs.m_data);
	m_data=(char*)malloc(length*sizeof(char));
	strcpy(m_data,rhs.m_data);

}
 ownstring& ownstring::operator=(const ownstring &rhs)
 {
	 if(&rhs==this)
		 return *this;
    if(m_data)
		delete []m_data;//地址不相同时，删除原来申请的空间，重新开始构造
	int length=strlen(rhs.m_data);
	m_data=(char*)malloc(length*sizeof(char));
	strcpy(m_data,rhs.m_data);
	return *this;
 }
 ownstring::~ownstring()
 {
	 delete []m_data;
 }
void ownstring::showstring()
{
	cout<<this->m_data<<endl;
}
class solution
{
  public:
	void push(int node)
	{
		// if (stack1.empty())
		// {
			cout << "log 0" << endl;
			stack1.push(node);
		// }
		// else if(!stack2.empty())
		// {
		// 	int tmpflag;
		// 	while (!stack2.empty())
		// 	{
		// 		cout << "log 1" << endl;

		// 		tmpflag = stack2.top();
		// 		stack2.pop();
		// 	}
		// 	stack2.push(tmpflag);
		// 	cout << "log 2" << endl;

		// 	stack1.push(node);
		// }
	}

	int pop()
	{
		int tmpflag = 0;
		//  cout<<"size  "<<stack2.size()<<endl;
		//  cout<<stack2.empty()<<endl;
		if (!stack2.empty())
		{
			cout << "log 3" << endl;

			tmpflag = stack2.top();
			stack2.pop();
		}
		else
		{

			while (!stack1.empty())
			{
				cout << "log 4" << endl;

				tmpflag = stack1.top();
				stack1.pop();
				stack2.push(tmpflag);
			}
			if (!stack2.empty())
			{
				cout << "log 5" << endl;

				tmpflag = stack2.top();
				stack2.pop();
			}
		}
		cout << "log 6" << endl;
		return tmpflag;
	}

  private:
	stack<int> stack1;
	stack<int> stack2;
};
class FindMinInRotateArray {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
		int  i;
		if(!rotateArray.size())
           return 0;
        for(i=1;i<rotateArray.size();i++)
        {
            if(rotateArray[i]>=rotateArray[i-1])
				continue;
			break;
        }
		return rotateArray[i];
    }
};

class Fibonacci {
public:
    int fibonaccifunc(int n) {
		int i;
		vector<int> TmpArray;
		if (n >= 1)
		{
			for (i = 1; i <= n; i++)
				if (i == 1)
					TmpArray.push_back(1);
				else if (i == 2)
					TmpArray.push_back(1);
				else
					TmpArray.push_back(TmpArray[i - 2] + TmpArray[i - 3]);
			return TmpArray[n - 1];
		}
       return 0;
	}
};
/*
class jumpFloor {
public:
    int jumpFloorFunc(int number) {
        int jumpFloorWay,i;
		int TmepNum=number;
		while(number)
		{
			int TmepNum=number;
			TmepNum-=2;
			if(TmepNum)
			else if()
			{
				for(int i=0;i<N;i++)
				{
					
				}
			}
		}
			
    }
};*/
bool IsBigEndian()
{	//联合体的大小等于最大成员的大小
	union NUM {
		int a;
		char b;
	} num;
	num.a = 0x1234;
	if (num.b = 0x12) //高地址端高字节
		return false;
	else
		return true;
}

bool IsBigEndian(int num)
{
	char a=*(char*)&num;
	if(a==0x12)//低端高字节
		return true;
	else 
		return	false;
}

void ForkFunc()
{
	ForkNum++;
	cout<<"ForkNum="<<ForkNum<<endl;
}
/*
* Add overloaded input,output,addition,add commpund-assignment operators
*/

class DoublePower {
public:
    double Power(double base, int exponent) {
		double baseresult=1.0;
		int Tmp;
		Tmp=abs(exponent);
		for(int i=0;i<Tmp;i++)
		{
			baseresult*=base;
		}
		return exponent>0?baseresult:1/baseresult;
	}
};


/*
*输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
class ReOrderArray {
public:
    void reOrderArray(vector<int> &array) {
	
    }
};
namespace alg
{
	template<typename K,typename V>
	class LruCache
	{
		typedef struct _Node_
		{
			K key;
			V value;
			struct _Node_ *pre;
			struct _Node_ *pnext;
		}CacheNode;
  		private:
		  	int CacheSize_;
			CacheNode *CacheListPre;//头
			CacheNode *CacheListPnext;//尾
			map<K,CacheNode*> Cache_Hash;
  		public:
			LruCache(int CacheSize=10)
			{
			   CacheSize_=CacheSize;
			   CacheListPre =new CacheNode();
			   CacheListPnext=new CacheNode();
			   CacheListPre->pre=NULL;
			   CacheListPre->pnext=CacheListPnext;
			   CacheListPnext->pre=CacheListPre;
			   CacheListPnext->pnext=NULL;
			}	
			~LruCache()
			{
				CacheNode *p;
				p=CacheListPre->pnext;//从头指针开始删除节点分配的内存
				while(p)
				{
					delete p->pre;
					p=p->pnext;
				}
				delete CacheListPnext;//删除尾节点
				Cache_Hash.clear();//删除缓存容器
			}
			V getValue(K key_)
			{
				
				if(Cache_Hash.find(key_)!=Cache_Hash.end())
				{
					CacheNode *p=Cache_Hash[key_];
					DeatchNode(p);
					AddFirstNode(p);
					return Cache_Hash[key_]->value;
				}
				else
				{
					cout<<"No elem has Key:"<<key_<<endl;
					return V();
				}
			}
			void InsertValue(K key_,V value_)
			{
				if (Cache_Hash.find(key_) != Cache_Hash.end())//能找到
				{
					Cache_Hash[key_]->value=value_;	
					CacheNode *p=Cache_Hash[key_];
					DeatchNode(p);
					AddFirstNode(p);
					//长度检查
					

				}
				else//不能找到
				{
					CacheNode *p = new CacheNode();
					p->key = key_;
					p->value = value_;
					Cache_Hash[key_] = p;
				
					AddFirstNode(p);
					//cout<<"CacheSize_="<<CacheSize_ <<endl;
					if (Cache_Hash.size() > CacheSize_)
					{
						cout << "The CacheList  full " << endl;
						DelEndCacheNode();
					}
				}
			}
			

			void Display()
			{
				CacheNode *p=CacheListPre;
				//cout<<"CacheList length ="<<Cache_Hash.size() <<endl;
				while(p)
				{
					cout<<"[Key]: "<<p->key<<"--->"<<"[Value]: "<<p->value<<endl;
					p=p->pnext;
				}
				// for(map<K,CacheNode*>::iterator it :Cache_Hash)
				// {
				// 	cout<<"[Key]: "<<it->first<<"--->"<<"[Value]: "<<it->second->value<<endl;
				// }
			}
			void DeatchNode(CacheNode *p)
			{
				//cout << "log 3" << endl;
				//cout<<"args_p="<<p<<endl;
				p->pre->pnext=p->pnext;
				p->pnext->pre=p->pre;
			}
			void AddFirstNode(CacheNode *p)
			{
				if(!CacheListPre)
				{
					CacheListPre->pre = NULL;
					CacheListPre->pnext = p;
					CacheListPnext->pre = p;
					CacheListPnext->pnext = NULL;
				}
				else//头插
				{
					p->pnext=CacheListPre->pnext;
					CacheListPre->pnext->pre=p;
					CacheListPre->pnext=p;
					p->pre=CacheListPre;
				}
			}
			void DelEndCacheNode()
			{
				CacheNode *p=CacheListPre;
				if (CacheListPnext)
				{
					//cout << "log 1" << endl;
					while (p->pnext != CacheListPnext)
					{
						//cout << "log 2" << endl;
						p = p->pnext;
					}
					DeatchNode(p);
					//cout << "log 4" << endl;
					Cache_Hash.erase(p->key);
					//cout << "log 5" << endl;
					free(p);
					//cout << "log 6" << endl;
					//	CacheListPnext = p;
				}
			}
	};
} // namespace alg	

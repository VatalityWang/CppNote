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
#include<exception>
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
using std::swap;
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
		; 
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
	auto mid = [&] { return InserElem.begin() + InserElem.size() / 2; };
	cout << "*mid=" << *mid() << endl;
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
		cout << &*it << endl; 
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
	Account(double interestRate); 
	Account();					  
	/*friend  ostream&operator<<(ostream &out, const Account &account)
	{
		out << "interestRate=" << account.interestRate << ",InterInterestRate= " << account.InterInterestRate;
		return out;
	}*/
	void print();
	~Account();
	

  private:
	static double interestRate;
	static double InitRate();
	double InterInterestRate;
};
Account::Account(double interestRate) 
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
namespace alg
{
	template <typename T>
	void swap(T &a, T &b)
	{
		T _t(a);
		a = b;
		b = _t;
	}
} // namespace alg
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
	elimDups(words);																							   
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); }); 
	auto wc = find_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });			   
	auto count = words.end() - wc;																				   
	for_each(wc, words.end(), [](const string &s) { cout << s << " "; });

	cout << endl;
}

/*
* biggies lambda trans into three pramerter
*/
void biggies1(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char c = ' ')
{
	elimDups(words);																							   
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); }); 
	auto wc = find_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });			   
	auto count = words.end() - wc;																				   
																												   
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
	elimDups(words);																							   
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); }); 
	auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz));									   
	auto count = words.end() - wc;																				   
																												   
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
			bulidmap[key] = value.substr(1); 
		else
			throw runtime_error("no rule for" + key);
	return bulidmap;
}

const string &transform(const string &key, map<string, string> &buildmap)
{
	auto MapFindIterator = buildmap.find(key);
	if (MapFindIterator != buildmap.cend())
	{
		return MapFindIterator->second; 
	}
	else
		return key;
}

void word_transform(ifstream &mapfile, ifstream &input)
{
	auto RuleMap = BuildMap(mapfile); 
	string text;
	while (getline(input, text)) 
	{
		string word;
		istringstream stream(text); 
		bool firstword = true;		
		while (stream >> word)
		{
			if (firstword) 
				firstword = false;
			else
				cout << " ";
			cout << transform(word, RuleMap);
		}
		cout << endl;
	}
}
void UsersAccount(ifstream &Usersfile)
{
	set<int> UsersSet;
	string text;
	while(getline(Usersfile,text))//读一行
	{
		//string symbol;
		int usernum;
		istringstream stream(text);//将这一行转换为字符流
		while(stream>>usernum)
		{
			UsersSet.insert(usernum);
		}
		//while(stream>>symbol)
	}
	cout<<"DAU:"<<UsersSet.size()<<endl;
	for(auto it:UsersSet)
	{
		cout<<it<<endl;
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
	void PrintHighestWords(int frequency,string WordFile);

  private:
	ifstream &ifs;
	shared_ptr<vector<string>> File;
	map<string, shared_ptr<set<line_no>>> wm;
};
void TextQuery::PrintHighestWords(int frequency,string WordFile)
{
	map<int,vector<string>> WordFreq;
	map<string, shared_ptr<set<line_no>>>::iterator it;
	map<int,vector<string>>::iterator im,ibegin;
	vector<string>::iterator in;
	int i,j;
	int strnum;
	vector<string> strtmp;
	for( it=wm.begin();it!=wm.end();it++)
	{
		strnum=it->second->size();
		strtmp.clear();
		strtmp.push_back(it->first);
		im=WordFreq.find(strnum);
		if(im!=WordFreq.end())
		{
			(im->second).push_back(it->first);
		}
		else
		{
			WordFreq.insert(std::make_pair(strnum,strtmp));
		}
	}
	ibegin=WordFreq.begin();
	ibegin--;
	ofstream ofs(WordFile);
	for(i=0,im=(WordFreq.end()),im--;im!=ibegin&&i!=frequency;im--,i++)
	{
		ofs<<im->first<<" "<<endl;
		for(j=1,in=(im->second).begin();in!=(im->second).end();in++,j++)
		{
			ofs<<*in<<"  ";
			if(j/5&&j%5==0)
				ofs<<endl;
		}
		ofs<<endl;
	}
	
}

TextQuery::TextQuery(ifstream &is) : File(new vector<string>), ifs(is)
{
	string text;
	while (getline(is, text))
	{
		//cout << text << endl;
		File->push_back(text);
		int n = File->size() - 1;
		istringstream line(text);  
		string word;
		while (line >> word)
		{
			//print(word);
			size_t pos;
			int i,j,num,len,tmpi;
			pos=word.find(',');
			if (pos!=std::string::npos)
			{
				word=word.substr(0, pos);
			}
			pos=word.find(';');
			if (pos!=std::string::npos)
			{
				word=word.substr(0, pos);
			}
			pos=word.find('.');
			if (pos!=std::string::npos)
			{
				word=word.substr(0, pos);
			}
			pos=word.find(':');
			if (pos!=std::string::npos)
			{
				word=word.substr(0, pos);
			}
			//filter left "
			printf("current word %s\n",word.c_str());
			
			//word=word.replace(word.find("\""),1,"");
			//word=word.replace(word.find("\""),1,"");
			/*
			char* strtmp=new char[word.size()];
			memcpy(strtmp,word.c_str());
			len=strlen(strtmp);
			num++;
			for(i=0;i<len;i++)
			{
			//while(strtmp[i]!='\0')
				if(strtmp[i]=='\"')
				{
					tmpi=i;
					j=i+1;
					while(j<len)
						strtmp[i++]=strtmp[j++];
					num++;
				}
				i=tmpi;
			}
			*/
		
			pos=word.find('"');
			if(pos!=std::string::npos)
			{
				word=word.replace(word.find('\"'),1,"");
				/*
				if(pos==0)
					word=word.substr(1,word.size()-1);
				else
					word=word.substr(0,pos);
					*/
			}
			//filter right "
			pos=word.find('"');			
			if(pos!=std::string::npos)
			{
				word=word.replace(word.find('\"'),1,"");
				/*
				if(pos==0)
					word=word.substr(1,word.size()-1);
				else
					word=word.substr(0,pos);
				*/
			}
			/*
			pos=word.find('”');			
			if(pos!=std::string::npos)
			{
				word=word.replace(word.find('”'),1,"");
			}
			pos=word.find('“');			
			if(pos!=std::string::npos)
			{
				word=word.replace(word.find('“'),1,"");
			}
			*/
			cout << word << endl;
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}
   
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
	string QueryString;	//查询单词					
	std::shared_ptr<std::vector<std::string>> file; //输入文件
	shared_ptr<set<line_no>> lines;	//出现行号
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
		return QueryResult(QueryString, File, nodata);
	}
	else
	{
		return QueryResult(QueryString, File, loc->second);
	}
}

std::ostream &print(std::ostream &out, const QueryResult &OutResult) 
{
	cout << "the results's size: "<<OutResult.lines->size() << endl;
	out << OutResult.QueryString << " occurs " << OutResult.lines->size() << " times" << endl;
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
	//
	//判断某序列是不是二叉搜素树后序遍历结果
	//
	 bool VerifySquenceOfBST(vector<int> sequence) 
	 {
		if(sequence.empty())
			return false;
		vector<int> LeftTree;
		vector<int> RightTree;
		int Size=sequence.size();
		int Rootval=sequence[Size-1];
		int i;
		bool TreeFlag=false;
		for(i=0;i<Size-1;i++)
			if (!TreeFlag)
			{
				if (sequence[i] < Rootval)
					LeftTree.push_back(sequence[i]);
				else if (sequence[i] > Rootval)
				{
					TreeFlag = true;
					RightTree.push_back(sequence[i]);
				}
			}
			else
			{
				if(sequence[i]>Rootval)
					RightTree.push_back(sequence[i]);
				else
					return false;					
			}
		if(!LeftTree.empty()&&!RightTree.empty())//左右子树均不空才
			return VerifySquenceOfBST(LeftTree)&&VerifySquenceOfBST(RightTree);
		else if(!LeftTree.empty())//只有左子树
			return VerifySquenceOfBST(LeftTree);
		else if(!RightTree.empty())//只有右子树
			return VerifySquenceOfBST(RightTree);	
		else  //只有根节点
			return true;
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
		int temp;
		vector<int>::iterator it=array.begin();
		int size=array.size();
		while (size)
		{
			if ((*it) % 2 == 0)
			{
				temp = *it;
				it = array.erase(it);
				array.push_back(temp);
			}
			else
				it++;
			size--;
		}
		//无法保证奇数 偶数相对位置不变		
		/*
		vector<int>::iterator begin,end;
		begin=array.begin();
		end=array.end()-1;
		for(;begin<=end;)
		{
			if(!((*begin)%2))//前一个为偶数, 交换
			{
				temp=*end;
				*end=*begin;
				*begin=temp;
				end--;
			}
			else if((*end)%2)//后一个为奇数，交换
			{
				temp=*begin;
				*begin=*end;
				*end=temp;
				begin++;
			}
			else
			{
				begin++;
				end--;
			}
		}
		*/
    }
};

/*
* 输入一个链表，输出倒数第k个结点
*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class LinkList {
public:
  ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
  {
	  if(!pListHead)
	  	return NULL;
	  if(k<0)	
	  	return NULL;
	  ListNode *p = pListHead->next;
	  ListNode *q;
	  int i;
	  pListHead->next=NULL;
	  while (p)
	  {
		q = p->next;
		p->next=pListHead->next;
		pListHead->next=p;
		p=q;
	  }
	  for(i=0,p=pListHead;i<k;i++,p=p->next);
	   return p;
  }
  ListNode *FindKthToTailSp(ListNode *pListHead,unsigned int k)
  {
	if(!pListHead)
		return NULL;
	if(k<=0)
	  	return NULL;
	int i;
	ListNode *p,*q;
	for(i=0,p=pListHead;i<k-1&&p->next;i++,p=p->next);
		cout<<"val: "<<p->val<<endl;
	if(i!=k-1)
		return NULL;
	for(q=pListHead;p->next;p=p->next,q=q->next)
	{
		cout<<"val: "<<p->val<<endl;
	}
	cout<<"val: "<<p->val<<endl;
	return q;		 
  }
	ListNode *ReverseList(ListNode *pHead)
	{
		if(!pHead)
			return NULL;
		ListNode *p,*q;
		p=pHead->next;
		pHead->next=NULL;
		while(p)
		{
		    q=p->next;
			p->next=pHead;
			pHead=p;
			p=q;
		}
	  return pHead;
	}
	/*
	* 单调不减合并单链表
	*/
	ListNode *Merage(ListNode *pHead1,ListNode *pHead2)
	{
		ListNode *p1,*q1,*p2,*q2,*pHead=NULL,*pRear=NULL;
		p1=pHead1,q1=pHead2;
		while(p1&&q1)
		{
			if(p1->val<=q1->val)
			{
				if(!pHead)
					pHead=p1;
				p2=p1->next;
				p1->next=q1;
				pRear=q1;
				p1=p2;
			}
			else
			{
				if(!pHead)
					pHead=q1;
				q2=q1->next;
				q1->next=p1;
				pRear=p1;
				q1=q2;
			}
		}
		if (!pHead)
		{
			if (p1)
				return p1;
			else
				return p2;
		}
		else
		{
			if (p1)
			{
				pRear = p1;
			}
			if (q1)
			{
				pRear = q1;
			}
		}
		return pHead;
	}
	
};

struct RandomListNode 
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
class RandomListSolution
{
	public:
 	RandomListNode* Clone(RandomListNode* pHead)
    {
		if(!pHead)
			return NULL;
		RandomListNode *pRear,*pFront,*p,*pHeadNew;
		pFront=pHead;
		while(pFront)		
		{
			pRear=pFront->next;
			p=(RandomListNode*)malloc(sizeof(RandomListNode));
			pFront->next=p;
			p->next=pRear;
			p->label=pFront->label;
			pFront=pRear;
		}
		//后一个复制的结点
		pFront=pHead;
		p=pFront->next;
		while(pFront)
		{
			pRear=p->next;
			if(pFront->random)
				p->random=pFront->random->next;
			pFront=pRear;
			if(pRear)
					p=pFront->next;
		}
		//test the copy link data
		p = pHead;
		cout << "the original data after data" << endl;
		while (p)
		{
			cout << "label " << p->label << " ";
			if (p->random)
				cout << "random " << p->random->label;
			cout << endl;
			p = p->next;
		}

		//拆分成两个单独的链表
		pFront=pHead;
		p=pFront->next;
		pHeadNew=p;
		while(pFront)
		{
			pRear=p->next;
			pFront->next=pRear;
			if(pRear)
				p->next=pRear->next;
			pFront=pRear;
			if(pFront)
				p=pFront->next;
		}
		return pHeadNew;	
    }
};
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
template<typename Elemtype,typename Elemmount>
class TreeSolution {
private:
	  Elemtype *pStartAddress;
	  Elemmount Num;
public:
	 TreeSolution(Elemtype *p,Elemmount num)
	 {
		pStartAddress=(Elemtype*)malloc(num*sizeof(Elemtype));
		for(int i=0;i<num;i++)
			*(pStartAddress+i)=*(p+i);
		Num=num;
	 }
	 TreeSolution()
	 {

	 }
	 ~TreeSolution()
	 {
		 delete pStartAddress;
	 }
	 TreeNode* CreateTree(vector<int> Elem)
	 {
		 int i,size=Elem.size();
		 TreeNode* p=(TreeNode*)malloc(size*sizeof(TreeNode));
		 for(i=0;i<size;i++)
		 {
		 	p[i].val=Elem[i];
			if(2*i+1<=size-1)
				p[i].left=p+2*i+1;
			if(2*i+2<=size-1)
				p[i].right=p+2*i+2;
		 }
		 PreOrder(p);
		 return p;
	 }
	 void ReRangeVector(vector<vector<int>> &Road)
	 {
		 vector<int> VectorSize;
		 int i,j;
		 for(i=0;i<Road.size()-1;i++)
		 	for(j=0;j<Road.size()-1-i;j++)
		 {
			 if(Road[j].size()<Road[j+1].size())
			 	std::swap(Road[j],Road[j+1]);
		 }
	 }
	 //输入整数 打印结点值总和=输入值的路径(从根节点到某个叶节点) 返回的路径中长度大的数组靠前
	 vector<vector<int> > FindPath_NonRecursive(TreeNode* root,int expectNumber) 
	 {
		int i=0,j;
		vector<vector<int> >PathRoad;
		PathRoad.clear();
		stack<TreeNode*> Road;
		stack<TreeNode*> RoadExtra;
		TreeNode *p=root;
		Road.push(p);
		while(!Road.empty())
		{
			p=Road.top();
			while(p->left)
			{
				Road.push(p->left);
				p=p->left;
			}
			if(!p->right)
				{
					int Sum=0;
					stack<TreeNode*> TempRoad;
					while(!Road.empty())
					{
						TempRoad.push(Road.top());
						Road.pop();
					}											
					while(!TempRoad.empty())
					{
						TreeNode* TempVal;
						TempVal=TempRoad.top();
						Sum+=TempVal->val;
						RoadExtra.push(TempVal);
						Road.push(TempVal);
						TempRoad.pop();
					}
					if(Sum==expectNumber)
					{
						while(!RoadExtra.empty())
						{
							PathRoad[i++].push_back(RoadExtra.top()->val);
							RoadExtra.pop();
						}
					}
				}
			else	
				Road.pop();
		}
	 	ReRangeVector(PathRoad);
		return PathRoad;
     }
	//
	//递归版本
	//
	 vector<vector<int>> FindPath(TreeNode *root,int expectNumber)
	 {
		vector<vector<int>> Road;
		vector<int> Path;
		Road.clear();
		if(!root)
			return Road;
		int CurrentSum=0;
		FindPath(root,expectNumber,Path,CurrentSum,Road);
		return Road;
	 }
	 void FindPath(TreeNode *pRoot,int expectSum,vector<int> &path,int &CurrentSum,vector<vector<int>> &Road)
	 {
		CurrentSum+=pRoot->val;
		path.push_back(pRoot->val);
		if(!pRoot->left&&!pRoot->right)
		{
			if (CurrentSum == expectSum)
					Road.push_back(path);
				
		}
		if (pRoot->left)
			FindPath(pRoot->left, expectSum, path, CurrentSum, Road);
		if (pRoot->right)
			FindPath(pRoot->right, expectSum, path, CurrentSum, Road);

		//返回父节点时减去当前节点
		CurrentSum-=pRoot->val;
		//清除路径中的当前节点值
		path.pop_back();
	 }
	 bool IsSubTree(TreeNode *pRoot1,TreeNode *pRoot2)
	{
		//先判断子树是否遍历完成 若未完成而主树为空 则必不为从树
        if(!pRoot2)
            return true;
		if(!pRoot1)
			return false;
       
		if(pRoot1->val==pRoot2->val)//对应的每个子树相应值都相等
			return IsSubTree(pRoot1->left,pRoot2->left)&&IsSubTree(pRoot1->right,pRoot2->right);
        else 
            return false;
	}
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		//空树不是任何一棵树的子树
		if(!pRoot2||!pRoot1)
			return false;
		return IsSubTree(pRoot1,pRoot2)||HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
    }
	/*
	* 二叉树镜像
	*/
	void Mirror(TreeNode *pRoot)
	{
		TreeNode *pTemp;
		if(!pRoot)
			return;
		pTemp=pRoot->left;
		pRoot->left=pRoot->right;
		pRoot->right=pTemp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
	//
	//从上至下 从左至右 按层打印二叉树结点
	//
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		queue<TreeNode*> TreeQueue;
		vector<int> Result;
		Result.clear();
		if(!root)
			return Result;
		TreeQueue.push(root);
		while(!TreeQueue.empty())
		{
			TreeNode *p=TreeQueue.front();
			Result.push_back(p->val);
			if(p->left)
				TreeQueue.push(p->left);
			if(p->right)
				TreeQueue.push(p->right);
			TreeQueue.pop();
		}		
		return Result;
    }
	void PreOrder(TreeNode *pRoot)
	{
		if(!pRoot)
			return;
		cout<<pRoot->val<<" ";
		if(pRoot->left)
			PreOrder(pRoot->left);
		if(pRoot->right)
			PreOrder(pRoot->right);
	}
	
};
class VectorSolution
{
	public:
    vector<int> printMatrix(vector<vector<int> > matrix) 
	{

		vector<int> Result;
		Result.clear();
		int row=matrix.size();//行数
		int column=matrix[0].size();//列数
		if(matrix.empty()||row<=0||column<=0)
			return Result;
		int i,j,endx,endy;
		int start=0;
		while(row>2*start&&column>2*start)
		{
			//结束行标和列标
			endx=column-1-start;
			endy=row-1-start;
			//左->右
			j=start;
			while(j<=endx)
				Result.push_back(matrix[start][j++]);
			//上->下
			if (start < endy)
			{
				i = start + 1;
				while (i <= endy)
					Result.push_back(matrix[i++][endx]);
			}
			//右->左
			if (start < endy && start < endx)
			{
				j = endx - 1;
				while (j >= start)
					Result.push_back(matrix[endy][j--]);
			}
			//下->上
			if (start < endy - 1 && start < endx)
			{
				i = endy - 1;
				while (i >= (start + 1))
					Result.push_back(matrix[i--][start]);
			}
			start++;
		}
		return Result;
    }
};
/*
* 定义栈的数据结构，并在该类型中实现一个能够得到栈中最小元素的min函数,时间复杂度O(1)
*/

class StackMin{
public:
    stack<int> stack1,stack2;
    void push(int value) {
        
        if(stack1.empty())
        {
			stack1.push(value);
            stack2.push(value);
        }
        else
        {
			stack1.push(value);
            if(stack2.top()>value)    
                stack2.push(value);
            else   
            {
                int Temp=stack2.top();
                stack2.push(Temp);
            }
        }
    }
    void pop() {
        if(!stack1.empty())
        {
            stack2.pop();
            stack1.pop();
        }
    }
    int top() {
        if(!stack1.empty())
         return stack1.top();
        
    }
    int min() {
        if(!stack2.empty())
         return stack2.top();
       
    }
};
class StackSolution
{
	private:
		int *Stack;
		int *MinStack;
		int Top;
		int MinTop;
		int Size;
		int Capacity;
	public:
	StackSolution(int capacity)
	{
		Top=-1;
		Size=0;
		Capacity=capacity;
		Stack=new int[capacity];
	}
    void push(int value) {
		if (Size == Capacity)
		{
			cout << "the stack is full" << endl;
			return;
		}
		if (Size == 0)
		{
			Stack[++Top] = value;
			MinStack[++Top] = value;
		}
		else
		{
			if (value < MinStack[MinTop])
				MinStack[++Top] = value;
			else//保证最小栈栈顶元素是最小元素.
			{
				int Temp=MinStack[MinTop];
				MinStack[++MinTop]=Temp;
			}
			Stack[++Top] = value;
		}
		Size++;
    }
    void pop() {
		if(Stack[Top]==MinStack[MinTop])
			MinTop--;
        Top--;
    }
    int top() {
        return Stack[Top];
    }
    int min() {
		return MinStack[MinTop];
    }
};
class StackPopOrderJudge {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) 
	{
		if(pushV.size()!=popV.size())
			return false;
		stack<int> TempStack;
		vector<int>::iterator iter1=popV.begin();
		vector<int>::iterator iter2=pushV.begin();
		//遍历弹出序列
		while(iter1!=popV.end())
		{
			//在压栈序列中找弹出序列 未找到压入辅助栈中
			while(*iter1!=*iter2&&iter2!=pushV.end())
			{
				TempStack.push(*iter2);
				iter2++;
			}
			//弹入序列已遍历完 
			if(iter2==pushV.end())
			{
				while(!TempStack.empty()&&TempStack.top()==*iter1)
				{
					TempStack.pop();
					iter1++;
				}
				if(!TempStack.empty())
					return false;
			}
			else if(*iter1==*iter2)
			{
				iter1++;
				iter2++;
			}
		}
		//弹出栈不为空 
		if(!TempStack.empty())
			return false;
		else
			return true;
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
				
				while(p)
				{
					cout<<"[Key]: "<<p->key<<"--->"<<"[Value]: "<<p->value<<endl;
					p=p->pnext;
				}
				
			}
			void DeatchNode(CacheNode *p)
			{
			
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
					
					while (p->pnext != CacheListPnext)
					{
					
						p = p->pnext;
					}
					DeatchNode(p);
				
					Cache_Hash.erase(p->key);
					
					free(p);
					
				}
			}
	};
	template<typename T=char>
	class Array2D
	{
		private:
			uint32_t NR;    //num of rows
			uint32_t NC;    //num of clolum 
			T *m_data;
		public:
			Array2D(uint32_t nrow,uint32_t ncol)
			{
				NR=nrow;
				NC=ncol;
				m_data=new T[nrow*ncol];
			}
			~Array2D()
			{
				delete []m_data;
			}
		private:
			Array2D(const Array2D&);
			Array2D&operator=(const Array2D);
		public:
			/*return the  array's row and col*/
			inline uint32_t  row(){return NR;}
			inline uint32_t  col(){return NC;}
			/*return the assigened num by given (row,col)*/
			inline T &operator()(int row,int col){return this->m_data[NR*row+col];}
			const inline T& operator()(int row,int col) const {return this->m_data[NR*row+col];}
			inline T* operator[](int row){return &m_data[NC*row];}
			//inline T* operator[](int col){return &m_data[NR*col];}
			inline const T*operator[](int row) const {return &m_data[NC*row];}
			/* clear a value by given*/
			void clear(const T& value)
			{
				for(uint32_t i=0;i<NC*NR;i++)
				{
					if(m_data)
						m_data[i]=value;
				}
			}
		
	};
	template<typename T>
	class Heap
	{
		struct elem
		{
			int key;
			T data;
		};
		private:
			int m_size;
			int m_max;
			elem *pheap;
			/*prevent changing the object by copy and  assignment*/
			Heap(const Heap&);
			Heap&operator=(const Heap&);

		public:
			Heap(int m_max):m_max(m_max)
			{
				m_size=0;
				pheap=new elem[m_max];
			}
			/*pop the minium element*/
			elem Pop()
			{
				int n=m_size-1;
				swap(pheap[0],pheap[n]);// exchange the elem of the first and the end
				down(0,n);
				m_size--;
				return pheap[m_size];//after adjust last elem is the minimum
			}
			void Push(int key,const T& InsertNum)
			{
				int n=m_size;
				pheap[n].data=InsertNum;
				pheap[n].key=key;
				up(n);
				m_size++;
				
			}
			bool Remove(T &InsertValue)
			{
				for(int i=0;i<m_size;i++)
				{
					if(pheap[i].data==InsertValue)
					{
						int n=m_size-1;
						if(n!=i)
						{
							swap(pheap[i], pheap[n]); 
							down(i, m_size);	// adjust  downward
							up(i);			    // adjust  upward
						}
						m_size--;
						return true;
					}
				}
				return false;
			}
			inline void clear()
			{
				m_size=0;
			}
			void Count(){return m_size;}

			/*
			*  test the heap is empty
			*/
			inline bool isempty() const
			{
				return m_size?true:false;
			}

			/*
			*  check there exist elem 
			*/
			bool contain(const T &data)
			{
				for(int i=0;i<m_size;i++)
					if(pheap[i].data==data)
						return true;
				return false;
			}
			void up(int num)
			{
				for(;;)
				{
					int parent=(num-1)/2; // the index start from 0
					if(num==parent||!less(num,parent))// the index num is not smaller than parent node
						break;
					swap(pheap[num],pheap[parent]);
					num=parent;
				}
			}
			void down(int i,int n)/*from the node i start to adjust  */
			{
				for(;;)
				{
					int L=2*i+1;
					if(L<0||L>=n)
						break;
					int M=L;
					int R=M+1;
					if(R<n&&!less(L,R))//chooser the smaller node's index
						M=R;
					if(!less(M,i))//if the smaller child node is bigger than current node return
						break;
					swap(pheap[i],pheap[M]);/*exchange the current and smaller child node*/
					i=M;	/* change the current node*/
				}
			}
			bool less(int i,int j)
			{
				return pheap[i].key<pheap[j].key;
			}
			void printheap()
			{
				for(int i=0;i<m_size;i++)	
					//printf("key:%d value:%s",pheap[i].key,decltype(pheap[i].data)==string?pheap[i].data.c_str():pheap[i].data);
					cout<<" key:"<<pheap[i].key<<" value:"<<pheap[i].data<<";";
				printf("\n");
			}
	};
	/*
	* first in but last out
	*/
	template<typename T=uintptr_t>
	class Stack 
	{
		private:
			class StackEmptyException:public std::exception
			{
				public:
					virtual const char*what() const throw()
					{
						return "stack is empty";
					}
			}excp_empty;
			class StackFullException:public std::exception
			{
				public:
					virtual const char*what() const throw()
					{
						return "index out of bound";
					}
			}excp_bound;
			uint32_t m_Capcity;//total 
			uint32_t m_Size;// current size
			T *pStack;//the elemments
		public:
			Stack(uint32_t	m_capcity)
			{
				m_Capcity=m_capcity;
				m_Size=0;
				pStack=new T[m_Capcity];
			}
			~Stack()
			{
				delete []pStack;
			}
		private:
			Stack(const Stack&);
			Stack& operator=(const Stack&);
		public:
			inline uint32_t Size() const {return m_Size;}
			inline bool push(const T &elem)
			{
				if(m_Size==m_Capcity) return false;
				pStack[m_Size++]=elem;
				return true;
			}
			inline  const T& Top() const
			{
				if(!m_Size) throw excp_empty;
				return pStack[m_Size-1];
			}
			inline void  Pop() 
			{
				if(!m_Size)
					return;
				m_Size--;
			}
			inline bool IsEmpty() const
			{
				return m_Size?true:false;
			}

			inline const T& operator[](uint32_t pos) const
			{
				if(pos<0||pos>=m_Size)
					throw excp_bound;
				return pStack[m_Size-1-pos];
			}
			inline uint32_t Count() const
			{
				return m_Size;
			}
	};
} // namespace alg	
namespace cpporident
{	/*
	class ZooAnimal
	{
		protected:
			string ZooDepart;
			int Age;

	};
	class Engdangered
	{
		protected:
			bool IsExhibit;
	};*/
	class Bear 
	{
		protected:
			string Area;
		public:
			Bear(string area):Area(area)
			{}
	};
	class Panda : private Bear
	{
	  public:
	  	/*
		Panda(string zoopart, string area, int age, bool isexihabit)
			: Bear(area), Engdangered(isexihabit), ZooAnimal(zoopart, age)
		{
		}
		*/
		string color="block";
		Panda(string area):Bear(area)
		{}
		void PrintBaseInfo()
		{
			// oss << "zoopart:" << ZooDepart;
			// oss << "age:" << age;
			cout<<"Area: "<<Area<<" color:"<<color<<endl;
		}
	};
}

namespace copyinitlize
{
	class student
	{
		private:
			char *Sname;
			int A;
		public:
			student(int a)
			{
				A=a;
				Sname=new char[A];
				cout<<"student()"<<endl;
			}
			~student()
			{
				cout<<"~student()"<<endl;
			}
	};
} // copyinitlize

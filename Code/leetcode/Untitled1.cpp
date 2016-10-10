#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
#include<algorithm>
#include<map>
#include<cmath>
#include<set>
#include<stack>
using namespace std;
//
//string output(int n)
//{
//	if (n == 0)
//		return "ling";
//	if (n == 1)
//		return "yi";
//	if (n == 2)
//		return "er";
//	if (n == 3)
//		return "san";
//	if (n == 4)
//		return "si";
//	if (n == 5)
//		return "wu";
//	if (n == 6)
//		return "liu";
//	if (n == 7)
//		return "qi";
//	if (n == 8)
//		return "ba";
//	if (n == 9)
//		return "jiu";
//}
//class A{
//public:
//	A()
//	{
////		f();
//	}
//	virtual void f()
//	{
//		cout << "A--F" << endl;
//	}
//};
//class B: public A{
//
//public:
//	B (){};
//	void f(int i)
//	{
//		cout << "B--F" << endl;
//	}
//};
//struct C
//{
//public:
//	void f()
//	{
//		cout << "C--F" << endl;
//	}
//};

//int main()
//{
//	int number;
//	cin >> number;
//	vector<string> str ;
//	vector<int> hash(10,0);
//	vector<long long> num(10,0);
//	string s;
//	map<char, int> w;
//	vector<char> msort;
//	for (int i = 0; i < number; i++)
//	{
//		cin >> s;
//		str.push_back(s);
//	}
//	for (int i = 0; i < str.size(); i++)
//	{
//		w[str[i][0]] = 1;
//		for (int j = 0; j < str[i].length(); j++)
//		{
//			if (j<str[i].length())
//				num[str[i][j] - 'A'] = num[str[i][j] - 'A']+pow(10, str[i].length() - j - 1);
//		}
//	}
//	for (auto itera = w.begin(); itera != w.end(); itera++)
//		cout << itera->first<<endl;
//	cout << w['A'] <<'A'<< endl;
////	cout << num[0] << endl;
////	cout << num[1] << endl;
//	long long max = 0;
//	int flag = 0;
//	for (int j = 0; j < num.size();j++)
//	{
//		for (int i = 0; i < num.size(); i++)
//		{
//			if (num[i]>=max)
//			{
//				max = num[i];
//				flag = i;
//			}
//		}
//		//w['A' + flag] = max;
//		num[flag] = -1;
//		max = 0;
//		msort.push_back('A' + flag);
//	//	cout << flag<<"  ";
//
//	}
//	cout << endl;
//	int minv=-1;
//	map<char, int>::iterator ite;
//	for (int i = msort.size()-1; i >-1; i--)
//	{
//		ite = w.find(msort[i]);
//	//	cout << ite->second << "sen" << endl;
//		if (ite->second==0)
//		{
//			cout << ite->second << "  sen  " << msort[i] << endl;
//			hash[msort[i] - 'A'] = 0;
//
//			minv = i;
//			break;
//
//		}
//	}
//	int j = 9;
//	for (int i = 0; i < msort.size(); i++)
//	{
//		if (i != minv)
//		{
//			hash[msort[i] - 'A'] = j;
//			j--;
//		}
//	}
//	long long sum = 0;
//	long long val = 0;
//	for (int i = 0; i < 10; i++)
//		cout << hash[i]<<"  "<<msort[i] <<"  "<< endl;
//	for (int i = 0; i < str.size(); i++)
//	{
//		for (int j = 0; j < str[i].length(); j++)
//		{
//			val = val * 10 + hash[str[i][j] - 'A'];
//		}
//		sum = sum + val;
//		val = 0;
//	}
////	cout << sum << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int x, k;
//	cin >> x >> k;
//	int loc = log2(k)+1;
////	cout << loc << endl;
//	int index = 0;
//	int len = log2(x) + 1;
//	int flag = 0;
//	while (index<len)
//	{
//
//		index++;
//		if ((x & 1) == 0)
//			flag++;
//		x = x >> 1;
//	}
//	cout << index<<"  "<<flag<<endl;
//	index = 0;
//	if (loc <= flag)
//	{
//		while (x&1)
//	}
//	int res = 1;
//	for (int i = 0; i<index; i++)
//	{
//		res = res * 2;
//	}
//	cout << pow(2, index);
//	return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	int x, y;
//	cin >> n;
//	int number = 0;
//	vector<int> s;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x >> y;
//		if (x == 1)
//		{
//			s.push_back(y);
//			number++;
//		}
//		else {
//			for (int i = 0; i < s.size(); i++)
//			{
//				if (s[i] == y)
//				{
//					s[i] = 0;
//					break;
//				}
//			}
//			number--;
//		}
//
//		if (number < 3)
//			cout << "No" << endl;
//		else{
//			int max = 0;
//			int sum = 0;
//			for (int i = 0; i < s.size(); i++)
//			{
//				sum = sum + s[i];
//				if (s[i]>max)
//					max = s[i];
//			}
//			if (max > (sum - max))
//				cout << "No" << "  "<<max<<"  "<<sum<<endl;
//			else
//				cout << "Yes" << "  " << max << "  " << sum << endl;
//		}
//
//	}
//
//}
//#include<iostream>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n, K;
//	cin >> n >> K;
//	while (cin)
//	{
//		char** strings = new char*[n];
//		int* index = new int[n];
//		for (size_t i = 0; i < n; i++)
//		{
//			strings[i] = new char[100];
//			cin >> strings[i];
//			index[i] = i;
//
//		}
//		int res = 0;
//		do{
//			char s[99999] = {};
//			char target[99999] = {};
//			for (size_t i = 0; i < n; i++)
//			{
//				strcat(s, strings[index[i + 1]]);
//			}
//			int weight = 0;
//			for (size_t i = 0; i < n; i++)
//			{
//				strcpy(target, s + strlen(s) - i);
//				strcpy(target + strlen(s) - i, s);
//				target[strlen(s)] = 0;
//				if (strcmp(target, s) == 0)
//					weight++;
//			}
//			if (weight == K)
//				res++;
//
//		}
//		while (next_permutation(index, index + n));
//		cout<<res<<endl;
//	}
//
//}
//#include<iostream>
//#include<memory>
//#include<string>
//#include<vector>
//using namespace std;
//bool shareletter(string a, string b)
//{
//	for (int i = 0; i < a.length(); i++)
//	{
//		for (int j = 0; j < b.length(); j++)
//		{
//			if (a[i] == b[j])
//				return true;
//		}
//	}
//	return false;
//}
//int main()
//{
//	vector<string>	words;
//	string w;
//	string max1, max2;
//	int product=0;
//	cin >> w;
//	while (w!="#")
//	{
//		words.push_back(w);
//		cin >> w;
//
//	}
//
//	for (int i = 0; i < words.size(); i++)
//	{
//		for (int j = i; j < words.size(); j++)
//		{
//			if (!shareletter(words[i], words[j]))
//			{
//				if (words[i].length()*words[j].length()>product)
//				{
//					max1 = words[i];
//					max2 = words[j];
//					product = words[i].length()*words[j].length();
//				}
//			}
//		}
//	}
//	cout << max1 << "  " << max2 << endl;
//	cout << product;
//
//	return 0;
//}

//#include<iostream>
//#include<memory>
//#include<string>
//#include<vector>
//using namespace std;
class Hash
{
public:
	int x;
	int y;
	Hash(int i, int j)
	{
		x = i; y = j;
	}
	bool operator < (const Hash b) const
	{
		return (b.y) < y;
	}
	bool operator == (const Hash b) const
	{
		return (b.x) == x;
	}


};
//int main()
//{
//	multiset<Hash> iset;
//	//iset.insert(Hash(1,2));
//	//iset.insert(Hash(2,1));
//	//iset.insert(Hash(3,2));
//	//
//	//cout << iset.begin()->x<<" "<<iset.size()<<" ";
//	vector<int> nums = {1,2};
//	map<int,int> mweight;
//	map<int, int>::iterator imap;
//	int k=2;
//	for (auto iter = nums.begin(); iter != nums.end(); iter++)
//	{
//		imap = mweight.find(*iter);
//		if (imap == mweight.end())
//			mweight[*iter] = 1;
//		else
//			mweight[*iter]++;
//	}
//
//	//cout << mweight[0] << endl;
//	for (auto iter = mweight.begin(); iter != mweight.end(); iter++)
//	{
//		cout << iter->first << "  " << iter->second << endl;
//		iset.insert(Hash(iter->first,iter->second));
//	}
//	set<Hash>::iterator iter = iset.begin();
//	for (int i = 0; i < k; i++)
//	{
//
//		cout << iter->x << endl;
//		iter++;
//	}
//
//	return 0;
//}
//
//
//int main()
//{
//	cout << "type: \t\t" << "************size**************" << endl;
//	cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);
//	cout << "\t最大值：" << (numeric_limits<bool>::max)();
//	cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;
//	cout << "char: \t\t" << "所占字节数：" << sizeof(char);
//	cout << "\t最大值：" << (numeric_limits<char>::max)();
//	cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;
//	cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);
//	cout << "\t最大值：" << (numeric_limits<signed char>::max)();
//	cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;
//	cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);
//	cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();
//	cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;
//	cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);
//	cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();
//	cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;
//	cout << "short: \t\t" << "所占字节数：" << sizeof(short);
//	cout << "\t最大值：" << (numeric_limits<short>::max)();
//	cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;
//	cout << "int: \t\t" << "所占字节数：" << sizeof(int);
//	cout << "\t最大值：" << (numeric_limits<int>::max)();
//	cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;
//	cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);
//	cout << "\t最大值：" << (numeric_limits<unsigned>::max)();
//	cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;
//	cout << "long: \t\t" << "所占字节数：" << sizeof(long);
//	cout << "\t最大值：" << (numeric_limits<long>::max)();
//	cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;
//	cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);
//	cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();
//	cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;
//	cout << "double: \t" << "所占字节数：" << sizeof(double);
//	cout << "\t最大值：" << (numeric_limits<double>::max)();
//	cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;
//	cout << "long double: \t" << "所占字节数：" << sizeof(long double);
//	cout << "\t最大值：" << (numeric_limits<long double>::max)();
//	cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;
//	cout << "long long: \t" << "所占字节数：" << sizeof(long long);
//	cout << "\t最大值：" << (numeric_limits<long long>::max)();
//	cout << "\t最小值：" << (numeric_limits<long long>::min)() << endl;
//	cout << "float: \t\t" << "所占字节数：" << sizeof(float);
//	cout << "\t最大值：" << (numeric_limits<float>::max)();
//	cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;
//	cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);
//	cout << "\t最大值：" << (numeric_limits<size_t>::max)();
//	cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;
//	cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;
//	// << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;
//	cout << "type: \t\t" << "************size**************" << endl;
//
//	return 0;
//
//
//}

#define DEBUG(X) cout<<#X<<"="<<X<<endl;

#pragma pack(16)
struct foo
{
    char c1;
    short s;
    char c2;
    int i;
};
#pragma pack()

#pragma pack(1)
struct foo_pack
{
    char c1;
    short s;
    char c2;
    int i;
};
#pragma pack()

struct stu2
{
      int k;
      short t;
};
int main()
{

    DEBUG(sizeof(stu2))
    DEBUG(sizeof(foo_pack))

    vector<int> test; // 10
    vector<int> test2; // 10

	test.push_back(1);

	DEBUG(sizeof(test))
	DEBUG(sizeof(test2))
	DEBUG(&test)
	DEBUG(&test2)

	string str("hello world");
	for (auto c : str)
		cout << c << " ";
	cout << endl;

	void* ptr;
	int * intptr;

	intptr = (int*)(ptr = &test);
	for (int i = 0; i < sizeof(test); i += 4) {
		cout << intptr << " " << *(intptr) << endl;
		intptr++;
	}
	cout << endl;

	test.push_back(1);
	test.push_back(2);

	intptr = (int*)(ptr = &test);
	for (int i = 0; i < sizeof(test); i += 4) {
		cout << intptr << " " << *(intptr) << endl;
		intptr++;
	}
	cout << endl;

	DEBUG(int(&test[0]));
	DEBUG(int(&test[1]));

//	ptr = test.begin();
 //   DEBUG(ptr)
//    DEBUG(test.end())
	/*
	int *p;
	cout << sizeof(p)<<endl;
	cout << sizeof(test) << endl;
	*/
}


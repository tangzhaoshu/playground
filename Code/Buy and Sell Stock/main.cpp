#include <iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    int a[2] ={1,2};
    vector<int> prices(a,a+2);
    vector<int>:: iterator iter1=prices.begin()+1;
        vector<int>:: iterator iter2=prices.begin();
        vector<int>:: iterator flag=prices.end();
        int maximum=0;
        if(iter2==prices.end()&&prices.size()==1)
        {
            cout<<100<<endl;
            return 0;
        }

        for (iter2=prices.begin();iter2!=prices.end();iter2++)
        {
            if(iter1==prices.end()&&flag!=prices.end())
            {
                maximum=maximum+(*iter2-*flag);
                cout<<maximum;
                return 0;
            }

            if(*iter1>*iter2&&flag==prices.end())
            {
                flag=iter2;
                iter1++;
            }
            else if(*iter1<*iter2&&flag!=prices.end())
            {
                maximum=maximum+(*iter2-*flag);
                flag=prices.end();
                iter1++;
            }
            else
                iter1++;
        }
        cout<<maximum<<endl;
        return 0;
}

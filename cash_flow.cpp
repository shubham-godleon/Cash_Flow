//SPLITWISE CODE MINIMUM CASH FLOW
//GodleoN's code
#include<bits/stdc++.h>
using namespace std;

class comparator{
    public : 
   bool operator()(pair<string,int> p1 , pair<string,int> p2)
   {
       return p1.second < p2.second;
   }
};

int main()
{
int no_of_transactions , friends;
cout << "Enter total no. of friends : " << endl;
cin >> friends ;
cout << "Enter total no. of transactions : " << endl;
cin >> no_of_transactions ;
string x,y;
int amount ;


//maintain list
map<string , int> net;
while(no_of_transactions--)
{
    cout << "The person that has to pay : " << endl;
    cin >> x;
    cout << "The person that gets the money : " << endl;
    cin >> y ;
    cout << "Amount : " << endl;
    cin >> amount ;
    if(net.count(x) == 0)
    {
      net[x] = 0;
    }
    if(net.count(y) == 0)
    {
        net[y] = 0;
    }
    net[x] -= amount;
    net[y] += amount;
}

//min. transaction list

multiset<pair<string , int> , comparator> m ;
for(auto p : net)
{
    string person =p.first;
    int amount = p.second ;

    if(net[person] != 0)
    {
        m.insert(make_pair(person , amount));
    }
}

int count = 0 ;

while(!m.empty())
{
auto low = m.begin();
auto high = prev(m.end());

string debit_person = low->first;
int debit = low->second;

string credit_person = high->first;
int credit = high->second;

m.erase(low);
m.erase(high);

int settled_amount = min(abs(debit) , abs(credit));
debit += settled_amount;
credit -= settled_amount;
count++;

cout << debit_person << " will pay " << settled_amount << " rupees to " << credit_person << endl;

if(debit != 0 )
{
    m.insert(make_pair(debit_person , debit));
}
if(credit != 0)
{
    m.insert(make_pair(credit_person , credit));
}
}
cout << "Total no. of transactions made were : " << count << endl;
}

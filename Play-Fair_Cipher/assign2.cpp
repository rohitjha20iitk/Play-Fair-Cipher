#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s="TR XYCB MH AFC MUVY EOHPTCS, AFCSS TE QCSI NTYIMS TNA AFCSC. EMRBH XAA VAFR MIUCQPUH \"LMRL_CCETOT\" FN HM AKUXAHK. OTA WANA OTXT FFU EISCWNAF HME BFU MCVA UGTOTRE. BM HYLF IFU UVTY ANE HBSEI QYOQM OUVSF AM EAFTE PYHYS XNSKE IFUSC.";
	char table[5][10]={"secur",
			 "ityab",
			 "dfghk",
			  "lmnop",
			  "qvwxz"};
	
	
	vector<char>temp;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			temp.push_back(s[i]);
		}
		if(s[i]>='A'&&s[i]<='Z')
		{
			temp.push_back(s[i]+32);
		}
	}
        vector<char> v; 
		list<int> trck;
	for(int i=0;i<temp.size();i++)
	{
		if(temp[i]!=temp[i+1])
		{
			v.push_back(temp[i]);
			v.push_back(temp[i+1]);
			i++;
		}
		else
		{	
			v.push_back(temp[i]);
			char ch='x';
			v.push_back(ch);
			trck.push_back(v.size()-1);
		}
	}
	unordered_map<char,pair<int,int> > m;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			pair<int,int> p;
			p.first=i;
			p.second=j;
			m[table[i][j]]=p;
		}
	}
	for(auto j:m)
	{
		pair<int,int> p=m[j.first];
		// cout<<p.first<<","<<p.second<<endl;
	}
	for(int i=0;i<v.size();i+=2)
	{
		if(v[i]=='j')
		{
			v[i]='i';
		}
		if(v[i+1]=='j')
		{
			v[i+1]='i';
		}
		pair<int,int> x=m[v[i]];
		pair<int,int> y=m[v[i+1]];
		if(x.first==y.first)
		{
			//do some work	
			if(x.second==0)
			{
				x.second=5;
			}
			if(y.second==0)
			{
				y.second=5;
			}
			v[i]=table[x.first][x.second-1];
			v[i+1]=table[y.first][y.second-1];		
		}
		else
		{
			if(x.second==y.second)
			{
				if(x.first==0)
				{
					x.first=5;
				}
				if(y.first==0)
				{
					y.first=5;
				}
				v[i]=table[x.first-1][x.second];
				v[i+1]=table[y.first-1][y.second];
			}
			else
			{
				v[i]=table[x.first][y.second];
				v[i+1]=table[y.first][x.second];
			}
		}		
	}
	string ans ="";
	for(int i=0;i<v.size();i++)
	{
		if(!trck.empty()){
			if( i!=trck.front()){
				ans = ans+v[i];
			}
			else{
				trck.pop_front();
			}
		}
		else ans = ans+v[i];
		// cout<<v[i];
	}
	cout<<endl;
	// cout<<ans;
	int index =0;
	for(int i =0; i<s.size();i++){
		if(isalpha(s[i])){
			char k = toupper(ans[index]);
			cout<<k;
			index++;
		}
		else cout<<s[i];
	}
	cout<<endl;
    return 0;
}
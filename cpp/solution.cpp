#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <climits>
// #include <map>
//asdsa
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
	int n;cin>>n;
	vector<pair<int,int>> ap(n),bp(n);
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		ap[i]={a[i],i};	
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		bp[i]={b[i],i};	
	}
	sort(ap.begin(),ap.end());
	sort(bp.begin(),bp.end());
	int product = (*max_element(a.begin(),a.end())) *( *max_element(b.begin(),b.end()) );
	for(int i=0;i<n;i++){
		auto new_a=a;
		auto new_b=b;
		new_a[ap[i].second]=new_b[ap[i].second];
		new_b[ap[i].second]=a[ap[i].second];
		
		int new_product =  (*max_element(new_a.begin(),new_a.end())) *( *max_element(new_b.begin(),new_b.end()) );

		
		if(new_product<product){
			product=new_product;
			a=new_a;
			b=new_b;
		}
	}
	for(int i=0;i<n;i++){
		auto new_a=a;
		auto new_b=b;
		new_a[bp[i].second]=new_b[bp[i].second];
		new_b[bp[i].second]=a[bp[i].second];
	
		int new_product =  (*max_element(new_a.begin(),new_a.end())) *( *max_element(new_b.begin(),new_b.end()) );
	
		
		if(new_product<product){
			product=new_product;
			a=new_a;
			b=new_b;
		}
	}		
	cout<<product<<endl;
	
}

signed main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
}
/*
3 11
1 5 7
_____
*/

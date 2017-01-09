#include<iostream>
#include<vector>
#include <algorithm> 
#include<stdio.h>
using  namespace std;

main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		int n;
		cin>>n;
		vector<int> x;
		for(int i=0;i<n;i++){
			int te;
			cin>>te;
			x.push_back(te);
		}
		sort(x.begin(),x.end());
	/*	for (vector<int>::iterator it=x.end()-1; it!=x.begin(); --it)
    			std::cout << ' ' << *it;
    */
    int j=0,c=0;
		for(int i=n-1;i>=0&&j-1<i;i--){
			if(x[i]>60){
			c++;
				
			}else{
				int xt=60/x[i];
				
				int total=x[i];
				while(xt--){
					total+=x[j++];					
				}
				
				c++;	
				//cout<<i<<" "<<j<<" "<<c<<" ";
			}
		}
		cout<<"Case #"<<tt<<": "<<c<<endl;			
    	

	}
	
}

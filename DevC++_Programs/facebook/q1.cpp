#include<iostream>
#include<math.h>
#define PI 3.14159265
using namespace std;

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	long long int T;
	cin>>T;
	for(long long int  TT=1;TT<=T;TT++){
		if(TT!=1) cout<<endl;
		double p,x,y;
		cin>>p>>x>>y;
		
		long long int dist = (x-50)*(x-50)+(y-50)*(y-50);
		if(dist > 2500){
			cout<<"Case #"<<TT<<": white";
		}else{
			double m;
			if(x>50){
				m=(50-y)*1.0/(50-x);
				m= atan (m) * 180 / PI;
				m=90-m;
			}else if(x<50){
				m=(50-y)*1.0/(50-x);
				m= atan (m) * 180 / PI;
				m=270-m;
			}else{
				if(y<50){
					m=180;
				} 
				else {
					m=0;
				}
			}
			//cout<<m<<" ";
			if(m*10<p*36){
				cout<<"Case #"<<TT<<": black";
			}else{
				cout<<"Case #"<<TT<<": white";
			}
		}
		
		
		
	}
	
}

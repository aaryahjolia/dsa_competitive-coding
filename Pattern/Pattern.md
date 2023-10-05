/* this program is written to print multiple types of pyramid */
#include<iostream>
using namespace std;

	void pyramid1()
		{
	     	int i,j,n;
	
			cout<<"enter the vaalue of n"<<endl;
			cin>>n;
				for(i=0;i<n;i++)
   				 	{
						for(j=0;j<=i;j++)
							{
								cout<<" * ";
							}
						cout<<endl;
		
	  			  }	
		}
	
	void pyramid2()
		{
	      	int i,j,n;
			cout<<"enter the vaalue of n"<<endl;
			cin>>n;
				for(i=n;i>0;i--)
    				{
						for(j=1;j<=i;j++)
							{
								cout<<" * ";
							}
						cout<<endl;
	   				 }	
		}
	
	void pyramid3()
		{
		  	int i,j,n,r=1;
			cout<<"enter the vaalue of n"<<endl;
			cin>>n;
				for(i=0;i<n;i++)
  				  	{
						for(j=0;j<=i;j++)
							{
								cout<<"    "<<r++;
							}
							cout<<endl;
	   				 }
		}
	
	void pyramid4()
		{
		  	int i,j,n;
			cout<<"enter the vaalue of n"<<endl;
			cin>>n;
				for(i=0;i<n;i++)
    				{
						for(j=0;j<=i;j++)
							{
								cout<<j<<" ";
							}
							cout<<endl;
	   				}
		}
	
	void pyramid5()
		{
			int i,j,n;
			cout<<"enter the vaalue of n"<<endl;
			cin>>n;
				for(i=0;i<n;i++)
    				{
						for(j=0;j<=i;j++)
							{
								cout<<i<<" ";
							}
							cout<<endl;
	   				}	
		}

int main(){
	

	
	int value;
	
     while(true)
     {
     	 cout<<"press 1 for print increasing order pyramin"<<endl;
     	 cout<<"press 2 for pring decreasing order pyramid"<<endl;
     	 cout<<"press 3 for print number pyramid "<<endl;
     	 cout<<"press 4 to print pyramid which have same number in column"<<endl;
     	 cout<<"press 5 to print pyramid which have same number in row"<<endl;
     	 cout<<"press 6 for exit"<<endl;
     	 cin>>value;
     	 
     	switch(value){
     		
     		case 1 : 
     		    	 
     		        pyramid1();
     		        break;
     		        
     		case 2 :
     			  	pyramid2();
					break;	
					
			case 3 :
					pyramid3();
					break;
					
			case 4 :
				    pyramid4();
				    break;
     		
			case 5 :
			
					pyramid5();
					break;    
     		case 6 :
     				
     				exit(0);
     				break;
     				
     		default : 
     				
     				cout<<"invalid value"<<endl;
     				break;
     				
		 }
     	 
	 }
	return 0;
}
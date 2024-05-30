#include<iostream> 
using namespace std; 
int main()
  {
    int i,j,k,row;
    cout<<"Enter Number of rows: "; 
    cin>>row;

     for(i=1;i<=row;i++)
      {
        for(j=1;j<=row-i;j++)
	   cout<<" ";
        for(k=1;k<=2*i-1;k++)
	 {
	   if(i<row)
	     {
	       if((k==1)||(k==2*i-1))
	           cout<<"*";
	       else
		  cout<<" ";
	     }
	   if(i==row)
	      cout<<"*";
         }
        cout<<endl;
      }

return 0;
 }
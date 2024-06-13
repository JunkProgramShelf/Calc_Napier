#include<stdio.h>
#include<math.h>
#define eps 1.0e-8
#define N 100000

double exponentiation(double x,int n);
double factorical(int n);
double compound_interest();
double calc_e();

int main(){
	double e=0;
	printf("e=%lf",compound_interest());
	printf("\n<==========================>\n");
	printf("e=%lf",calc_e());
	return 0;
}


//exponential function:f(x)=x^n
double exponentiation(double x,int n){
	if(n<=0){
		return 1;
	}else{
		return x * exponentiation(x,n-1);
	}
}
//factorical function:f(x)=x!
double factorical(int n){
	if(n<=0){
		return 1;
	}else{
		return n * factorical(n-1);
	}
}
/*compound interest
	e=lim[n->infinity](1+1/n)^n
*/
double compound_interest(){
	unsigned int count=1;
	double new_data=100.0;
	double old_data=0.0;

	while(fabs(old_data-new_data) > eps){


		old_data = new_data;
		new_data = exponentiation(1.0 +(1.0/(double)count) , count);
		count++;
		if(count>N){
			break;
		}
	}
	return new_data;
}
/*	Maclaurin series
	e =Sum[n->infinity]1/n!
*/
double calc_e(){
	unsigned int count=1;
	double new_data=100.0;
	double old_data=0.0;

	while(fabs(old_data-new_data) > eps){
		old_data=new_data;
		new_data=0.0;
		for(int i=0;i<count;i++){
			new_data += 1.0/(double)factorical(i);
		}
		count++;
	}
	return new_data;
}
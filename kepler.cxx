#include <iostream>
#include <cmath>

using namespace std;

int main (void){
  double H,H0;
  double p[2],pneu[2];
  double q[2],qneu[2];
  const double e=0.6;
  const double tEnd=20*3.141;
  const double dt=0.05;
  const double N=tEnd/dt;
 q[0]=1-e;
 q[1]=0;
 p[0]=0;
 p[1]=sqrt((1+e)/(1-e));
 H0=0.5*(p[0]*p[0]+p[1]*p[1])-1/(sqrt(q[0]*q[0]+q[1]*q[1]));
 
 for(int i=0;i<=N;i++){
   
 H=0.5*(p[0]*p[0]+p[1]*p[1])-1/(sqrt(q[0]*q[0]+q[1]*q[1]));
 
 cout<<i*dt<<"\t"<< H << "\t" << p[0] << "\t" << p[1] << "\t" << q[0] << "\t" << q[1] << endl;
 
 pneu[0]=p[0]-dt*q[0]/(pow(sqrt(q[0]*q[0]+q[1]*q[1]),3));
 pneu[1]=p[1]-dt*q[1]/(pow(sqrt(q[0]*q[0]+q[1]*q[1]),3));
 
 qneu[0]=q[0]+dt*pneu[0];
 qneu[1]=q[1]+dt*pneu[1];
 
 
 
 q[0]=qneu[0];
 q[1]=qneu[1];
 p[0]=pneu[0];
 p[1]=pneu[1];
  
 }
  
  return 0;
}
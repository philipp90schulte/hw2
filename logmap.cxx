/**
* Homework 2
* Author: Philipp Schulte
* Date: 10.11.2015
*
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
        // Declaration of variables
	double x0 = 0.5;
	double x;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	int deltaN = Nend-Nskip;
	double results[deltaN];
        
        // Open / Create a file to save the results.
	ofstream out("output.dat");
	
        //Start for loops to iterate r first and then x
	for(double r=0; r <= 4; r += 0.001){	
	   x=x0;
           // for loop the calculate the first "Nskip" result which shall be not saved in the output file
	   for(int i=1; i <= Nskip; i++)
		   x = r*x*(1-x);

           // For loop to calculate the result x values and save them into an array
	   for(int i=Nskip+1; i <= Nend; i++){
	   		   x = r*x*(1-x);
	   		   results[i-Nskip-1] = x;
   	   }
	   
           // for loop to print out the result values which was saved in the result array.
	   for (int i=0; i<= deltaN; i++) 
		   out << r << "\t" << results[i] << endl;
	   
	   
	}
        // close the result file.
	out.close();
	return 0;
}

#include<Rcpp.h>
#include<vector>
#include<ctime>
#include<cstdlib>
#include"EuropeanOption.h"
#include"getVecMean.h"
#include"getVecStdDev.h"

using namespace Rcpp;
using std::vector;

// [[Rcpp::export]]
double getEuropeanPutPrice(
  int nInt,
  double Strike,
  double Spot,
  double Vol,
  double Rfr,
  double Expiry,
  double B,
  long int nReps = 1000
  ){

	// set the seed
	srand( time(NULL) );

	// create a new instance of a class
	EuropeanOption myEuropean(nInt, Strike, Spot, Vol, Rfr, Expiry,B);

	// call the method to get option price
	double price = myEuropean.getEuropeanPutPrice(nReps);
	
	// return option price  
	return price;
}

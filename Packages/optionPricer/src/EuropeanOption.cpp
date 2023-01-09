#include<iostream>
#include<cmath>
#include <algorithm>
#include"getOneGaussianByBoxMueller.h"
#include"EuropeanOption.h"


//definition of constructor
EuropeanOption::EuropeanOption(
	int nInt_,
	double strike_,
	double spot_,
	double vol_,
	double r_,
	double expiry_,
	double B_
	){
		nInt = nInt_;
		strike = strike_;
		spot = spot_;
		vol = vol_;
		r = r_;
		expiry = expiry_;
		B = B_;
		generatePath();
}

//method definition
void EuropeanOption::generatePath(){
	//generate path for Monte Carlo based on BoxMueller
	double thisDrift = (r * expiry - 0.5 * vol * vol * expiry) / double(nInt);
	double cumShocks = 0;
	thisPath.clear();

	for(int i = 0; i < nInt; i++){
		cumShocks += (thisDrift + vol * sqrt(expiry / double(nInt)) * getOneGaussianByBoxMueller());
		thisPath.push_back(spot * exp(cumShocks));
	}
}

//method definition
double EuropeanOption::getMax(){
	 // get max value of path for barrier check
	double max = 0.0;
	max = *std::max_element(thisPath.begin(), thisPath.end());
	return max;
}

//method definition
void EuropeanOption::printPath(){
	// print generated path
	for(int i = 0;  i < nInt; i++){
		std::cout << thisPath[i] << "\n";
	}

}

//method definition
double EuropeanOption::getEuropeanPutPrice(int nReps){
	//run Monte Carlo simulation
	double rollingSum = 0.0;
	double thisMax = 0.0;
	double thisEnd = 0.0;

	for(int i = 0; i < nReps; i++){
		generatePath();
		thisMax=getMax();
		thisEnd=*thisPath.end();
		//add payout if max value of the path is bigger than the barrier and the price at maturity below the strike price
		rollingSum += (thisMax > B && thisEnd < strike) ? (strike-thisEnd) : 0;
	}
	
	//averaging and discounting returns
	return exp(-r*expiry)*rollingSum/double(nReps);

}

#include<vector>

class EuropeanOption{
public:

	//constructor
	EuropeanOption(
		int nInt_,
		double strike_,
		double spot_,
		double vol_,
		double r_,
		double expiry_,
		double B_
		);

	//destructor
	~EuropeanOption(){};

	//methods
	void generatePath();
	void printPath();
	double getMax();
	double getEuropeanPutPrice(int nReps);
	
	//members
	std::vector<double> thisPath;
	int nInt;
	double strike;
	double spot;
	double vol;
	double r;
	double expiry;
	double B;

};

/**
	Test for the PASF - First-Order Periodic/Aperiodic Separation Filter.
	@author: Hisayoshi Muramatsu
	@date: 2019.12.18
*/

#include <iostream>
#include <fstream>

#include "PASF.cpp"

int main(){
	// Simulation time [s]
	const double tEND = 30;
	// Sampling time [s]
	const double Ts = 0.0001;
	// Fundamental frequency of a periodic signal [rad/s]
	const double w0 = 4.0*M_PI;
	// Time, signal, periodic signal, aperiodic signal, period
	double t(0.0), x(0.0), xp(0.0), xa(0.0), T(0.0);

	/*
	* PASF
	*/
	// Initial periodic signal
	const double xp0 = 0.0;
	// Initial aperiodic signal
	const double xa0 = 0.0;
	// Maximum period [s]
	const double MaxPeriod = 10;
	 // Separated periodic signal, separated aperiodic signal, separation frequency
	double PASFxp(0.0), PASFxa(0.0), p;

	/*
	* Input/Output
	*/
	std::ifstream fin("NOISE.dat"); // Input file
	std::ofstream ofs("DATA.dat"); // Output file

	std::cout << "=====================================" << std::endl;
	std::cout << "            PASF SIMULATION          " << std::endl;
	std::cout << "=====================================" << std::endl;

	// Construct the PASF
	PASF pa(xp0, xa0, MaxPeriod, Ts);

	/**
	* Real-time signal processing simulation
	*/
	do{
		/**
		* Input signal
		*/
		// Periodic signal
		xp = 0.1; // Constant signal
		for(int i(1); i<11; i++){ // Harmonic signals
			xp += 0.1*sin(i*w0*t);
		}
		// Aperiodic signal
		if       (10 < t && t <= 12){ // White noise
			fin >> xa;
		}else if (25 < t && t <= 27){
			fin >> xa;
		}else{
			xa = 0;
		}
		if       (5.125  < t && t <= 5.135){ // Impulse noise
			xa += 1;
		}else if (20.125 < t && t <= 20.135){
			xa += 1;
		}else{
			xa += 0;
		}
		// Input signal
		x = xp + xa;

		/**
		* PASF
		*/
		if (t < 20.0){
			p = 1.0;
		}else{
			p = 0.01;
		}
		T = 2.0*M_PI/w0;
		pa.Separation(x, &PASFxp, &PASFxa, p, T);

		// Display results
		if((int)(t/Ts)%(int)(1/Ts) == 0) {
			std::cout << "---------------- " << (int) t << " s" << " ----------------" << std::endl;
			std::cout << "Separation Frequency      : " << p      << std::endl;
			std::cout << "Separated Periodic Signal : " << PASFxp << std::endl;
			std::cout << "Separated Aperiodic Signal: " << PASFxa << std::endl;
		}
		// Output results
		ofs << t << " " << x << " " << xp << " " << xa << " " << p  << " " << PASFxp << " " << PASFxa << std::endl;

		t += Ts;

	}while(t<=tEND);

	std::cout << "=============== Finish ==============" << std::endl;

	fin.close();
	ofs.close();

	return 0;
}

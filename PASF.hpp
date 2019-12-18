/*
	Implementation of the PASF - First-Order Periodic/Aperiodic Separation Filter.
	@author: Hisayoshi Muramatsu
	@date: 2019.12.18
*/

#ifndef DEF_PASF
#define DEF_PASF

class PASF{
public:
	PASF(
		// Initial periodic signal
	    double IN_xp0,
		// Initial aperiodic signal
	    double IN_xa0,
	    // Maximum period
	    double IN_MaxPeriod,
	    // Sampling time
	    double IN_Ts
	);
	// Separation of signal into periodic and aperiodic signals
	void Separation(double x, double* xp, double* xa, double p, double T);

private:
	// Variables
	double xp, xa, MaxPeriod, Ts;
	int Delaycount1, Delaycount2;
	std::vector<double> DelayMemory1, DelayMemory2;
	// Functions
	double Delay1(double z, double T);
	double Delay2(double z, double T);
};

#endif

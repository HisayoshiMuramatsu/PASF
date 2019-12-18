/*
	Implementation of the PASF - First-Order Periodic/Aperiodic Separation Filter.
	@author: Hisayoshi Muramatsu
	@date: 2019.12.18
*/

#include <vector>
#include <math.h>

#include "PASF.hpp"

PASF::PASF(
		double IN_xp0,
		double IN_xa0,
	    double IN_MaxPeriod,
	    double IN_Ts
	):xp(IN_xp0), xa(IN_xa0), MaxPeriod(IN_MaxPeriod), Ts(IN_Ts)
{
	Delaycount1 = 1;
	Delaycount2 = 1;
	std::vector<double> Memory1((int)((MaxPeriod+0.1)/Ts));
	DelayMemory1 = Memory1;
	std::vector<double> Memory2((int)((MaxPeriod+0.1)/Ts));
	DelayMemory2 = Memory2;
}

void PASF::Separation(double x, double* OUT_xp, double* OUT_xa, double p, double T){
	double xd(0.0), xpd(0.0);

	xd  = Delay1(x, T);
	xpd = Delay2(xp, T);
	xp  = -(T*p-2)/(T*p+2)*xpd + (T*p)/(T*p+2)*(x+xd);
	xa  = x - xp;

	*OUT_xp = xp;
	*OUT_xa = xa;

}

double PASF::Delay1(double z, double T){
	double Output(0.0);

	Output = DelayMemory1[Delaycount1];
	DelayMemory1[Delaycount1] = z;
	Delaycount1++;
	if(Delaycount1==(int)(T/Ts)) Delaycount1=1;

	return Output;
}

double PASF::Delay2(double z, double T){
	double Output(0.0);

	Output = DelayMemory2[Delaycount2];
	DelayMemory2[Delaycount2] = z;
	Delaycount2++;
	if(Delaycount2==(int)(T/Ts)) Delaycount2=1;

	return Output;
}









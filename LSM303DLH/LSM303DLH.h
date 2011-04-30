#ifndef LSM303DLH_h
#define LSM303DLH_h
#include <Wire.h>
#include <vector.h>

class LSM303DLH
{
	public:
		vector a; //accelerometer	
		vector m; //magnetometer
		vector a_max;
		vector a_min;
		vector m_max;
		vector m_min;
	
		LSM303DLH();
		void enable(void);
		void read(void);
		int heading(void);
		int heading(vector from);
		int surge(void);
		int sway(void);
		int heave(void);
		float pitch(void);
		float roll(void);
		void calibrate(void);
};

#endif




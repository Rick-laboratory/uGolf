#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include <math.h>
#include <iomanip>
struct GPS_Data {
	double  Breite = 0;
	double Laenge = 0;
};
//
struct GPS_Data_String {
	std::string Breite;
	std::string Laenge;
};
//
struct Distance_Shot {
	double  Tee_Ball;
	double  Tee_TargetLine;
	double  TargetLine_Ball;
};

class GPS_Distance_Calculator
{
public:


	GPS_Distance_Calculator();
	~GPS_Distance_Calculator();
	const double Abstand_Laengengrad(const double &Laengengrad);
	const double Abstand_zwei_Punkte(const GPS_Data &Erster_Punkt, const GPS_Data &Zweiter_Punkt);
	const double Distantace_Tee_Ball(const GPS_Data &Tee, const GPS_Data &Ball);
	GPS_Data Lot_Punkt_bestimmen(const GPS_Data &Abschlag, const GPS_Data &Ziel, const GPS_Data &Ball);
	const double Grad_DM_To_DGrad(const std::string a);
	const double Grad_DM_To_DGrad(const double &a);
//	void All_GPS_to_Dezimalgrad();
	void set_Abstand_Laengengrade(double value)
	{
		Abstand_Laengengrade = value;
	}
	Distance_Shot DistanceStrike;
	GPS_Data Tee, Target, Ball, Hilfs_Vektor, Lotpunkt;


private:
	const double Radius_Earth = 6371000;	
	const double Abstand_Breiten = 111194;	
	double Abstand_Laengengrade; 			
	const double PI = 3.14159265359;


//	GPS_Data_String GNGLL_Tee{ "5150.2894341", "716.0578924" };
//	GPS_Data_String GNGLL_Target{ "5150.2894615", "716.0578808" };
//	GPS_Data_String GNGLL_Ball{ "5150.2894638", "716.0577722" };
	
};


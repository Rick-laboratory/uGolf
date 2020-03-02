#include "GPS_Distance_Calculator.h"
#include <QString>
using namespace std;

GPS_Distance_Calculator::GPS_Distance_Calculator()
{
}

GPS_Distance_Calculator::~GPS_Distance_Calculator()
{
}

const double GPS_Distance_Calculator::Abstand_Laengengrad(const double &Laengengrad)
{	
	double  Abstand_Laengen;
	double  Laengengrad_Grad = Laengengrad * PI / 180;
	Abstand_Laengen = cos(Laengengrad_Grad) * 2 * PI * Radius_Earth / 360;
	return Abstand_Laengen;
}
const double GPS_Distance_Calculator::Abstand_zwei_Punkte(const GPS_Data &Erster_Punkt, const GPS_Data &Zweiter_Punkt)
{
	double  Abstand = 0;
	Hilfs_Vektor.Breite = Erster_Punkt.Breite - Zweiter_Punkt.Breite;
	Hilfs_Vektor.Laenge = Erster_Punkt.Laenge - Zweiter_Punkt.Laenge;
	cout << "Zwischenergebniss aus FKT Abstand_zwei_Punkte" << endl;
	cout << Hilfs_Vektor.Breite << Hilfs_Vektor.Laenge << endl;
	Abstand = sqrt(((Hilfs_Vektor.Breite * Abstand_Breiten) * (Hilfs_Vektor.Breite * Abstand_Breiten)) + ((Hilfs_Vektor.Laenge * Abstand_Laengengrad(Erster_Punkt.Laenge)) * (Hilfs_Vektor.Laenge * Abstand_Laengengrad(Erster_Punkt.Laenge))));
	return Abstand;
}
const double GPS_Distance_Calculator::Distantace_Tee_Ball(const GPS_Data &Tee, const GPS_Data &Ball)
{	
	double  Distance_Calc;
	Hilfs_Vektor.Breite = Ball.Breite - Tee.Breite;
	Hilfs_Vektor.Laenge = Ball.Laenge - Tee.Laenge;
	Distance_Calc = sqrt(((Hilfs_Vektor.Breite * Abstand_Breiten) * (Hilfs_Vektor.Breite * Abstand_Breiten)) + ((Hilfs_Vektor.Laenge * Abstand_Laengengrade) * (Hilfs_Vektor.Laenge * Abstand_Laengengrade)));
	return Distance_Calc;
}
GPS_Data GPS_Distance_Calculator::Lot_Punkt_bestimmen(const GPS_Data &Abschlag, const GPS_Data &Ziel, const GPS_Data &Ball)
{
	double  skalarfaktor;
	skalarfaktor = ((-Abschlag.Breite * Abschlag.Breite + Ball.Breite * (Abschlag.Breite) + Abschlag.Breite * (Ziel.Breite) - Ball.Breite * 
		Ziel.Breite - Abschlag.Laenge * Abschlag.Laenge + Ball.Laenge * Abschlag.Laenge + Abschlag.Laenge * Ziel.Laenge - Ball.Laenge * Ziel.Laenge) /
		(2 * Ziel.Breite * Abschlag.Breite - Abschlag.Breite * Abschlag.Breite - Ziel.Breite * Ziel.Breite + 2 * Ziel.Laenge * Abschlag.Laenge - Abschlag.Laenge * Abschlag.Laenge - Ziel.Laenge * Ziel.Laenge));
	Lotpunkt.Breite = Abschlag.Breite + skalarfaktor * (Ziel.Breite - Abschlag.Breite);
	Lotpunkt.Laenge = Abschlag.Laenge + skalarfaktor * (Ziel.Laenge - Abschlag.Laenge);
	cout.precision(8);
	cout << "******Aus FKT Lot_Punkt_Bestimmen -> Skalarfaktor:\t" << skalarfaktor << endl;
	cout << "******Aus FKT Lot_Punkt_Bestimmen -> Lotpunkt_Breite; \t" << Lotpunkt.Breite << endl;
	cout << "******Aus FKT Lot_Punkt_Bestimmen -> Lotpunkt_Länge; \t" << Lotpunkt.Laenge << endl;
	return Lotpunkt;
}
const double GPS_Distance_Calculator::Grad_DM_To_DGrad(const string a)
{
	double grad = 0;
	double DMGrad = 0, fminuten = 0;
	//cout.precision(8);
	setprecision(15);
	QString Tmpqstr = QString::fromStdString(a);
	double dummy = Tmpqstr.toDouble();
	grad = dummy / 100;
	fminuten = ((dummy - grad * 100) * 10 / 6) / 100;
	DMGrad = grad + fminuten;
	return DMGrad;
}
const double GPS_Distance_Calculator::Grad_DM_To_DGrad(const double &a)
{
	double grad = 0;
	double DMGrad = 0, fminuten = 0;
	grad = a / 100;								
	fminuten = ((a - grad * 100) * 10 / 6) / 100;
	DMGrad = grad + fminuten;					
	return DMGrad;
}
//void GPS_Distance_Calculator::All_GPS_to_Dezimalgrad() {
//	Tee.Breite = Grad_DM_To_DGrad(GNGLL_Tee.Breite);
//	Tee.Laenge = Grad_DM_To_DGrad(GNGLL_Tee.Laenge);
//	Target.Breite = Grad_DM_To_DGrad(GNGLL_Target.Breite);
//	Target.Laenge = Grad_DM_To_DGrad(GNGLL_Target.Laenge);
//	Ball.Breite = Grad_DM_To_DGrad(GNGLL_Ball.Breite);
//	Ball.Laenge = Grad_DM_To_DGrad(GNGLL_Ball.Laenge);
//}
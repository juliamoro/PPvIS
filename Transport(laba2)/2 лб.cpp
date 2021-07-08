#include "Transport.h"



using namespace transport;
using namespace std;

int main()
{
	cout << "Transport" << endl;

	Transport tr;
	tr.set_maxSpeed(500);
	tr.set_type_fuel("Autogas PBA");
	cout << tr.get_maxSpeed() << " " << tr.get_type_fuel() << " ";
	tr.signal();

	cout << endl;

	cout << "Public-transport" << endl;

	Public_transport tr_p;
	tr_p.set_cost(1.0);
	tr_p.set_number_people(5);
	cout << tr_p.get_cost() << " " << tr_p.get_number_people() << endl;

	cout << "Plane" << endl;

	Plane An_2;
	An_2.set_maxSpeed(180);
	An_2.set_type_fuel("B-91");
	An_2.set_flight_view("Chartered flight");
	cout << An_2.get_maxSpeed() << " " << An_2.get_type_fuel() << " " << An_2.get_flight_view()<< endl;

	cout << "Car" << endl;

	Car bmw_x5;
	bmw_x5.set_maxSpeed(300);
	bmw_x5.set_type_fuel("B-91");
	bmw_x5.set_haveCruise_control(true);
	cout << bmw_x5.get_maxSpeed() << " " << bmw_x5.get_type_fuel() << " " << bmw_x5.get_haveCruise_control() << endl;

	cout << "Metro" << endl;

	Metro R179;
	R179.set_cost(0.70);
	R179.set_number_people(36);
	R179.set_maxSpeed(89);
	R179.set_type_fuel("electricity");
	R179.set_railway_carriage(6);
	cout << R179.get_cost() << " " << R179.get_number_people() << " " << R179.get_maxSpeed() << " " << R179.get_type_fuel() << " "
		<< R179.get_railway_carriage() << " ";
	R179.signal();

	cout << endl << "Bus" << endl;

	Bus MAZ_303;
	MAZ_303.set_maxSpeed(80);
	MAZ_303.set_type_fuel("diesel");
	MAZ_303.set_Tier(1);
	cout <<  MAZ_303.get_maxSpeed() << " " << MAZ_303.get_type_fuel() << " "
		<< MAZ_303.get_Tier() << "  " << endl;

	cout << "Helicopter" << endl;

	Helicopter ME_24;
	ME_24.set_lifting_height(320);
	ME_24.set_haveWeapon(false);
	cout << ME_24.get_haveWeapon() << " " << ME_24.get_lifting_height() << " " << " ";
	ME_24.signal();
	cout << endl;

	cout << "Ship" << endl;

	Ship A_13;
	A_13.set_deck(1);
	A_13.set_haveSail(true);
	cout << A_13.get_deck() << " " << A_13.get_haveSail() << endl;

	cout << "Flying-Car" << endl;

	Flying_Сar	Lightning;
	Lightning.set_haveCruise_control(true);
	Lightning.set_maxSpeed(1230);
	Lightning.set_type_fuel("Natural gas");
	Lightning.set_start("Turbo acceleration");
	cout << Lightning.get_haveCruise_control() << " " << Lightning.get_maxSpeed() << " " << Lightning.get_type_fuel() << " " << Lightning.get_start() << endl;

}

#include "Transport.h"


void transport::Transport::set_maxSpeed(int maxSpeed)
{
	Transport::maxSpeed = maxSpeed;
}

int transport::Transport::get_maxSpeed()
{
	return Transport::maxSpeed;
}

void transport::Transport::set_type_fuel(std::string type_fuel)
{
	Transport::type_fuel = type_fuel;
}

std::string transport::Transport::get_type_fuel()
{
	return std::string(type_fuel);
}

void transport::Transport::signal()
{
	std::cout << "Start" << std::endl;
}

void transport::Public_transport::set_cost(double cost)
{
	Public_transport::cost = cost;
}

double transport::Public_transport::get_cost()
{
	return Public_transport::cost;
}

void transport::Public_transport::set_number_people(int number_people)
{
	Public_transport::number_people = number_people;
}

int transport::Public_transport::get_number_people()
{
	return Public_transport::number_people;
}

void transport::Plane::set_flight_view(std::string flight_view)
{
	Plane::flight_view = flight_view;
}

std::string transport::Plane::get_flight_view()
{
	return std::string(flight_view);
}

void transport::Car::set_haveCruise_control(bool haveCruise_control)
{
	Car::haveCruise_control = haveCruise_control;
}

bool transport::Car::get_haveCruise_control()
{
	return haveCruise_control;
}

void transport::Metro::set_railway_carriage(int railway_carriage)
{
	Metro::railway_carriage = railway_carriage;
}

int transport::Metro::get_railway_carriage()
{
	return railway_carriage;
}

void transport::Metro::signal()
{
	std::cout << "Vzhik" << std::endl;
}

void transport::Bus::set_Tier(int Tier)
{
	Bus::Tier = Tier;
}

int transport::Bus::get_Tier()
{
	return Tier;
}

void transport::Helicopter::set_lifting_height(int lifting_height)
{
	Helicopter::lifting_height = lifting_height;
}

int transport::Helicopter::get_lifting_height()
{
	return lifting_height;
}

void transport::Helicopter::set_haveWeapon(bool haveWeapon)
{
	Helicopter::haveWeapon = haveWeapon;
}

bool transport::Helicopter::get_haveWeapon()
{
	return haveWeapon;
}

void transport::Helicopter::signal()
{
	std :: cout<<"whoo-whoo"<< std::endl;
}

void transport::Ship::set_haveSail(bool haveSail)
{
	Ship::haveSail = haveSail;
}

bool transport::Ship::get_haveSail()
{
	return haveSail;
}

void transport::Ship::set_deck(int deck)
{
	Ship::deck = deck;
}

int transport::Ship::get_deck()
{
	return deck;
}

void transport::Flying_Ñar::set_start(std::string start)
{
	Flying_Ñar::start = start;
}

std::string transport::Flying_Ñar::get_start()
{
	return std::string(start);
}

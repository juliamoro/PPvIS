#include <string>
#include <iostream>

namespace transport
{
	class Transport {
	public:
		void set_maxSpeed(int maxSpeed);
		int get_maxSpeed();
		void set_type_fuel(std::string type_fuel);
        std::string get_type_fuel();
		virtual void signal();
	protected:
		int maxSpeed;
		std::string type_fuel;
	};

	class Public_transport {
	protected:
		int number_people;
		double cost;
	public:
		void set_cost(double cost);
		double get_cost();
		void set_number_people(int number_people);
		int get_number_people();
	};

	class Plane : virtual public Transport {
	protected:
		std::string flight_view;
	public:
		void set_flight_view(std::string flight_view);
		std::string get_flight_view();
	};

	class Car : virtual public Transport {
	protected:
		bool haveCruise_control;
	public:
		void set_haveCruise_control(bool haveCruise_control);
		bool get_haveCruise_control();
	};

	class Metro : public Transport, public Public_transport {
	protected:
		int railway_carriage;
	public:
		void set_railway_carriage(int railway_carriage);
		int get_railway_carriage();
		void signal() override;
	};

	class Bus : public Transport {
	protected:
		 int Tier;
	public:
		void set_Tier(int Tier);
		int get_Tier();
	};

	class Helicopter : private Transport {
	protected:
		int lifting_height;
		bool haveWeapon;
	public:
		void set_lifting_height(int lifting_height);
		int get_lifting_height();
		void set_haveWeapon(bool haveWeapon);
		bool get_haveWeapon();
		void signal() override;
	};

	class Ship : protected Transport {
	public:
		void set_haveSail(bool haveSail);
		bool get_haveSail();
		void set_deck(int deck);
		int get_deck();
	private:
		bool haveSail;
		int deck;
	};

	class Flying_Ñar : public Car, public Plane {
	private:
		std::string start;
	public:
		void set_start(std::string start);
		std::string get_start();
	};

}


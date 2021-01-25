#include <iostream>

using namespace std;

class PlayingField {
	int size_;
	int** field_;
	bool player_ = true;
	int horizontal_check();
	int vertical_check();
	int diagonal_check();
	bool figure_pres(int line_choice, int col_choice);
public:
	PlayingField(int size);
	~PlayingField();
	int* operator[] (int line);
	bool set_figure(int line_choice, int col_choice);
	void cheat(int line_choice, int col_choice, int figure);
	void field_output();
	bool field_boundaries(int line_choice, int col_choice);
	bool get_player() { return player_; }
	int check();
	bool draw_check();
};
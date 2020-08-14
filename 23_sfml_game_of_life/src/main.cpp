
#include "SFML/Graphics.hpp"
#include "sfml_app.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include "../../thirdparty/simpleini/SimpleIni.h"

void hide_console()
{
#ifdef _WIN32
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
#endif
}


std::pair<unsigned int, unsigned int> preferred_window_size;
std::pair<unsigned int, unsigned int> preferred_cell_size;
sf::Color living_cell_color_;
sf::Color dead_cell_color_;
sf::Color text_color_;
unsigned character_size_;
int duration_in_millis_between_updates;
bool infinite_map;
std::string pattern;

void initSetup(const std::string& file_name)
{
	CSimpleIniA ini;
	char rc = ini.LoadFile(file_name.c_str());

	CSimpleIniA::TNamesDepend sections;
	ini.GetAllSections(sections);

	preferred_window_size.first = atoi(ini.GetValue("window", "window_size.x"));
	preferred_window_size.second = atoi(ini.GetValue("window", "window_size.y"));
	preferred_cell_size.first = atoi(ini.GetValue("window", "cell_size.x"));
	preferred_cell_size.second = atoi(ini.GetValue("window", "cell_size.y"));

	living_cell_color_ = sf::Color(atoi(ini.GetValue("living_cell_color", "r")), atoi(ini.GetValue("living_cell_color", "g")), atoi(ini.GetValue("living_cell_color", "b")));
	dead_cell_color_ = sf::Color(atoi(ini.GetValue("dead_cell_color", "r")), atoi(ini.GetValue("dead_cell_color", "g")), atoi(ini.GetValue("dead_cell_color", "b")));
	text_color_ = sf::Color(atoi(ini.GetValue("text_color", "r")), atoi(ini.GetValue("text_color", "g")), atoi(ini.GetValue("text_color", "b")));
	character_size_ = atoi(ini.GetValue("text", "character_size"));

	duration_in_millis_between_updates = atoi(ini.GetValue("animation", "duration_in_millis_between_updates"));

	pattern = ini.GetValue("matrix", "pattern");

	std::string s = ini.GetValue("matrix", "infinite_map");
	infinite_map = (s == "true");
}

int main()
{
	hide_console();
	// TODO: maybe load from a configuration file? INI file?
	initSetup("../../data/23_sfml_game_of_life.ini");

	SfmlApp app(preferred_window_size, preferred_cell_size);
	app.init(living_cell_color_, dead_cell_color_, text_color_, character_size_);
	app.game.DrawShape(pattern);
	app.game.infinite_map = infinite_map;
	app.run(duration_in_millis_between_updates);
}
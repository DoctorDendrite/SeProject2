
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.h"
#include "..\game\screens.h"

#define pass(name, value) \
std::cout << name << ": [" << value << "]\n"

#define pause(name, value) \
pass(name, value); \
std::cin.get()

TEST_CASE("GetRotationAngle")
{
	REQUIRE(GetRotationAngle(sf::Vector2f({ 5, 4 })) == 38.65981f);
	REQUIRE(GetRotationAngle(sf::Vector2f({ 1, 0 })) == 0.0f);
	REQUIRE(GetRotationAngle(sf::Vector2f({ 1, 1 })) == 45.0f);
	REQUIRE(GetRotationAngle(sf::Vector2f({ 1999999, 2000000 })) == Approx(45.00002f).epsilon(0.0001));
	REQUIRE(GetRotationAngle(sf::Vector2f({ 1, 2000000 })) == Approx(89.99996f).epsilon(0.00001));
	REQUIRE(GetRotationAngle(sf::Vector2f({ 2000, 1 })) == Approx(0.0286478873f).epsilon(0.00001));
}

TEST_CASE("NewPlayerVelocity")
{
	auto temp = NewPlayerVelocity(200.0f, 40.0f, 1, 0, 1, 0);
	REQUIRE(temp.x == -8000.f);
	REQUIRE(temp.y == -8000.f);

	temp = NewPlayerVelocity(200.1f, 40.1f, 1, 0, 1, 0);
	REQUIRE(temp.x == -8024.01f);
	REQUIRE(temp.y == -8024.01f);

	temp = NewPlayerVelocity(200.0f, 40.0f, 0, 1, 0, 1);
	REQUIRE(temp.x == 8000.f);
	REQUIRE(temp.y == 8000.f);

	temp = NewPlayerVelocity(200.1f, 40.1f, 0, 1, 0, 1);
	REQUIRE(temp.x == 8024.01f);
	REQUIRE(temp.y == 8024.01f);

	// pass("x", temp.x);
	// pass("y", temp.y);
}

TEST_CASE("ObjectOutOfBounds")
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(80, 80), "", sf::Style::Default);
	pass("Size", window.getSize().x);
	pass("Size", window.getSize().y);
	pass("Out of bounds", ObjectOutOfBounds(window, sf::Vector2f({ 4, 5 }), sf::Vector2f({ 50, 50 })));
	pass("Out of bounds", ObjectOutOfBounds(window, sf::Vector2f({ 45, 46 }), sf::Vector2f({ 50, 50 })));
	pass("Out of bounds", ObjectOutOfBounds(window, sf::Vector2f({ 30, 31 }), sf::Vector2f({ 50, 50 })));
	window.close();
}

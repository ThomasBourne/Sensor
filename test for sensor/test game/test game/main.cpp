#include <sensor.hpp> //bundles standard include files as well as entry loop
#include <conio.h>

const sensor::vec2i TL (sensor::vec2i(100, 100)); //top left pos of player
const sensor::vec2i TR (sensor::vec2i(200, 100)); //top Right of player
const sensor::vec2i BL (sensor::vec2i(100, 200)); //bottom left pos of player
const sensor::vec2i BR (sensor::vec2i(200, 200)); //bottom right pos of player

const sensor::recti START_POS(TL, TR, BL, BR);

const int TILE_SIZE{ 100 };
const sensor::vec2<int> TILE (TILE_SIZE);

sensor::recti player (TL, TR, BL, BR);
sensor::rgb playerColour = sensor::Colour.blue;

int maze[20][11] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1},
	{1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1},
	{1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1},
	{1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1},
	{1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1},
	{1, 0, 1, 0, 1, 2, 1, 1, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void MovePlayer(sensor::recti*);
void kill();

sensor_win::setup inline PreDef() {
	player.colour = playerColour;
	sensor_win::setup obj{ sensor_win::setup(600, 600, L"Maze Game", true) };
	return obj;
}

int inline SensorUpdate(HDC hdc) { //work out how to retrive thread ret vals as this does nothing
	
	MovePlayer(&player);

	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 11; y++)
		{
			sensor::vec2i truePos(x * TILE_SIZE, y * TILE_SIZE);
			if (maze[x][y] == 1) { //has to have == as check for other numbers not 0 | 1
				sensor::recti wall = sensor::recti(
					truePos, sensor::vec2i(truePos.x + TILE_SIZE, truePos.y),
					sensor::vec2i(truePos.x, truePos.y + TILE_SIZE), sensor::vec2i(truePos.x + TILE_SIZE, truePos.y + TILE_SIZE)
				);
				wall.render(hdc);
				if (player.p1.x == wall.p1.x && player.p1.y == wall.p1.y)
					kill();
			}
			else if (x * TILE_SIZE == START_POS.p1.x && y * TILE_SIZE == START_POS.p1.y) {
				sensor::recti indicator = sensor::recti(
					truePos, sensor::vec2i(truePos.x + TILE_SIZE, truePos.y),
					sensor::vec2i(truePos.x, truePos.y + TILE_SIZE), sensor::vec2i(truePos.x + TILE_SIZE, truePos.y + TILE_SIZE)
				);
				indicator.colour = sensor::Colour.yellow;
				indicator.render(hdc);
			}
			else if (maze[x][y] == 2) { //has to have == as check for other numbers not 0 | 1
				sensor::recti goal = sensor::recti(
					truePos, sensor::vec2i(truePos.x + TILE_SIZE, truePos.y),
					sensor::vec2i(truePos.x, truePos.y + TILE_SIZE), sensor::vec2i(truePos.x + TILE_SIZE, truePos.y + TILE_SIZE)
				);
				goal.colour = sensor::Colour.green;
				goal.render(hdc);
				if (player.p1.x == goal.p1.x && player.p1.y == goal.p1.y) {
					kill();
					exit(0);
				}
			}
			/*else {
				sensor::recti floor = sensor::recti(
					truePos, sensor::vec2i(truePos.x + TILE_SIZE, truePos.y),
					sensor::vec2i(truePos.x, truePos.y + TILE_SIZE), sensor::vec2i(truePos.x + TILE_SIZE, truePos.y + TILE_SIZE)
				);
				floor.colour = sensor::Colour.grey;
				floor.render(hdc);
			}*/
		}
	}


	player.render(hdc);

	return 0;
}

void MovePlayer(sensor::recti* player) {
	if (KEY::W)
		player->move(sensor::vec2i(0, -100));
	if (KEY::A)
		player->move(sensor::vec2i(-100, 0));
	if (KEY::S)
		player->move(sensor::vec2i(0, 100));
	if (KEY::D)
		player->move(sensor::vec2i(100, 0));
}

void kill() {
	player = sensor::recti(TL, TR, BL, BR);
	player.colour = playerColour;
}
#include <iostream>
#include <conio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

enum class Direction { Up, Down, Left, Right };

class GameObject {
public:
	int x, y;
	char symbol;
	
	GameObject(int x, int y, char symbol) : x(x), y(y), symbol(symbol) {}
	
	virtual void Draw() const {
		std::cout << symbol << " ";
	}
	
	virtual bool CanMove(Direction direction, const std::vector<GameObject*>& objects) const {
		int newX = x, newY = y;
		switch (direction) {
		case Direction::Up:
			newY--;
		break;
		case Direction::Down:
			newY++;
		break;
		case Direction::Left:
			newX--;
		break;
		case Direction::Right:
			newX++;
		break;
		}
		for (const auto& obj : objects) {
			if (obj->x == newX && obj->y == newY) {
				return false;
			}
		}
		return true;
	}
	
	virtual void Move(Direction direction, std::vector<GameObject*>& objects) {
		if (CanMove(direction, objects)) {
			switch (direction) {
			case Direction::Up:
				y--;
			break;
			case Direction::Down:
				y++;
			break;
			case Direction::Left:
				x--;
			break;
			case Direction::Right:
				x++;
			break;
			}
		}
	}
};

class Frog : public GameObject {
public:
	Frog(int x, int y) : GameObject(x, y, 'F') {}
	
	void Move(Direction direction, std::vector<GameObject*>& objects) override {
		if (CanMove(direction, objects)) {
			switch (direction) {
			case Direction::Up:
				y--;
			break;
			case Direction::Down:
				y++;
			break;
			case Direction::Left:
				x--;
			break;
			case Direction::Right:
				x++;
			break;
			}
		}
	}
};

class Car : public GameObject {
public:
	Car(int x, int y) : GameObject(x, y, 'C') {}
	
	void Move(Direction direction, std::vector<GameObject*>& objects) override {
		if (CanMove(direction, objects)) {
			switch (direction) {
			case Direction::Up:
				y--;
			break;
			case Direction::Down:
				y++;
			break;
			case Direction::Left:
				x--;
			break;
			case Direction::Right:
				x++;
			break;
			}
		}
	}
};

class Log : public GameObject {
public:
	Log(int x, int y) : GameObject(x, y, 'L') {}
	
	bool CanMove(Direction direction, const std::vector<GameObject*>& objects) const override {
		int newX = x, newY = y;
		switch (direction) {
		case Direction::Up:
			newY--;
		break;
		case Direction::Down:
			newY++;
		break;
		case Direction::Left:
			newX--;
		break;
		case Direction::Right:
			newX++;
		break;
		}
		for (const auto& obj : objects) {
			if (obj->x == newX && obj->y == newY) {
				return false;
			}
		}
		return true;
	}
};

class GameManager {
public:
	void StartGame() {
		srand(time(0));
		std::vector<GameObject*> objects;
		objects.push_back(new Frog(5, 5));
		for (int i = 0; i < 10; i++) {
			objects.push_back(new Car(rand() % 10, rand() % 10));
		}
		for (int i = 0; i < 5; i++) {
			objects.push_back(new Log(rand() % 10, rand() % 10));
		}
		while (true) {
			system("cls");
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					bool found = false;
					for (const auto& obj : objects) {
						if (obj->x == i && obj->y == j) {
							obj->Draw();
							found = true;
							break;
						}
					}
					if (!found) {
						std::cout << "  ";
					}
				}
				std::cout << std::endl;
			}
			char key = _getch();
			if (key == 'w' || key == 'W') {
				objects[0]->Move(Direction::Up, objects);
			} else if (key == 's' || key == 'S') {
				objects[0]->Move(Direction::Down, objects);
			} else if (key == 'a' || key == 'A') {
				objects[0]->Move(Direction::Left, objects);
			} else if (key == 'd' || key == 'D') {
				objects[0]->Move(Direction::Right, objects);
			}
		}
	}
};

int main() {
	GameManager manager;
	manager.StartGame();
	return 0;
}

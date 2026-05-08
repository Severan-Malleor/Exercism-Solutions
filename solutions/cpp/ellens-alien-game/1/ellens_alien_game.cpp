namespace targets {
	
	class Alien {
	public:
		int x_coordinate{ 0 };
		int y_coordinate{ 0 };


		// Initializer List (Recommended)
		/*
			Initializer List = You tell the construction crew exactly what materials to use while building the foundation.
			Assignment = You build the house with default cheap materials first, then go back and replace them with the good ones later.
		*/

		Alien(int x, int y) : x_coordinate(x), y_coordinate(y) {}

		int get_health() {
			return health;
		}

		bool hit() {
			// Alien takes 1 point of damage when hit, only if it is still alive.
			if (health <= 0) {
				return false;
			}
			health--;
			return true;
		}

		bool is_alive() {
			return health > 0;
		}

		bool teleport(int x_new, int y_new) {
			x_coordinate = x_new;
			y_coordinate = y_new;

			return true;
		}

		bool collision_detection(Alien alien) {
			return (x_coordinate == alien.x_coordinate) && (y_coordinate == alien.y_coordinate);
		}

	private:
		// Encapsulation = Hiding the internal state of an object and requiring all interaction to be performed through an object's methods.
		// Cannot access private members outside of the class, but can access them within the class.
		int health{ 3 };

	};

}  // namespace targets

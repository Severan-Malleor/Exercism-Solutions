namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
	enum class AccountStatus {
		troll,
		guest,
		user,
		mod
	};

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
	enum class  Action {
		read,
		write,
		remove
	};

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
	bool display_post(AccountStatus poster, AccountStatus viewer) {
		if (poster == AccountStatus::troll && viewer != AccountStatus::troll) {
			return false;
		}
		else {
			return true;
		}
	}

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
	bool permission_check(Action action, AccountStatus status) {
		
		switch (action) {
		case Action::read:
			return true;
		case Action::write:
			if (status == AccountStatus::guest) {
				return false;
			}
			else {
				return true;
			}
		case Action::remove:
			if (status == AccountStatus::mod) {
				return true;
			}
			else {
				return false;
			}
		default:
			return false;
		}
	}

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
	bool valid_player_combination(AccountStatus player_one, AccountStatus player_two) {

		if (player_one == AccountStatus::guest || player_two == AccountStatus::guest) {
			return false;
		}
		else if ((player_one != AccountStatus::troll && player_two != AccountStatus::troll) || (player_one == AccountStatus::troll && player_two == AccountStatus::troll)) {
			return true;
		}
		else {
			return false;
		}
	}

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.

	bool has_priority(AccountStatus user_one, AccountStatus user_two) {

		switch (user_one) {
		case AccountStatus::mod:
			if (user_two == AccountStatus::mod) {
				return false;
			}
			else {
				return true;
			}
		case AccountStatus::user:
			if (user_two != AccountStatus::mod && user_two != AccountStatus::user) {
				return true;
			}
			else {
				return false;
			}
		case AccountStatus::guest:
			if (user_two != AccountStatus::mod && user_two != AccountStatus::user && user_two != AccountStatus::guest) {
				return true;
			}
			else {
				return false;
			}
		default:
			return false;
		}
	}

}  // namespace hellmath

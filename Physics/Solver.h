#ifndef SOLVER_H
#define SOLVER_H

#include <Physics/Contact.h>

class Solver {
public:
	Solver(ContactList *contacts);

private:
	void setupVelocityConstraints();

private:
	ContactList *_contacts;
};

#endif
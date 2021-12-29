#include "my_contact_listener.h"

void MyContactListener::BeginContact(b2Contact *contact) {
    b2Body *bodyA = contact->GetFixtureA()->GetBody();
    b2Body *bodyB = contact->GetFixtureB()->GetBody();
    int *idA = (int *)bodyA->GetUserData().pointer;
    int *idB = (int *)bodyB->GetUserData().pointer;
    *idA = *idB = 1;
    // std::cout << idA << "\t" << idB << std::endl;
}
void MyContactListener::EndContact(b2Contact *contact) {
    b2Body *bodyA = contact->GetFixtureA()->GetBody();
    b2Body *bodyB = contact->GetFixtureB()->GetBody();
    int *idA = (int *)bodyA->GetUserData().pointer;
    int *idB = (int *)bodyB->GetUserData().pointer;
    *idA = *idB = 0;
    // std::cout << idA << "\t" << idB << std::endl;
}
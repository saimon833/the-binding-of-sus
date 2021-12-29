#include "my_contact_listener.h"

void MyContactListener::BeginContact(b2Contact *contact) {
    b2Body *bodyA = contact->GetFixtureA()->GetBody();
    b2Body *bodyB = contact->GetFixtureB()->GetBody();
    hitInfo *idA = (hitInfo *)bodyA->GetUserData().pointer;
    hitInfo *idB = (hitInfo *)bodyB->GetUserData().pointer;
    idA->m_contact = 1;
    idB->m_contact = 1;
    idA->hit_id = idB->self_id;
    idB->hit_id = idA->self_id;

    // std::cout << idA << "\t" << idB << std::endl;
}
void MyContactListener::EndContact(b2Contact *contact) {
    b2Body *bodyA = contact->GetFixtureA()->GetBody();
    b2Body *bodyB = contact->GetFixtureB()->GetBody();
    hitInfo *idA = (hitInfo *)bodyA->GetUserData().pointer;
    hitInfo *idB = (hitInfo *)bodyB->GetUserData().pointer;
    idA->m_contact = 0;
    idB->m_contact = 0;
    idA->hitRegistered = 0;
    idB->hitRegistered = 0;
    // std::cout << idA << "\t" << idB << std::endl;
}
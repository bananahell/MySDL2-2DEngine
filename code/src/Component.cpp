#include "Component.h"

Component::Component(GameObject& parent) : parent(parent) {}

Component::~Component() {}

void Component::render() {}

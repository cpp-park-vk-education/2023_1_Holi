//
// Created by Алексей on 04.05.2023.
//

#include "orm/profile_reference.h"


bool ProfileReference::Save() { return false; }

bool ProfileReference::Alter(int id) { return false; }

json::value ProfileReference::SelectAll() { return {}; }

json::value ProfileReference::Get(int id) { return {}; }

bool ProfileReference::Delete(int id) { return false; }

json::value ProfileReference::SelectWith(QString condition) { return {}; }

bool ProfileReference::DeleteWith(QString condition) { return false; }

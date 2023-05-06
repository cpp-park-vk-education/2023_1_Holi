//
// Created by Алексей on 04.05.2023.
//

#include "user.h"


bool User::Save() { return false; }

bool User::Alter(int id) { return false; }

json::value User::SelectAll() { return {}; }

json::value User::Get(int id) { return {}; }

bool User::Delete(int id) { return false; }

json::value User::SelectWith(QString condition) { return {}; }

bool User::DeleteWith(QString condition) { return false; }

//
// Created by Алексей on 04.05.2023.
//

#include "message.h"


bool Message::Save() { return false; }

bool Message::Alter(int id) { return false; }

json::value Message::SelectAll() { return {}; }

json::value Message::Get(int id) { return {}; }

bool Message::Delete(int id) { return false; }

json::value Message::SelectWith(QString condition) { return {}; }

bool Message::DeleteWith(QString condition) { return false; }

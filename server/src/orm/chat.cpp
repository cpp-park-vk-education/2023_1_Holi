//
// Created by Алексей on 04.05.2023.
//

#include "orm/chat.h"


bool Chat::Save() { return false; }

bool Chat::Alter(int id) { return false; }

json::value Chat::SelectAll() { return {}; }

json::value Chat::Get(int id) { return {}; }

bool Chat::Delete(int id) { return false; }

json::value Chat::SelectWith(QString condition) { return {}; }

bool Chat::DeleteWith(QString condition) { return false; }

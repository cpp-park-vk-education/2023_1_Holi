//
// Created by Алексей on 04.05.2023.
//

#include "orm/playlist.h"


bool Playlist::Save() { return false; }

bool Playlist::Alter(int id) { return false; }

json::value Playlist::SelectAll() { return {}; }

json::value Playlist::Get(int id) { return {}; }

bool Playlist::Delete(int id) { return false; }

json::value Playlist::SelectWith(QString condition) { return {}; }

bool Playlist::DeleteWith(QString condition) { return false; }

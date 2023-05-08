//
// Created by Алексей on 04.05.2023.
//

#include "orm/video.h"


bool Video::Save() { return false; }

bool Video::Alter(int id) { return false; }

json::value Video::SelectAll() { return {}; }

json::value Video::Get(int id) { return {}; }

bool Video::Delete(int id) { return false; }

json::value Video::SelectWith(QString condition) { return {}; }

bool Video::DeleteWith(QString condition) { return false; }

//
// Created by Алексей on 04.05.2023.
//

#pragma once

#include <stdexcept>


struct Error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct DatabaseError : public Error {
    using Error::Error;
};

struct DbConnectError : public DatabaseError {
    using DatabaseError::DatabaseError;
};

struct ConditionError : public DatabaseError {
    using DatabaseError::DatabaseError;
};

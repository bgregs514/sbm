//
// Created by ben on 6/11/23.
//
#include "sqlite.h"
#include <sqlite3.h>
#include <stdio.h>

int open_db()
{
    sqlite3 *db;
    int rc;

    rc = sqlite3_open("test.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sqlite3_close(db);

    return 0;
}
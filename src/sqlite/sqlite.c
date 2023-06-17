#include "sqlite.h"
#include "sqlconst.h"

#include <stdio.h>

int open_db()
{
    sqlite3 *db;
    int rc;

    rc = sqlite3_open(SBMDB, &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        close_db(db);
        return 1;
    }

    rc = init_db(db);
    if (rc) {
        fprintf(stderr, "Failed to init database: %s\n", sqlite3_errmsg(db));
        close_db(db);
        return 1;
    }

    close_db(db);

    return 0;
}

void close_db(sqlite3 *db)
{
    fprintf(stdout, "Closing database connection\n");
    sqlite3_close(db);

    return;
}

int init_db(sqlite3 *db)
{
    int rc;
    char *err;

    fprintf(stdout, "Initializing SBM database\n");

    // Init plan table
    rc = sqlite3_exec(db, SBM_INIT_PLAN_TABLE, 0, 0, &err);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to init plan table: %s\n", err);
        sqlite3_free(err);
        return 1;
    }
    // Init actual table
    rc = sqlite3_exec(db, SBM_INIT_ACTUALS_TABLE, 0, 0, &err);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to init actuals table: %s\n", err);
        sqlite3_free(err);
        return 1;
    }

    return 0;
}

#include <sqlite3.h>

#ifndef SBM_SQLITE_H
#define SBM_SQLITE_H

int open_db();
void close_db(sqlite3 *db);
int init_db(sqlite3 *db);

#endif //SBM_SQLITE_H

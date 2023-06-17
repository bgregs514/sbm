//
// Created by ben on 6/17/23.
//

#ifndef SBM_SQLCONST_H
#define SBM_SQLCONST_H

/* Sqlite config constants */
#define SBMDB "sbm.db"

/* SQL statements */
#define SBM_INIT_PLAN_TABLE "CREATE TABLE IF NOT EXISTS budget_plan(parent_category, child_category, amount_USD);"
#define SBM_INIT_ACTUALS_TABLE "CREATE TABLE IF NOT EXISTS budget_actuals(parent_category, child_category, amount_USD);"

#endif //SBM_SQLCONST_H

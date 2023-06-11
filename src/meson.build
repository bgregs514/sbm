sqlite_sources = ['sqlite/sqlite.c']
sources = ['main.c', sqlite_sources]

executable('sbm',
            sources,
            dependencies: sqlitedeps,
            include_directories: inc
)
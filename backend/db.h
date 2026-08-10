#include <iostream>
#include <vector>
#include <string>
#include <sqlite3.h>
#include "item.h"



std::vector<Pdf> loadBooks() {
    // Open the file-based SQLite database
    sqlite3* db = nullptr;
    std::vector<Pdf> library;

    int rc = sqlite3_open("../data/meta.db", &db); // return code

    if (rc != SQLITE_OK) {
        std::cerr << "Can't open database: "
                  << (db ? sqlite3_errmsg(db) : "unknown error")
                  << '\n';

        if (db) {
            sqlite3_close(db);
        }
        return library;
    }

    // Prepare the SQL statement to select all PDFs

    const char* sql = R"(
        SELECT id, title, filename
        FROM pdfs;
    )";
    sqlite3_stmt* stmt = nullptr;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return library;
    }

    // Execute the statement and read the results

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);

        const unsigned char* titleRaw = sqlite3_column_text(stmt, 1);
        std::string title =
            titleRaw ? reinterpret_cast<const char*>(titleRaw) : "";

        const unsigned char* pathRaw = sqlite3_column_text(stmt, 2);
        std::string filepath =
            pathRaw ? reinterpret_cast<const char*>(pathRaw) : "";

        // Pdf requires: title, author, year, id, filename.
        library.emplace_back(title, "", 0, id, filepath);
    }

    if (rc != SQLITE_DONE) {
        std::cerr << "Error reading database: " << sqlite3_errmsg(db) << '\n';
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    std::cout << "\n--- Found " << library.size() << " PDFs ---\n";

    for (const auto& book : library) {
        std::cout << "ID: " << book.getId()
                  << " | Title: " << book.getTitle()
                  << " | Path: " << book.getFilename()
                  << '\n';
    }

    // *************************************************************


    return library;
}
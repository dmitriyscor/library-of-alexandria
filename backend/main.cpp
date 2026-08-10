#pragma once

#include "httplib.h"
#include "db.h"
#include <filesystem>

int main() {
    httplib::Server svr;

    svr.set_mount_point("/", "../frontend");

    svr.Get("/books", [](const httplib::Request&, httplib::Response& res) {
        auto library = loadBooks();
        std::string json = "[";
        for (size_t i = 0; i < library.size(); ++i) {
            json += "{\"id\":" + std::to_string(library[i].getId()) +
                    ",\"title\":\"" + library[i].getTitle() +
                    "\",\"filename\":\"" + library[i].getFilename() + "\"}";
            if (i + 1 < library.size()) json += ",";
        }
        json += "]";
        res.set_content(json, "application/json");
    });

    svr.Get(R"(/pdf/(.*))", [](const httplib::Request& req, httplib::Response& res) {
        std::string filename = req.matches[1];
        std::string filepath = "../data/library/" + filename;

        if (!std::filesystem::exists(filepath)) {
            res.status = 404;
            res.set_content("PDF not found", "text/plain");
            return;
        }

        res.set_file_content(filepath, "application/pdf");
    });

    svr.listen("0.0.0.0", 8080);
}
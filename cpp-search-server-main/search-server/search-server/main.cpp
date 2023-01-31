#include "search_server.h"
#include "process_queries.h"
#include "log_duration.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    SearchServer search_server("and in at"s); 
    RequestQueue request_queue(search_server);

    search_server.AddDocument(1, "curly cat curly tail"s, DocumentStatus::ACTUAL, {7, 2, 7}); 
    search_server.AddDocument(2, "curly dog and fancy collar"s, DocumentStatus::ACTUAL, {1, 2, 3});
    search_server.AddDocument(3, "big cat fancy collar "s, DocumentStatus::ACTUAL, {1, 2, 8});
    search_server.AddDocument(4, "big dog sparrow Eugene"s, DocumentStatus::ACTUAL, {1, 3, 2});
    search_server.AddDocument(5, "big dog sparrow Vasiliy"s, DocumentStatus::ACTUAL, {1, 1, 1});
    
    
    std::string query = "big dog Vasiliy"s;
    
    std::vector<Document> documents =  search_server.FindTopDocuments(query); 
    
    for(Document& doc : documents) {
        std::cout << doc.id << std::endl;
    }
    
}



# cpp-search-server
 поисковая система
Представляет собой систему в которую можно вносить информцию, а затем, с помощью поисковых запросов производить ее поиск.

Пример работы:

// в качестве аргументов вводятся слова не использующиеся при формировании запросов


int main() {
    SearchServer search_server("and in at"s); 
    RequestQueue request_queue(search_server);

    search_server.AddDocument(1, "curly cat curly tail"s, DocumentStatus::ACTUAL, {7, 2, 7}); // формат ввода id, текст документа, статус документа и вектор рэйтинга документа
    search_server.AddDocument(2, "curly dog and fancy collar"s, DocumentStatus::ACTUAL, {1, 2, 3});
    search_server.AddDocument(3, "big cat fancy collar "s, DocumentStatus::ACTUAL, {1, 2, 8});
    search_server.AddDocument(4, "big dog sparrow Eugene"s, DocumentStatus::ACTUAL, {1, 3, 2});
    search_server.AddDocument(5, "big dog sparrow Vasiliy"s, DocumentStatus::ACTUAL, {1, 1, 1});
    
    
    std::string query = "big dog Vasiliy"s;
    
    std::vector<Document> documents =  search_server.FindTopDocuments(query); // запрос на поиск наиболее подходящих документов по запросу query
    
    for(Document& doc : documents) {
        std::cout << doc.id << std::endl;
    }

    //будет выведено 5 4 3 2
    // числа - id документов в порядке убывания рельевантности 

    
}

Данная функция main показывает пример запросов к поисковому серверу.

Версия языка C++ 17



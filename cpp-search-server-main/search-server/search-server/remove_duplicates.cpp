/*
#include "remove_duplicates.h"

using namespace std;

void RemoveDuplicates( SearchServer& search_server) {
    set<int> ids_to_del;
    map<set<string>, int> words_freq_to_id;
    for (const int document_id : search_server) {
        auto words_to_freq = search_server.GetWordFrequencies(document_id);
        set<string> key_words;
        for(const auto& [word, _] : words_to_freq) {
            key_words.insert(word);
        }
        if(words_freq_to_id.count(key_words)) {
            int id_to_word_freq_local = words_freq_to_id.at(key_words);
            ids_to_del.insert(max(document_id, id_to_word_freq_local));
        } else {
            words_freq_to_id[key_words] = document_id;
        }
    }
    for(int id : ids_to_del) {
        search_server.RemoveDocument(id);
        cout << "Found duplicate document id " << id << endl;
    }
}
*/

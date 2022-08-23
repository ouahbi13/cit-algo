while (understood.size() != book.size()) {
            for (int a = 0; a < book.size(); a++) {
                for (int b = 0; b < book[a].size(); b++) {
                    if (find(understood.begin(), understood.end(), book[a][b]) == understood.end()) break;
                    understood.push_back(book[a][b]);
                    }
            }
        }
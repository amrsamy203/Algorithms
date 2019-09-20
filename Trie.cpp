struct trie {
    
    static const int MAX_CHAR = 26; //if MAX_CHAR is big range but not all values are used, use a map instead of static array
	trie* child[MAX_CHAR];
	bool isLeaf;

	trie() {
		memset(child, 0, sizeof(child));
		isLeaf = 0;
	}

	void insert(char * str) { // reference to the current char in the char sequence starting at str;
		if(*str == '\0') { // end of char sequence
            isLeaf = 1;
            return;
		}
        int cur = *str-'a';
		if(child[cur] == 0) // have no child;
			child[cur] = new trie();
		child[cur]->insert(str+1);
	}

	bool find(char * str) {
        if(*str == '\0')
            return isLeaf; // end of char seq
        int cur = *str-'a';
        if(child[cur]!=0) // have childes;
            return child[cur]->find(str+1);
        return false;
	}
};

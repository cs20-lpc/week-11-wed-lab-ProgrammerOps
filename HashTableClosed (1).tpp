//(Linear Probing, Quadratic Probing, Double Hashing)
//Think of a closed hash table like a row of lockers numbered 0 to 100.
//Each time you store a key, you must find an empty locker for it.

//To find the "first possible locker," we use:

//h1(key)=key%M
//For M = 101, this is just key 
//+1, +4, +9, +16, +25,



template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:

int probes = 0;
    int h1 = hash1(key);

    for (int i = 0; i < M; i++) {     //This loop tries the probing sequence:  i = 0 → first try // i = 1 → second try
        probes++;                    //We increase our probe count because: Every time the student looks at a locker, that counts as a probe.
        
        int index = probeIndex(key, i);  //compute the locker number to check next.

        // If not occupied → insert here
        if (!occupied[index]) {
            table[index] = key;  //Put the key inside the locker.
            occupied[index] = true;
            N++;
            return probes;
        }

        // If already exists, no re-insert (still counts as probe)
        if (table[index] == key) {
            return probes;
        }
    }

    throw runtime_error("Hash table is full");  //After trying every locker, no space is found. So we throw an exception. Analogy: “The hallway is completely full — there’s nowhere left to put your stuff.”
}



template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO: 

int probes = 0;

    for (int i = 0; i < M; i++) {
        probes++;
        int index = probeIndex(key, i);

        // If a slot is empty → key is NOT in table
        if (!occupied[index])
            return {false, probes};

        // Found
        if (table[index] == key)
            return {true, probes};
    }

    return {false, probes};

    
}

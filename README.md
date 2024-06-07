## ScrabbleHelper

### To Compile

1. Navigate to the /src directory:
   `cd src`
   
2. Create the "main" executable: 
   `g++ -o main main.cpp Diccionario.cpp Grafo.cpp Palabra.cpp Trie.cpp TrieNode.cpp`
   
3. Run the executable:
   `./main`

   
### Project Structure

- `src/`: Source files
  
  - `main.cpp`: Entry point of the program
  - `Diccionario.cpp` and `Diccionario.h`: Dictionary handling
  - `Grafo.cpp` and `Grafo.h`: Graph data structure
  - `Palabra.cpp` and `Palabra.h`: Word handling
  - `Trie.cpp` and `Trie.h`: Trie data structure
  - `TrieNode.cpp` and `TrieNode.h`: Trie node implementation
  - `archivo.txt`: Contains the dictionary of words to use in the program


### Functionality

1. **Dictionary Management:**
   - **Initialize Dictionary:** Loads a dictionary from archivo.txt.
     `Command: inicializar archivo.txt`
     
   - **Initialize Inverse Dictionary:** Loads the dictionary with words in reverse order.
     `Command: iniciar_inverso archivo.txt`

     
2. **Scoring Words:**
   - **Calculate Score:** Computes the Scrabble score for a given word.
     `Command: puntaje word`
     `[EXAMPLE]: Command: puntaje apple`


3. **Tree Structure Initialization:**
   - **Initialize Trie:** Sets up a Trie data structure for the dictionary.
     `Command: iniciar_arbol archivo.txt`
     
   - **Initialize Inverse Trie:** Sets up a Trie for the reverse dictionary.
     `Command: iniciar_arbol_inverso archivo.txt`
     

4. **Word Search:**
   - **Words by Prefix:** Finds words starting with a specified prefix.
     `Command: palabras_por_prefijo prefix`
     `[EXAMPLE]: Command: palabras_por_prefijo app`
     
   - **Words by Suffix:** Finds words ending with a specified suffix.
     `Command: palabras_por_sufijo suffix`
     `[EXAMPLE]: Command: palabras_por_sufijo ple`


5. **Graph Data Structure:**
   - **Build Word Graph:** Constructs a graph of words.
     `Command: grafo_de_palabras`
     

6. **Possible Words Construction:**
   - **Construct Possible Words:** Finds words that can be formed with given letters, including wildcards.
     `Command: posibles_palabras word`
     `[EXAMPLE]: Command: posibles_palabras lim?`


### Language
The code is written in Spanish.
    

![imagen](https://github.com/tortegaf/ScrabbleHelper/assets/124638175/3ded8743-f30a-47e2-96a3-80b08dc58a77)

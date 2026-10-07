Ciao sono Andrea Strozziero anche chiamato Strozzi.
Ho scritto diversi programmi in c++ per fare un gioco che si sviluppa sul 3 modelli: wordle, (con una parola o un pin), battaglia navale e tris.
Per scaricare il gioco basa cliccare sul pulsante code in verde e poi estrarre i file dalla zip e infine avviare il collegamento big battle da quel punto in poi sarete guidati da lui.

## Interfaccia grafica
Nella cartella `Git/Gioco` c'e' il file `BigBattle.html`: basta aprirlo con un doppio clic (si apre nel browser, non serve installare niente).
Contiene tutti i giochi del menu con la grafica: indovina il pin e la parola (2 giocatori o single player), battaglia navale (2 giocatori o contro il computer), tris (2 giocatori o contro il computer), snake, campo minato, sudoku, solitario, 2048 e l'aggiunta di nuove parole.
Si puo' aprire anche dal menu del gioco da console con l'opzione 13.

## Snake, campo minato, sudoku, solitario e 2048
- **Snake** (`snake.cpp`, opzione 8): frecce o W A S D per muoverti, P per la pausa, Q per uscire. Il record viene salvato in `snake_record.txt`.
- **Campo minato** (`campo_minato.cpp`, opzione 9): scegli se scoprire una casella o mettere/togliere una bandiera, poi inserisci le coordinate. La prima casella scoperta non e' mai una mina.
- **Sudoku** (`sudoku.cpp`, opzione 10): tre difficolta', ogni sudoku e' generato a caso e ha una sola soluzione. Puoi inserire o cancellare numeri, controllare gli errori, chiedere un aiuto o vedere la soluzione.
- **Solitario** (`solitario.cpp`, opzione 11): il classico Klondike, pescando 1 o 3 carte alla volta. Le colonne sono numerate da 1 a 7, le fondazioni sono la destinazione 8; spostando da una colonna il gioco sceglie da solo quante carte portare.
- **2048** (`2048.cpp`, opzione 12): frecce o W A S D per muovere le tessere, N = nuova partita, Q = esci. Il record viene salvato in `2048_record.txt`.

## Ricompilare i programmi
I file `.cpp` dei giochi pin/parola usano `comune.h` (deve stare nella stessa cartella). Con MinGW:
`g++ -static -o tris.exe tris.cpp`

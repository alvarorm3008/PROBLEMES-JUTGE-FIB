
#include "Player.hh"

using namespace std;


/**
 * Write the name of your player and save this file
 * as AI<name>.cc
 */
#define PLAYER_NAME AIsisisi





struct PLAYER_NAME : public Player {


    /**
     * Factory: returns a new instance of this class.
     * Do not modify this function.
     */
    static Player* factory () {
        return new PLAYER_NAME;
    }
    

    /**
     * Attributes for your player can be defined here.
     */     
    vector<Dir> totes_dirs;

    bool up(Dir d)   { return d == SLOW_UP   or d == UP   or d == FAST_UP;   }
    bool down(Dir d) { return d == SLOW_DOWN or d == DOWN or d == FAST_DOWN; }

    bool pos_valida (const Pos& pos, const Dir& d, int dist) { //comporvamos que no haya pneumatico ni cohce yq ue este dentro del rango 
        if (not within_window(pos+d, round()+dist+1)) return false;

        return true;//falta mirar lo de los posiciones
    }

    Dir bfs (const Car& cotxe) {
        queue<pair<Pos, int>> q;
        q.push({cotxe.pos, 0});

        vector<vector<Dir>> t (number_rows(), vector<Dir>(number_universe_columns(), SLOW));

        while (not q.empty()) {
            Pos act = q.front().first;
            int distancia = q.front().second;
            int iact = first(act);
            int jact = second(act)%number_universe_columns();

            q.pop();
            Dir dir_ini;
            for (Dir dir : totes_dirs) {
                Pos pos_seg = act + dir;
                int iseg = first (pos_seg);
                int jseg = second (pos_seg)%number_universe_columns();
                
                if(within_universe(pos_seg) and within_window(pos_seg, round()+1) and t[iseg][jseg] == SLOW) {
                    if (distancia == 0) dir_ini = dir;
                    else dir_ini = t[iact][jact];
                    if (pos_valida(act, dir, distancia)) {
                        if (cell(pos_seg).type == WATER_BONUS) return dir_ini;
                        q.push ({pos_seg, distancia + 1});
                        t[iseg][jseg] = dir_ini;
                    }    
                }
            }
        }
        return SLOW;
    }

    /*
    Dir mover(const Car& cotxe, Tablero& t, int f, int c) {
        queue <pair<Pos, Dir>> q;

        q.push ({cotxe.pos, SLOW});
        int i = first(cotxe.pos);
        int j = second(cotxe.pos);

        t[i][j] = {false, 0};
        //t[i][j] = {true, cotxe.pos};//marcamos como valida la posicion del coche
       
        while (not q.empty()) {       
            Pos act = q.front().first;
            i = first(act);
            j = second(act);
            int dist = t[i][j].second;
            q.pop();
            for (Dir dir : totes_dirs) {
                Pos pos_seg = act + dir;
                if (pos_valida(pos_seg, )) {//añadimos a la cola
                    q.push({pos_seg, dir});
                    //t[i][j] = {true, pos_seg};
                }
                else //t[i][j] = {false, pos_seg};
            }
        }
    }
    
    */
    

    /**
     * Play method.
     * 
     * This method will be invoked once per each round.
     * You have to read the board here to place your actions
     * for this round.
     *
     */     
    virtual void play () {
       //afegim totes les direccions possibles
        totes_dirs = {UP, DEFAULT, DOWN, SLOW_UP, SLOW_DOWN, FAST_UP, FAST, FAST_DOWN};
        
        for (Car_Id cid = begin(me()); cid != end(me()); ++cid) {
            Car cotxe = car (cid);
            if (cotxe.alive) {
                move (cotxe.cid, bfs(cotxe));
            }
        }
    }

    
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);


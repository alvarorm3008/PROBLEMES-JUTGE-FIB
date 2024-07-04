
#include "Player.hh"
#include <complex>

using namespace std;


/**
 * Write the name of your player and save this file
 * as AI<name>.cc
 */
#define PLAYER_NAME AIjordan2





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

    bool pos_valida (const Pos& pos, const Dir& d, int dist) {
        if (not within_window(pos+d, round()+dist+1)) return false;
        if (d == UP) {
            return (cell (pos+SLOW_UP).type != TYRE and cell (pos+SLOW_UP).type != CAR and 
                    cell (pos+DEFAULT).type != TYRE and cell (pos+DEFAULT).type != CAR and 
                    cell (pos+d).type != TYRE and cell (pos+d).type != CAR); 
        }
        else if (d == DEFAULT) { 
            return (cell (pos+d).type != TYRE and cell (pos+d).type != CAR and 
                    cell (pos+d).type != TYRE and cell (pos+d).type != CAR);
        }
        else if (d == DOWN) {
            return (cell (pos+SLOW_DOWN).type != TYRE and cell (pos+SLOW_DOWN).type != CAR and
                    cell (pos+DEFAULT).type != TYRE and cell (pos+DEFAULT).type != CAR and
                    cell (pos+d).type != TYRE and cell (pos+d).type != CAR); 
        }
        else if (d == SLOW_UP) {
            return (cell (pos+d).type != TYRE and cell (pos+d).type != CAR and 
                    cell (pos+d).type != TYRE and cell (pos+d).type != CAR);
        }
        else if (d == SLOW_DOWN) {
            return cell (pos+d).type != TYRE and cell (pos+d).type != CAR and 
                    cell (pos+d).type != TYRE and cell (pos+d).type != CAR;
        }
        else if (d == FAST_UP) {
            return (cell (pos+DEFAULT).type != TYRE and cell (pos+DEFAULT).type != CAR and 
                    cell (pos+FAST).type != TYRE and cell (pos+FAST).type != CAR and 
                    cell (pos+UP).type != TYRE and cell (pos+UP).type != CAR and
                    cell (pos+SLOW_UP).type != TYRE and cell (pos+SLOW_UP).type != CAR and
                    cell (pos+d).type != TYRE and cell (pos+d).type != CAR);
        }
        else if (d == FAST) {
            return (cell (pos+DEFAULT).type != TYRE and cell (pos+DEFAULT).type != CAR and 
                    cell (pos+d).type != TYRE and cell (pos+d).type != CAR);
        }
        else if (d == FAST_DOWN) {
            return (cell (pos+DEFAULT).type != TYRE and cell (pos+DEFAULT).type != CAR and 
                    cell (pos+FAST).type != TYRE and cell (pos+FAST).type != CAR and
                    cell (pos+DOWN).type != TYRE and cell (pos+DOWN).type != CAR and
                    cell (pos+SLOW_DOWN).type != TYRE and cell (pos+SLOW_DOWN).type != CAR and 
                    cell (pos+d).type != TYRE and cell (pos+d).type != CAR);        
        }
        else return true;
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

    Dir gasolina(const Car& cotxe) {
    queue<pair<Pos, int>> q;
    q.push({cotxe.pos, 0});

    vector<vector<Dir>> t(number_rows(), vector<Dir>(number_universe_columns(), SLOW));

    while (!q.empty()) {
        Pos act = q.front().first;
        int distancia = q.front().second;
        int iact = first(act);
        int jact = second(act) % number_universe_columns();

        q.pop();
        Dir dir_ini = t[iact][jact];
        for (Dir dir : totes_dirs) {
            Pos pos_seg = act + dir;
            int iseg = first(pos_seg);
            int jseg = second(pos_seg) % number_universe_columns();

            if (within_universe(pos_seg) && within_window(pos_seg, round() + 1) && t[iseg][jseg] == SLOW) {
                if (distancia == 0) {
                    dir_ini = dir;
                }
                if (pos_valida(act, dir, distancia)) {
                    if (cell(pos_seg).type == GAS_BONUS) {
                        return dir_ini;
                    }
                    q.push({pos_seg, distancia + 1});
                    t[iseg][jseg] = dir_ini;
                }
            }
        }
    }
    return SLOW;
}


    Dir bfs2(const Car& cotxe) {
    queue<pair<Pos, int>> q;
    q.push({cotxe.pos, 0});

    vector<vector<Dir>> t(number_rows(), vector<Dir>(number_universe_columns(), SLOW));

    while (!q.empty()) {
        Pos act = q.front().first;
        int distancia = q.front().second;
        int iact = first(act);
        int jact = second(act) % number_universe_columns();

        q.pop();
        Dir dir_ini = t[iact][jact];
        for (Dir dir : totes_dirs) {
            Pos pos_seg = act + dir;
            int iseg = first(pos_seg);
            int jseg = second(pos_seg) % number_universe_columns();

            if (within_universe(pos_seg) && within_window(pos_seg, round() + 1) && t[iseg][jseg] == SLOW) {
                if (distancia == 0) {
                    dir_ini = dir;
                }
                if (pos_valida(act, dir, distancia)) {
                    if (cell(pos_seg).type == WATER_BONUS) {
                        return dir_ini;
                    }
                    q.push({pos_seg, distancia + 1});
                    t[iseg][jseg] = dir_ini;
                }
            }
        }
    }
    return SLOW;
}

Dir bfs3(const Car& cotxe) {
    const int rows = number_rows();
    const int cols = number_universe_columns();

    vector<vector<Dir>> t(rows, vector<Dir>(cols, SLOW));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    queue<pair<Pos, Dir>> q;
    const Pos start_pos = cotxe.pos;
    q.push({start_pos, SLOW});
    visited[first(start_pos)][second(start_pos) % cols] = true;

    while (!q.empty()) {
        const Pos curr_pos = q.front().first;
        const Dir prev_dir = q.front().second;
        q.pop();

        for (Dir dir : totes_dirs) {
            const Pos next_pos = curr_pos + dir;
            const int i = first(next_pos);
            const int j = second(next_pos) % cols;

            if (within_universe(next_pos) && within_window(next_pos, round() + 1) && !visited[i][j] && t[i][j] == SLOW && pos_valida(curr_pos, dir, 0)) {
                visited[i][j] = true;
                if (cell(next_pos).type == WATER_BONUS) {
                    return prev_dir;
                }
                q.push({next_pos, prev_dir});
                t[i][j] = prev_dir;
            }
        }
    }

    return SLOW;
}



    /**
     * Play method.
     * 
     * This method will be invoked once per each round.
     * You have to read the board here to place your actions
     * for this round.
     *
     */     
    virtual void play () {
        totes_dirs = {UP, DEFAULT, DOWN, SLOW_UP, SLOW_DOWN, FAST_UP, FAST, FAST_DOWN};
        
        for (Car_Id cid = begin(me()); cid != end(me()); ++cid) {
                Car cotxe = car (cid);
                if (cotxe.alive) {
                    Cell ahead = cell(cotxe.pos + DEFAULT);
                    if (cotxe.nb_miss > 0 and (ahead.type == TYRE or ahead.type == CAR)) shoot (cid);
                    //if (cotxe.gas < 10) move (cotxe.cid, gasolina(cotxe));
                    //else
                     move (cotxe.cid, bfs(cotxe));
                }
            
            
        }
    }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);


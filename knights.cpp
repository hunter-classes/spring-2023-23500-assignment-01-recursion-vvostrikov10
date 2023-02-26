#include <iostream>
#include <vector>

int BOARD_SIZE = 5;
int X_STARTING = 0;
int Y_STARTING = 0;

void print_board(std::vector<std::vector<int>> board, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout << board.at(j).at(i) << "\t ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int knight_tour(int x, int y, int count, int size, std::vector<std::vector<int>> &board){
    int a;
    try{
        a = board.at(x).at(y);
    }
    catch(...){
        return -1;
    }

    if(a != 0){
        return -1;
    }

    board.at(x).at(y) = count;
    //print_board(board, size); //testing, forgot that the vector passes a copy of itself normally
    if (size*size == count){
        return 1;
    }

    int attempt = knight_tour(x+2,y+1,count+1,size,board);
    if (attempt == 1){
        return 1;
    }
    attempt = knight_tour(x-2,y+1,count+1,size,board);
    if (attempt == 1){
        return 1;
    }
    attempt = knight_tour(x+2,y-1,count+1,size,board);
    if (attempt == 1){
        return 1;
    }    
    attempt = knight_tour(x-2,y-1,count+1,size,board);
    if (attempt == 1){
        return 1;
    }
    attempt = knight_tour(x+1,y+2,count+1,size,board);
    if (attempt == 1){
        return 1;
    }
    attempt = knight_tour(x-1,y+2,count+1,size,board);
    if (attempt == 1){
        return 1;
    }
    attempt = knight_tour(x+1,y-2,count+1,size,board);
    if (attempt == 1){
        return 1;
    }    
    attempt = knight_tour(x-1,y-2,count+1,size,board);
    if (attempt == 1){
        return 1;
    }

    board.at(x).at(y) = 0;//if no branch is correct then the move was not right to begin with
    return -1;
}



int main(){
    std::vector<std::vector<int>> b(BOARD_SIZE);
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            b.at(i).push_back(0);
        }
    }
    knight_tour(X_STARTING, Y_STARTING, 1, BOARD_SIZE, b);
    print_board(b, BOARD_SIZE);

}
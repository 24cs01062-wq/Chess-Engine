//
//  main.cpp
//  chess engine
//
//  Created by Raam Sundaran on 11/10/26.
//

#include <iostream>
#include<vector>
#include<map>
using namespace std;
class queen{
private:
    vector<pair<int,int>>mov;
    vector<vector<string>>arr;
public:

    queen(vector<vector<string>>&arr){
        this->arr=arr;
    }

    vector<pair<int,int>> moveset(int r,int c){
        for(int i=r+1;i<8;i++){
            if(arr[i][c]=="# "){
                mov.push_back({i,c});
            }
            else if(arr[i][c][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({i,c});
                break;
            }
        }
        for(int i=r-1;i>=0;i--){
            if(arr[i][c]=="# "){
                mov.push_back({i,c});
            }
            else if(arr[i][c][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({i,c});
                break;
            }
        }
        for(int i=c+1;i<8;i++){
            if(arr[r][i]=="# "){
                mov.push_back({r,i});
            }
            else if(arr[r][i][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({r,i});
                break;
            }
        }
        for(int i=c-1;i>=0;i--){
            if(arr[r][i]=="# "){
                mov.push_back({r,i});
            }
            else if(arr[r][i][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({r,i});
                break;
            }
        }
        for(int i=1;i<8-max(r,c);i++){
            if(arr[r+i][c+i]=="# "){
                mov.push_back({r+i,c+i});
            }
            else if(arr[r+i][c+i][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({r+i,c+i});
                break;
            }
        }
        for(int i=1;i<min(r,c);i++){
            if(arr[r-i][c-i]=="# "){
                mov.push_back({r-i,c-i});
            }
            else if(arr[r-i][c-i][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({r-i,c-i});
                break;
            }
        }
        for(int i=1;i<min(8-r,c);i++){
            if(arr[r+i][c-i]=="# "){
                mov.push_back({r+i,c-i});
            }
            else if(arr[r+i][c-i][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({r+i,c-i});
                break;
            }
        }
        for(int i=1;i<min(r,8-c);i++){
            if(arr[r-i][c+i]=="# "){
                mov.push_back({r-i,c+i});
            }
            else if(arr[r-i][c+i][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({r-i,c+i});
                break;
            }
        }
        return mov;
    }
    
};
class bishop{
private:
    vector<pair<int,int>>mov;
    vector<vector<string>>arr;
public:
    
    bishop(vector<vector<string>>&arr){
        this->arr=arr;
    }
  
    vector<pair<int,int>> moveset(int r,int c){
        for(int i=1;i<8-max(r,c);i++){
            if(arr[r+i][c+i]=="# "){
                mov.push_back({r+i,c+i});
            }
            else if(arr[r+i][c+i][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({r+i,c+i});
                break;
            }
        }
        for(int i=1;i<min(r,c);i++){
            if(arr[r-i][c-i]=="# "){
                mov.push_back({r-i,c-i});
            }
            else if(arr[r-i][c-i][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({r-i,c-i});
                break;
            }
        }
        for(int i=1;i<min(8-r,c);i++){
            if(arr[r+i][c-i]=="# "){
                mov.push_back({r+i,c-i});
            }
            else if(arr[r+i][c-i][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({r+i,c-i});
                break;
            }
        }
        for(int i=1;i<min(r,8-c);i++){
            if(arr[r-i][c+i]=="# "){
                mov.push_back({r-i,c+i});
            }
            else if(arr[r-i][c+i][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({r-i,c+i});
                break;
            }
        }
        return mov;
    }
    
};
class king{
private:
    vector<pair<int,int>>mov;
    vector<vector<string>>arr;
public:
   
    king(vector<vector<string>>&arr){
        this->arr=arr;
    }
    
    
    vector<pair<int,int>> moveset(int r,int c){
        if(r>0 && arr[r-1][c][0]!=arr[r][c][0])mov.push_back({r-1,c});
        if(c>0 && arr[r][c-1][0]!=arr[r][c][0])mov.push_back({r,c-1});
        if(r<7 && arr[r+1][c][0]!=arr[r][c][0])mov.push_back({r+1,c});
        if(c<7 && arr[r][c+1][0]!=arr[r][c][0])mov.push_back({r,c+1});
        if(r>0 && c>0 &&  arr[r-1][c-1][0]!=arr[r][c][0])mov.push_back({r-1,c-1});
        if(r>0 && c<7 && arr[r-1][c+1][0]!=arr[r][c][0])mov.push_back({r-1,c+1});
        if(r<7 && c>0 && arr[r+1][c-1][0]!=arr[r][c][0])mov.push_back({r+1,c-1});
        if(r<7 && c<7 && arr[r+1][c+1][0]!=arr[r][c][0])mov.push_back({r+1,c+1});
        return mov;
    }
};
class knight{
private:
    vector<pair<int,int>>mov;
    vector<vector<string>>arr;
public:
  
    knight(vector<vector<string>>&arr){
        this->arr=arr;
    }
    vector<pair<int,int>> moveset(int r,int c){
        //r-2,c+1
        //r-2,c-1
        //r+2,c-1
        //r+2,c+1
        //r-1,c+2
        //r-1,c-2
        //r+1,c+2
        //r+1,c-2
        
        if(r-2>=0 && c+1<=7){
            mov.push_back({r-2,c+1});
        }
        if(r-2>=0 && c-1>=0){
            mov.push_back({r-2,c-1});
        }
        if(r+2<=7 && c+1<=7){
            mov.push_back({r+2,c+1});
        }
        if(r-1>=0 && c-2>=0){
            mov.push_back({r-1,c-2});
        }
        if(r-1>=0 && c+2<=7){
            mov.push_back({r-1,c+2});
        }
        if(r+1<=7 && c+2<=7){
            mov.push_back({r+1,c+2});
        }
        if(r+1<=7 && c-2>=0){
            mov.push_back({r+1,c-2});
        }
        if(r+2<=7 && c-1>=0){
            mov.push_back({r+2,c-1});
        }
        return mov;
    }
};
class rook{
private:
    vector<pair<int,int>>mov;
    vector<vector<string>>arr;
public:
   
    rook(vector<vector<string>>&arr){
        this->arr=arr;
    }
   
    vector<pair<int,int>> moveset(int r,int c){
        for(int i=r+1;i<8;i++){
            if(arr[i][c]=="# "){
                mov.push_back({i,c});
            }
            else if(arr[i][c][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({i,c});
                break;
            }
        }
        for(int i=r-1;i>=0;i--){
            if(arr[i][c]=="# "){
                mov.push_back({i,c});
            }
            else if(arr[i][c][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({i,c});
                break;
            }
        }
        for(int i=c+1;i<8;i++){
            if(arr[r][i]=="# "){
                mov.push_back({r,i});
            }
            else if(arr[r][i][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({r,i});
                break;
            }
        }
        for(int i=c-1;i>=0;i--){
            if(arr[r][i]=="# "){
                mov.push_back({r,i});
            }
            else if(arr[r][i][0]==arr[r][c][0]){
                break;
            }
            else{
                mov.push_back({r,i});
                break;
            }
        }
        return mov;
    }
    
};
class pawn{
private:
    vector<pair<int,int>>mov;
    vector<vector<string>>arr;
public:
   
    pawn(vector<vector<string>>&arr){
        this->arr=arr;
    }
    
    vector<pair<int,int>> moveset(int r,int c){
        if(arr[r][c]=="Wp"){
            if(r==6){
                if(arr[4][c]=="# ")mov.push_back({4,c});
                if(arr[5][c]=="# ")mov.push_back({5,c});
                if(c>0 && arr[5][c-1][0]=='B')mov.push_back({5,c-1});
                if(c<arr[0].size()-1 && arr[5][c+1][0]=='B')mov.push_back({5,c+1});
            }
            else if(r>0){
                if(arr[r-1][c]=="# ")mov.push_back({r-1,c});
                if(c>0 && arr[r-1][c-1][0]=='B')mov.push_back({r-1,c-1});
                if(c<arr[0].size()-1 && arr[r-1][c+1][0]=='B')mov.push_back({r-1,c+1});
            }
            
            
            
        }
        else{
            if(r==1){
                if(arr[2][c]=="# ")mov.push_back({2,c});
                if(arr[3][c]=="# ")mov.push_back({3,c});
                if(c>0 && arr[2][c-1][0]=='W')mov.push_back({2,c-1});
                if(c<arr[0].size()-1 && arr[2][c+1][0]=='W')mov.push_back({2,c+1});
            }
            else if(r<arr.size()-1){
                if(arr[r+1][c]=="# ")mov.push_back({r+1,c});
                if(c>0 && arr[r+1][c-1][0]=='W')mov.push_back({r+1,c-1});
                if(c<arr[0].size()-1 && arr[r+1][c+1][0]=='W')mov.push_back({r+1,c+1});
            }
           
          }
        return mov;
    }
       
    

    
};
class chess{
private:
    map<pair<int,int>,int>white;
    map<pair<int,int>,int>black;
    vector<vector<string>>arr;
   
  public:
    int bkx=0,bky=4,wkx=7,wky=4;
    chess(vector<vector<string>>&arr){
        this->arr=arr;
        
    }
    bool iswhite(int x,int y){
        if(arr[x][y][0]=='W')return 1;
        return 0;
    }
    void threats(){
        for(int r=0;r<8;r++){
            for(int c=0;c<8;c++){
                if(arr[r][c]=="#")continue;
                vector<pair<int,int>>pos;
                    if(arr[r][c][1]=='p'){
                        pawn p(arr);
                       pos=p.moveset(r, c);
                       
                        
                    }
                   else  if(arr[r][c][1]=='q'){
                       queen q(arr);
                       pos=q.moveset(r, c);
                    }
                   else  if(arr[r][c][1]=='k'){
                       king k(arr);
                       pos=k.moveset(r, c);
                     
                   
                    }
                    else if(arr[r][c][1]=='b'){
                        bishop b(arr);
                        pos=b.moveset(r, c);
                    }
                    else if(arr[r][c][1]=='n'){
                        knight n(arr);
                        pos=n.moveset(r, c);
                       
                        
                    }
                    else if(arr[r][c][1]=='r'){
                        rook r1(arr);
                        pos=r1.moveset(r, c);
                    }
                if(arr[r][c][0]=='W'){
                    for(int i=0;i<pos.size();i++){
                        white[{pos[i].first,pos[i].second}]++;
                    }
                }
                else{
                    for(int i=0;i<pos.size();i++){
                        black[{pos[i].first,pos[i].second}]++;
                    }
                }
                
            }
        }
        

    }
  
    void buildblock(){
        for(int j=0;j<8;j++){
            arr[1][j]="Bp";
        }
        for(int j=0;j<8;j++){
            arr[6][j]="Wp";
        }
        
        arr[0][0]="Br";
        arr[0][7]="Br";
        arr[0][1]="Bn";
        arr[0][6]="Bn";
        arr[0][2]="Bb";
        arr[0][5]="Bb";
        arr[0][3]="Bq";
        arr[0][4]="Bk";
        arr[7][0]="Wr";
        arr[7][7]="Wr";
        arr[7][1]="Wn";
        arr[7][6]="Wn";
        arr[7][2]="Wb";
        arr[7][5]="Wb";
        arr[7][3]="Wq";
        arr[7][4]="Wk";
        threats();
        
    }
    
    void display(){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"------------------------\n";

    }
    bool iscontain(vector<pair<int,int>>&pos,int x,int y){
        for(int i=0;i<pos.size();i++){
            if(pos[i].first==x && pos[i].second==y)return 1;
        }
        return 0;
    }
    
    vector<pair<int,int>> argum(int r,int c){
        vector<pair<int,int>>pos;
        if(arr[r][c][1]=='p'){
            pawn p(arr);
           pos=p.moveset(r, c);
           
            
        }
       else  if(arr[r][c][1]=='q'){
           queen q(arr);
           pos=q.moveset(r, c);
           
        }
       else  if(arr[r][c][1]=='k'){
           king k(arr);
           pos=k.moveset(r, c);
           
         
       
        }
        else if(arr[r][c][1]=='b'){
            bishop b(arr);
            pos=b.moveset(r, c);
        }
        else if(arr[r][c][1]=='n'){
            knight n(arr);
            pos=n.moveset(r, c);
           
            
        }
        else if(arr[r][c][1]=='r'){
            rook r1(arr);
            pos=r1.moveset(r, c);
        }
        return pos;
    }
    int playermove(int r,int c,int x,int y){
        vector<pair<int,int>>pos;
        if(arr[r][c][1]=='p'){
            pawn p(arr);
           pos=p.moveset(r, c);
           
            
        }
       else  if(arr[r][c][1]=='q'){
           queen q(arr);
           pos=q.moveset(r, c);
           
        }
       else  if(arr[r][c][1]=='k'){
           king k(arr);
           pos=k.moveset(r, c);
           
         
       
        }
        else if(arr[r][c][1]=='b'){
            bishop b(arr);
            pos=b.moveset(r, c);
        }
        else if(arr[r][c][1]=='n'){
            knight n(arr);
            pos=n.moveset(r, c);
           
            
        }
        else if(arr[r][c][1]=='r'){
            rook r1(arr);
            pos=r1.moveset(r, c);
        }
        
        if(iscontain(pos, x, y)){
            if(arr[r][c][1]=='p'){
                if(x==0 || x==7){
                    cout<<"Pawn going to promote!!!\n";
                    cout<<"Choose piece(Q,N,B,R)\n";
                    char ch;
                    cin>>ch;
                    if(ch=='Q'){
                        if(arr[r][c][0]=='W'){
                            arr[r][c]="Wq";
                        }
                        else arr[r][c]="Bq";
                    }
                    else if(ch=='N'){
                        if(arr[r][c][0]=='W'){
                            arr[r][c]="Wn";
                        }
                        else arr[r][c]="Bn";
                    }
                    else if(ch=='B'){
                        if(arr[r][c][0]=='W'){
                            arr[r][c]="Wb";
                        }
                        else arr[r][c]="Bb";
                    }
                    else{
                        if(arr[r][c][0]=='W'){
                            arr[r][c]="Wr";
                        }
                        else arr[r][c]="Br";
                    }
                    
                }

            }
            if(arr[r][c][1]=='k'){
                int count=0;
               
                if(arr[r][c][0]=='W'){
                    for(int i=0;i<pos.size();i++){
                        if(black.find({pos[i].first,pos[i].second})!=black.end())count++;
                    }
                    if(count==pos.size() && black.find({r,c})!=black.end())return 2;//checkmate
                    if(count==pos.size())return -1;//stalemate
                    if(black.find({x,y})!=black.end())return 0;//Invalid move
                    wkx=x;
                    wky=y;
                }
                else{
                    for(int i=0;i<pos.size();i++){
                        if(white.find({pos[i].first,pos[i].second})!=white.end())count++;
                    }
                   
                    if(count==pos.size() && white.find({r,c})!=white.end())return 2;//checkmate
                    if(count==pos.size())return -1;//stalemate
                    if(white.find({x,y})!=white.end())return 0;//Invalid move
                    bkx=x;
                    bky=y;
                }
            }
            white.clear();
            black.clear();
            arr[x][y]=arr[r][c];
            arr[r][c]="# ";
            threats();
            if(arr[x][y][0]=='W' && white.find({bkx,bky})!=white.end())return -2;//check
            if(arr[x][y][0]=='B' && black.find({wkx,wky})!=black.end())return -2;//check
            return 1;// move successfull;
         
        }
       
        return 0;
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
        
    cout<<"Let The Game Begin!!!!\n";
    vector<vector<string>>arr(8,vector<string>(8,"# "));
    chess game(arr);
    game.buildblock();
   
    game.display();
    bool turn =0;
    int l=0;
    while(true){
       
        if(turn ==0){
            if(l==-1){
                cout<<"White king under attack!!\n";
                int x,y;
                x=game.wkx;
                y=game.wky;
                int r,c;
                cin>>r>>c;
                if(game.argum(x,y).size()==0){
                    cout<<"Stalemate!!!\n";
                    continue;
                }
                int ans=game.playermove(x, y, r, c);
               
                while(ans==0){
                    cout<<"Invalid Move select a different position"<<"\n";
                    cin>>r>>c;
                    ans=game.playermove(x, y, r, c);
                }
                if(ans==2){
                    cout<<" Checkmate!->Black Wins!!!";
                    l=1;
                }
                if(ans==-1){
                    cout<<"Stalemate!->Draw!!";
                    l=1;
                }
                if(ans==-2){
                    l=-1;
                    
                }
                if(ans==1)l=0;
                turn=1;
            }
            else{
                while(true){
                    cout<<"Player White Move:";
                    int x,y;
                    cin>>x>>y;
                    cout<<"\n";
                    if(game.argum(x,y).size()==0){
                        cout<<"No Possible moves\n";
                        continue;
                    }
                    if(game.iswhite(x, y)){
                        cout<<"Touch piece!! Select a destination place"<<"\n";
                        int r,c;
                        cin>>r>>c;
                        int ans=game.playermove(x, y, r, c);
                       
                        while(ans==0){
                            cout<<"Invalid Move select a different position"<<"\n";
                            cin>>r>>c;
                            ans=game.playermove(x, y, r, c);
                        }
                       
                        if(ans==2){
                            cout<<" Checkmate!->Black Wins!!!";
                            l=1;
                        }
                        if(ans==-1){
                            cout<<"Stalemate!->Draw!!";
                            l=1;
                        }
                        if(ans==-2){
                            l=-1;
                            
                        }
                       
                        turn=1;
                        break;
                    }
                    else cout<<"Choose a white piece!!!"<<"\n";
                    
                }
            }
        }
        else{
           
            if(l==-1){
                cout<<"Black king under attack!!\n";
                int x,y;
                x=game.bkx;
                y=game.bky;
                int r,c;
                cin>>r>>c;
                if(game.argum(x,y).size()==0){
                    cout<<"Stalemate!!!\n";
                    continue;
                }
                int ans=game.playermove(x, y, r, c);
                while(ans==0){
                    cout<<"Invalid Move select a different position"<<"\n";
                    cin>>r>>c;
                    ans=game.playermove(x, y, r, c);
                }
                if(ans==2){
                    cout<<" Checkmate!->White Wins!!!";
                    l=1;
                }
                if(ans==-1){
                    cout<<"Stalemate!->Draw!!";
                    l=1;
                }
                if(ans==-2){
                    l=-1;
                    
                }
                if(ans==1){
                    l=0;
                }
                turn=0;
            }
            else{
                while(true){
                    cout<<"Player Black Move:";
                    int x,y;
                    cin>>x>>y;
                    cout<<"\n";
                    if(game.argum(x,y).size()==0){
                        cout<<"No Possible moves\n";
                        continue;
                    }
                    if(game.iswhite(x, y)==0){
                        cout<<"Touch piece!! Select Destination!!"<<"\n";
                        int r,c;
                        cin>>r>>c;
                        int ans=game.playermove(x, y, r, c);
                        while(ans==0){
                            cout<<"Invalid Move select a different position"<<"\n";
                            cin>>r>>c;
                            ans=game.playermove(x, y, r, c);
                        }
                        if(ans==2){
                            cout<<" Checkmate!->White Wins!!!";
                            l=1;
                        }
                        if(ans==-1){
                            cout<<"Stalemate!->Draw!!";
                            l=1;
                        }
                        if(ans==-2){
                            l=-1;
                            
                        }
                        turn=0;
                        break;
                    }
                    else cout<<"Choose a Black piece!!!"<<"\n";
                    
                }
            }
        }
        if(l==1)break;
        game.display();
       
    }
    
}

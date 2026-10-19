//
//  main.cpp
//  chess engine
//
//  Created by Raam Sundaran on 11/10/26.
//

#include <iostream>
#include<vector>
using namespace std;
class chess{
  public:
    vector<vector<string>>arr;
    chess(vector<vector<string>>&arr){
        this->arr=arr;
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
        
    }
    vector<vector<string>> board(){
        return arr;
    }
    
    void display(){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"-------end-------\n";

    }
    
    

};

class queen: public chess{
public:
    vector<pair<int,int>>mov;
    queen(vector<vector<string>>arr): chess(arr){
        
    }
    bool moveto(int r,int c,int x,int y){
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
            if(arr[r+i][c+i]=="#"){
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
            if(arr[r-i][c-i]=="#"){
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
            if(arr[r+i][c-i]=="#"){
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
            if(arr[r-i][c+i]=="#"){
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
        for(int i=0;i<mov.size();i++){
            if(x==mov[i].first && y==mov[i].second){
                arr[x][y]=arr[r][c];
                arr[r][c]="# ";
                return 1;
            }
        }
        return 0;
    }
    vector<pair<int,int>> moveset(){
        return mov;
    }
    
};
class bishop: public chess{
public:
    vector<pair<int,int>>mov;
    bishop(vector<vector<string>>arr): chess(arr){
        
    }
    bool moveto(int r,int c,int x,int y){
       
        for(int i=1;i<8-max(r,c);i++){
            if(arr[r+i][c+i]=="#"){
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
            if(arr[r-i][c-i]=="#"){
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
            if(arr[r+i][c-i]=="#"){
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
            if(arr[r-i][c+i]=="#"){
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
        for(int i=0;i<mov.size();i++){
            if(x==mov[i].first && y==mov[i].second){
                arr[x][y]=arr[r][c];
                arr[r][c]="# ";
                return 1;
            }
        }
        return 0;
    }
    vector<pair<int,int>> moveset(){
        return mov;
    }
    
};
class king: public chess{
public:
    vector<pair<int,int>>mov;
    king(vector<vector<string>>arr): chess(arr){
        
    }
    int moveto(int r,int c,int x,int y){
        if(r>0 && arr[r-1][c][0]!=arr[r][c][0])mov.push_back({r-1,c});
        if(c>0 && arr[r][c-1][0]!=arr[r][c][0])mov.push_back({r,c-1});
        if(r<7 && arr[r+1][c][0]!=arr[r][c][0])mov.push_back({r+1,c});
        if(c<7 && arr[r][c+1][0]!=arr[r][c][0])mov.push_back({r,c+1});
        if(r>0 && c>0 &&  arr[r-1][c-1][0]!=arr[r][c][0])mov.push_back({r-1,c-1});
        if(r>0 && c<7 && arr[r-1][c+1][0]!=arr[r][c][0])mov.push_back({r-1,c+1});
        if(r<7 && c>0 && arr[r+1][c-1][0]!=arr[r][c][0])mov.push_back({r+1,c-1});
        if(r<7 && c<7 && arr[r+1][c+1][0]!=arr[r][c][0])mov.push_back({r+1,c+1});
        if(mov.size()==0){
            cout<<"cant move";
            return -1;
        }
        for(int i=0;i<mov.size();i++){
            if(mov[i].first==x && mov[i].second==y){
                arr[x][y]=arr[r][c];
                arr[r][c]="#";
                return 1;
            }
        }
        return 0;
        
    }
    vector<pair<int,int>> moveset(){
        return mov;
    }
};
class knight: public chess{
    vector<pair<int,int>>mov;
    knight(vector<vector<string>>arr): chess(arr){
        
    }
    bool moveto(int r,int c,int x,int y){
        return 0;
    }
    vector<pair<int,int>> moveset(){
        return mov;
    }
};
class rook: public chess{
public:
    vector<pair<int,int>>mov;
    rook(vector<vector<string>>arr): chess(arr){
        
    }
    bool moveto(int r,int c,int x,int y){
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
        for(int i=0;i<mov.size();i++){
            if(x==mov[i].first && y==mov[i].second){
                arr[x][y]=arr[r][c];
                arr[r][c]="# ";
                return 1;
            }
        }
        return 0;
    }
    vector<pair<int,int>> moveset(){
        return mov;
    }
    
};
class pawn:public chess{
public:
    vector<pair<int,int>>mov;
    pawn(vector<vector<string>>arr): chess(arr){
        
    }
    bool moveto(int r,int c,int x,int y){
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
        for(int i=0;i<mov.size();i++){
            if(x==mov[i].first && y==mov[i].second){
                arr[x][y]=arr[r][c];
                arr[r][c]="# ";
                
                return 1;
            }
        }
        return 0;
    }
    vector<pair<int,int>> moveset(){
        return mov;
    }
       
    

    
};
int main(int argc, const char * argv[]) {
    // insert code here...
        
    
    vector<vector<string>>arr(8,vector<string>(8,"# "));
    chess game(arr);
    game.buildblock();
    game.display();
    
   
}

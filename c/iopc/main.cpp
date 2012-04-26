 //
//  main.cpp
//  IOPC
//
//  Created by Rishab Arora on 14/01/12.
//  Copyright 2012 __rishab.in__. All rights reserved.
//
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class rcube{
    int front[9],back[9],up[9],down[9],left[9],right[9],vfront[9],vback[9],vup[9],vdown[9],vleft[9],vright[9];
    //int *front,*back,*up,*down,*left,*right;
   // int *vfront,*vback,*vup,*vdown,*vleft,*vright;
public:
   /* rcube(){
        front = new int[10];
        back = new int[10];
        left = new int[10];
        right = new int[10];
        up = new int[10];
        down = new int[10];
        vfront = new int[10];
        vback = new int[10];
        vleft = new int[10];
        vright = new int[10];
        vup = new int[10];
        vdown = new int[10];
    }*/
    void reset(){
        
        
        for (int i=0;i<9;i++){
            vfront[i]=front[i]=10+i;
            vback[i]=back[i]=20+i;
            vup[i]=up[i]=30+i;
            vdown[i]=down[i]=40+i;
            vleft[i]=left[i]=50+i;
            vright[i]=right[i]=60+i;
            
            
        }
        
        
        
    }
    
    void f(){

        int f1[] = {front[6],front[3],front[0],front[7],front[4],front[1],front[8],front[5],front[2]};
      
        int l1[] = {left[0],left[1],down[2],left[3],left[4],down[5],left[6],left[7],down[8]};
        
        int u1[] = {up[0],up[1],left[2],up[3],up[4],left[5],up[6],up[7],left[8]};
        
        int r1[] = {right[0],right[1],up[2],right[3],right[4],up[5],right[6],right[7],up[8]};
        
        int d1[] = {down[0],down[1],right[2],down[3],down[4],right[5],down[6],down[7],right[8]};
        
        
        for (int i=0; i<9; i++){
            front[i]=f1[i];
          //  back[i]=b1[i];
            up[i]=u1[i];
            down[i]=d1[i];
            left[i]=l1[i];
            right[i]=r1[i];
        }
    }
    void fd(){
        f();
        f();
        f();
    }
    void b(){
        int b1[] = {back[6],back[3],back[0],back[7],back[4],back[1],back[8],back[5],back[2]};
      
        int l1[] = {up[0],left[1],left[2],up[3],left[4],left[5],up[6],left[7],left[8]};
       
        int u1[] = {right[0],up[1],up[2],right[3],up[4],up[5],right[6],up[7],up[8]};
        
        int r1[] = {down[0],right[1],right[2],down[3],right[4],right[5],down[6],right[7],right[8]};
        
        int d1[] = {left[0],down[1],down[2],left[3],down[4],down[5],left[6],down[7],down[8]};
       
        for (int i=0; i<9; i++){
            //front[i]=f1[i];
            back[i]=b1[i];
            up[i]=u1[i];
            down[i]=d1[i];
            left[i]=l1[i];
            right[i]=r1[i];
        }

        
        
    }
    void bd(){
        b();
        b();
        b();
    }
    
    void u(){
        int u1[] = {up[6],up[3],up[0],up[7],up[4],up[1],up[8],up[5],up[2]};
    
        int l1[] = {front[0],front[1],front[2],left[3],left[4],left[5],left[6],left[7],left[8]};
      
        int f1[] = {right[8],right[7],right[6],front[3],front[4],front[5],front[6],front[7],front[8]};
       
        int r1[] = {right[0],right[1],right[2],right[3],right[4],right[5],back[2],back[1],back[0]};
      
        int b1[] = {left[0],left[1],left[2],back[3],back[4],back[5],back[6],back[7],back[8]};
        
        for (int i=0; i<9; i++){
            front[i]=f1[i];
            back[i]=b1[i];
            up[i]=u1[i];
            //down[i]=d1[i];
            left[i]=l1[i];
            right[i]=r1[i];
        }

    }
    void ud(){
        u();
        u();
        u();
    }
//int f1[] = {front[0],front[1],front[2],front[3],front[4],front[5],front[6],front[7],front[8]};
    void d(){
        int d1[] = {down[6],down[3],down[0],down[7],down[4],down[1],down[8],down[5],down[2]};
       
        int l1[] = {left[0],left[1],left[2],left[3],left[4],left[5],back[6],back[7],back[8]};
     
        int f1[] = {front[0],front[1],front[2],front[3],front[4],front[5],left[6],left[7],left[8]};
       
        int r1[] = {front[8],front[7],front[6],right[3],right[4],right[5],right[6],right[7],right[8]};
       
        int b1[] = {back[0],back[1],back[2],back[3],back[4],back[5],right[2],right[1],right[0]};
        
        for (int i=0; i<9; i++){
            front[i]=f1[i];
            back[i]=b1[i];
            //up[i]=u1[i];
            down[i]=d1[i];
            left[i]=l1[i];
            right[i]=r1[i];
        }

    }
    void dd(){
        d();
        d();
        d();
    }
    void l(){
        int l1[] = {left[6],left[3],left[0],left[7],left[4],left[1],left[8],left[5],left[2]};
        
        int f1[] = {up[6],front[1],front[2],up[7],front[4],front[5],up[8],front[7],front[8]};
       
        int u1[] = {up[0],up[1],up[2],up[3],up[4],up[5],back[8],back[5],back[2]};
       
        int b1[] = {back[0],back[1],down[0],back[3],back[4],down[1],back[6],back[7],down[2]};
        
        int d1[] = {front[6],front[3],front[0],down[3],down[4],down[5],down[6],down[7],down[8]};
        
        for (int i=0; i<9; i++){
            front[i]=f1[i];
            back[i]=b1[i];
            up[i]=u1[i];
            down[i]=d1[i];
            left[i]=l1[i];
            //right[i]=r1[i];
        }

    }
    void ld(){
        l();
        l();
        l();
    }
    
    void r(){
        int r1[] = {right[6],right[3],right[0],right[7],right[4],right[1],right[8],right[5],right[2]};
        
        int f1[] = {front[0],front[1],down[8],front[3],front[4],down[7],front[6],front[7],down[6]};
        
        int u1[] = {front[2],front[5],front[8],up[3],up[4],up[5],up[6],up[7],up[8]};
        
        int b1[] = {up[2],back[1],back[2],up[1],back[4],back[5],up[0],back[7],back[8]};
       
        int d1[] = {down[0],down[1],down[2],down[3],down[4],down[5],back[0],back[3],back[6]};
        
        for (int i=0; i<9; i++){
            front[i]=f1[i];
            back[i]=b1[i];
            up[i]=u1[i];
            down[i]=d1[i];
            //left[i]=l1[i];
            right[i]=r1[i];
        }

    }
    void rd(){
        r();
        r();
        r();
    }
    
    void showCube(){
        cout<<"front\n";
        for (int i=0; i<9; i++){
            cout<<front[i]<<", ";
        }
        cout<<"\nback\n";
        for (int i=0; i<9; i++){
            cout<<back[i]<<", ";
        }

        cout<<"\nup\n";
        for (int i=0; i<9; i++){
            cout<<up[i]<<", ";
        }
        cout<<"\ndown\n";
        for (int i=0; i<9; i++){
            cout<<down[i]<<", ";
        }
        cout<<"\nleft\n";
        for (int i=0; i<9; i++){
            cout<<left[i]<<", ";
        }
        cout<<"\nright\n";
        for (int i=0; i<9; i++){
            cout<<right[i]<<", ";
        }
    }
        bool verifyCube(){
            bool okay=true;
            for (int i=0; i<9; i++){
                if (front[i]!=vfront[i] || back[i]!=vback[i] || up[i] !=vup[i] || down[i] != vdown[i] || left[i] != vleft[i] || right[i] != right[i]){
                    okay = false;
                    break;
                }
            }
            return okay;
    }
        
    
    
    
} cube;
class sequence{
    string seq;
    queue<int> squ;


public:
    void reset(){
        cube.reset();
    }
    void breakString(){
        for (int i=0; i<seq.length(); i++){
            switch(seq[i]){
                case 'F':
                    squ.push(1);
                    break;
                case 'B':
                    squ.push(2);
                    break;
                case 'U':
                    squ.push(3);
                    break;
                case 'D':
                    squ.push(4);
                    break;
                case 'L':
                    squ.push(5);
                    break;
                case 'R':
                    squ.push(6);
                    break;
                case '2':
                    squ.push(squ.back());
                    break;
                case '\'':
                    int LastPush=squ.back();
                    squ.push(-1*LastPush);
                    squ.push(-1*LastPush);
                    break;

            }
        }
    }
    bool normalizeString(){
        queue<int> squ2;
        long ln;
        bool normalizable=false;
        ln = squ.size();
        int temp;
        for (int i=0; i<ln; i++){
            temp = squ.front();
            squ.pop();
            if (temp == -1*(squ.front())){
                squ.pop();
                normalizable=true;
            }else
                squ2.push(temp);
        }
        squ=squ2;
        return normalizable;
    }

    
    void getString(){
        cin>>seq;
        breakString();
        while (normalizeString()){
            continue;
        
       }
       
    }
    
    void showSeq(){
        queue<int> squ2 (squ);
        cout<<"DUMP: ";
        for (long i=squ2.size(); i>0; i--){
            cout<<squ2.front()<<endl;
            squ2.pop();
        }
    }
    
    long performSeq(){
        
        queue<int> squ2;
       // cout<<"SIZE: "<<squ2.size();
        long count=0;
        int temp;
        if (squ.size()==0)
            return 1;
        do {
            squ2=squ;
            for (long i=squ2.size(); i>0; i--){
                //cout<<"check";
                temp=squ2.front();
                squ2.pop();
                switch (temp) {
                    case 1:
                        cube.f();
                        break;
                    case -1:
                        cube.fd();
                        break;
                    case 2:
                        cube.b();
                        break;
                    case -2:
                        cube.bd();
                        break;
                    case 3:
                        cube.u();
                        break;
                    case -3:
                        cube.ud();
                        break;
                    case 4:
                        cube.d();
                        break;
                    case -4:
                        cube.dd();
                        break;
                    case 5:
                        cube.l();
                        break;
                    case -5:
                        cube.ld();
                        break;
                    case 6:
                        cube.r();
                        break;
                    case -6:
                        cube.rd();
                        break;
                    default:
                        break;
                }
                 
                
            } 
            count++;
        } while (cube.verifyCube()!=1);
        return count;
    }
    
};



int main (int argc, const char * argv[])
{

    // insert code here...
    int inp;
    cin>>inp;

        sequence seq;
    for  (int iter=0; iter<inp; iter++){

        seq.reset();
        seq.getString();
       // seq.showSeq();
        cout<<seq.performSeq()<<endl;

    }

    
    return 0;
}

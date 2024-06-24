#include <stdio.h>
int x[4][4],li=4,ci=4,ld=4,cd=4,i,j,ve=0,som=0,timer=0,tam=0,ln[3],vff;
char pos[3][3];
void ji(){
    printf("Jogador 1:\n");
    do{
        printf("Linha: ");
        scanf("%d",&li);
    }
    while(li<0 || li>3 || ln[li-1]==1);
    do{
        printf("Coluna: ");
        scanf("%d",&ci);
        if(x[li-1][ci-1]==0){
        x[li-1][ci-1]=1;
        vff=0;
        }else{
            vff=1;
        }
    }
    while(ci<0 || ci>3 || vff==1);
}
void jii(){
    printf("Jogador 2:\n");
    do{
        printf("Linha: ");
        scanf("%d",&ld);
    }
    while(ld<0 || ld>3 || ln[ld-1]==1);
    do{
        printf("Coluna: ");
        scanf("%d",&cd);
        if(x[ld-1][cd-1]==0){
            x[ld-1][cd-1]=10;
            vff=0;
        }else{
            vff=1;
        }
    }
    while(cd<0 || cd>3 || vff==1);
}
void vr(){
    for(i=0;i<=5;i++){
        for(j=0;j<=2;j++){
            if(i<=2){
                som=som+x[i][j];
            }else{
                som=som+x[j][i-3];
            }
            if(i<=2){
                if(x[i][j]>0){
                tam=tam+1;
            }
            }
        }
         if(tam==3){
            ln[i]=1;
        }else{
            ln[i]=0;
        }
        tam=0;
        if(som==3){
            ve=1;
            i=5;
        }else if(som==30){
            ve=2;
            i=5;
        }else{
            som=0;
        }
    }
    if(ve==0){
        som=x[0][0]+x[1][1]+x[2][2];
        if(som==3){
            ve=1;
        }else if(som==30){
            ve=2;
        }
        som=x[0][2]+x[1][1]+x[2][0];
        if(som==3){
            ve=1;
        }else if(som==30){
            ve=2;
        }}
        if(timer==9){
            ve=3;
        }
}
void mostrar(){
    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
            if(x[i][j]==1){
               pos[i][j]='X'; 
            }else if(x[i][j]==10){
                pos[i][j]='O';
            }else{
                pos[i][j]=' ';
            }
        }
    }
    printf("  1   2   3\n1 %c | %c | %c\n ---|---|---\n2 %c | %c | %c \n ---|---|---\n3 %c | %c | %c\n",pos[0][0],pos[0][1],pos[0][2],pos[1][0],pos[1][1],pos[1][2],pos[2][0],pos[2][1],pos[2][2]);
}
int main(){
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            x[i][j]=0;
        }
    }
    printf("  1 2 3\n1 _|_|_\n2 _|_|_\n3  | | \n");
    do{
        ji();
        timer++;
        mostrar();
        vr();
        if(ve==0){
        jii();
        timer++;
        mostrar();
        vr();
        }
    }
    while(ve==0);
    if(ve==1){
        printf("Vitória do jogador 1");
    }else if(ve==2){
        printf("Vitória do jogador 2");
    }else{
        printf("Empate");
    }
    return 0;
}


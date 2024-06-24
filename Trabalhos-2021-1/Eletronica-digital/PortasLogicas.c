#include <stdio.h>
#include <string.h>
char p[4];
int a,b,s=0,i,ii=0,q,vv,ss=0,yy=1;
/*int x(){
    printf("Entrada A (1 ou 0): ");
    scanf("%d",&a);
    if(a>1){
        printf("Inválido\n");
        x();
    }else{
    int xx(){
        if(strcmp(p,"NOT")==0){
            if(a==0){
                s=1;
            }
            printf("| A | X |\n| %d | %d |",a,s);
        }else{
        printf("Entrada B (1 ou 0): ");
        scanf("%d",&b);
        if(b>1){
            printf("Inválido\n");
            xx();
        }else{
            if(strcmp(p,"OR")==0){
            s=a+b;
            if(a==1 && b==1){
                s=1;
            }
        }else if(strcmp(p,"AND")==0){
            s=a*b;
        }else if(strcmp(p,"NAND")==0){
            if(a==0 || b==0){
                s=1;
            }
        }else if(strcmp(p,"NOR")==0){
            if(a==0 && b==0){
                s=1;
            }
        }else if(strcmp(p,"XOR")==0){
            if(a!=b){
                s=1;
            }
        }else if(strcmp(p,"XNOR")==0){
            if(a=b){
                s=1;
            }
        }
            printf("| A | B | X |\n| %d | %d | %d |",a,b,s);
        }}
        return 0;
}
        xx();
    }
    return 0;
}
int y(){
    printf("Quantas entradas você quer?: ");
    scanf("%d",&q);
    int v[q];
    int yyy(){
    for(i=ii;i<q;i++){
        printf("%dº entrada: ",i+1);
        scanf("%d",&v[i]);
        if(v[i]>1){
            printf("Inválido\n");
            i=q-1;
            yy=2;
            yyy();
        }
        ss++;
        yy=yy*v[i];
        ii++;
    }
    return 0;
    }
    yyy();
    if(yy<2){
    if(strcmp(p,"AND")==0){
        s=yy;
    }else if(strcmp(p,"OR")==0){
        if(ss>0){
            s=1;
        }
    }else if(strcmp(p,"NAND")==0){
        if(yy==0){
            s=1;
        }
    }else if(strcmp(p,"NOR")==0){
        if(ss==0){
            s=1;
        }
    }else if(strcmp(p,"XOR")==0){
        if(ss%2!=0){
            s=1;
        }
    }else{
        if(ss%2==0){
            s=1;
        }
    }
    printf("|");
    for(i=1;i<=q;i++){
        printf(" %dº |",i);
    }
    printf(" X |\n|");
    for(i=0;i<q;i++){
        printf(" %d  |",v[i]);
    }
    printf(" %d |",s);
    }
    return 0;
}
int main()
{
    printf("Qual porta você quer?(NOT, AND, OR, NAND, NOR, XOR, XNOR): ");
    scanf("%s",p);
    if(strcmp(p,"NOT")!=0 && strcmp(p,"AND")!=0 && strcmp(p,"OR")!=0 && strcmp(p,"NAND")!=0 && strcmp(p,"NOR")!=0 && strcmp(p,"XOR")!=0 && strcmp(p,"XNOR")!=0){
        printf("Inválido\n");
        main();
    }else{
    int mainn(){
    if(strcmp(p,"NOT")==0){
        x();
    }else{
    printf("Qual versão você quer?(1 ou 2): ");
    scanf("%d",&vv);
    if(vv==1){
    x();
    }else if(vv==2){
        y();
    }else{
        printf("Inválido\n");
        mainn();
    }return 0;
    }
    }
        mainn();
    }
    return 0;
}
*/
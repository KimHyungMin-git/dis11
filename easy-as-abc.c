#include <stdio.h>
#include <string.h>
int main(){
    FILE * fp = fopen("formula2", "w") ;
 int i,j,n,m;
 char element[6]={'_','A','B','C','D','E'};
 int grid;
 scanf("%d",&grid); 
 getchar();
 char con_top[15];
 char con_bottom[15];
 char con_left[15];
 char con_right[15];
            for(i=0; i<grid; i++)
            scanf("%c",&con_top[i]);  
            getchar();
            for(i=0; i<grid; i++)
            scanf("%c",&con_bottom[i]);  
            getchar();
            for(i=0; i<grid; i++)
            scanf("%c",&con_left[i]);  
            getchar();
            for(i=0; i<grid; i++)
            scanf("%c",&con_right[i]);  
            getchar();
    
    for(i=1; i<=grid; i++){
        for(j=1; j<=grid; j++){
            for(n=1; n<=6; n++){
                fprintf(fp,"(declare-const p%d%d%c Bool)",i,j,element[n-1]);}
            }
        }
        fprintf(fp,"\n");

        fprintf(fp,"(assert ");
        fprintf(fp,"(and ");
    
      fprintf(fp,"(and ");
    for(i=1; i<=grid; i++){
        for(n=1; n<=5; n++){
            fprintf(fp,"(or ");
            for(j=1; j<=grid; j++){
                    fprintf(fp,"p%d%d%c ",i,j,element[n]);
            }
            fprintf(fp,")");
        }
    }
    fprintf(fp,")");
    fprintf(fp,"\n");

    fprintf(fp,"(and ");
    for(j=1; j<=grid; j++){
        for(n=1; n<=5; n++){
            fprintf(fp,"(or ");
            for(i=1; i<=grid; i++){
                    fprintf(fp,"p%d%d%c ",i,j,element[n]);
            }
            fprintf(fp,")");
        }
    }
    fprintf(fp,")");
    fprintf(fp,"\n");
	

fprintf(fp,"(and ");
     for(i=1; i<=grid; i++){
        for(j=1; j<=grid; j++){
            for(n=1; n<=6; n++){
                for(m=n+1; m<=6; m++){
                    fprintf(fp,"(=> p%d%d%c (not p%d%d%c))",i,j,element[n-1],i,j,element[m-1]);
                }
            }
        }
    }
    fprintf(fp,")");
    fprintf(fp,"\n");



    fprintf(fp,"(and ");
    for(i=1; i<=grid; i++){
    for(n=1; n<=5; n++){
	for(j=1; j<=grid; j++){
	for(m=j+1; m<=grid; m++){
	fprintf(fp,"(=> p%d%d%c (not p%d%d%c))",i,j,element[n],i,m,element[n]);
}
}
}	
}
   fprintf(fp,")");
   fprintf(fp,"\n");

   fprintf(fp,"(and ");
   for(j=1; j<=grid; j++){
   for(n=1; n<=5; n++){
   for(i=1; i<=grid; i++){
   for(m=i+1; m<=grid; m++){
   fprintf(fp,"(=> p%d%d%c (not p%d%d%c))",i,j,element[n],m,j,element[n]);
}
}
}
} 
   fprintf(fp,")");
   fprintf(fp,"\n");
	

    for(i=0; i<grid; i++){
        if(con_top[i]!='_'){
            fprintf(fp,"(or ");
            for(j=1; j<=grid-4; j++){
	    fprintf(fp,"(and ");
	    fprintf(fp,"p%d%d%c ",i+1,j,con_top[i]);
	    for(m=1; m<j; m++){
            fprintf(fp,"p%d%d%c ",i+1,m,'_');}
	    fprintf(fp,")");
}
            fprintf(fp,")");
        }
    }
	for(i=0; i<grid; i++){
        if(con_bottom[i]!='_'){
            fprintf(fp,"(or ");
            for(j=1; j<=grid-4; j++){
            fprintf(fp,"(and ");
            fprintf(fp,"p%d%d%c ",i+1,grid+1-j,con_bottom[i]);
            for(m=1; m<j; m++){
            fprintf(fp,"p%d%d%c ",i+1,grid+1-m,'_');}
            fprintf(fp,")");
}
            fprintf(fp,")");
        }
    }
	for(i=0; i<grid; i++){
        if(con_left[i]!='_'){
            fprintf(fp,"(or ");
            for(j=1; j<=grid-4; j++){
            fprintf(fp,"(and ");
            fprintf(fp,"p%d%d%c ",j,i+1,con_left[i]);
            for(m=1; m<j; m++){
            fprintf(fp,"p%d%d%c ",m,i+1,'_');}
            fprintf(fp,")");
}
            fprintf(fp,")");
        }
    }

for(i=0; i<grid; i++){
        if(con_right[i]!='_'){
            fprintf(fp,"(or ");
            for(j=1; j<=grid-4; j++){
            fprintf(fp,"(and ");
            fprintf(fp,"p%d%d%c ",grid+1-j,i+1,con_right[i]);
            for(m=1; m<j; m++){
            fprintf(fp,"p%d%d%c ",grid+1-m,i+1,'_');}
            fprintf(fp,")");
}
            fprintf(fp,")");
        }
    }

    
    fprintf(fp,")");
    fprintf(fp,")");
    fprintf(fp,"\n(check-sat)\n");
    fprintf(fp,"(get-model)");
    fclose(fp) ;
    FILE * fin = popen("z3 formula2", "r") ;
	char buf[128] ;
        char output[20][20];
        char temp[20];
        int col,row;
        int val=0;
	fscanf(fin, "%s %s", buf, buf) ;
	while (!feof(fin)) {
		fscanf(fin, "%s", buf) ; 
                if(buf[1]=='l'){
                val=1;
                break;
}
		fscanf(fin, "%s", temp ) ; 
		fscanf(fin, "%s", buf) ; 
		fscanf(fin, "%s", buf) ; 
		fscanf(fin, "%s", buf) ; 
                if(strcmp(buf,"true)")==0){
                if(strlen(temp)<5){
                col=(int)temp[1]-49;
                row=(int)temp[2]-49;
                output[row][col]=temp[3];
}
                else if(strlen(temp)==5){
                if(((int)temp[1]-48==1)&&((int)temp[2]-48==0)){
                col=9;
                row=(int)temp[3]-49;}
                else{
                col=(int)temp[1]-49;
                row=9;
}
                output[row][col]=temp[4];
}
                else{
                col=9;
                row=9;
                output[row][col]=temp[5];
}
} 
	}
        printf("\n");
        if(val==0){
        for(i=0; i<grid; i++){
        for(j=0; j<grid; j++){
        printf("%c",output[i][j]);
}
        printf("\n");
}
}else{
    printf("input is invaild!\n");
}
	pclose(fin) ;

}

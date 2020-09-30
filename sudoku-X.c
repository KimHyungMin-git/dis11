#include<stdio.h>
#include<string.h>
int main(){
    FILE * fp = fopen("formula", "w") ;
    int i,j,k,m,s,n,r;
    char input[9][9];
    for(j=0; j<9; j++){
        for(i=0; i<9; i++){
            scanf("%c",&input[j][i]);
        }
        getchar();
    }
    fprintf(fp,"; final.txt\n");
    for(i=1; i<=9; i++){
        for(j=1; j<=9; j++){
            for(n=1; n<=9; n++){
                fprintf(fp,"(declare-const p%d%d%d Bool)",i,j,n);}
            }
        }
    fprintf(fp,"\n");
    for(i=1; i<=9; i++){
        for(j=1; j<=9; j++){
            if(input[j-1][i-1]!='?'){
            fprintf(fp,"(assert ");
            fprintf(fp,"(= p%d%d%d true)",i,j,(int)input[j-1][i-1]-48);
                fprintf(fp,")");
            }
        }
    }
    fprintf(fp,"\n");
    fprintf(fp,"(assert ");
    fprintf(fp,"(and ");

    fprintf(fp,"(and ");
    for(i=1; i<=9; i++){
        for(n=1; n<=9; n++){
            fprintf(fp,"(or ");
            for(j=1; j<=9; j++){
                    fprintf(fp,"p%d%d%d ",i,j,n);
            }
            fprintf(fp,")");
        }
    }
    fprintf(fp,")");
    fprintf(fp,"\n");

    fprintf(fp,"(and ");
    for(j=1; j<=9; j++){
        for(n=1; n<=9; n++){
            fprintf(fp,"(or ");
            for(i=1; i<=9; i++){
                    fprintf(fp,"p%d%d%d ",i,j,n);
            }
            fprintf(fp,")");
        }
    }
    fprintf(fp,")");
    fprintf(fp,"\n");
     fprintf(fp,"(and ");
     for(i=1; i<=9; i++){
        for(j=1; j<=9; j++){
            for(n=1; n<=9; n++){
                for(m=n+1; m<=9; m++){
                    fprintf(fp,"(=> p%d%d%d (not p%d%d%d))",i,j,n,i,j,m);
                }
            }
        }
    }
    fprintf(fp,")");
    fprintf(fp,"\n");

    fprintf(fp,"(and ");
    for(n=1; n<=9; n++){
        fprintf(fp,"(or ");
        j=0; 
        for(i=1; i<=9; i++){
            j++;
            fprintf(fp,"p%d%d%d ",i,j,n);
        }
        fprintf(fp,")");
    }
    fprintf(fp,")");
    
    fprintf(fp,"(and ");
    for(n=1; n<=9; n++){
        fprintf(fp,"(or ");
        j=10;
        for(i=1; i<=9; i++){
             j--;
            fprintf(fp,"p%d%d%d ",i,j,n);
        }
        fprintf(fp,")");
    }
    fprintf(fp,")");
    fprintf(fp,"\n");

    fprintf(fp,"(and ");
    for(r=0; r<=2; r++){
        for(s=0; s<=2; s++){
            for(n=1; n<=9; n++){
                fprintf(fp,"(or ");
                for(i=1; i<=3; i++){
                    for(j=1; j<=3; j++){
                        fprintf(fp,"p%d%d%d ",3*r+i,3*s+j,n);
                    }
                       
                }
        fprintf(fp,")");    }
        }
    }
    fprintf(fp,")");
    fprintf(fp,"\n");
    
    fprintf(fp,")");
    fprintf(fp,")");
    fprintf(fp,"\n(check-sat)\n");
    fprintf(fp,"(get-model)");
    fclose(fp) ;
    FILE * fin = popen("z3 formula", "r") ;
	char buf[128] ;
        char arynum[128];
        int output[9][9];
        int col,row;
        int val=0;
	fscanf(fin, "%s %s", buf, buf) ;
	while (!feof(fin)) {
		fscanf(fin, "%s", buf) ;
		if(buf[1]=='l'){
                val=1;
                break;
}
		
		fscanf(fin, "%s", arynum) ;
		fscanf(fin, "%s", buf) ; 
		fscanf(fin, "%s", buf) ; 
		fscanf(fin, "%s", buf) ;
                if(strcmp(buf,"false)")!=0){
                col=(int)arynum[1]-49;
                row=(int)arynum[2]-49;
                output[row][col]=(int)arynum[3]-48;
} 
}
       printf("\n");
       if(val==0){
       for(i=0; i<9; i++){
       for(j=0; j<9; j++){
       printf("%d",output[i][j]);
}
       printf("\n");
}
}
else{
printf("Input is invaild!\n");
}

	pclose(fin) ;

}
